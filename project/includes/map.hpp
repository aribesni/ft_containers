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
    typedef struct          s_node {

        struct s_node*      parent;
        struct s_node*      left;
        struct s_node*      right;
        enum {red, black}   colour;
    }                       t_node;

    template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
        class map {
            
            public :

            //MEMBER TYPES

                typedef Key                                                     key_type;
                typedef T                                                       mapped_type;
                typedef std::pair<const Key, T>                                 value_type;
                typedef std::size_t                                             size_type;
                typedef std::ptrdiff_t                                          difference_type;
                typedef Compare                                                 key_compare;
                typedef Allocator                                               allocator_type;
                typedef value_type&                                             reference;
                typedef const value_type&                                       const_reference;
                typedef value_type*                                             pointer;
                typedef const value_type*                                       const_pointer;
                typedef ft::regular_iterator<value_type>                        iterator;
                typedef ft::regular_iterator<const value_type>                  const_iterator;
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
                explicit    map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _ptr(_rb_tree.minimum()), _alloc(alloc) {}
                template <class InputIterator>
                    map(InputIterator first, InputIterator last, const key_compare& comp = key_compare()) {}
                map(const map& x) {}

                //Destructor
                ~map(void) {}

                //Iterators
                iterator                begin(void) { return (this->_ptr); }
                const_iterator          begin(void) const { return (this->_ptr); }
                iterator                end(void) {}
                const_iterator          end(void) const {}
                reverse_iterator        rbegin(void) {}
                const_reverse_iterator  rbegin(void) const {}
                reverse_iterator        rend(void) {}
                const_reverse_iterator  rend(void) const {}

                //Capacity
                bool        empty(void) const {}
                size_type   size(void) const {}
                size_type   max_size(void) const {}

                //Element access
                mapped_type&    operator[] (const key_type& k) {}

                //Modifiers
                pair<iterator, bool>    insert(const value_type& val) {}
                iterator                insert(iterator position, const value_type& val) {}
                template<class InputIterator>
                    void    insert(InputIterator first, InputIterator last) {}
                void                    erase(iterator position) {}
                size_type               erase(const key_type& k) {}
                void                    erase(iterator first, iterator last) {}
                void                    swap(map& x) {}
                void                    clear(void) {}

                //Observers
                key_compare     key_comp(void) const {}
                value_compare   value_comp(void) const {}

                //Operations
                iterator                                find(const key_type& k) {}
                const_iterator                          find(const key_type& k) const {}
                size_type                               count(const key_type& k) const {}
                iterator                                lower_bound(const key_type& k) {}
                const_iterator                          lower_bound(const key_type& k) const {}
                iterator                                upper_bound(const key_type& k) {}
                const_iterator                          upper_bound(const key_type& k) const {}
                pair<const_iterator, const_iterator>    equal_range(const key_type& k) const {}
                pair<iterator, iterator>                equal_range(const key_type& k) {}

                //Allocator
                allocator_type  get_allocator(void) const {}

                private :

                    RedBlackTree    _rb_tree;
                    pointer         _ptr;
                    allocator_type  _alloc;
        };
}

#endif