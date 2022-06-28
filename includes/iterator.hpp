/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:18:38 by aribesni          #+#    #+#             */
/*   Updated: 2022/06/24 18:18:39 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_H
# define ITERATOR_H

# include <cstddef>
# include <iostream>

namespace ft {

    template <class Iterator> 
        class iterator_traits {
            typedef typename Iterator::value_type        value_type;
            typedef typename Iterator::difference_type   difference_type;
            typedef typename Iterator::pointer           pointer;
            typedef typename Iterator::reference         reference;
            typedef typename Iterator::iterator_category iterator_category;

        };

    template <class T>
        class iterator_traits<T*> {
            typedef T                               value_type;
            typedef ptrdiff_t                       difference_type;
            typedef T*                              pointer;
            typedef T&                              reference;
            typedef std::random_access_iterator_tag iterator_category;
        };

    template <class T>
        class iterator_traits<const T*> {
            typedef T                               value_type;
            typedef ptrdiff_t                       difference_type;
            typedef const T*                        pointer;
            typedef const T&                        reference;
            typedef std::random_access_iterator_tag iterator_category;
        };

    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
        struct iterator {
            typedef T           value_type;
            typedef Distance    difference_type;
            typedef Pointer     pointer;
            typedef Reference   reference;
            typedef Category    iterator_category;
        };
    
    template <class Iterator>
        class reverse_iterator {

            public :

            //MEMBER TYPES

                typedef iterator_traits<iterator>::value_type           value_type;
                typedef iterator_traits<iterator>::difference_type      difference_type;
                typedef iterator_traits<iterator>::pointer              pointer;
                typedef iterator_traits<iterator>::reference            reference;
                typedef iterator_traits<Iterator>::iterator_category    iterator_category;
                typedef Iterator                                        iterator_type;
            
            //MEMBER FUNCTIONS

                //Constructors
                reverse_iterator(void) : _elem(NULL) {};
                explicit    reverse_itetor(iterator_type it) : _elem(it) {};
                template <class Iter>
                    reverse_iterator(const reverse_iterator<Iter>& rev_it) : _elem(rev_it._elem) {};
                

                iterator_type   base(void) const { return (this->_elem); }

                //Operators
                reference           operator*(void) const {
                    
                    Iterator    tmp;
                    
                    tmp = *this->_elem--;
                    return (tmp);
                }
                reverse_iterator    operator+(difference_type n) const { return (this->_elem - n); }
                reverse_iterator&   operator++(void) { return (this->*_elem--); }
                reverse_iterator    operator++(void) {

                    reverse_iterator    tmp;

                    tmp = *this;
                    *this--;
                    return (tmp); 
                }
                reverse_iterator&   operator+=(difference_type n) { return (*this->_elem - n); }
                reverse_iterator    operator-(difference_type n) const { return (this->_elem + n); }
                reverse_iterator&   operator--(void) { return (this->*_elem++); }
                reverse_iterator    operator--(void) {

                    reverse_iterator    tmp;

                    tmp = *this;
                    *this++;
                    return (tmp); 
                }
                reverse_iterator&   operator-=(difference_type n) { return (*this->_elem + n); }
                pointer             operator->(void) const { return &(operator*()); }
                reference           operator[](difference_type n) const { return (*this->_elem - n - 1); }
            
            private :

            //MEMBER TYPES

                Iterator    _elem;

        };
}

#endif