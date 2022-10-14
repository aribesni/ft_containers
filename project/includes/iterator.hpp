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

            public :

                typedef typename Iterator::value_type        value_type;
                typedef typename Iterator::difference_type   difference_type;
                typedef typename Iterator::pointer           pointer;
                typedef typename Iterator::reference         reference;
                typedef typename Iterator::iterator_category iterator_category;
        };

    template <class T>
        class iterator_traits<T*> {

            public :

                typedef T                               value_type;
                typedef ptrdiff_t                       difference_type;
                typedef T*                              pointer;
                typedef T&                              reference;
                typedef std::random_access_iterator_tag iterator_category;
        };

    template <class T>
        class iterator_traits<const T*> {

            public :

                typedef T                               value_type;
                typedef ptrdiff_t                       difference_type;
                typedef const T*                        pointer;
                typedef const T&                        reference;
                typedef std::random_access_iterator_tag iterator_category;
        };

    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
        class iterator {

            public :

                typedef T           value_type;
                typedef Distance    difference_type;
                typedef Pointer     pointer;
                typedef Reference   reference;
                typedef Category    iterator_category;
        };
    
    template <class Iterator>
        class reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category,
        typename iterator_traits<Iterator>::value_type, typename iterator_traits<Iterator>::difference_type,
        typename iterator_traits<Iterator>::pointer, typename iterator_traits<Iterator>::reference> {

            public :

            //MEMBER TYPES

                typedef Iterator                                           iterator_type;
                // typedef iterator_traits<iterator>::value_type           value_type;
                typedef typename iterator_traits<Iterator>::difference_type      difference_type;
                typedef typename iterator_traits<Iterator>::pointer              pointer;
                typedef typename iterator_traits<Iterator>::reference            reference;
                // typedef iterator_traits<iterator>::iterator_category    iterator_category;

            //MEMBER FUNCTIONS

                //Constructors
                reverse_iterator(void) : _elem(NULL) {};
                explicit    reverse_iterator(iterator_type it) : _elem(it) {};
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
                reverse_iterator    operator++(int) {

                    reverse_iterator    tmp;

                    tmp = *this;
                    *this--;
                    return (tmp);
                }
                reverse_iterator&   operator+=(difference_type n) { return (*this->_elem - n); }
                reverse_iterator    operator-(difference_type n) const { return (this->_elem + n); }
                reverse_iterator&   operator--(void) { return (this->*_elem++); }
                reverse_iterator    operator--(int) {

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
        
        template <typename T>
            class regular_iterator {
                
                public :

                    typedef T                               value_type;
                    typedef std::ptrdiff_t                  difference_type;
                    typedef value_type*                     pointer;
                    typedef value_type&                     reference;
                    typedef std::random_access_iterator_tag iterator_category;
                    typedef regular_iterator<value_type>    iterator;

                    regular_iterator(void) : _elem(pointer()) {}
                    regular_iterator(const T& src) : _elem(src) {}
                    regular_iterator(pointer ptr) : _elem(ptr) {}

                    reference   operator*(void) const { return (*this->_elem); }
                    reference   operator[](difference_type n) const { return (*this->_elem + n); }

                    iterator    &operator=(iterator const &rhs) { *this->_elem = *rhs._elem; return (*this); }
                    iterator    &operator+(difference_type n) { this->_elem += n; return (*this); } // keep an eye on this one
                    iterator    &operator++(void) { ++this->_elem; return (*this); }
                    iterator    operator++(int) { iterator tmp = *this; ++this->_elem; return (tmp); }
                    iterator    operator+=(difference_type n) { this->_elem += n; return (*this); }

                    // pointer base() const { return (this->_elem); }

                    pointer     _elem; // put this in private and create a getElem function
            };


        //NON-MEMBER FUNCTION OVERLOADS

            //Relational operators
            template <class Iterator>
                bool    operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs._elem == rhs._elem); }
            template <class Iterator>
                bool    operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs._elem != rhs._elem); };
            template <class Iterator>
                bool    operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs._elem > rhs._elem); };
            template <class Iterator>
                bool    operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs._elem >= rhs._elem); };
            template <class Iterator>
                bool    operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs._elem < rhs._elem); };
            template <class Iterator>
                bool    operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs._elem <= rhs._elem); };


            template <class Iterator>
                reverse_iterator<Iterator>                              operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) { return (rev_it._elem - n); }
            template <class Iterator>
                typename reverse_iterator<Iterator>::difference_type    operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) { return (lhs._elem - rhs._elem); }


            template <class Iterator>
                bool    operator==(const regular_iterator<Iterator>& lhs, const regular_iterator<Iterator>& rhs) { return (lhs._elem == rhs._elem); }
            template <class Iterator>
                bool    operator!=(const regular_iterator<Iterator>& lhs, const regular_iterator<Iterator>& rhs) { return (lhs._elem != rhs._elem); };
            template <class Iterator>
                bool    operator<(const regular_iterator<Iterator>& lhs, const regular_iterator<Iterator>& rhs) { return (lhs._elem < rhs._elem); };
            template <class Iterator>
                bool    operator<=(const regular_iterator<Iterator>& lhs, const regular_iterator<Iterator>& rhs) { return (lhs._elem <= rhs._elem); };
            template <class Iterator>
                bool    operator>(const regular_iterator<Iterator>& lhs, const regular_iterator<Iterator>& rhs) { return (lhs._elem > rhs._elem); };
            template <class Iterator>
                bool    operator>=(const regular_iterator<Iterator>& lhs, const regular_iterator<Iterator>& rhs) { return (lhs._elem >= rhs._elem); };

            // template<typename Iterator>
            // regular_iterator<Iterator>
            //     operator+(typename regular_iterator<Iterator>::difference_type n,
            //         regular_iterator<Iterator>& i)
            //     {
            //         return i.base() + n;
            //     }
}

#endif