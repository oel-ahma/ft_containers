#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <functional>

namespace ft 
{
    /* enable_if : https://en.cppreference.com/w/cpp/types/enable_if */
	template<bool B, class T = void>
	struct enable_if {};
	
	template<class T>
	struct enable_if<true, T> 
	{ 
		typedef T type; 
	};

    template <bool isConst, typename T>
    struct enable_if_const 
    {
        typedef typename T::value_type value_type; 
    };

    template <typename T>
    struct enable_if_const<true, T> 
    { 
        typedef const typename T::value_type value_type; 
    };

	/* is_integral : https://en.cppreference.com/w/cpp/types/is_integral */
	template <typename T, bool bool_type>
	struct integral_constant 
    {
		typedef T type;
		const static bool value = bool_type;
	};

	template <class T> struct is_integral : public integral_constant<T, false> {} ;
	template <> struct is_integral<bool> : public integral_constant<bool, true> {} ;
	template <> struct is_integral<char> : public integral_constant<char, true> {} ;
	template <> struct is_integral<wchar_t> : public integral_constant<wchar_t, true> {} ;
	template <> struct is_integral<signed char> : public integral_constant<signed char, true> {} ;
	template <> struct is_integral<short int> : public integral_constant<short int, true> {} ;
	template <> struct is_integral<int> : public integral_constant<int, true> {} ;
	template <> struct is_integral<long int> : public integral_constant<long int, true> {} ;
	template <> struct is_integral<long long int> : public integral_constant<long long int, true> {} ;
	template <> struct is_integral<unsigned char> : public integral_constant<unsigned char, true> {} ;
	template <> struct is_integral<unsigned short int> : public integral_constant<unsigned short int, true> {} ;
	template <> struct is_integral<unsigned int> : public integral_constant<unsigned int, true> {} ;
	template <> struct is_integral<unsigned long int> : public integral_constant<unsigned long int, true> {} ;
	template <> struct is_integral<unsigned long long int> : public integral_constant<unsigned long long int, true> {} ;

	/* equal : https://www.cplusplus.com/reference/algorithm/equal/?kw=equal */ 
	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1) 
		{
			if (!pred(*first1,*first2))
				return false;
			++first1; ++first2;
		}
		return true;
	}

	/* lexicographical_compare : https://www.cplusplus.com/reference/algorithm/lexicographical_compare/ */
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || comp(*first2, *first1)) return (false);
            else if (comp(*first1, *first2)) return (true);
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }

	/* pair : https://www.cplusplus.com/reference/utility/pair/?kw=pair */ 
	template <class T1, class T2>
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		pair() {}
		pair( const T1& x, const T2& y ) : first(x), second(y) {}
		template< class U1, class U2 >
		pair( const pair<U1, U2>& p ) : first(p.first), second(p.second) {}
		virtual ~pair() {}

		pair& operator=(const pair& other)
		{
			if (this != &other)
			{
				this->first = other.first;
				this->second = other.second;
			}
			return *this;
		}
	};

	template< class T1, class T2 >
	ft::pair<T1,T2> make_pair(T1 t, T2 u)
	{
		return ft::pair<T1,T2>(t, u);
	};

	template< class T1, class T2 >
	bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) 
	{ 
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}
	template< class T1, class T2 >
	bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (!(lhs == rhs)); }
	
	template< class T1, class T2 >
	bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		if (lhs.first == rhs.first)
			return (lhs.second < rhs.second);
		if (lhs.first < rhs.first)
			return (lhs.second < rhs.second);
		return false;
	}
	template< class T1, class T2 >
	bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (!(rhs < lhs)); }
	template< class T1, class T2 >
	bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (rhs < lhs); }
	template< class T1, class T2 >
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (!(lhs < rhs)); }

	template <class T> 
	struct less : binary_function<T,T,bool> 
	{
		bool operator() (const T& x, const T& y) const 
		{
			return (x < y);
		}
	};

};

#endif