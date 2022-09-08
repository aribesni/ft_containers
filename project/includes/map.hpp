/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:28:10 by aribesni          #+#    #+#             */
/*   Updated: 2022/07/27 10:28:11 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <iostream>
# include <cstddef>
# include "iterator.hpp"

namespace ft {

    //IS INTEGRAL
    template <class T>
        struct is_integral

    //PAIR
    template< class T1, class T2 >
        struct pair {

        //MEMBER TYPES

            typedef T1  first_type;
            typedef T2  second_type;

            first_type  first;
            second_type second;

        //MEMBER FUNCTIONS

            //Constructors
            pair(void) : first(), second() {}
            template<class U, class V>
                pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {}
            pair(first_type& a, second_type& b) : first(a), second(b) {}

            pair&   operator=(const pair& pr) {
                
                this->first = pr.first;
                this->second = pr.second;
                return (*this);
            }
    };

    //PAIR OPERATORS
    template<class T1, class T2>
        bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); }
    template<class T1, class T2>
        bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (!(lhs == rhs)); }
    template<class T1, class T2>
        bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second)); }
    template<class T1, class T2>
        bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (!(rhs < lhs)); }
    template<class T1, class T2>
        bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (rhs < lhs); }
    template<class T1, class T2>
        bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (!(lhs < rhs)); }

    //MAKE PAIR
    template<class T1, class T2>
        pair<T1, T2>    make_pair(T1 x, T2 y) { return (pair<T1, T2>(x, y)); }

    //MAP
    template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
        class map {

            //NODE
            public :

                typedef struct                              s_node {

                    struct s_node                           *parent;
                    struct s_node                           *left;
                    struct s_node                           *right;
                    ft::pair<const Key, T>                  val;
                    typename ft::map<Key, T>::key_type      key;
                    typename ft::map<Key, T>::mapped_type   data;
                    int                                     color;

                    s_node(void) {}
                    s_node(ft::pair<const Key, T> value) : val(value), key(value.first), data(value.second) {}
                }
                                                            t_node;
                                                                            
            //MAP ITERATORS
            template <typename IT>
                class MapIterator {
                        
                    public :

                    //MEMBER TYPES

                        typedef IT                              value_type;
                        typedef value_type&                     reference;
                        typedef value_type*                     pointer;
                        typedef std::bidirectional_iterator_tag iterator_category;
                        typedef std::ptrdiff_t                  difference_type;
                        typedef MapIterator<value_type>         iterator;
                        typedef t_node*                         node_ptr;

                        //Constructors
                        MapIterator(void) : _ptr() {}
                        MapIterator(node_ptr ptr) : _ptr(ptr) {}

                        ~MapIterator(void) {}

                        //Operators
                        reference   operator*(void) { return (this->_ptr->val); }
                        pointer     operator->(void) { return (&this->_ptr->val); }
                        iterator&   operator=(iterator const &rhs) { this->_ptr = rhs.getPtr(); return (*this); }
                        bool        operator==(iterator const &rhs) { return (this->_ptr == rhs.getPtr()); }
                        bool        operator!=(iterator const &rhs) { return (this->_ptr != rhs.getPtr()); }
                        iterator&   operator++(void) { this->_ptr = this->next_node(this->_ptr); return (*this); }
                        iterator    operator++(int) { iterator tmp = *this; this->_ptr = this->next_node(this->_ptr); return (tmp); }
                        iterator&   operator--(void) { this->_ptr = this->previous_node(this->_ptr); return (*this); }
                        iterator    operator--(int) { iterator tmp = *this; this->_ptr = this->previous_node(this->_ptr); return (tmp); }

                        node_ptr    getPtr(void) const { return (this->_ptr); }

                    private :

                    //MEMBER TYPES

                        node_ptr    _ptr;

                        node_ptr    next_node (node_ptr node)
                        {
                            if (node->right != node->right->left)
                            {
                                node = node->right;
                                while (node->left != node->left->left)
                                    node = node->left;
                            }
                            else
                            {
                                while (node == node->parent->right && node != node->parent)
                                    node = node->parent;
                                node = node->parent;
                            }
                            return (node);
                        }

                        node_ptr    previous_node (node_ptr node)
                        {
                            if (node == node->parent)
                            {
                                while (node->right != node->right->left)
                                    node = node->right;
                            }
                            else if (node->left != node->left->left)
                            {
                                node = node->left;
                                while (node->right != node->right->left)
                                    node = node->right;
                            }
                            else
                            {
                                while (node == node->parent->left && node != node->parent)
                                    node = node->parent;
                                node = _ptr->parent;
                            }
                            return (node);
                        }
            };

            //MEMBER TYPES

                typedef Key                                                     key_type;
                typedef T                                                       mapped_type;
                typedef ft::pair<const Key, T>                                  value_type;
                typedef std::size_t                                             size_type;
                typedef std::ptrdiff_t                                          difference_type;
                typedef Compare                                                 key_compare;
                typedef typename Allocator::template rebind<t_node>::other      allocator_type;
                typedef value_type&                                             reference;
                typedef const value_type&                                       const_reference;
                typedef value_type*                                             pointer;
                typedef const value_type*                                       const_pointer;
                typedef MapIterator<value_type>                                 iterator;
                typedef MapIterator<const value_type>                           const_iterator;
                typedef ft::reverse_iterator<iterator>                          reverse_iterator;
                typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;

                class value_compare {
                    
                        // friend class map;

                    public :

                    //MEMBER TYPES 

                        typedef bool        result_type;
                        value_type          first_argument_type;
                        value_type          second_argument_type;
                    
                    //MEMBER FUNCTIONS

                        //Operators
                        bool    operator()(const value_type& lhs, const value_type& rhs) const { return (comp(lhs.first, rhs.first)); }

                    protected :

                    //MEMBER TYPES

                        Compare _comp;
                    
                    //MEMBER FUNCTIONS

                        //Constructors
                        value_compare(Compare c) : _comp(c) {}

                };

            //MEMBER FUNCTIONS

                //Constructors
                explicit    map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp) {
                    
                    this->new_nil_node();
                    this->init_root();
                }
                template <class InputIterator>
                    map(InputIterator first, InputIterator last, const key_compare& comp = key_compare()) : _comp(comp) {
                        
                        this->new_nil_node();
                        this->init_root();
                        this->insert(first, last);
                    }
                map(const map& x) : _alloc(x._alloc), _comp(x._comp) {
                    
                    this->new_nil_node();
                    this->init_root();
                    this->insert(x.begin(), x.end());
                }

                //Destructor
                ~map(void) {}

                //Iterators
                iterator                begin(void) { return (iterator(this->left_most(this->_node_ptr))); }
                const_iterator          begin(void) const { return (const_iterator(this->left_most(this->_node_ptr))); }
                iterator                end(void) { return (iterator(this->right_most(this->_node_ptr))); }
                const_iterator          end(void) const { return (const_iterator(this->right_most(this->_node_ptr))); }
                reverse_iterator        rbegin(void) { return (reverse_iterator(this->end())); }
                const_reverse_iterator  rbegin(void) const { return (const_reverse_iterator(this->end())); }
                reverse_iterator        rend(void) { return (reverse_iterator(this->begin())); }
                const_reverse_iterator  rend(void) const { return (const_reverse_iterator(this->begin())); }

                //Capacity
                bool        empty(void) const { return (this->size == 0 ? true : false); }
                size_type   size(void) const {

                    size_type   n = 0;
                    for (const_iterator it = this->begin(); it != this->end(); it++)
                        n++;
                    return (n);
                }
                size_type   max_size(void) const { return (this->_alloc.max_size()); }

                //Element access
                mapped_type&    operator[] (const key_type& k) {
                    
                    this->insert(ft::make_pair(k, mapped_type()));
                    return (this->find(k)->second);
                }

                //Modifiers
                pair<iterator, bool>    insert(const value_type& val) {
                    
                    iterator    it;
                    if (this->count(val.first))
                    {
                        it = this->find(val.first);
                        return (ft::make_pair(it, false));
                    }
                    else
                    {
                        it = iterator(this->insert_node(val));
                        return (ft::make_pair(it, true));
                    }
                }
                iterator                insert(iterator position, const value_type& val) {

                    (void)position;
                    return (this->insert(val).first);
                }
                template<class InputIterator>
                    void    insert(InputIterator first, InputIterator last) {

                        while (first != last)
                            this->insert(first++);
                    }
                void                    erase(iterator position) {

                    t_node  *node = position.getPtr();
                    this->deleteNode(node->key);
                }
                size_type               erase(const key_type& k) {

                    if (this->count(k))
                    {
                        this->erase(this->find(k));
                        return (1);
                    }
                    return (0);
                }
                void                    erase(iterator first, iterator last) {

                    for (iterator it = first; it != last; it++)
                        this->erase(it);
                }
                void                    swap(map& x) {

                    swap(this->_alloc, x._alloc);
                    swap(this->_comp, x._comp);
                }
                void                    clear(void) { this->erase(this->begin(), this->end()); }

                //Observers
                key_compare     key_comp(void) const { return (key_compare()); }
                value_compare   value_comp(void) const { return (value_compare(_comp)); }

                //Operations
                iterator                                find(const key_type& k) { return (iterator(this->searchTree(k))); }
                const_iterator                          find(const key_type& k) const { return (const_iterator(this->searchTree(k))); }
                size_type                               count(const key_type& k) const { return (this->find(k) != this->end() ? 1 : 0); }
                iterator                                lower_bound(const key_type& k) {

                    iterator    it;

                    it = this->begin();
                    while (key_compare(it.first, k) == true && it != this->end())
                        it++;
                    return (it);
                }
                const_iterator                          lower_bound(const key_type& k) const {
            
                    const_iterator    it;

                    it = this->begin();
                    while (key_compare(it.first, k) == true && it != this->end())
                        it++;
                    return (it);
                }
                iterator                                upper_bound(const key_type& k) {

                    iterator    it;

                    it = this->begin();
                    while (key_compare(it.first, k) == false && it != this->end())
                        it++;
                    return (it);
                }
                const_iterator                          upper_bound(const key_type& k) const {

                    const_iterator    it;

                    it = this->begin();
                    while (key_compare(it.first, k) == false && it != this->end())
                        it++;
                    return (it);
                }
                pair<iterator, iterator>                equal_range(const key_type& k) { return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); }
                pair<const_iterator, const_iterator>    equal_range(const key_type& k) const { return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); }

                //Allocator
                allocator_type  get_allocator(void) const {return (allocator_type()); }

                private :

                    t_node*         _node_ptr;
                    allocator_type  _alloc;
                    key_compare     _comp;


                    t_node* root;
                    t_node* TNULL;

                    void    new_nil_node(void) {
                        
                        this->_node_ptr = this->_alloc.allocate(1);
                        this->construct(this->_node_ptr);
                        this->_node_ptr->color = 0;
                    }
                    void    construct(t_node* ptr, const value_type& val = value_type()) {

                        t_node  tmp(val);
                        tmp.left = this->_node_ptr;
                        tmp.right = this->_node_ptr;
                        tmp.parent = this->_node_ptr;
                        tmp.color = 1;
                        this->_alloc.construct(ptr, tmp);
                    }
                    t_node* searchTreeHelper(t_node* node, key_type key) const {
                        
                        if (node == this->_node_ptr || key == node->key)
                            return (node);
                        if (key < node->key)
                            return (searchTreeHelper(node->left, key));
                        return (searchTreeHelper(node->right, key));
                    }
                    void    balance_after_delete(t_node* x) {

                        t_node* s;

                        while (x != root && x->color == 0)
                        {
                            if (x == x->parent->left)
                            {
                                s = x->parent->right;
                                if (s->color == 1)
                                {
                                    s->color = 0;
                                    x->parent->color = 1;
                                    leftRotate(x->parent);
                                    s = x->parent->right;
                                }
                                if (s->left->color == 0 && s->right->color == 0)
                                {
                                    s->color = 1;
                                    x = x->parent;
                                } 
                                else
                                {
                                    if (s->right->color == 0)
                                    {
                                        s->left->color = 0;
                                        s->color = 1;
                                        rightRotate(s);
                                        s = x->parent->right;
                                    }
                                    s->color = x->parent->color;
                                    x->parent->color = 0;
                                    s->right->color = 0;
                                    leftRotate(x->parent);
                                    x = root;
                                }
                            }
                            else
                            {
                                s = x->parent->left;
                                if (s->color == 1)
                                {
                                    s->color = 0;
                                    x->parent->color = 1;
                                    rightRotate(x->parent);
                                    s = x->parent->left;
                                }
                                if (s->right->color == 0 && s->right->color == 0)
                                {
                                    s->color = 1;
                                    x = x->parent;
                                } 
                                else
                                {
                                    if (s->left->color == 0)
                                    {
                                        s->right->color = 0;
                                        s->color = 1;
                                        leftRotate(s);
                                        s = x->parent->left;
                                    }
                                    s->color = x->parent->color;
                                    x->parent->color = 0;
                                    s->left->color = 0;
                                    rightRotate(x->parent);
                                    x = root;
                                }
                            }
                        }
                        x->color = 0;
                    }
                    void    rbTransplant(t_node* u, t_node* v) {
                        
                        if (u->parent == NULL)
                            root = v;
                        else if (u == u->parent->left)
                            u->parent->left = v;
                        else
                            u->parent->right = v;
                        v->parent = u->parent;
                    }
                    void    balance_after_insert(t_node* k) {

                        t_node* u;

                        while (k->parent->color == 1)
                        {
                            if (k->parent == k->parent->parent->right)
                            {
                                u = k->parent->parent->left;
                                if (u->color == 1)
                                {
                                    u->color = 0;
                                    k->parent->color = 0;
                                    k->parent->parent->color = 1;
                                    k = k->parent->parent;
                                }
                                else
                                {
                                    if (k == k->parent->left)
                                    {
                                        k = k->parent;
                                        rightRotate(k);
                                    }
                                    k->parent->color = 0;
                                    k->parent->parent->color = 1;
                                    leftRotate(k->parent->parent);
                                }
                            }
                            else
                            {
                                u = k->parent->parent->right;
                                if (u->color == 1)
                                {
                                    u->color = 0;
                                    k->parent->color = 0;
                                    k->parent->parent->color = 1;
                                    k = k->parent->parent;
                                }
                                else
                                {
                                    if (k == k->parent->right)
                                    {
                                        k = k->parent;
                                        leftRotate(k);
                                    }
                                    k->parent->color = 0;
                                    k->parent->parent->color = 1;
                                    rightRotate(k->parent->parent);
                                }
                            }
                            if (k == root)
                                break;
                        }
                        root->color = 0;
                    }
                    void    init_root(const value_type& val = value_type()) {

                        t_node tmp(val);
                        this->TNULL = this->_alloc.allocate(1);
                        this->root = this->_alloc.allocate(1);
                        tmp.left = this->_node_ptr;
                        tmp.right = this->_node_ptr;
                        tmp.parent = this->_node_ptr;
                        this->_alloc.construct(this->TNULL, tmp);
                        this->TNULL->color = 0;
                        this->root = this->TNULL;
                    }
                    t_node* searchTree(int k) const { return (searchTreeHelper(this->root, k)); }
                    t_node* minimum(t_node* node) const {

                        while (node->left != this->TNULL)
                            node = node->left;
                        return (node);
                    }
                    t_node* left_most(t_node* node) const {

                        while (node->left != node->left->left)
                            node = node->left;
                        return (node);
                    }
                    t_node* maximum(t_node* node) const {

                        while (node->right != this->TNULL)
                            node = node->right;
                        return (node);
                    }
                    t_node* right_most(t_node* node) const {

                        while (node->right != node->right->right)
                            node = node->right;
                        return (node);
                    }
                    t_node* previous_node(t_node* x) {

                        if (x->right != this->TNULL)
                            return (minimum(x->right));
                        t_node* y = x->parent;
                        while (y != this->TNULL && x == y->right)
                        {
                            x = y;
                            y = y->parent;
                        }
                        return (y);
                    }
                    t_node* next_node(t_node* x) {

                        if (x->left != this->TNULL)
                            return (maximum(x->left));
                        t_node* y = x->parent;
                        while (y != this->TNULL && x == y->left)
                        {
                            x = y;
                            y = y->parent;
                        }
                        return (y);
                    }
                    void    leftRotate(t_node* x) {

                        t_node* y = x->right;
                        x->right = y->left;
                        if (y->left != this->TNULL)
                            y->left->parent = x;
                        y->parent = x->parent;
                        if (x->parent == NULL)
                            this->root = y;
                        else if (x == x->parent->left)
                            x->parent->left = y;
                        else
                            x->parent->right = y;
                        y->left = x;
                        x->parent = y;
                    }
                    void    rightRotate(t_node* x) {

                        t_node* y = x->left;
                        x->left = y->right;
                        if (y->right != this->TNULL)
                            y->right->parent = x;
                        y->parent = x->parent;
                        if (x->parent == NULL)
                            this->root = y;
                        else if (x == x->parent->right)
                            x->parent->right = y;
                        else
                            x->parent->left = y;
                        y->right = x;
                        x->parent = y;
                    }
                    t_node* insert_node(value_type val) {

                        t_node* node = new t_node(val);
                        t_node* y = NULL;
                        t_node* x = this->root;

                        node->parent = NULL;
                        node->left = this->TNULL;
                        node->right = this->TNULL;
                        node->color = 1;
                        while (x != this->TNULL) {

                            y = x;
                            if (node->key < x->key)
                                x = x->left;
                            else
                                x = x->right;
                        }
                        node->parent = y;
                        if (y == NULL)
                            root = node;
                        else if (node->key < y->key)
                            y->left = node;
                        else
                            y->right = node;
                        if (node->parent == NULL)
                        {
                            node->color = 0;
                            return (NULL);
                        }
                        if (node->parent->parent == NULL)
                            return (NULL);
                        balance_after_insert(node);
                        return (node);
                    }
                    // t_node* getRoot() { return (this->root); }
                    void    deleteNode(key_type key) {

                        t_node* z = this->TNULL;
                        t_node  *x, *y;
                        t_node* node = this->root;

                        while (node != this->TNULL)
                        {
                            if (node->data == key)
                                z = node;
                            if (node->data <= key)
                                node = node->right;
                            else
                            node = node->left;
                        }
                        if (z == this->TNULL)
                        {
                            std::cout << "Key not found in the tree" << std::endl;
                            return ;
                        }
                        y = z;
                        int y_original_color = y->color;
                        if (z->left == this->TNULL)
                        {
                            x = z->right;
                            rbTransplant(z, z->right);
                        } 
                        else if (z->right == this->TNULL)
                        {
                            x = z->left;
                            rbTransplant(z, z->left);
                        }
                        else
                        {
                            y = minimum(z->right);
                            y_original_color = y->color;
                            x = y->right;
                            if (y->parent == z)
                                x->parent = y;
                            else
                            {
                                rbTransplant(y, y->right);
                                y->right = z->right;
                                y->right->parent = y;
                            }
                            rbTransplant(z, y);
                            y->left = z->left;
                            y->left->parent = y;
                            y->color = z->color;
                        }
                        delete z;
                        if (y_original_color == 0)
                            balance_after_delete(x);
                    }
        };

        template<class T>
            void    swap(T& a, T& b) {

                T   tmp(a);

                a = b;
                b = tmp;
            }
}

#endif