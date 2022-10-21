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

    template <class T>
        void swap (T & a, T & b)
        {
            T	tmp(a);
            a = b;
            b = tmp;
    }

    //IS INTEGRAL
    template <bool is_integral, typename T>
        struct is_integral_res {

        //MEMBER TYPES

            typedef T           type;
            static const bool   value = is_integral;
    };

    template<typename>
        struct is_integral_type : is_integral_res<false, bool> {};
    template<>
        struct is_integral_type<bool> : is_integral_res<true, bool> {};
    template<>
        struct is_integral_type<char> : is_integral_res<true, char> {};
    template<>
        struct is_integral_type<signed char> : is_integral_res<true, signed char> {};
    template<>
        struct is_integral_type<short int> : is_integral_res<true, short int> {};
    template<>
        struct is_integral_type<int> : is_integral_res<true, int> {};
    template<>
        struct is_integral_type<long int> : is_integral_res<true, long int> {};
    template<>
        struct is_integral_type<long long int> : is_integral_res<true, long long int> {};
    template<>
        struct is_integral_type<unsigned char> : is_integral_res<true, unsigned char> {};
    template<>
        struct is_integral_type<unsigned short int> : is_integral_res<true, unsigned short int> {};
    template<>
        struct is_integral_type<unsigned int> : is_integral_res<true, unsigned int> {};
    template<>
        struct is_integral_type<unsigned long int> : is_integral_res<true, unsigned long int> {};
    template<>
        struct is_integral_type<unsigned long long int> : is_integral_res<true, unsigned long long int> {};

    template<typename T>
        struct is_integral : is_integral_type<T> {};

    //EQUAL
    template<class InputIterator1, class InputIterator2>
        bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
            
            while (first1 != last1)
            {
                if (first2 == last2 || *first1 != *first2)
                    return (false);
                ++first1;
                ++first2;
            }
            return (first2 == last2);
    }

    //LEXICOGRAPHICAL COMPARE
    template <class InputIterator1, class InputIterator2>
        bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
            while (first1 != last1)
            {
                if (first2 == last2 || *first2 < *first1)
                    return (false);
                else if (*first1 < *first2)
                    return (true);
                ++first1;
                ++first2;
            }
            return (first2 != last2);
    }

    //PAIR
    template<class T1, class T2>
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
            pair(const first_type& a, const second_type& b) : first(a), second(b) {}

            pair&   operator=(const pair& pr) {
                
                this->first = pr.first;
                this->second = pr.second;
                return (*this);
            }
    };

    template< bool Cond, class T = void >
        struct enable_if {};
    template<class T>
        struct enable_if<true, T> {

            //MEMBER TYPES

                typedef T   type;
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

    //NODE
    template<typename PAIR>
        struct                                      t_node {

            typedef PAIR                            value_type;
            
            value_type                              val;
            t_node                                  *parent;
            t_node                                  *left;
            t_node                                  *right;
            int                                     color;

            t_node(void) {}
            t_node(value_type value) : val(value) {};
    };

    //MAP ITERATORS
    template<typename T>
        class MapIterator : public ft::iterator<std::bidirectional_iterator_tag, T> {

            public :

            //MEMBER TYPES

                typedef typename T::value_type                                                                  value_type;
                typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::iterator_category   iterator_category;
                typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::difference_type     difference_type;
                typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::pointer             pointer;
                typedef typename ft::iterator<std::bidirectional_iterator_tag, value_type>::reference           reference;

            //MEMBER FUNCTIONS
          
                //Constructors
                MapIterator(void) : _current(), _end(), _root() {}
                MapIterator(const MapIterator& src) : _current(src._current), _end(src._end), _root(src._root) {}
                MapIterator(T* ptr, T* root, T* end) : _current(ptr), _end(end), _root(root) {}

                ~MapIterator(void) {}

                //Operators
                reference       operator*(void) { return (this->_current->val); }
                pointer         operator->(void) { return (&this->_current->val); }
                pointer         operator->(void) const { return (&this->_current->val); }
                MapIterator&    operator=(MapIterator const &rhs) {
                    
                    if (this != &rhs)
                    {
                        this->_current = rhs.base();
                        this->_end = rhs.getEnd();
                        this->_root = rhs.getRoot();
                    }
                    return (*this);
                }
                bool            operator==(MapIterator const &rhs) { return (this->_current == rhs.base()); }
                bool            operator!=(MapIterator const &rhs) { return (this->_current != rhs.base()); }
                MapIterator&    operator++(void) {

                    if (this->_current != this->_end)
                        this->_current = this->next_node(this->_current);
                    return (*this);
                }
                MapIterator     operator++(int) {
                    
                    MapIterator tmp(*this);
                    this->operator++();
                    return (tmp);
                }
                MapIterator&    operator--(void) {

                    if (this->_current != this->_end)
                        this->_current = this->previous_node(this->_current);
                    else
                        this->_current = this->maximum(this->_root);
                    return (*this);
                }
                MapIterator     operator--(int) {
                    
                    MapIterator tmp(*this);
                    this->operator--();
                    return (tmp);
                }

                T*  base(void) const { return (this->_current); }
                T*  getEnd(void) const { return (this->_end); }
                T*  getRoot(void) const { return (this->_root); }

            private :

            //MEMBER TYPES

                T*  _current;
                T*  _end;
                T*  _root;


            //MEMBER FUNCTIONS
    
                T*    minimum(T* node) {

                    while (node->left != this->_end)
                        node = node->left;
                    return (node);
                }
                T*  maximum(T* node) {

                    while (node->right != this->_end)
                        node = node->right;
                    return (node);
                }
                T*  previous_node(T* x) {

                    if (x->left != this->_end)
                        return (maximum(x->left));
                    T*  y = x->parent;
                    while (x->parent && x == y->left)
                    {
                        x = y;
                        y = y->parent;
                    }
                    return (y);
                }
                T*  next_node(T* x) {

                    if (x == this->_end)
                        return (this->_end);
                    if (x->right != this->_end)
                        return (minimum(x->right));
                    T*  y = x->parent;
                    while (x->parent != this->_end && x == y->right)
                    {
                        x = y;
                        y = y->parent;
                    }
                    return (y);
                }
    };
    template<typename T>
        class MapConstIterator : public ft::iterator<std::bidirectional_iterator_tag, T> {

            public :

            //MEMBER TYPES

                typedef typename T::value_type                                                                      value_type;
                typedef typename ft::iterator<std::bidirectional_iterator_tag, const value_type>::iterator_category iterator_category;
                typedef typename ft::iterator<std::bidirectional_iterator_tag, const value_type>::difference_type   difference_type;
                typedef typename ft::iterator<std::bidirectional_iterator_tag, const value_type>::pointer           pointer;
                typedef typename ft::iterator<std::bidirectional_iterator_tag, const value_type>::reference         reference;

            //MEMBER FUNCTIONS
            
                //Constructors
                MapConstIterator(void) : _current(), _end(), _root() {}
                MapConstIterator(T* ptr, T* root, T* end) : _current(ptr), _end(end), _root(root) {}
                MapConstIterator(const MapConstIterator& src) : _current(src._current), _end(src._end), _root(src._root) {}
                MapConstIterator(const MapIterator<T>& src) : _current(src.base()), _end(src.getEnd()), _root(src.getRoot()) {}

                ~MapConstIterator(void) {}

                //Operators
                reference           operator*(void) const { return (this->_current->val); }
                pointer             operator->(void) const { return (&this->_current->val); }
                MapConstIterator&   operator=(MapConstIterator const &rhs) {
                
                    if (this != &rhs)
                    {
                        this->_current = rhs.base();
                        this->_end = rhs.getEnd();
                        this->_root = rhs.getRoot();
                    }
                    return (*this);
                }
                bool                operator==(MapConstIterator const &rhs) { return (this->_current == rhs.base()); }
                bool                operator!=(MapConstIterator const &rhs) { return (this->_current != rhs.base()); }
                MapConstIterator&   operator++(void) {

                    if (this->_current != this->_end)
                        this->_current = this->next_node(this->_current);
                    return (*this);
                }
                MapConstIterator    operator++(int) {
                    
                    MapConstIterator    tmp(*this);
                    this->operator++();
                    return (tmp);
                }
                MapConstIterator&   operator--(void) {
                    
                    if (this->_current != this->_end)
                        this->_current = this->previous_node(this->_current);
                    else
                        this->_current = this->maximum(this->_root);
                    return (*this);
                }
                MapConstIterator    operator--(int) {
                    
                    MapConstIterator    tmp(*this);
                    this->operator--();
                    return (tmp);
                }

                T*  base(void) const { return (this->_current); }
                T*  getEnd(void) const { return (this->_end); }
                T*  getRoot(void) const { return (this->_root); }
        
            private :

            //MEMBER TYPES

                T*  _current;
                T*  _end;
                T*  _root;


            //MEMBER FUNCTIONS

                T*  minimum(T* node) {

                    while (node && node->left && node->left != this->_end)
                        node = node->left;
                    return (node);
                }
                T*  maximum(T* node) {

                    while (node && node->right && node->right != this->_end)
                        node = node->right;
                    return (node);
                }
                T*  previous_node(T* x) {

                    if (x->left != this->_end)
                        return (maximum(x->left));
                    T*  y = x->parent;
                    while (x->parent != this->_end && x == y->left)
                    {
                        x = y;
                        y = y->parent;
                    }
                    return (y);
                }
                T*  next_node(T* x) {

                    if (x == this->_end)
                        return (this->_end);
                    if (x->right != this->_end)
                        return (minimum(x->right));
                    T*  y = x->parent;
                    while (x->parent != this->_end && x == y->right)
                    {
                        x = y;
                        y = y->parent;
                    }
                    return (y);
                }
    };   
    template<typename IT>
        class MapReverseIterator {

            public :

            //MEMBER TYPES

                typedef IT                      iterator_type;
                typedef typename IT::value_type value_type;
                typedef typename IT::pointer    pointer;
                typedef typename IT::reference  reference;

                //Constructors
                MapReverseIterator(void) : _it() {}
                template <class Iter>
                    MapReverseIterator (const MapReverseIterator<Iter>& src) : _it(src.base()) {}
                MapReverseIterator (iterator_type it) : _it(it) {}
                ~MapReverseIterator(void) {}

                //Operators
                reference           operator*(void) const { iterator_type tmp = this->_it; return (*(--tmp)); }
                pointer             operator->(void) { return (&operator*()); }
                pointer             operator->(void) const { return (&operator*()); }
                MapReverseIterator& operator=(MapReverseIterator const &rhs) {
                
                    if (this != &rhs)
                        this->_it = rhs.base();
                    return (*this);
                }
                bool                operator==(MapReverseIterator const &rhs) { return (this->_it == rhs.base()); }
                bool                operator!=(MapReverseIterator const &rhs) { return (this->_it != rhs.base()); }
                MapReverseIterator& operator++(void) { --this->_it; return (*this); }
                MapReverseIterator  operator++(int) { MapReverseIterator tmp = *this; ++(*this); return (tmp); }
                MapReverseIterator& operator--(void) { ++this->_it; return (*this); }
                MapReverseIterator  operator--(int) { MapReverseIterator tmp = *this; --(*this); return (tmp); }

                iterator_type    base(void) const { return (this->_it); }
            
            private :

            //MEMBER TYPES

                iterator_type   _it;

    };

    //MAP
    template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
        class map {

            public :

            //MEMBER TYPES

                typedef Key                                                             key_type;
                typedef T                                                               mapped_type;
                typedef ft::pair<const Key, T>                                          value_type;
                typedef std::size_t                                                     size_type;
                typedef std::ptrdiff_t                                                  difference_type;
                typedef Compare                                                         key_compare;
                typedef typename Allocator::template rebind<t_node<value_type> >::other allocator_type;
                typedef value_type&                                                     reference;
                typedef const value_type&                                               const_reference;
                typedef value_type*                                                     pointer;
                typedef const value_type*                                               const_pointer;
                typedef ft::MapIterator<t_node<value_type> >                            iterator;
                typedef ft::MapConstIterator<t_node<value_type> >                       const_iterator;
                typedef ft::MapReverseIterator<iterator>                                reverse_iterator;
                typedef ft::MapReverseIterator<const_iterator>                          const_reverse_iterator;
                typedef ft::t_node<value_type>                                          node;

                class value_compare {

                    friend class map;

                    public :

                    //MEMBER TYPES

                        typedef bool        result_type;
                        value_type          first_argument_type;
                        value_type          second_argument_type;

                    //MEMBER FUNCTIONS

                        //Operators
                        bool    operator()(const value_type& lhs, const value_type& rhs) const { return (this->_comp(lhs.first, rhs.first)); }

                    protected :

                    //MEMBER TYPES

                        Compare _comp;
                    
                    //MEMBER FUNCTIONS

                        //Constructors
                        value_compare(Compare c) : _comp(c) {}
                };

            //MEMBER FUNCTIONS

                //Constructors
                explicit    map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp) { this->init_root(); }
                template <class InputIterator>
                    map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) : _alloc(alloc), _comp(comp) {

                        this->init_root();
                        this->insert(first, last);
                }
                map(const map& x) : _alloc(x._alloc), _comp(x._comp) {

                    this->init_root();
                    this->insert(x.begin(), x.end());
                }

                //Destructor
                ~map(void) {}

                //Operator
                map&    operator=(const map& x) {

                    if (this == &x)
                        return (*this);
                    this->clear();
                    this->_alloc = x._alloc;
                    this->_comp = x._comp;
                    this->insert(x.begin(), x.end());
                    return (*this);
                }

                //Iterators
                iterator                begin(void) { return (iterator(this->left_most(this->root), this->root, this->TNULL)); }
                const_iterator          begin(void) const { return (const_iterator(this->left_most(this->root), this->root, this->TNULL)); }
                iterator                end(void) { return (iterator(this->TNULL, this->root, this->TNULL)); }
                const_iterator          end(void) const { return (const_iterator(this->TNULL, this->root, this->TNULL)); }
                reverse_iterator        rbegin(void) { return (reverse_iterator(end())); }
                const_reverse_iterator  rbegin(void) const { return (const_reverse_iterator(end())); }
                reverse_iterator        rend(void) { return (reverse_iterator(begin())); }
                const_reverse_iterator  rend(void) const { return (const_reverse_iterator(begin())); }

                //Capacity
                bool        empty(void) const { return (this->size() == 0 ? true : false); }
                size_type   size(void) const {

                    size_type   n = 0;
                    for (const_iterator it = this->begin(); it != this->end(); it++)
                        n++;
                    return (n);
                }
                size_type   max_size(void) const { return (this->_alloc.max_size()); }

                //Element access
                mapped_type&    operator[](const key_type& k) {

                    this->insert(ft::make_pair(k, mapped_type()));
                    return (this->find(k)->second);
                }
                mapped_type&    at(const key_type& k) {

                    return (this->find(k)->second);
                    throw (std::out_of_range("Out of range"));
                }
                const mapped_type&  at(const key_type& k) const {

                    return (this->find(k)->second);
                    throw (std::out_of_range("Out of range"));
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
                        it = iterator(this->insert_node(val), this->root, this->TNULL);
                        return (ft::make_pair(it, true));
                    }
                }
                iterator                insert(iterator position, const value_type& val) {

                    (void)position;
                    return (this->insert(val).first);
                }
                template<class InputIterator>
                    void    insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {

                        while (first != last)
                            this->insert(*first++);
                }
                void                    erase(iterator position) {

                    node    *node = position.base();
                    this->deleteNode(node->val.first);
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
                    {
                        std::cout << "KEY FIRST : " << it->first << " VALUE FIRST : " << it->second << std::endl;
                        this->erase(it);
                    }
                }
                void                    swap(map& x) {

                    ft::swap(this->_alloc, x._alloc);
                    ft::swap(this->_comp, x._comp);
                    ft::swap(this->TNULL, x.TNULL);
                    ft::swap(this->root, x.root);
                }
                void                    clear(void) { this->erase(this->begin(), this->end()); }

                //Observers
                key_compare     key_comp(void) const { return (key_compare()); }
                value_compare   value_comp(void) const { return (value_compare(_comp)); }

                //Operations
                iterator                                find(const key_type& k) { return (iterator(this->searchTree(this->root, k), this->root, this->TNULL)); }
                const_iterator                          find(const key_type& k) const { return (const_iterator(this->searchTree(this->root, k), this->root, this->TNULL)); }
                size_type                               count(const key_type& k) const { return (this->find(k) != this->end() ? 1 : 0); }
                iterator                                lower_bound(const key_type& k) {

                    iterator    it;

                    it = this->begin();
                    while (this->_comp(it->first, k) == true && it != this->end())
                        it++;
                    return (it);
                }
                const_iterator                          lower_bound(const key_type& k) const {
            
                    const_iterator    it;

                    it = this->begin();
                    while (this->_comp(it->first, k) == true && it != this->end())
                        it++;
                    return (it);
                }
                iterator                                upper_bound(const key_type& k) {

                    iterator    it;

                    it = this->begin();
                    while (this->_comp(it->first, k) == false && it != this->end())
                        it++;
                    return (it);
                }
                const_iterator                          upper_bound(const key_type& k) const {

                    const_iterator    it;

                    it = this->begin();
                    while (this->_comp(it->first, k) == false && it != this->end())
                        it++;
                    return (it);
                }
                pair<iterator, iterator>                equal_range(const key_type& k) { return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); }
                pair<const_iterator, const_iterator>    equal_range(const key_type& k) const { return (ft::make_pair(this->lower_bound(k), this->upper_bound(k))); }

                //Allocator
                allocator_type  get_allocator(void) const {return (allocator_type()); }

                /*******************************************/
                //tmp functions

                void    ft_tmp(void) {

                    iterator tmp = this->begin();
                    node   *node_tmp = tmp.getPtr();
                    std::cout << "BEGIN KEY : " << node_tmp->val->first << "   ";
                    std::cout << "BEGIN DATA : " << node_tmp->val->second << "   ";
                    tmp = this->end();
                    // tmp--;
                    node_tmp = tmp.getPtr();
                    std::cout << "END KEY : " << node_tmp->val->first << "   ";
                    std::cout << "END DATA : " << node_tmp->val->second << std::endl;
                }

                /******************************************/

                private :

                //MEMBER TYPES

                    allocator_type  _alloc;
                    key_compare     _comp;
                    node            *root;
                    node            *TNULL;

                //MEMBER FUNCTIONS
            
                    void    init_root(const value_type& val = value_type()) {

                        node    tmp(val);
                        this->TNULL = this->_alloc.allocate(1);
                        tmp.left = this->TNULL;
                        tmp.right = this->TNULL;
                        tmp.parent = this->TNULL;
                        this->_alloc.construct(this->TNULL, tmp);
                        this->TNULL->color = 0;
                        this->root = this->TNULL;
                    }
                    void    construct(node *ptr, const value_type& val = value_type()) {

                        node    tmp(val);
                        tmp.left = this->TNULL;
                        tmp.right = this->TNULL;
                        tmp.parent = this->TNULL;
                        tmp.color = 1;
                        this->_alloc.construct(ptr, tmp);
                    }
                    node *searchTree(node *node, key_type key) const {

                        if (node == this->TNULL || (!this->_comp(node->val.first, key) && !this->_comp(key, node->val.first)))
                            return (node);
                        if (this->_comp(key, node->val.first))
                            return (this->searchTree(node->left, key));
                        return (this->searchTree(node->right, key));
                    }
                    node *left_most(node *node) const {

                        while (node->left != this->TNULL)
                            node = node->left;
                        return (node);
                    }
                    void    leftRotate(node *x) {

                        node *y = x->right;
                        x->right = y->left;
                        if (y->left != this->TNULL)
                            y->left->parent = x;
                        y->parent = x->parent;
                        if (x->parent == this->TNULL)
                            this->root = y;
                        else if (x == x->parent->left)
                            x->parent->left = y;
                        else
                            x->parent->right = y;
                        y->left = x;
                        x->parent = y;
                    }
                    void    rightRotate(node *x) {

                        node *y = x->left;
                        x->left = y->right;
                        if (y->right != this->TNULL)
                            y->right->parent = x;
                        y->parent = x->parent;
                        if (x->parent == this->TNULL)
                            this->root = y;
                        else if (x == x->parent->right)
                            x->parent->right = y;
                        else
                            x->parent->left = y;
                        y->right = x;
                        x->parent = y;
                    }
                    void    balance_after_delete(node *x) {

                        node *s;

                        while (x != this->root && x->color == 0)
                        {
                            if (x == x->parent->left)
                            {
                                s = x->parent->right;
                                if (s->color == 1)
                                {
                                    s->color = 0;
                                    x->parent->color = 1;
                                    this->leftRotate(x->parent);
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
                                        this->rightRotate(s);
                                        s = x->parent->right;
                                    }
                                    s->color = x->parent->color;
                                    x->parent->color = 0;
                                    s->right->color = 0;
                                    this->leftRotate(x->parent);
                                    x = this->root;
                                }
                            }
                            else
                            {
                                s = x->parent->left;
                                if (s->color == 1)
                                {
                                    s->color = 0;
                                    x->parent->color = 1;
                                    this->rightRotate(x->parent);
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
                                        this->leftRotate(s);
                                        s = x->parent->left;
                                    }
                                    s->color = x->parent->color;
                                    x->parent->color = 0;
                                    s->left->color = 0;
                                    this->rightRotate(x->parent);
                                    x = this->root;
                                }
                            }
                        }
                        x->color = 0;
                    }
                    void    rbTransplant(node *u, node *v) {

                        if (u->parent == this->TNULL)
                            this->root = v;
                        else if (u == u->parent->left)
                            u->parent->left = v;
                        else
                            u->parent->right = v;
                        v->parent = u->parent;
                    }
                    void    balance_after_insert(node *k) {

                        node *u;

                        while (k->parent->color == 1)
                        {
                            if (k->parent == k->parent->parent->left)
                            {
                                u = k->parent->parent->right;
                                if (u->color == 1)
                                {
                                    u->color = 0;
                                    k->parent->color = 0;
                                    k->parent->parent->color = 1;
                                    k = k->parent->parent;
                                }
                                else if (k == k->parent->right)
                                {
                                    k = k->parent;
                                    this->leftRotate(k);
                                    k->parent->color = 0;
                                    k->parent->parent->color = 1;
                                    this->rightRotate(k->parent->parent);
                                }
                                else
                                {
                                    k->parent->color = 0;
                                    k->parent->parent->color = 1;
                                    this->rightRotate(k->parent->parent);
                                }
                            }
                            else
                            {
                                u = k->parent->parent->left;
                                if (u->color == 1)
                                {
                                    u->color = 0;
                                    k->parent->color = 0;
                                    k->parent->parent->color = 1;
                                    k = k->parent->parent;
                                }
                                else if (k == k->parent->left)
                                {
                                    k = k->parent;
                                    this->rightRotate(k);
                                    k->parent->color = 0;
                                    k->parent->parent->color = 1;
                                    this->leftRotate(k->parent->parent);
                                }
                                else
                                {
                                    k->parent->color = 0;
                                    k->parent->parent->color = 1;
                                    this->leftRotate(k->parent->parent);
                                }
                            }
                        }
                        this->root->color = 0;
                    }
                    node* insert_node(value_type val) {

                        node *new_node = this->_alloc.allocate(1);
                        this->construct(new_node, val);
                        node *y = this->TNULL;
                        node *x = this->root;

                        while (x != this->TNULL) {
                            
                            y = x;
                            if (this->_comp(new_node->val.first, x->val.first))
                                x = x->left;
                            else
                                x = x->right;
                        }
                        new_node->parent = y;
                        if (y == this->TNULL)
                            this->root = new_node;
                        else if (this->_comp(new_node->val.first, y->val.first))
                            y->left = new_node;
                        else
                            y->right = new_node;
                        if (new_node->parent == this->TNULL)
                        {
                            new_node->color = 0;
                            return (NULL);
                        }
                        if (new_node->parent->parent == this->TNULL)
                            return (NULL);
                        this->balance_after_insert(new_node);
                        return (new_node);
                    }
                    void    deleteNode(key_type key) {

                        node    *z = this->TNULL;
                        node    *x, *y;
                        node    *new_node = this->root;

                        while (new_node != this->TNULL)
                        {
                            if (!this->_comp(new_node->val.first, key) && !this->_comp(key, new_node->val.first))
                                z = new_node;
                            if (!this->_comp(key, new_node->val.first))
                                new_node = new_node->right;
                            else
                                new_node = new_node->left;
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
                            this->rbTransplant(z, z->right);
                        } 
                        else if (z->right == this->TNULL)
                        {
                            x = z->left;
                            this->rbTransplant(z, z->left);
                        }
                        else
                        {
                            y = this->left_most(z->right);
                            y_original_color = y->color;
                            x = y->right;
                            if (y->parent == z)
                                x->parent = y;
                            else
                            {
                                this->rbTransplant(y, y->right);
                                y->right = z->right;
                                y->right->parent = y;
                            }
                            this->rbTransplant(z, y);
                            y->left = z->left;
                            y->left->parent = y;
                            y->color = z->color;
                        }
                        delete z;
                        if (y_original_color == 0)
                            this->balance_after_delete(x);
                    }
        };

    //RELATIONAL OPERATORS

    template <class Key, class T, class Compare, class Alloc>
        bool operator==(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs) { return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
	template <class Key, class T, class Compare, class Alloc>
        bool operator<(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs) { return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }
	template <class Key, class T, class Compare, class Alloc>
        bool operator!=(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs) { return (!(lhs == rhs)); }
	template <class Key, class T, class Compare, class Alloc>
        bool operator<=(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs) { return (!(rhs < lhs)); }
	template <class Key, class T, class Compare, class Alloc>
        bool operator>(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs) { return (rhs < lhs); }
	template <class Key, class T, class Compare, class Alloc>
        bool operator>=(const map<Key, T, Compare, Alloc> & lhs, const map<Key, T, Compare, Alloc> & rhs) { return (!(lhs < rhs)); }

    template <class Key, class T, class Compare, class Alloc>
        void swap(map<Key, T, Compare, Alloc> &lhs, map<Key, T, Compare, Alloc> &rhs) { lhs.swap(rhs); }
}

#endif