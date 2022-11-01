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

# include "utils.hpp"

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
                typedef typename iterator_traits<Iterator>::difference_type      difference_type;
                typedef typename iterator_traits<Iterator>::pointer              pointer;
                typedef typename iterator_traits<Iterator>::reference            reference;

            //MEMBER FUNCTIONS

                //Constructors
                reverse_iterator(void) : _elem(NULL) {};
                explicit    reverse_iterator(iterator_type it) : _elem(it) {}
                template <class Iter>
                    reverse_iterator(const reverse_iterator<Iter>& rev_it) : _elem(rev_it.base()) {}
                

                iterator_type   base(void) const { return (this->_elem); }

                //Operators
                reference           operator*(void) const {
                    
                    Iterator    tmp = this->_elem;
                    return *(--tmp);
                }
                reverse_iterator&   operator=(const reverse_iterator & x) { this->_elem = x.base(); return (*this); }
                reverse_iterator    operator+(difference_type n) const { return reverse_iterator(this->base() - n); }
                reverse_iterator&   operator++(void) { --this->_elem; return (*this); }
                reverse_iterator    operator++(int) {

                    reverse_iterator    tmp = *this;
                    --this->_elem;
                    return (tmp);
                }
                reverse_iterator&   operator+=(difference_type n) { this->_elem -= n; return (*this); }
                reverse_iterator    operator-(difference_type n) const { return (reverse_iterator(this->base() + n)); }
                reverse_iterator&   operator--(void) { ++this->_elem; return (*this); }
                reverse_iterator    operator--(int) {

                    reverse_iterator    tmp = *this;
                    ++this->_elem;
                    return (tmp); 
                }
                reverse_iterator&   operator-=(difference_type n) { this->_elem += n; return (*this); }
                pointer             operator->(void) const { return &(operator*()); }
                reference           operator[](difference_type n) const { return (this->_elem[- n - 1]); }
            
            private :

            //MEMBER TYPES

                iterator_type    _elem;

        };
        template <class T>
            class input_iterator : public ft::iterator<std::input_iterator_tag, T> {

            public :

                typedef typename ft::iterator< std::input_iterator_tag, T >::iterator_category iterator_category;
                typedef typename ft::iterator< std::input_iterator_tag, T >::value_type value_type;
                typedef typename ft::iterator< std::input_iterator_tag, T >::difference_type difference_type;
                typedef typename ft::iterator< std::input_iterator_tag, T >::pointer pointer;
                typedef typename ft::iterator< std::input_iterator_tag, T >::reference reference;

                input_iterator(pointer ptr = 0) : _elem(ptr) {}
                input_iterator(const input_iterator& other) : _elem(other.ptr) {}
                template <class diff>
                    input_iterator(const input_iterator< diff >& it) : _elem(it.base()) {}

                input_iterator& operator++()
                {
                    ++_elem;
                    return (*this);
                }
                input_iterator operator++(int)
                {
                    input_iterator tmp = *this;
                    ++(*this);
                    return (tmp);
                }
                bool operator==(const input_iterator< T >& other) {return ( _elem == other._elem); }
                bool operator!=(const input_iterator< T >& other) {return ( _elem != other._elem); }
                reference operator*() const { return (*_elem); }
                pointer operator->() const { return &(operator*()); }
                pointer const& base() const { return (_elem); }
            
            private :

                pointer _elem;
        };
        template <class T>
            class forward_iterator : public ft::iterator<std::forward_iterator_tag, T> {
            
            public :

                typedef typename ft::iterator< std::forward_iterator_tag, T >::iterator_category iterator_category;
                typedef typename ft::iterator< std::forward_iterator_tag, T >::value_type value_type;
                typedef typename ft::iterator< std::forward_iterator_tag, T >::difference_type difference_type;
                typedef typename ft::iterator< std::forward_iterator_tag, T >::pointer pointer;
                typedef typename ft::iterator< std::forward_iterator_tag, T >::reference reference;

                forward_iterator(pointer ptr = 0) : _elem(ptr) {}
                forward_iterator(const forward_iterator& other) : _elem(other.ptr) {}
                template <class diff>
                    forward_iterator(const forward_iterator< diff >& it) : _elem(it.base()) {}

                forward_iterator& operator++()
                {
                    ++_elem;
                    return (*this);
                }
                forward_iterator operator++(int)
                {
                    forward_iterator tmp = *this;
                    ++(*this);
                    return (tmp);
                }
                bool operator==(const forward_iterator< T >& other) { return (_elem == other._elem); }
                bool operator!=(const forward_iterator< T >& other) { return (_elem != other._elem); }
                reference operator*() const { return (*_elem); }
                pointer operator->() const { return &(operator*()); }
                forward_iterator& operator--()
                {
                    --_elem;
                    return (*this);
                }
                forward_iterator operator--(int)
                {
                    forward_iterator tmp = *this;
                    --(*this);
                    return (tmp);
                }
                pointer const& base() const { return _elem; }

                private :
                    
                    pointer _elem;
        };
        template <class T>
            class bidirectional_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> {
            
            public :

                typedef typename ft::iterator< std::bidirectional_iterator_tag, T >::iterator_category iterator_category;
                typedef typename ft::iterator< std::bidirectional_iterator_tag, T >::value_type value_type;
                typedef typename ft::iterator< std::bidirectional_iterator_tag, T >::difference_type difference_type;
                typedef typename ft::iterator< std::bidirectional_iterator_tag, T >::pointer pointer;
                typedef typename ft::iterator< std::bidirectional_iterator_tag, T >::reference reference;

                bidirectional_iterator(pointer ptr = 0) : _elem(ptr) {}
                bidirectional_iterator(const bidirectional_iterator& other) : _elem(other._elem) {}
                template <class diff>
                bidirectional_iterator(const bidirectional_iterator< diff >& it) : _elem(it.base()) {}

                bidirectional_iterator& operator++()
                {
                    ++_elem;
                    return (*this);
                }
                bidirectional_iterator operator++(int)
                {
                    bidirectional_iterator tmp = *this;
                    ++(*this);
                    return (tmp);
                }
                bool operator==(const bidirectional_iterator< T >& other) { return (_elem == other._elem); }
                bool operator!=(const bidirectional_iterator< T >& other) { return (_elem != other._elem); }
                reference operator*() const { return (*_elem); }
                pointer operator->() const { return &(operator*()); }
                bidirectional_iterator& operator--()
                {
                    --_elem;
                    return (*this);
                }
                bidirectional_iterator operator--(int)
                {
                    bidirectional_iterator tmp = *this;
                    --(*this);
                    return (tmp);
                }
                pointer const& base() const { return (_elem); }
                
                private :
                
                    pointer _elem;
        };
        template <class T>
            class random_access_iterator: public ft::iterator< std::random_access_iterator_tag, T > {

                public :

                    typedef typename ft::iterator< std::random_access_iterator_tag, T >::iterator_category  iterator_category;
                    typedef typename ft::iterator< std::random_access_iterator_tag, T >::value_type         value_type;
                    typedef typename ft::iterator< std::random_access_iterator_tag, T >::difference_type    difference_type;
                    typedef typename ft::iterator< std::random_access_iterator_tag, T >::pointer            pointer;
                    typedef typename ft::iterator< std::random_access_iterator_tag, T >::reference          reference;
                
                    random_access_iterator(pointer ptr = 0) : _elem(ptr){};
                    random_access_iterator(const random_access_iterator< T >& it) : _elem(it._elem){};

                    operator random_access_iterator<const T>() const { return _elem; }
                    random_access_iterator& operator++()
                    {
                        ++_elem;
                        return (*this);
                    };
                    random_access_iterator operator++(int)
                    {
                        random_access_iterator tmp = *this;
                        ++(*this);
                        return (tmp);
                    };
                    reference operator*() const { return *_elem; };
                    pointer operator->() const { return &(operator*()); };
                    random_access_iterator& operator--()
                    {
                        --_elem;
                        return (*this);
                    };
                    random_access_iterator operator--(int)
                    {
                        random_access_iterator tmp = *this;
                        --(*this);
                        return (tmp);
                    };
                    random_access_iterator operator+(difference_type i) const { return random_access_iterator(_elem + i);};
                    random_access_iterator operator-(difference_type i) const { return random_access_iterator(_elem - i);};
                    random_access_iterator& operator+=(difference_type i)
                    {
                        _elem += i;
                        return (*this);
                    };
                    random_access_iterator& operator-=(difference_type i)
                    {
                        _elem -= i;
                        return (*this);
                    };
                    reference operator[](difference_type i) const { return (_elem[i]); };
                    pointer const& base() const { return _elem; };
                
                private :

                    pointer _elem;
            };

            template <class T1, class T2>
                bool operator==(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs) { return (lhs.base() == rhs.base()); }
            template <class T1, class T2>
                bool operator!=(const random_access_iterator< T1 >& lhs, const random_access_iterator< T2 >& rhs) { return (lhs.base() != rhs.base()); }
            template <class T1, class T2>
                bool operator<(const random_access_iterator< T1 > lhs, const random_access_iterator< T2 >& rhs){ return (lhs.base() < rhs.base()); }
            template <class T1, class T2>
                bool operator<=(const random_access_iterator< T1 >& lhs, const random_access_iterator< T2 >& rhs) { return (lhs.base() <= rhs.base()); }
            template <class T1, class T2>
                bool operator>(const random_access_iterator< T1 > lhs, const random_access_iterator< T2 >& rhs) { return (lhs.base() > rhs.base()); }
            template <class T1, class T2>
                bool operator>=(const random_access_iterator< T1 >& lhs, const random_access_iterator< T2 >& rhs) { return (lhs.base() >= rhs.base()); }
            template <class Iterator>
                random_access_iterator<Iterator> operator+(typename random_access_iterator<Iterator>::difference_type n, const random_access_iterator< Iterator >& it) { return random_access_iterator<Iterator>(it.base() + n); }
            template <class T1, class T2>
                typename random_access_iterator< T1 >::difference_type operator-(const random_access_iterator< T2 >& lhs, const random_access_iterator< T1 >& rhs) { return lhs.base() - rhs.base(); }

        //NON-MEMBER FUNCTION OVERLOADS

            //Relational operators
            template <class T1, class T2>
                bool    operator==(const reverse_iterator<T1>& lhs, const reverse_iterator<T2>& rhs) { return (lhs.base() == rhs.base()); }
            template <class T1, class T2>
                bool    operator!=(const reverse_iterator<T1>& lhs, const reverse_iterator<T2>& rhs) { return (lhs.base() != rhs.base()); }
            template <class T1, class T2>
                bool    operator<(const reverse_iterator<T1>& lhs, const reverse_iterator<T2>& rhs) { return (lhs.base() > rhs.base()); }
            template <class T1, class T2>
                bool    operator<=(const reverse_iterator<T1>& lhs, const reverse_iterator<T2>& rhs) { return (lhs.base() >= rhs.base()); }
            template <class T1, class T2>
                bool    operator>(const reverse_iterator<T1>& lhs, const reverse_iterator<T2>& rhs) { return (lhs.base() < rhs.base()); }
            template <class T1, class T2>
                bool    operator>=(const reverse_iterator<T1>& lhs, const reverse_iterator<T2>& rhs) { return (lhs.base() <= rhs.base()); }


            template <class Iterator>
                reverse_iterator<Iterator>  operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) { return (reverse_iterator<Iterator>(rev_it + n)); }
            template <class T1, class T2>
                typename reverse_iterator<T1>::difference_type  operator-(const reverse_iterator<T1>& lhs, const reverse_iterator<T2>& rhs) { return (rhs.base() - lhs.base()); }

}

#endif