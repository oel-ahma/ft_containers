#include <vector>
#include <iostream>

namespace ft
{
    template <class T, class Alloc = std::allocator<T>>
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
            
            typedef typename ft::iterator_traits<iterator>::difference_type     difference_type;
            typedef typename allocator_type::size_type                          size_type;

            //Iterator
            typedef ft::random_access_iterator<value_type>                      iterator;            
            typedef ft::random_access_iterator<value_type>                      const_iterator;            

            typedef ft::rev_random_access_iterator<value_type>                  reverse_iterator;            
            typedef ft::rev_random_access_iterator<value_type>                  const_reverse_iterator;            

        private:
            pointer                                                             _data;
            size_type                                                           _size;
            size_type                                                           _capacity;
            allocator_type                                                      _alloc; 

        public:
            /* Constructors */
            explicit vector(const allocator_type& alloc = allocator_type()); // default constructor
            explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()); // fill constructor (Constructs a container with n elements. Each element is a copy of val.)
            vector(iterator first, iterator last, const allocator_type& alloc = allocator_type());
            vector(const_iterator first, const_iterator last, const allocator_type& alloc = allocator_type());           
            vector(const vector& x); //copy constructor

            /* Destructors */
            ~vector();

            /* Operator= Overload */
            vector& operator=(const vector& x);
        
            /* iterators */
            iterator begin() { return iterator(this->_data); }
            const_iterator begin() const { return const_iterator(this->_data); }
            iterator end() { return iterator(this->_data + this->_size); }
            const_iterator end() const  { return const_iterator(this->_data + this->_size); }

            iterator rbegin() { return reverse_iterator(this->_data + (this->_size - 1)); }
            const_iterator rbegin() const { return const_reverse_iterator(this->_data + (this->_size - 1)); }
            iterator rend() { return reverse_iterator(this->_data - 1); }
            const_iterator rend() const { return const_reverse_iterator(this->_data - 1); }

            /* Capacity */
            size_type size() const { return this->_size; }
            size_type max_size() const { return std::numeric_limits<size_type>::max() / sizeof(size_type); }
            void resize(size_type n, value_type val = value_type()); // NOT YET!!
            size_type capacity() const { return this->_capacity; }
            bool empty() const { return (this->_size == 0); }
            void reserve(size_type n) {} // NOT YET!!

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
            reference front() { return this->_data; }
            const_reference front() const { return this->_data; }
            reference back() { return this->_data[this->_size - 1]; }
            const_reference back() const { return this->_data[this->_size - 1]; }

            /* Modifiers */
            void assign(iterator first, iterator last);
            void assign(const_iterator first, const_iterator last);
            void assign(size_type n, const value_type& val);
            void push_back(const value_type& val);
            void pop_back();
            iterator insert(iterator position, const value_type& val);
            void insert(iterator position, size_type n, const value_type& val);
            void insert(iterator position, iterator first, iterator last);
            void insert(iterator position, const_iterator first, const_iterator last);
            iterator erase(iterator position);
            iterator erase(iterator first, iterator last);
            void swap(vector& x);
            void clear();
    };

    template <class T, class Alloc>
    vector<T, Alloc>::vector(const allocator_type& alloc = allocator_type())
        : _data(NULL), _size(0), _capacity(0), _alloc(alloc) {}
    
    template <class T, class Alloc>
    vector<T, Alloc>::vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
        : _size(n), _capacity(n), _alloc(alloc) 
    {
        this->_data = this->_alloc.allocate(this->_capacity, 0);
        for(size_type i = 0; i < this->_size; ++i)
            this->_alloc.construct(&this->_data[i], val);
    }

    template <class T, class Alloc>
    vector<T, Alloc>::vector(iterator first, iterator last, const allocator_type& alloc = allocator_type())
        : _size(last - first), _capacity(last - first), _alloc(alloc)
    {
        this->_data = this->_alloc.allocate(this->_size, 0);
        
        size_type i = 0;
        for(iterator it = first; it != last; ++it)
            this->_alloc.construct(&this->_data[i++], *it);
    }

    template <class T, class Alloc>
    vector<T, Alloc>::vector(const_iterator first, const_iterator last, const allocator_type& alloc = allocator_type())
        : _size(last - first), _capacity(last - first), _alloc(alloc)
    {
        this->_data = this->_alloc.allocate(this->_size, 0);
        
        size_type i = 0;
        for(iterator it = first; it != last; ++it)
            this->_alloc.construct(&this->_data[i++], *it);
    }   


    template <class T, class Alloc>
    vector<T, Alloc>::vector(const vector& x)
        : _size(x._size), _capacity(x._capacity), _alloc(x._alloc)
    {
        this->_data = this->_alloc.allocate(this->_capacity);

        size_type i = 0;
        for(const_iterator it = x.begin(); it != x.end(); ++it)
            this->_alloc.construct(&this->_data[i++], *it);
        return *this;
    }

    template <class T, class Alloc>
    vector<T, Alloc>::~vector()
    {
        for (iterator it = begin(); it != end(); ++it)
            this->_alloc.destroy(&(*it));
        this->_alloc.deallocate(&this->_data, this->_capacity);
    }

    template <class T, class Alloc>
    vector<T, Alloc>::vector& operator=(const vector& x)
    {

    }
}