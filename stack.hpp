#ifndef _stack_HPP_
#define _stack_HPP_


#include "vector.hpp"

namespace ft 
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
        public:
            typedef T               value_type;
            typedef Container       container_type;
            typedef size_t          size_type;

            container_type          _cont;
        
        public:
            /* Default Constructor */
            explicit stack (const container_type& ctnr = container_type()) : _cont(ctnr) {}

            /* Member Functions */
            bool empty() const { return (_cont.empty()); }
            size_type size() const { return (_cont.size()); }
            value_type& top() { return (_cont.back()); }
            const value_type& top() const { return (_cont.back()); }
            void push(const value_type& val) { _cont.push_back(val); }
            void pop() { _cont.pop_back(); }
    };

    /* Relational Operators */
    template <class T, class Container>
    bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs._cont == rhs._cont); }

    template <class T, class Container>
    bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs._cont != rhs._cont); }

    template <class T, class Container>
    bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs._cont < rhs._cont); }

    template <class T, class Container>
    bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs._cont <= rhs._cont); }

    template <class T, class Container>
    bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs._cont > rhs._cont); }

    template <class T, class Container>
    bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs._cont >= rhs._cont); }
}


#endif