#ifndef _REVERSE_ITERATOR_HPP
#define _REVERSE_ITERATOR_HPP

#include "utils.hpp"

namespace ft
{
    template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
    struct iterator
    {
        typedef Category    iterator_category;
        typedef T           value_type;
        typedef Distance    difference_type;
        typedef Pointer     pointer;
        typedef Reference   reference;
    };

    struct random_access_iterator_tag {};

    template <class Iter> 
    struct iterator_traits
    {
        typedef typename Iter::difference_type      difference_type;
        typedef typename Iter::value_type           value_type;
        typedef typename Iter::pointer              pointer;
        typedef typename Iter::reference            reference;
        typedef typename Iter::iterator_category    iterator_category;  
    };

    template <class T>
    struct iterator_traits<T*>
    {
        typedef std::ptrdiff_t                              difference_type;
        typedef T                                           value_type;
        typedef T*                                          pointer;
        typedef T&                                          reference;
        typedef typename ft::random_access_iterator_tag     iterator_category;
    };

    template <class T>
	struct iterator_traits<const T *>
	{
		typedef typename std::ptrdiff_t	                    difference_type;
		typedef const T                                     value_type;
		typedef const T*                                    pointer;
		typedef const T&                                    reference;
		typedef typename ft::random_access_iterator_tag	    iterator_category;
	};

    template <class Iter>
    class reverse_iterator
    {
        public:
            typedef Iter                                                    iterator_type;
            typedef typename iterator_traits<Iter>::iterator_category       iterator_category;
            typedef typename iterator_traits<Iter>::value_type              value_type;
            typedef typename iterator_traits<Iter>::difference_type         difference_type;
            typedef typename iterator_traits<Iter>::pointer                 pointer;
            typedef typename iterator_traits<Iter>::reference               reference;

        protected:
            iterator_type _current;
        
        public:
            reverse_iterator() : _current(0){}
            explicit reverse_iterator(iterator_type x) : _current(x) {}
            template <class T>
            reverse_iterator( const reverse_iterator<T>& other ) : _current(other.base()) {}
            template <class T>
            reverse_iterator& operator=( const reverse_iterator<T>& other ) { _current = other.base(); return *this; }
            iterator_type base() const { return this->_current; }
            reference operator*() const 
            { 
                iterator_type tmp = this->_current;
                return *--tmp;
            }
            pointer operator->() const { return &(operator*()); }

            reverse_iterator& operator++() 
            {
                _current--; 
                return *this;
            }
            reverse_iterator& operator--()
            {
                _current++;
                return *this;
            }
            reverse_iterator operator++( int )
            {
                reverse_iterator tmp = *this;
                --_current;
                return (tmp);
            }
            reverse_iterator operator--( int )
            {
                reverse_iterator tmp = *this;
                ++_current;
                return (tmp);
            }
            reverse_iterator operator+(difference_type n) const { return reverse_iterator(_current - n); }
            difference_type operator+(reverse_iterator const rhs) { return rhs.base() + this->base(); }
            reverse_iterator operator-(difference_type n) const { return reverse_iterator(_current + n); }
            difference_type operator-(reverse_iterator const rhs) { return rhs.base() - this->base(); }
            reverse_iterator& operator+=(difference_type n) { _current -= n; return (*this); }
            reverse_iterator& operator-=(difference_type n) { _current += n; return (*this); }
            reference operator[](difference_type n) const{ return base()[-n - 1]; }
    };

    template <typename T, typename U>
	bool operator==(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs) { return(lhs.base() == rhs.base()); };
 	template <typename T, typename U>
	bool operator!=(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs) { return(lhs.base() != rhs.base()); };
 	template <typename T, typename U>
	bool operator<(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs) { return(lhs.base() > rhs.base()); };
 	template <typename T, typename U>
	bool operator<=(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs) { return(lhs.base() >= rhs.base()); };
 	template <typename T, typename U>
	bool operator>(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs) { return(lhs.base() < rhs.base()); };
 	template <typename T, typename U>
	bool operator>=(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs) { return(lhs.base() <= rhs.base()); };

    template< class T >
    reverse_iterator<T> operator+( typename reverse_iterator<T>::difference_type n, const reverse_iterator<T>& it )
    {
        return reverse_iterator<T>(it.base() - n);
    };
    template< class T >
    typename reverse_iterator<T>::difference_type operator-( const reverse_iterator<T>& lhs, const reverse_iterator<T>& rhs )
    {
        return rhs.base() - lhs.base();
    };
};

#endif