#ifndef _RANDOM_ACCESS_ITERATOR_HPP
#define _RANDOM_ACCESS_ITERATOR_HPP



template <class T>
class random_access_iterator
{
    public:
        typedef T                                                  value_type;
        typedef long int                                          difference_type;
        typedef size_t                                             size_type;    
    
        typedef T*                                                 pointer;
        typedef T&                                                 reference;

    private:
        pointer     _current;

    public:
        random_access_iterator(pointer current = 0) : _current(current){}
        pointer getCurrent() const { return (this->_current); }
        random_access_iterator(const random_access_iterator<value_type> &other) { _current = other.getCurrent(); }
        virtual ~random_access_iterator(){}

        random_access_iterator &operator=(const random_access_iterator &other)
        { 
            this->_current = other._current;
            return *this;
        }

        reference operator*() { return *this->_current; }
        pointer operator->() { return this->_current; }

        bool operator==(const random_access_iterator &other) const { return (this->_current == other._current); }
        bool operator!=(const random_access_iterator &other) const { return (this->_current != other._current); }
        bool operator<(const random_access_iterator &other) const { return (this->_current < other._current); }
        bool operator<=(const random_access_iterator &other) const { return (this->_current <= other._current); }
        bool operator>(const random_access_iterator &other) const { return (this->_current > other._current); }
        bool operator>=(const random_access_iterator &other) const { return (this->_current >= other._current); }

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
        random_access_iterator operator+(size_type offset) const { return (random_access_iterator(this->_current + offset)); }
        random_access_iterator operator-(size_type offset) const { return (random_access_iterator(this->_current - offset)); }
        difference_type operator-(random_access_iterator const &itself) const { return (this->_current - itself._current); }
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
        random_access_iterator operator[](size_type const offset) const { return (*(*this + offset)); }        
};



template <class T>
class rev_random_access_iterator
{
    public:
        typedef T                                                  value_type;
        typedef long int                                          difference_type;
        typedef size_t                                             size_type;    
    
        typedef T*                                                 pointer;
        typedef T&                                                 reference;

    private:
        pointer     _current;

    public:
        rev_random_access_iterator(pointer current = 0) : _current(current){}
        pointer getCurrent() const { return (this->_current); }
        rev_random_access_iterator(const rev_random_access_iterator<value_type> &other) { _current = other.getCurrent(); }
        virtual ~rev_random_access_iterator(){}

        rev_random_access_iterator &operator=(rev_random_access_iterator const &other)
        { 
            this->_current = other._current;
            return *this;
        }

        reference operator*() { return *this->_current; }
        pointer operator->() { return this->_current; }

        bool operator==(const rev_random_access_iterator &other) const { return (this->_current == other._current); }
        bool operator!=(const rev_random_access_iterator &other) const { return (this->_current != other._current); }
        bool operator<(const rev_random_access_iterator &other) const { return (this->_current < other._current); }
        bool operator<=(const rev_random_access_iterator &other) const { return (this->_current <= other._current); }
        bool operator>(const rev_random_access_iterator &other) const { return (this->_current > other._current); }
        bool operator>=(const rev_random_access_iterator &other) const { return (this->_current >= other._current); }

        rev_random_access_iterator &operator++() //prefix
        {
            this->_current--;
            return (*this);
        }
        rev_random_access_iterator operator++(int) //postfix
        {
            rev_random_access_iterator tmp = *this;
            --(*this);
            return (tmp);
        }
        rev_random_access_iterator &operator--() //prefix
        {
            this->_current++;
            return (*this);
        }
        rev_random_access_iterator operator--(int) //postfix
        {
            rev_random_access_iterator tmp = *this;
            ++(*this);
            return (tmp);
        }
        rev_random_access_iterator operator+(size_type offset) const { return (rev_random_access_iterator(this->_current - offset)); }
        rev_random_access_iterator operator-(size_type offset) const { return (rev_random_access_iterator(this->_current + offset)); }
        difference_type operator-(rev_random_access_iterator const &itself) const { return (this->_current + itself._current); }
        rev_random_access_iterator &operator+=(size_type const offset)
        {
            this->_current -= offset;
            return *this;
        }
        rev_random_access_iterator &operator-=(size_type const offset)
        {
            this->_current += offset;
            return *this;
        }
        rev_random_access_iterator operator[](size_type const offset) const { return (*(*this + offset)); }    
};



#endif

