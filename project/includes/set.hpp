/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:07:44 by aribesni          #+#    #+#             */
/*   Updated: 2022/09/29 09:07:46 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_H
# define SET_H

# include <functional>
# include <memory>

namespace ft {

    template < class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> >
        class set {

            public :

            //MEMBER TYPES
                
                typedef Key                                     key_type;
                typedef Key                                     value_type;
                typedef std::size_t                             size_type;
                typedef std::ptrdiff_t                          difference_type;
                typedef Compare                                 key_compare;
                typedef Compare                                 value_compare;
                typedef Allocator                               allocator_type;
                typedef value_type&                             reference;
                typedef const value_type&                       const_reference;
                typedef value_type*                             pointer;
                typedef const value_type*                       const_pointer;
                typedef ft::SetIterator<value_type>             iterator;
                typedef ft::SetIterator<const value_type>       const_iterator;
                typedef ft::SetReverseIterator<iterator>        reverse_iterator;
                typedef ft::SetReverseIterator<const_iterator>  const_reverse_iterator;

            //MEMBER FUNCTIONS

                //Constructors
                explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {}
                template <class InputIterator>
                    set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {}
                set(const set& x) {}

                //Destructor
                ~set(void) {}

                //Operators
                set&    operator=(const set& x) {}

                //Iterators
                iterator                begin(void) {}
                const_iterator          begin(void) const {}
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

                //Modifiers
                pair<iterator, bool>
                    insert(const value_type& val) {}
                iterator    insert(iterator position, const value_type& val) {}
                template <class InputIterator>
                    void    insert(InputIterator first, InputIterator last) {}
                void        erase(iterator position) {}
                size_type   erase(const value_type& val) {}
                void        erase(iterator first, iterator last) {}
                void        swap(set& x) {}
                void        clear(void) {}

                //Observers
                key_compare     key_comp(void) const {}
                value_compare   value_comp(void) const {}

                //Operations
                iterator                    find(const value_type& val) const {}
                size_type                   count(const value_type& val) const {}
                iterator                    lower_bound(const value_type& val) const {}
                iterator                    upper_bound(const value_type& val) const {}
                pair<iterator, iterator>    equal_range(const value_type& val) const {}

                //Allocator
                allocator_type  get_allocator(void) const {}
        };
}

#endif