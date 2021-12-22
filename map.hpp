#ifndef _MAP_HPP
#define _MAP_HPP

#include "utils.hpp"
#include "reverse_iterator.hpp"
#include "bidirectional_iterator.hpp"


namespace ft
{
    template< class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > > 
    class map
    {
        /* Member types */
        public :
            typedef Key                                                         key_type;
            typedef T                                                           mapped_type;
            typedef ft::pair<const Key, T>                                      value_type;
            typedef size_t                                                      size_type;
            typedef ptrdiff_t                                                   difference_type;
            typedef Compare                                                     key_compare;
            typedef Allocator                                                   allocator_type;
            typedef value_type&                                                 reference;
            typedef const value_type&                                           const_reference;
            typedef typename Allocator::pointer                                 pointer;
            typedef typename Allocator::const_pointer                           const_pointer;

            typedef ft::random_access_iterator<value_type>                      iterator;
            typedef ft::random_access_iterator<const value_type>                const_iterator;
            typedef	ft::reverse_iterator<iterator>                              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                        const_reverse_iterator;

            class value_compare : std::binary_function<value_type, value_type, bool>
            {
                friend class map;
                protected:
                    Compare _comp;
                    value_compare(Compare c) : _comp(c) {}

                public:
                    bool operator()(const value_type& lhs, const value_type& rhs) const
                    {
                        return comp(lhs.first, rhs.first);
                    }
            };

        private:
            size_type       _size;
            key_compare     _comp;
            allocator_type  _alloc;

    };
};


#endif