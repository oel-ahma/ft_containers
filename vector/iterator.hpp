#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft
{
	template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T *, class Reference = T &>
	struct iterator
	{
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};

	struct random_access_iterator_tag {};

    template <typename Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template <class T>
	struct iterator_traits<T *>
	{
		typedef typename std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef typename ft::random_access_iterator_tag	iterator_category;
	};

	template <class T>
	struct iterator_traits<const T *>
	{
		typedef typename std::ptrdiff_t	difference_type;
		typedef const T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef typename ft::random_access_iterator_tag	iterator_category;
	};

	template <class Iterator> class reverse_iterator
	{
        public:
            typedef Iterator iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename iterator_traits<Iterator>::value_type value_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer pointer;
            typedef typename iterator_traits<Iterator>::reference reference;
            
            iterator_type base() const {return _it;}
            reverse_iterator(void): _it(0){}
            explicit reverse_iterator(iterator_type it):_it(it){}
            template <class Iter>
            reverse_iterator(const reverse_iterator<Iter> &rev_it):_it(rev_it.base()){}
            reference operator*() const{iterator_type tmp = _it; return *--tmp;}
            reverse_iterator operator+(difference_type n) const{return reverse_iterator(_it - n);}
            difference_type operator+(reverse_iterator const &r){return r.base() + this->base();}
            reverse_iterator operator-(difference_type n) const{return reverse_iterator(_it + n);}
            difference_type operator-(reverse_iterator const &r){return r.base() - this->base();}
            reverse_iterator& operator++(){_it--; return *this;}
            reverse_iterator operator++(int){reverse_iterator tmp = *this;--_it; return tmp;}
            reverse_iterator& operator--(){_it++; return *this;}
            reverse_iterator operator--(int){reverse_iterator tmp(*this); _it++; return tmp;}
            reverse_iterator& operator+=(difference_type n){_it -= n; return *this;}
            reverse_iterator& operator-=(difference_type n){ _it += n; return *this;}
            pointer operator->() const{return &(operator*());};
            reference operator[](difference_type n) const{return base()[-n-1];};

        private:
            iterator_type _it;
	};
 	template <typename T, typename U>
	bool operator==(const reverse_iterator<T> &l, const reverse_iterator<U> &r){return(l.base() == r.base());};
 	template <typename T, typename U>
	bool operator!=(const reverse_iterator<T> &l, const reverse_iterator<U> &r){return(l.base() != r.base());};
 	template <typename T, typename U>
	bool operator<(const reverse_iterator<T> &l, const reverse_iterator<U> &r){return(l.base() > r.base());};
 	template <typename T, typename U>
	bool operator<=(const reverse_iterator<T> &l, const reverse_iterator<U> &r){return(l.base() >= r.base());};
 	template <typename T, typename U>
	bool operator>(const reverse_iterator<T> &l, const reverse_iterator<U> &r){return(l.base() < r.base());};
 	template <typename T, typename U>
	bool operator>=(const reverse_iterator<T> &l, const reverse_iterator<U> &r){return(l.base() <= r.base());};
	template <typename T>
	reverse_iterator<T> operator+(typename ft::reverse_iterator<T>::difference_type n, const reverse_iterator<T> &r){return(reverse_iterator<T>(n - r.base()));}
    template <typename T>
	reverse_iterator<T> operator-(typename ft::reverse_iterator<T>::difference_type n, const reverse_iterator<T> &r){return(reverse_iterator<T>(n + r.base()));}

    template <class T>
    class random_access_iterator : private ft::iterator<random_access_iterator_tag, T>
    {
        public:
            typedef T value_type;
            typedef T& reference;
            typedef T* pointer;
            typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type difference_type;
		    typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category iterator_category;

            pointer base() const{return(this->_ptr);}
            random_access_iterator(void){};
            random_access_iterator(const random_access_iterator &other){*this = other;};
            random_access_iterator(pointer ptr): _ptr(ptr){};
            ~random_access_iterator(void){};
            random_access_iterator &operator=(const random_access_iterator &other){_ptr = other._ptr;return(*this);};
            operator random_access_iterator<const T>() {return random_access_iterator<const T>(_ptr);}
            difference_type operator+(const random_access_iterator& random_access_iterator2) const{return(_ptr + random_access_iterator2._ptr);}
            random_access_iterator operator+(difference_type n) const{return(random_access_iterator(_ptr + n));}
            difference_type operator-(const random_access_iterator& random_access_iterator2) const{return(_ptr - random_access_iterator2._ptr);}
            random_access_iterator operator-(difference_type n) const{return(random_access_iterator(_ptr - n));}
            random_access_iterator &operator++(void){_ptr++;return (*this);};
            random_access_iterator operator++(int){random_access_iterator tmp(*this);operator++();return(tmp);};
            random_access_iterator &operator--(void){_ptr--;return (*this);};
            random_access_iterator operator--(int){random_access_iterator tmp(*this);operator--();return(tmp);};
            random_access_iterator &operator+=(difference_type n){_ptr+=n;return(*this);};
            random_access_iterator &operator-=(difference_type n){_ptr-=n;return(*this);};
            bool operator==(const random_access_iterator &other) const{return(_ptr == other._ptr);};
            bool operator!=(const random_access_iterator &other) const{return(_ptr != other._ptr);};
            bool operator>(const random_access_iterator &other) const{return(_ptr > other._ptr);};
            bool operator>=(const random_access_iterator &other) const{return(_ptr >= other._ptr);};
            bool operator<(const random_access_iterator &other) const{return(_ptr < other._ptr);};
            bool operator<=(const random_access_iterator &other) const{return(_ptr <= other._ptr);}; 
            reference operator*(void){return(*_ptr);};
            pointer operator->(void){return(_ptr);};
            value_type &operator[](difference_type n) const{return (*(*this + n));}

            protected:
                pointer _ptr;
    };
    template <typename T, typename U>
	bool operator==(const random_access_iterator<T> &l, const random_access_iterator<U> &r){return(l.base() == r.base());};   
    template <typename T, typename U>
	bool operator!=(const random_access_iterator<T> &l, const random_access_iterator<U> &r){return(l.base() != r.base());};
    template <typename T, typename U>
	bool operator<(const random_access_iterator<T> &l, const random_access_iterator<U> &r){return(l.base() < r.base());};
    template <typename T, typename U>
	bool operator<=(const random_access_iterator<T> &l, const random_access_iterator<U> &r){return(l.base() <= r.base());};
    template <typename T, typename U>
	bool operator>(const random_access_iterator<T> &l, const random_access_iterator<U> &r){return(l.base() > r.base());};
    template <typename T, typename U>
	bool operator>=(const random_access_iterator<T> &l, const random_access_iterator<U> &r){return(l.base() >= r.base());};
    template <typename T>
	random_access_iterator<T> operator+(typename ft::random_access_iterator<T>::difference_type n, const random_access_iterator<T> &r){return(random_access_iterator<T>(r.base() + n));}
    template <typename T>
	random_access_iterator<T> operator-(typename ft::random_access_iterator<T>::difference_type n, const random_access_iterator<T> &r){return(random_access_iterator<T>(r.base() - n));}






    
}

#endif