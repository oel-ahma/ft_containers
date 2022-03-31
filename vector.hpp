#ifndef _MY_vector_HPP
#define _MY_vector_HPP


//#include <vector>
#include <iostream>
#include <limits>

#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "utils.hpp"


namespace ft
{

    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
            /* Member Types */
            typedef T                                                           value_type;
            typedef Alloc                                                       allocator_type;
            
            typedef typename allocator_type::reference                          reference;
            typedef typename allocator_type::const_reference                    const_reference;

            typedef typename allocator_type::pointer                            pointer;
            typedef typename allocator_type::const_pointer                      const_pointer;
            
            typedef typename std::ptrdiff_t                                     difference_type;
            typedef size_t                                                      size_type;

            //Iterator
            typedef ft::random_access_iterator<value_type>                      iterator;
			typedef ft::random_access_iterator<const value_type>                const_iterator;
			typedef	ft::reverse_iterator<iterator>                              reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>                        const_reverse_iterator;

  

        private:
            pointer                                                             _data;
            size_type                                                           _size;
            size_type                                                           _capacity;
            allocator_type                                                      _alloc; 

        public:
            /* Constructors */
            explicit vector(const allocator_type& alloc = allocator_type()); // default constructor
            explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
            
            template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = 0): _data(NULL), _size(0), _capacity(0), _alloc(alloc)
			{
				_data = _alloc.allocate(0);
				assign(first, last);
                if (this->_capacity > this->_size + 1)
                    this->_capacity = this->_size;
			};
            
            vector(const vector& x); //copy constructor

            /* Destructor */
            virtual ~vector();

            /* Operator= Overload */
            vector& operator=(const vector& x);
        
            /* iterators */
            iterator begin() { return iterator(this->_data); }
            const_iterator begin() const { return const_iterator(this->_data); }
            iterator end() { return iterator(&this->_data[this->_size]); }
            const_iterator end() const { return const_iterator(&this->_data[this->_size]); }

            reverse_iterator rbegin() { return reverse_iterator(&this->_data[this->_size]); }
            const_reverse_iterator rbegin() const { return const_reverse_iterator(&this->_data[this->_size]); }
            reverse_iterator rend() { return reverse_iterator(this->_data); }
            const_reverse_iterator rend() const { return const_reverse_iterator(this->_data); }

            /* Capacity */
            size_type size() const { return this->_size; }
            size_type max_size() const { return allocator_type().max_size(); }
            void resize(size_type n, value_type val = value_type());
            size_type capacity() const { return this->_capacity; }
            bool empty() const { return (this->_size == 0); }
            void reserve(size_type n);

            /* Element access */
            reference operator[] (size_type n) { return this->_data[n]; }
            const_reference operator[] (size_type n) const { return this->_data[n]; }
            reference at(size_type n)
            {
                if (n >= this->_size)
                    throw (std::out_of_range("out of range"));
                return this->_data[n];
            }
            const_reference at(size_type n) const
            {
                if (n >= this->_size)
                    throw (std::out_of_range("out of range"));
                return this->_data[n];
            }
            reference front() { return this->_data[0]; }
            const_reference front() const { return this->_data[0]; }
            reference back() { return this->_data[this->_size - 1]; }
            const_reference back() const { return this->_data[this->_size - 1]; }

            /* Modifiers */
            template <class InputIterator>
            void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = 0)
            {
                this->clear();
                for (InputIterator it = first; it != last; ++it)
                    this->push_back(*it);
                if (this->_capacity < this->_size + 1)
                    this->_capacity = this->_size;
            }
            void assign(size_type n, const value_type& val);
            void push_back(const value_type& val);
            void pop_back();
            iterator insert(iterator position, const value_type& val);
            void insert(iterator position, size_type n, const value_type& val);
            template <class InputIterator>
            void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = 0)
            {
                vector<T, Alloc> tmp(position, this->end());

                this->_size -= (this->end() - position);
                for (InputIterator it = first; it != last; ++it)
                    this->push_back(*it);

                for (iterator it = tmp.begin(); it != tmp.end(); ++it)
                    this->push_back(*it);
                if (this->_capacity > this->_size + 1)
                    this->_capacity = this->_size;
            }
            iterator erase(iterator position);
            iterator erase(iterator first, iterator last);
            void swap(vector& x);
            void clear();

            private:
                /* Reallocate vector */
                void _reallocVec(size_type newCapacity)
                {
                    pointer tmp = this->_alloc.allocate(newCapacity);
                    for (size_type i = 0; i < this->_size; ++i)
                        this->_alloc.construct(&tmp[i], this->_data[i]);

                    this->~vector();
                    this->_capacity = newCapacity;
                    this->_data = tmp;
                } 
    };

     /* Constructors */
    template <class T, class Alloc>
    vector<T, Alloc>::vector(const allocator_type& alloc)
        : _data(NULL), _size(0), _capacity(0), _alloc(alloc) {}
    
    template <class T, class Alloc>
    vector<T, Alloc>::vector(size_type n, const value_type& val, const allocator_type& alloc)
        : _size(n), _capacity(n), _alloc(alloc) 
    {
        this->_data = this->_alloc.allocate(this->_capacity, 0);
        for(size_type i = 0; i < this->_size; ++i)
            this->_alloc.construct(&this->_data[i], val);
    } 

    template <class T, class Alloc>
    vector<T, Alloc>::vector(const vector& x)
        : _size(x._size), _capacity(x._capacity), _alloc(x._alloc)
    {
        this->_data = this->_alloc.allocate(this->_capacity);

        size_type i = 0;
        for(const_iterator it = x.begin(); it != x.end(); ++it)
            this->_alloc.construct(&this->_data[i++], *it);
    }

    /* Destructor */
    template <class T, class Alloc>
    vector<T, Alloc>::~vector()
    {
        for (iterator it = begin(); it != end(); ++it)
            this->_alloc.destroy(&(*it));
        this->_alloc.deallocate(this->_data, this->_capacity);
    }

    /* Operator= Overload */
    template <class T, class Alloc>
    vector<T, Alloc> &vector<T, Alloc>::operator=(const vector& other)
    {
        if (this->_data)
            this->_alloc.deallocate(this->_data, this->_capacity);
        this->_data = this->_alloc.allocate(other._capacity);
        this->_capacity = other._capacity;
        this->_size = 0;
        this->assign(other.begin(), other.end());
        return *this;
    }

    /* Capacity */
    template <class T, class Alloc>
    void vector<T, Alloc>::resize(size_type n, value_type val)
    {
        while (n < this->_size)
            this->pop_back();
        if (n > this->_capacity)
            this->reserve(n);
        while (n > this->_size)
            this->push_back(val);
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::reserve(size_type n)
    {
        if (n > max_size())
            throw std::length_error("vector::reserve");
        if (n > this->_capacity)
            _reallocVec(n);
    }

    /* Modifiers */

    template <class T, class Alloc>
    void vector<T, Alloc>::push_back(const value_type& val)
    {
        if (this->_size + 1 > this->_capacity)
            _reallocVec((this->capacity() == 0) ? 1 : this->_capacity * 2);
        this->_alloc.construct(&this->_data[this->_size++], val);
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::pop_back()
    {
        if (this->_size)
            this->_alloc.destroy(&this->_data[this->_size-- - 1]);
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::clear()
    {
        while (this->_size)
            this->pop_back();
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::assign(size_type n, const value_type& val)
    {
        this->clear();
        for (size_t i = 0; i < n; i++)
            this->push_back(val);
        if (this->_capacity > this->_size + 1)
            this->_capacity = this->_size;
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::insert(iterator position, size_type n, const value_type& val)
    {
        vector<T, Alloc> tmp(position, this->end());

        this->_size -= this->end() - position;
        for (size_type i = 0; i < n; i++)
            this->push_back(val);
        for (iterator it = tmp.begin(); it != tmp.end(); ++it)
            this->push_back(*it);
        if (this->_capacity > this->_size + 1)
            this->_capacity = this->_size;
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator position, const value_type& val)
    {
        size_type n = position - this->begin();
        if (position == this->end())
            n = this->_size;
        this->insert(position, 1, val);
        if (this->_capacity > this->_size + 1)
            this->_capacity = this->_size;
        return (iterator(&this->_data[n]));
    }

    template < class T, class Alloc >
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator position)
    {
        iterator ret(position);
        iterator ite = this->end() - 1;

        for (; position != ite; ++position)
            *position = *(position + 1);
        this->_size--;
        
        return (ret);
    }
    
    template < class T, class Alloc >
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first, iterator last)
    {
        iterator ret(first);
        iterator ite = this->end();

        for (; last != ite ; ++last, ++first)
            *first = *last;

        this->_size -= last - first;
        return (ret);
    }

    template < class T, class Alloc >
    void vector<T, Alloc>::swap (vector& x)
    {
        pointer tmp;
        tmp = this->_data;
        this->_data = x._data;
        x._data = tmp;

        size_type tmpA;
        tmpA = this->_size;
        this->_size = x._size;
        x._size = tmpA;

        size_type    tmpB;
        tmpB = this->_capacity;
        this->_capacity = x._capacity;
        x._capacity = tmpB;

        allocator_type   tmpD;
        tmpD = this->_alloc;
        this->_alloc = x._alloc;
        x._alloc = tmpD; 
    }

    /* non-member operator overload */
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        
        typename ft::vector<T, Alloc>::const_iterator itl = lhs.begin();
        typename ft::vector<T, Alloc>::const_iterator itle = lhs.end();
        typename ft::vector<T, Alloc>::const_iterator itr = rhs.begin();
        typename ft::vector<T, Alloc>::const_iterator itre = rhs.end();

        for (; (itl != itle) && (itr != itre); ++itl, ++itr)
            if ((*itl) != (*itr))
                return false;
        return true; 
    }

    template <class T, class Alloc>
    bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {        
        typename ft::vector<T, Alloc>::const_iterator itl = lhs.begin();
        typename ft::vector<T, Alloc>::const_iterator itle = lhs.end();
        typename ft::vector<T, Alloc>::const_iterator itr = rhs.begin();
        typename ft::vector<T, Alloc>::const_iterator itre = rhs.end();

        for (; (itl != itle) && (itr != itre); ++itl, ++itr)
        {
            if ((*itl) > (*itr))
                return false;
            if ((*itl) < (*itr))
                return true;
        }
        return (lhs.size() < rhs.size());
    }


    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs == rhs)); }

    template<class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(rhs < lhs)); }

    template <class T, class Alloc>
    bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (rhs < lhs); }

    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs < rhs)); }
};

#endif