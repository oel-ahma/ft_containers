#ifndef _BIDIRECTIONAL_ITERATOR_HPP
#define _BIDIRECTIONAL_ITERATOR_HPP

//#include "utils.hpp"
#include "/mnt/nfs/homes/oel-ahma/Documents/ft_containers/corrections/cont-al/utils.hpp"

namespace ft
{
    struct bidirectional_iterator_tag {};

    template <typename T, bool isConst>
    class bidirectional_iterator : private ft::iterator<bidirectional_iterator_tag, T> 
    {
        public:
            typedef typename ft::enable_if_const<isConst, T>::value_type                                    value_type;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category    iterator_category;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer              pointer;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference            reference;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type      difference_type;

            T* _M_node;
        
            bidirectional_iterator() {};
            bidirectional_iterator(T* ptr) : _M_node(ptr) {};
            bidirectional_iterator(bidirectional_iterator const &copy) : _M_node(copy._M_node) {}
            ~bidirectional_iterator() {};

            bidirectional_iterator operator=(bidirectional_iterator const &copy) 
            {
                if (this == &copy)
                    return (*this);
                _M_node = copy._M_node;
                return (*this);
            }

            bool operator==(bidirectional_iterator const &lhs) { return (_M_node == lhs._M_node); }
            bool operator!=(bidirectional_iterator const &lhs) 
            { return (_M_node != lhs._M_node); }
        
            reference operator*() const { return (_M_node->data); }

            pointer operator->() const { return (&(operator*())); }

            bidirectional_iterator &operator++()
            {
                if (_M_node->right)
                {
                    _M_node = _M_node->right;
                    while (_M_node->left)
                        _M_node = _M_node->left;
                }
                else
                {
                    while (_M_node->parent && _M_node->parent->right == _M_node)
                        _M_node = _M_node->parent;
                    if (_M_node->parent)
                        _M_node = _M_node->parent;
                }
                return (*this);
            }

            bidirectional_iterator operator++(int)
            {
                bidirectional_iterator tmp(*this);
                operator++();
                return (tmp);
            }

            bidirectional_iterator &operator--()
            {
                if (_M_node->left)
                {
                    _M_node = _M_node->left;
                    while (_M_node->right)
                        _M_node = _M_node->right;
                }
                else
                {
                    while (_M_node->parent && _M_node->parent->left == _M_node)
                        _M_node = _M_node->parent;
                    if (_M_node->parent)
                        _M_node = _M_node->parent;
                }
                return (*this);
            }

            bidirectional_iterator operator--(int)
            {
                bidirectional_iterator tmp(*this);
                operator--();
                return (tmp);
            } 

            operator bidirectional_iterator<const T, true>() 
            { 
                return (bidirectional_iterator<const T, true>(_M_node)); 
            }

    };
}


#endif