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
# include "iterator.hpp"
# include "red_black_tree.hpp"

namespace ft {

    //RED BLACK TREE
    // typedef struct          s_node {

    //     struct s_node*      parent;
    //     struct s_node*      left;
    //     struct s_node*      right;
    //     enum {red, black}   colour;
    // }                       t_node;

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
            pair(const first_type& a, const second_type& b) : first(a), second(b) {}

            pair&   operator=(const pair& pr) { this->first = pr.first; this->second = pr.second; return (*this); }

    };

    //MAKE PAIR
    template< class T1, class T2 >
        pair<T1, T2>    make_pair(T1 x, T2 y) { return (pair<T1, T2>(x, y)); }

    //MAP
    template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
        class map {
            
            public :

            //MAP ITERATORS
                template <typename T>
                    class MapIterator {
                        
                        //MEMBER TYPES

                            typedef T                               value_type;
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
                            reference   operator*(void) { return (this->_ptr->data); }
                            pointer     operator->(void) { return ( &this->_ptr->data); }
                            iterator&   operator=(iterator const &rhs) { this->_ptr = rhs.getPtr(); return (*this); }
                            bool        operator==(iterator const &rhs) { return (this->_ptr == rhs.getPtr()); }
                            bool        operator!=(iterator const &rhs) { return (this->_ptr != rhs.getPtr()); }
                            iterator&   operator++(void) { this->_ptr = _rb_tree.next_node(); return (*this); }
                            iterator    operator++(int) { iterator tmp = *this; this->_ptr = _rb_tree.next_node(); return (tmp); }
                            iterator&   operator--(void) { this->_ptr = _rb_tree.previous_node(); return (*this); }
                            iterator    operator--(int) { iterator tmp = *this; this->_ptr = _rb_tree.previous_node(); return (tmp); }

                            node_ptr    getPtr(void) const { return (this->_ptr); }

                        private :

                        //MEMBER TYPES

                            node_ptr    _ptr;
                };

            //MEMBER TYPES

                typedef Key                                                     key_type;
                typedef T                                                       mapped_type;
                typedef ft::pair<const Key, T>                                  value_type;
                typedef std::size_t                                             size_type;
                typedef std::ptrdiff_t                                          difference_type;
                typedef Compare                                                 key_compare;
                typedef Allocator                                               allocator_type;
                typedef value_type&                                             reference;
                typedef const value_type&                                       const_reference;
                typedef value_type*                                             pointer;
                typedef const value_type*                                       const_pointer;
                typedef ft::MapIterator<value_type>                             iterator;
                typedef ft::MapIterator<const value_type>                       const_iterator;
                typedef ft::reverse_iterator<iterator>                          reverse_iterator;
                typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;
                typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
                typedef size_t                                                  size_type;

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
                explicit    map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _rb_tree(new RedBlackTree()), _ptr(_rb_tree.minimum()), _alloc(alloc) {}
                template <class InputIterator>
                    map(InputIterator first, InputIterator last, const key_compare& comp = key_compare()) {}
                map(const map& x) {}

                //Destructor
                ~map(void) {}

                //Iterators
                iterator                begin(void) { return (iterator(this->_rb_tree.minimum)); }
                const_iterator          begin(void) const { return (const_iterator(this->_rb_tree.minimum)); }
                iterator                end(void) { return (iterator(this->_rb_tree.maximum)); }
                const_iterator          end(void) const { return (const_iterator(this->_rb_tree.maximum)); }
                reverse_iterator        rbegin(void) { return (reverse_iterator(this->end())); }
                const_reverse_iterator  rbegin(void) const { return (const_reverse_iterator(this->end())); }
                reverse_iterator        rend(void) { return (reverse_iterator(this->begin())); }
                const_reverse_iterator  rend(void) const { return (const_reverse_iterator(this->begin())); }

                //Capacity
                bool        empty(void) const { return (this->size == 0 ? true : false;) }
                size_type   size(void) const {

                    size_type   n = 0;
                    for (iterator it = this->begin(); it != this->end(); it++)
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
                        it = iterator(this->_rb_tree.insert(val));
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
                    this->_rb_tree.deleteNode(node->key);
                }
                size_type               erase(const key_type& k) {

                    if (this->find(k))
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
                void                    swap(map& x) {}
                void                    clear(void) {}

                //Observers
                key_compare     key_comp(void) const { return (key_compare()); }
                value_compare   value_comp(void) const { return (value_compare(_comp)); }

                //Operations
                iterator                                find(const key_type& k) { return (iterator(_rb_tree.searchTree(k))); }
                const_iterator                          find(const key_type& k) const { return (const_iterator(_rb_tree.searchTree(k))); }
                size_type                               count(const key_type& k) const { return (this->find(k) != this->end() ? 1 : 0); }
                iterator                                lower_bound(const key_type& k) {

                    iterator    it;

                    it = this->begin();
                    while (key_compare(it.first, k) == true && it != this->end())
                        i++;
                    return (it);
                }
                const_iterator                          lower_bound(const key_type& k) const {
            
                    const_iterator    it;

                    it = this->begin();
                    while (key_compare(it.first, k) == true && it != this->end())
                        i++;
                    return (it);
                }
                iterator                                upper_bound(const key_type& k) {

                    iterator    it;

                    it = this->begin();
                    while (key_compare(it.first, k) == false && it != this->end())
                        i++;
                    return (it);
                }
                const_iterator                          upper_bound(const key_type& k) const {

                    const_iterator    it;

                    it = this->begin();
                    while (key_compare(it.first, k) == false && it != this->end())
                        i++;
                    return (it);
                }
                pair<const_iterator, const_iterator>    equal_range(const key_type& k) const {}
                pair<iterator, iterator>                equal_range(const key_type& k) {}

                //Allocator
                allocator_type  get_allocator(void) const {return (allocator_type()); }

                private :

                    RedBlackTree    _rb_tree;
                    pointer         _ptr;
                    allocator_type  _alloc;
                    key_compare     _comp;
        };
}

#endif