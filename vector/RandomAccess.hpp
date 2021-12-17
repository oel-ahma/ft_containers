#ifndef RANDOMACCESS_HPP
#define RANDOMACCESS_HPP

/* Use a boolean to typedef either type 1 or type 2. */
template <bool isConst, typename isFalse, typename isTrue>
struct chooseConst {};

/* Typedef: pointer, ref... */
template <typename isFalse, typename isTrue>
struct chooseConst<false, isFalse, isTrue>
{
    typedef isFalse type;
};

/* Typedef: const pointer, const ref... */
template <typename isFalse, typename isTrue>
struct chooseConst<true, isFalse, isTrue>
{
    typedef isTrue type;
};


// @param T     Type of container's elements.
// @param B     Boolean to indicate if it's an iterator / a const iterator.

template <typename T, bool B>
class  RandomAccess
{
public:
/* Aliases definition */
    typedef long int                                        difference_type;            // distance or range lenght between iterator in a container and another one
    typedef size_t                                          size_type;
    typedef T                                               value_type;                 // ex : int, float, double ..etc
    typedef typename chooseConst<B, T*, const T*>::type     pointer;
    typedef typename chooseConst<B, T&, const T&>::type     reference;

private:
/* Attributs */
    pointer                                                 _current;

public:
/* Constructors */
    RandomAccess(pointer current = 0) : _current(current) {}

/* Destructor */
    ~RandomAccess() {}

/* Copy constructor */
    pointer getCurrent() const { return (this->_current); }
    RandomAccess(const RandomAccess<value_type, false>& copyObj) { _current = copyObj.getCurrent(); }

/* Overloading operators assignation */
    RandomAccess& operator = (const RandomAccess& assignObj)
    {
        if (this != &assignObj)
            this->_current = assignObj._current;
        return (*this);
    }

/* Overloading operators dereferencement */
    reference operator * () { return *this->_current; }
    pointer operator -> () { return this->_current; }

/* Overloading operators comparaison */
    bool operator == (const RandomAccess<value_type, true>& other) const { return (this->_current == other.getCurrent()); }
    bool operator != (const RandomAccess<value_type, true>& other) const { return (this->_current != other.getCurrent()); }
    bool operator < (const RandomAccess<value_type, true>& other) const { return (this->_current < other.getCurrent()); }
    bool operator > (const RandomAccess<value_type, true>& other) const { return (this->_current > other.getCurrent()); }
    bool operator >= (const RandomAccess<value_type, true>& other) const { return (this->_current >= other.getCurrent()); }
    bool operator <= (const RandomAccess<value_type, true>& other) const { return (this->_current <= other.getCurrent()); }

/* Overloading operators decrementation */
    RandomAccess& operator -- ()
    { 
        this->_current--;
        return (*this);
    }   // postfix
    RandomAccess operator -- (int)
    {
        RandomAccess oldCopy = *this;
        --(*this);
        return (oldCopy);
    }   // prefix
    
/* Overloading operators incrementation */
    RandomAccess& operator++ ()
    {
        this->_current++; 
        return (*this);
    }   // postfix
    RandomAccess operator++ (int)
    {
        RandomAccess oldCopy = *this;
        ++(*this);
        return (oldCopy);
    }   // prefix

/* Overloading operators additioning and subtracting */
    RandomAccess operator+ (size_type offset) const
    {
        return (RandomAccess(this->_current + offset));
    }
    RandomAccess operator- (size_type offset) const
    {
        return (RandomAccess(this->_current - offset));
    }
    difference_type operator- (const RandomAccess& it) const
    {
        return (this->_current - it._current);
    }
    RandomAccess& operator += (size_type const offset)
    {
        this->_current += offset;
        return (*this);
    }
    RandomAccess& operator -= (size_type const offset)
    {
        this->_current -= offset;
        return (*this);
    }
    
    /* Overloading operator dereferencing */
    reference operator [] (size_type const offset) const
    {
        return (*(*this + offset));
    }
}; // class RandomAccess

// https://cplusplus.com/reference/iterator/RandomAccessIterator/


template <typename T, bool B>
class  RevRandomAccess
{
public:
/* Aliases definition */
    typedef long int                                        difference_type;            // distance or range lenght between iterator in a container and another one
    typedef size_t                                          size_type;
    typedef T                                               value_type;                 // ex : int, float, double ..etc
    typedef typename chooseConst<B, T*, const T*>::type     pointer;
    typedef typename chooseConst<B, T&, const T&>::type     reference;

private:

/* Attributs */
    pointer                                                 _current;

public:

/* Constructors */
    RevRandomAccess(pointer current = 0) : _current(current) {}

/* Destructor */
    ~RevRandomAccess() {}

/* Copy constructor */
    pointer getCurrent() const { return (this->_current); }
    RevRandomAccess(const RevRandomAccess<value_type, false>& copyObj) { _current = copyObj.getCurrent(); }

/* Overloading operators assignation */
    RevRandomAccess& operator = (const RevRandomAccess<value_type, false>& assignObj)
    {
        this->_current = assignObj._current;
        return (*this);
    }

/* Overloading operators dereferencement */
    reference operator * () { return *this->_current; }
    pointer operator -> () { return this->_current; }

/* Overloading operators comparaison */
    bool operator== (const RevRandomAccess<value_type, true>& other) const { return (this->_current == other.getCurrent()); }
    bool operator!= (const RevRandomAccess<value_type, true>& other) const { return (this->_current != other.getCurrent()); }
    bool operator< (const RevRandomAccess<value_type, true>& other) const { return (this->_current < other.getCurrent()); }
    bool operator> (const RevRandomAccess<value_type, true>& other) const { return (this->_current > other.getCurrent()); }
    bool operator>= (const RevRandomAccess<value_type, true>& other) const { return (this->_current >= other.getCurrent()); }
    bool operator<= (const RevRandomAccess<value_type, true>& other) const { return (this->_current <= other.getCurrent()); }

/* Overloading operators decrementation */
    RevRandomAccess& operator -- ()
    { 
        this->_current++;
        return (*this);
    }   // postfix
    RevRandomAccess operator -- (int)
    {
        RevRandomAccess oldCopy = *this;
        ++(*this);
        return (oldCopy);
    }   // prefix
    
/* Overloading operators incrementation */
    RevRandomAccess& operator ++ ()
    {
        this->_current--; 
        return (*this);
    }   // postfix
    RevRandomAccess operator ++ (int)
    {
        RevRandomAccess oldCopy = *this;
        --(*this);
        return (oldCopy);
    }   // prefix

/* Overloading operators additioning and subtracting */
    RevRandomAccess operator + (size_type offset) const
    {
        return(RevRandomAccess(this->_current - offset));
    }
    RevRandomAccess operator - (size_type offset) const
    {
        return(RevRandomAccess(this->_current + offset));
    }
    difference_type operator - (const RevRandomAccess& it) const
    {
        return (this->_current += it._current);
    }
    RevRandomAccess& operator += (size_type const offset)
    {
        this->_current -= offset;
        return (*this);
    }
    RevRandomAccess& operator -= (size_type const offset)
    {
        this->_current += offset;
        return (*this);
    }
    
    /* Overloading operator dereferencing */
    reference operator [] (size_type const offset) const
    {
        return (*(*this + offset));
    }
}; // class RevRandomAccess

// https://www.cplusplus.com/reference/iterator/reverse_iterator/

#endif
