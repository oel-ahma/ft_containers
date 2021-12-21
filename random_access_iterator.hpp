#ifndef _RANDOM_ACCESS_ITERATOR_HPP
#define _RANDOM_ACCESS_ITERATOR_HPP

#include "reverse_iterator.hpp"

namespace ft
{
    template <class T> 
    class  random_access_iterator : private ft::iterator<random_access_iterator_tag, T>
    {
        public:
            typedef size_t                                                                      size_type;
            typedef T                                                                           value_type;
            typedef T*                                                                          pointer;
            typedef T&                                                                          reference;
            typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type       difference_type;
            typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category     iterator_category;

        protected:
            pointer     _current;

        public:
            pointer base() const{ return(this->_current); }
            random_access_iterator() : _current(0) {}
            random_access_iterator(const random_access_iterator &other) : _current(other.base()) {}
            random_access_iterator(pointer ptr): _current(ptr) {}
            virtual ~random_access_iterator(){}
            random_access_iterator &operator=(const random_access_iterator &other)
            {
                _current = other.base();
                return(*this);
            };
            operator random_access_iterator<const T>() { return random_access_iterator<const T>(_current); }

            reference operator*() { return *this->_current; }
            pointer operator->() { return this->_current; }

            bool operator==(const random_access_iterator &other) const { return (this->_current == other.base()); }
            bool operator!=(const random_access_iterator &other) const { return (this->_current != other.base()); }
            bool operator<(const random_access_iterator &other) const { return (this->_current < other.base()); }
            bool operator<=(const random_access_iterator &other) const { return (this->_current <= other.base()); }
            bool operator>(const random_access_iterator &other) const { return (this->_current > other.base()); }
            bool operator>=(const random_access_iterator &other) const { return (this->_current >= other.base()); }

            random_access_iterator &operator++() //prefix
            {
                this->_current++;
                return (*this);
            }
            random_access_iterator operator++(int) //postfix
            {
                random_access_iterator tmp = *this;
                ++(*this);
                return (tmp);
            }
            random_access_iterator &operator--() //prefix
            {
                this->_current--;
                return (*this);
            }
            random_access_iterator operator--(int) //postfix
            {
                random_access_iterator tmp = *this;
                --(*this);
                return (tmp);
            }
            
            difference_type operator+(random_access_iterator const &itself) const { return (this->_current + itself.base()); }
            random_access_iterator operator+(size_type offset) const { return (random_access_iterator(this->_current + offset)); }
            
            random_access_iterator operator-(size_type offset) const { return (random_access_iterator(this->_current - offset)); }
            difference_type operator-(random_access_iterator const &itself) const { return (this->_current - itself.base()); }
            
            random_access_iterator &operator+=(size_type const offset)
            {
                this->_current += offset;
                return *this;
            }
            
            random_access_iterator &operator-=(size_type const offset)
            {
                this->_current -= offset;
                return *this;
            }
            value_type &operator[](difference_type n) const{return (*(*this + n));}
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


};
#endif

