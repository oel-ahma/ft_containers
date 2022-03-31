#ifndef _map_HPP
#define _map_HPP

#include "utils.hpp"
#include "reverse_iterator.hpp"
#include "bidirectional_iterator.hpp"

namespace ft
{
    template<class T, class Alloc>
    struct node
    {
        typedef T value_type;

        value_type data;
        node *left;
        node *right;
        node *parent;

        node(value_type const &data, node* left = NULL, node* right = NULL, node* parent = NULL) 
            : data(data), left(left), right(right), parent(parent) {}
        node(node const &other) : data(other.data), left(other.left), right(other.right), parent(other.parent) {}
        ~node() {}
        node &operator=(const node &other)
        {
            if (this == &other)
                return *this;
            data = other.data;
            left = other.left;
            right = other.right;
            parent = other.parent;
            return *this;
        }
    };

    template< class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > > 
    class map
    {
        /* Member types */
        public :
            typedef Key                                                         key_type;
            typedef T                                                           mapped_type;
            typedef ft::pair<const Key, T>                                      value_type;
            typedef size_t                                                      size_type;
            typedef std::ptrdiff_t                                                   difference_type;
            typedef Compare                                                     key_compare;
            typedef Allocator                                                   allocator_type;
            typedef value_type&                                                 reference;
            typedef const value_type&                                           const_reference;
            typedef typename Allocator::pointer                                 pointer;
            typedef typename Allocator::const_pointer                           const_pointer;

            typedef ft::bidirectional_iterator<ft::node<value_type, allocator_type>, false>         iterator;
            typedef ft::bidirectional_iterator<const ft::node<value_type, allocator_type>, true>    const_iterator;

            typedef	ft::reverse_iterator<iterator>                                                  reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                                            const_reverse_iterator;

            class value_compare : std::binary_function<value_type, value_type, bool>
            {
                friend class map;
                protected:
                    Compare _comp;
                    value_compare(Compare c) : _comp(c) {}

                public:
                    bool operator()(const value_type& lhs, const value_type& rhs) const
                    {
                        return _comp(lhs.first, rhs.first);
                    }
            };

        private:
            
            typedef ft::node<value_type, allocator_type>    node;
            typedef typename allocator_type::template rebind<node>::other allocator_node;
            
            size_type       _size;
            key_compare     _comp;
            allocator_type  _alloc;
            allocator_node  _allocNode;
            
            node*           _root;
            node*           _begin;
            node*           _end;

            void deallocate_node(node *n) 
            {
                _allocNode.destroy(n);
                _allocNode.deallocate(n, 1);
                _size--;
            }

            iterator    search_key(const key_type &k) const
            {
                node* find = _root;

                while (find) {
                    if (!_comp(find->data.first, k) && !_comp(k, find->data.first))
                        break;
                    if (_comp(find->data.first, k))
                        find = find->right;
                    else
                        find = find->left;
                }
                if (!find)
                    return (_end);
                return (find);
            }

            iterator    insert_node(node *pos, const value_type &val)
            {
                if (_root == _end)  
                {
                    node* tmp = _allocNode.allocate(1);
                    _allocNode.construct(tmp, node(val));
                    _root = tmp;
                    tmp->right = _end;
                    _end->parent = tmp;
                    _begin = _root;
                    _size++;
                    return (tmp);
                }
                while (1)
                {
                    if (!_comp(val.first, pos->data.first) && !_comp(pos->data.first, val.first))
                        break;
                    if (_comp(val.first, pos->data.first)) 
                    {
                        if (pos->left)
                            pos = pos->left;
                        else 
                        {
                            node* tmp = _allocNode.allocate(1);
                            _allocNode.construct(tmp, node(val));
                            if (pos == _begin)
                                _begin = tmp;
                            pos->left = tmp;
                            tmp->parent = pos;
                            _size++;
                            return (tmp);
                        }
                    } 
                    else 
                    {
                        if (pos->right && pos->right != _end)
                            pos = pos->right;
                        else
                        {
                            node *tmp = _allocNode.allocate(1);
                            _allocNode.construct(tmp, node(val));
                            if (pos->right == _end) 
                            {
                                tmp->right = _end;
                                _end->parent = tmp;
                            }
                            pos->right = tmp;
                            tmp->parent = pos;
                            _size++;
                            return (tmp);
                        }
                    }
                }
                return (pos);
            }

        public:
            /* Constructor (finshed)*/ /*check why the size is not copied and initiated to 0 */
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
                : _size(0), _comp(comp), _alloc(alloc), _allocNode()
            {
                _end = _allocNode.allocate(1);
                _allocNode.construct(_end, node(value_type()));
                _root = _end;
                _begin = _root;
            }

            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
                : _size(0), _comp(comp), _alloc(alloc), _allocNode()
            {
                _end = _allocNode.allocate(1);
                _allocNode.construct(_end, node(value_type()));
                _root = _end;
                _begin = _root;
                this->insert(first, last);                
            }
            map (const map& x)
                : _size(0), _comp(x._comp), _alloc(x._alloc), _allocNode(x._allocNode)
            {
                _end = _allocNode.allocate(1);
                _allocNode.construct(_end, node(value_type()));
                _root = _end;
                _begin = _root;
                this->insert(x.begin(), x.end());
            }
            /* Destructor (finshed)*/
            ~map()
            {
                erase(this->begin(), this->end());
                _allocNode.destroy(_end);
                _allocNode.deallocate(_end, 1);
            }

            /* operator= (finshed) */
            map& operator= (const map& x)
            {
                if (this == &x)
                    return *this;
                this->clear();
                _comp = x._comp;
                _alloc = x._alloc;
                _allocNode = x._allocNode;
                this->insert(x.begin(), x.end());
                return *this;
            }

            /* Iterator (finshed) */ 
            iterator begin() { return _begin; }
            const_iterator begin() const { return _begin; }
            iterator end() { return _end; }
            const_iterator end() const { return _end; }
            reverse_iterator rbegin() { return reverse_iterator(this->end()); }
            const_reverse_iterator rbegin() const { return reverse_iterator(this->end()); }
            reverse_iterator rend() { return reverse_iterator(this->begin()); }
            const_reverse_iterator rend() const { return reverse_iterator(this->begin()); }

            /* Capacity (finshed) */
            bool empty() const { return (_size == 0); }
            size_type size() const { return _size; }
            size_type max_size() const { return _allocNode.max_size(); }

            /* Element Access (finshed) */
            mapped_type& operator[] (const key_type& k)
            {
                iterator index = search_key(k);
                if (index._M_node == _end)
                    return (insert(_root, ft::make_pair(k, mapped_type()))->second);
                return index->second;
            }

            /* Modifiers (finshed) */
            pair<iterator,bool> insert(const value_type& val)
            {
                iterator position;
                if ((position = search_key(val.first)) == _end)
                    return (ft::make_pair(insert(position, val), true));
                return (ft::make_pair(position, false));
            }

            iterator insert(iterator position, const value_type& val)
            {
                if (_root == _end)
                    return (insert_node(_root, val));
                if (_comp(position->first, val.first))
                {
                    while(_comp(position->first, val.first) && position != _end)
                        ++position;
                    if (!_comp(position->first, val.first) && !_comp(val.first, position->first))
                        return position;
                    --position;
                    if (position._M_node->parent)
                        return (insert_node(position._M_node->parent, val));
                    return (insert_node(position._M_node, val));
                }
                else
                {
                    while(_comp(val.first, position->first) && position != _begin)
                        --position;
                    if (!_comp(position->first, val.first) && !_comp(val.first, position->first))
                        return position;
                    ++position;
                    if (position._M_node->parent)
                        return (insert_node(position._M_node->parent, val));
                    return (insert_node(position._M_node, val));
                }
                return position;
            }

            template <class InputIterator>
            void insert(InputIterator first, InputIterator last)
            {
                iterator position = this->begin(); // _begin
                for (; first != last; first++)
                    position = insert(position, *first);
            }

            void erase(iterator position)
            {
                erase(position->first);
            }

            size_type erase(const key_type &k)
            {
                node *clear = search_key(k)._M_node;

                if (clear == _end || clear == NULL)
                    return (0);
                if (!clear->left && !clear->right)
                {
                    if (clear->parent->right == clear)
                        clear->parent->right = NULL;
                    else
                        clear->parent->left = NULL;
                        
                    if (clear == _begin)
                    {
                        if (clear->parent)
                            _begin = clear->parent;
                    }
                    deallocate_node(clear);
                }
                else if (!clear->left || !clear->right)
                {
                    bool left_exist = clear->left != NULL;
                    if (_root == clear)
                    {
                        clear->right->parent = NULL;
                        _root = clear->right;
                        if (clear == _begin) 
                        {
                            if (clear->left || clear->right) 
                            {
                                if (clear->left)
                                    _begin = clear->left;
                                else
                                    _begin = clear->right;
                                while (_begin->left)
                                    _begin = _begin->left;
                            } 
                            else 
                                _begin = clear->parent;
                        }
                    }
                    else
                    {
                        if (clear->parent->left == clear && left_exist)
                        {
                            clear->parent->left = clear->left;
                            clear->left->parent = clear->parent;
                        }
                        else if (clear->parent->left == clear && !left_exist)
                        {
                            clear->parent->left = clear->right;
                            clear->right->parent = clear->parent;
                        }
                        else if (clear->parent->right == clear && left_exist)
                        {
                            clear->parent->right = clear->left;
                            clear->left->parent = clear->parent;
                        }
                        else if (clear->parent->right == clear && !left_exist)
                        {
                            clear->parent->right = clear->right;
                            clear->right->parent = clear->parent;
                        }
                    }
                    if (clear == _begin) 
                    {
                        if (clear->right) 
                        {
                            _begin = clear->right; 
                            while (_begin->left)
                                _begin = _begin->left;
                        } 
                        else if (_begin != _root)
                            _begin = clear->parent;
                    }
                    deallocate_node(clear);
                }
                else if (clear->left && clear->right)
                {
                    node *car = NULL;
                    car = clear->right; 
                    while (car->left)
                        car = car->left;
                    
                    if (car->right) 
                    {
                        if (car->parent && car->parent->right == car) 
                        { 
                            car->parent->right = car->right;
                            car->right->parent = car->parent;
                        } 
                        else if (car->parent) 
                        {
                            car->parent->left = car->right;
                            car->right->parent = car->parent;
                        }
                    } 
                    else 
                    {
                        if (car->parent && car->parent->right == car) 
                            car->parent->right = NULL;
                        else if (car->parent)
                            car->parent->left = NULL;
                    }
                    car->parent = clear->parent;
                    if (car->parent && car->parent->right == clear) 
                        car->parent->right = car;
                    else if (car->parent)
                        car->parent->left = car;

                    car->left = clear->left;
                    car->right = clear->right;
                    if (clear->left)
                        clear->left->parent = car;
                    if (clear->right)
                        clear->right->parent = car;

                    if (clear == _root)
                        _root = car;
                    deallocate_node(clear);
                }
                return (1);
            }

            void erase(iterator first, iterator last)
            {
                while (first != last)
                    erase(first++); 
            }

            void swap(map& x)
            {
                if (this == &x)
				    return;
                node*           _root_tmp = _root;
                node*           _begin_tmp = _begin;
                node*           _end_tmp = _end;
                size_type       _size_tmp = _size;
                key_compare     _comp_tmp = _comp;
                allocator_type  _alloc_tmp = _alloc;
                allocator_node  _allocNode_tmp = _allocNode;

                _root = x._root;
                _begin = x._begin;
                _end = x._end;
                _size = x._size;
                _comp = x._comp;
                _alloc = x._alloc;
                _allocNode = x._allocNode;
                
                x._root = _root_tmp;
                x._begin = _begin_tmp;
                x._end = _end_tmp;
                x._size = _size_tmp;
                x._comp = _comp_tmp;
                x._alloc = _alloc_tmp;
                x._allocNode = _allocNode_tmp;
            }

            void clear()
            {
                erase(this->begin(), this->end());
            }

            /* Observers (finished) */
            key_compare key_comp() const { return _comp; }
            value_compare value_comp() const { return value_compare(_comp); }

            /* Operations (finished) */
            iterator find(const key_type& k) { return search_key(k); }
            const_iterator find(const key_type& k) const { return search_key(k); }

            size_type count(const key_type& k) const
            {
                const_iterator it = this->begin();
                const_iterator ite = this->end();
                for (; it != ite ; ++ it)
                    if (it->first == k)
                        return (1);
                return (0);
            }

            iterator lower_bound(const key_type& k)
            {
                iterator it = this->begin();
                iterator ite = this->end();
                for (; it != ite ; ++it)
                    if (this->_comp(it->first, k) <= 0)
                        return (it);
                return (ite);
            }

            const_iterator lower_bound(const key_type& k) const
            {
                const_iterator it = this->begin();
                const_iterator ite = this->end();
                for (; it != ite ; ++it)
                    if (this->_comp(it->first, k) <= 0)
                        return (it);
                return (ite);
            }

            iterator upper_bound(const key_type& k)
            {
                iterator it = this->begin();
                iterator ite = this->end();
                for (; it != ite ; ++it)
                    if (it->first != k && this->_comp(it->first, k) <= 0)
                        return (it);
                return (ite);
            }
            const_iterator upper_bound(const key_type& k) const
            {
                const_iterator it = this->begin();
                const_iterator ite = this->end();
                for (; it != ite ; ++it)
                    if (it->first != k && this->_comp(it->first, k) <= 0)
                        return (it);
                return (ite);
            }

            ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
            { 
                return (ft::make_pair(lower_bound(k), upper_bound(k)));
            }
            ft::pair<iterator,iterator> equal_range (const key_type& k) 
            { 
                return (ft::make_pair(lower_bound(k), upper_bound(k)));
            }

            /* Allocator (finshed) */
            allocator_type get_allocator() const { return _allocNode; }
    };

    template< class Key, class T, class Compare, class Alloc >
    bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
    {
        if (lhs.size() != rhs.size())
            return false;
        return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
    
    template< class Key, class T, class Compare, class Alloc >
    bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) { return (!(lhs == rhs)); }
    
    template< class Key, class T, class Compare, class Alloc >
    bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
    
    template< class Key, class T, class Compare, class Alloc >
    bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) { return !(rhs < lhs); }
    
    template< class Key, class T, class Compare, class Alloc >
    bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) { return rhs < lhs; }
    
    template< class Key, class T, class Compare, class Alloc >
    bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) { return !(lhs < rhs); }

};


#endif