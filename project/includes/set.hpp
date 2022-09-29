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


        };
}

#endif