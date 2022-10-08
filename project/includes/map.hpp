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
/*
const
class nullptr_t
{
public:
   template<class T>
   operator T*() const
      { return 0; }

   template<class C, class T>
      operator T C::*() const
      { return 0; }   

private:
   void operator&() const;

} nullptr = {};
*/
namespace ft {

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
        bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
            while (first1 != last1)
            {
                if (!(*first1 == *first2))
                    return (false);
                ++first1;
                ++first2;
            }
            return (true);
    }
    template<class InputIterator1, class InputIterator2, class BinaryPredicate>
        bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {

            while (first1 != last1)
            {
                if (!pred(*first1, *first2))
                    return (false);
                ++first1;
                ++first2;
            }
            return (true);
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
            pair(first_type& a, second_type& b) : first(a), second(b) {}

            pair&   operator=(const pair& pr) {
                
                this->first = pr.first;
                this->second = pr.second;
                return (*this);
            }
    };

    template<bool Cond, class T = void>
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
                // typedef MapIterator<value_type>                                                                 iterator;
                typedef T*                                                                                      node_ptr;

                //Constructors
                MapIterator(void) : _ptr() {}
                MapIterator(const MapIterator& src) : _ptr(src._ptr) {}
                MapIterator(const node_ptr ptr) : _ptr(ptr) {}

                ~MapIterator(void) {}

                //Operators
                reference       operator*(void) { return (this->_ptr->val); }
                pointer         operator->(void) { return (&this->_ptr->val); }
                MapIterator&    operator=(MapIterator const &rhs) { this->_ptr = rhs.getPtr(); return (*this); }
                bool            operator==(MapIterator const &rhs) { return (this->_ptr == rhs.getPtr()); }
                bool            operator!=(MapIterator const &rhs) { return (this->_ptr != rhs.getPtr()); }
                MapIterator&    operator++(void) { this->_ptr = this->next_node(this->_ptr); return (*this); }
                MapIterator     operator++(int) { MapIterator tmp = *this; this->_ptr = this->next_node(this->_ptr); return (tmp); }
                MapIterator&    operator--(void) { this->_ptr = this->previous_node(this->_ptr); return (*this); }
                MapIterator     operator--(int) { MapIterator tmp = *this; this->_ptr = this->previous_node(this->_ptr); return (tmp); }

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
    template<typename T>
        class MapConstIterator : public ft::iterator<std::bidirectional_iterator_tag, T> {

            public :

            //MEMBER TYPES

                typedef typename T::value_type                                                                      value_type;
                typedef typename ft::iterator<std::bidirectional_iterator_tag, const value_type>::iterator_category iterator_category;
                typedef typename ft::iterator<std::bidirectional_iterator_tag, const value_type>::difference_type   difference_type;
                typedef typename ft::iterator<std::bidirectional_iterator_tag, const value_type>::pointer           pointer;
                typedef typename ft::iterator<std::bidirectional_iterator_tag, const value_type>::reference         reference;
                // typedef MapConstIterator<value_type>    const_iterator;
                typedef T*                                                                                          node_ptr;

                //Constructors
                MapConstIterator(void) : _ptr() {}
                MapConstIterator(const node_ptr ptr) : _ptr(ptr) {}
                MapConstIterator(const MapConstIterator& src) : _ptr(src._ptr) {}
                MapConstIterator(const MapIterator<T>& src) : _ptr(src.getPtr()) {}

                ~MapConstIterator(void) {}

                //Operators
                reference           operator*(void) { return (this->_ptr->val); }
                pointer             operator->(void) { return (&this->_ptr->val); }
                MapConstIterator&   operator=(MapConstIterator const &rhs) { this->_ptr = rhs.getPtr(); return (*this); }
                bool                operator==(MapConstIterator const &rhs) { return (this->_ptr == rhs.getPtr()); }
                bool                operator!=(MapConstIterator const &rhs) { return (this->_ptr != rhs.getPtr()); }
                MapConstIterator&   operator++(void) { this->_ptr = this->next_node(this->_ptr); return (*this); }
                MapConstIterator    operator++(int) { MapConstIterator tmp = *this; this->_ptr = this->next_node(this->_ptr); return (tmp); }
                MapConstIterator&   operator--(void) { this->_ptr = this->previous_node(this->_ptr); return (*this); }
                MapConstIterator    operator--(int) { MapConstIterator tmp = *this; this->_ptr = this->previous_node(this->_ptr); return (tmp); }

                node_ptr        getPtr(void) const { return (this->_ptr); }

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
    template<typename IT>
        class MapReverseIterator {

            public :

            //MEMBER TYPES

                typedef typename IT::value_type         value_type;
                typedef typename IT::iterator_category  iterator_category;
                typedef typename IT::difference_type    difference_type;
                typedef typename IT::pointer            pointer;
                typedef typename IT::reference          reference;
                typedef typename IT::node_ptr           node_ptr;

                //Constructors
                MapReverseIterator(void) : _ptr() {}
                MapReverseIterator(node_ptr ptr) : _ptr(ptr) {}
                MapReverseIterator(const MapReverseIterator& src) : _ptr(src._ptr) {}
                MapReverseIterator(const IT& src) : _ptr(src.getPtr()) {}

                ~MapReverseIterator(void) {}

                //Operators
                reference           operator*(void) { return (this->_ptr->val); }
                pointer             operator->(void) { return (&this->_ptr->val); }
                MapReverseIterator& operator=(MapReverseIterator const &rhs) { this->_ptr = rhs.getPtr(); return (*this); }
                bool                operator==(MapReverseIterator const &rhs) { return (this->_ptr == rhs.getPtr()); }
                bool                operator!=(MapReverseIterator const &rhs) { return (this->_ptr != rhs.getPtr()); }
                MapReverseIterator& operator++(void) { this->_ptr = this->previous_node(this->_ptr); return (*this); }
                MapReverseIterator  operator++(int) { MapReverseIterator tmp = *this; this->_ptr = this->previous_node(this->_ptr); return (tmp); }
                MapReverseIterator& operator--(void) { this->_ptr = this->next_node(this->_ptr); return (*this); }
                MapReverseIterator  operator--(int) { MapReverseIterator tmp = *this; this->_ptr = this->next_node(this->_ptr); return (tmp); }

                node_ptr            getPtr(void) const { return (this->_ptr); }

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
                // typedef MapConstReverseIterator                             const_reverse_iterator;
                typedef ft::t_node<value_type>                                          node_ptr;

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
                iterator                begin(void) { return (iterator(this->left_most(this->root))); }
                const_iterator          begin(void) const { return (const_iterator(this->left_most(this->root))); }
                iterator                end(void) { return (iterator(this->right_most(this->root))); }
                const_iterator          end(void) const { return (const_iterator(this->right_most(this->TNULL))); }
                reverse_iterator        rbegin(void) { return (reverse_iterator(this->end()--)); }
                // const_reverse_iterator  rbegin(void) const { return (const_reverse_iterator(this->TNULL)); }
                reverse_iterator        rend(void) { return (reverse_iterator(this->begin()--)); }
                // const_reverse_iterator  rend(void) const { return (const_reverse_iterator(this->left_most(this->root))); }

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
                        it = iterator(this->insert_node(val));
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

                    node_ptr    *node = position.getPtr();
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
                iterator                                find(const key_type& k) { return (iterator(this->searchTree(this->root, k))); }
                const_iterator                          find(const key_type& k) const { return (const_iterator(this->searchTree(this->root, k))); }
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

                /*******************************************/
                //tmp functions

                void    ft_tmp(void) {

                    iterator tmp = this->begin();
                    node_ptr   *node_tmp = tmp.getPtr();
                    std::cout << "BEGIN KEY : " << node_tmp->val.first << "   ";
                    std::cout << "BEGIN DATA : " << node_tmp->val->second << "   ";
                    tmp = this->end();
                    // tmp--;
                    node_tmp = tmp.getPtr();
                    std::cout << "END KEY : " << node_tmp->val.first << "   ";
                    std::cout << "END DATA : " << node_tmp->val->second << std::endl;
                }

                /******************************************/

                private :

                    allocator_type  _alloc;
                    key_compare     _comp;
                    node_ptr         *root;
                    node_ptr         *TNULL;

                    void    init_root(const value_type& val = value_type()) {

                        node_ptr    tmp(val);
                        this->TNULL = this->_alloc.allocate(1);
                        this->root = this->_alloc.allocate(1);
                        tmp.left = this->TNULL;
                        tmp.right = this->TNULL;
                        tmp.parent = this->TNULL;
                        this->_alloc.construct(this->TNULL, tmp);
                        this->TNULL->color = 0;
                        this->root = this->TNULL;
                    }
                    void    construct(node_ptr *ptr, const value_type& val = value_type()) {

                        node_ptr    tmp(val);
                        tmp.left = this->TNULL;
                        tmp.right = this->TNULL;
                        tmp.parent = this->TNULL;
                        tmp.color = 1;
                        this->_alloc.construct(ptr, tmp);
                    }
                    node_ptr *searchTree(node_ptr *node, key_type key) const {

                        if (node == this->TNULL || key == node->val.first)
                            return (node);
                        if (key < node->val.first)
                            return (this->searchTree(node->left, key));
                        return (this->searchTree(node->right, key));
                    }
                    node_ptr *left_most(node_ptr *node) const {

                        while (node->left != node->left->left)
                            node = node->left;
                        return (node);
                    }
                    node_ptr *right_most(node_ptr *node) const {

                        while (node->right != node->right->right)
                            node = node->right;
                        return (node);
                    }
                    void    leftRotate(node_ptr *x) {

                        node_ptr *y = x->right;
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
                    void    rightRotate(node_ptr *x) {

                        node_ptr *y = x->left;
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
                    void    balance_after_delete(node_ptr *x) {

                        node_ptr *s;

                        while (x != root && x->color == 0)
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
                                    x = root;
                                }
                            }
                        }
                        x->color = 0;
                    }
                    void    rbTransplant(node_ptr *u, node_ptr *v) {

                        if (u->parent == this->TNULL)
                            root = v;
                        else if (u == u->parent->left)
                            u->parent->left = v;
                        else
                            u->parent->right = v;
                        v->parent = u->parent;
                    }
                    void    balance_after_insert(node_ptr *k) {

                        node_ptr *u;

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
                                        this->rightRotate(k);
                                    }
                                    k->parent->color = 0;
                                    k->parent->parent->color = 1;
                                    this->leftRotate(k->parent->parent);
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
                                        this->leftRotate(k);
                                    }
                                    k->parent->color = 0;
                                    k->parent->parent->color = 1;
                                    this->rightRotate(k->parent->parent);
                                }
                            }
                            if (k == this->root)
                                break ;
                        }
                        root->color = 0;
                    }
                    node_ptr* insert_node(value_type val) {

                        node_ptr *node = this->_alloc.allocate(1);
                        this->construct(node, val);
                        node_ptr *y = this->TNULL;
                        node_ptr *x = this->root;

                        while (x != this->TNULL) {
                            
                            y = x;
                            if (node->val.first < x->val.first)
                                x = x->left;
                            else
                                x = x->right;
                        }
                        node->parent = y;
                        if (y == this->TNULL)
                            this->root = node;
                        else if (node->val.first < y->val.first)
                            y->left = node;
                        else
                            y->right = node;
                        if (node->parent == this->TNULL)
                        {
                            node->color = 0;
                            return (NULL);
                        }
                        if (node->parent->parent == this->TNULL)
                            return (NULL);
                        this->balance_after_insert(node);
                        return (node);
                    }
                    void    deleteNode(key_type key) {

                        node_ptr    *z = this->TNULL;
                        node_ptr    *x, *y;
                        node_ptr    *node = this->root;

                        while (node != this->TNULL)
                        {
                            if (node->val.first == key)
                                z = node;
                            if (node->val.first <= key)
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

        //NON-MEMBER FUNCTION OVERLOADS

            template<class T>
                void    swap(T& a, T& b) {

                    T   tmp(a);

                    a = b;
                    b = tmp;
                }
}

#endif