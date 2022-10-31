/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:54:27 by aribesni          #+#    #+#             */
/*   Updated: 2022/06/14 16:54:28 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "iterator.hpp"
# include "utils.hpp"

# include <vector>
# include <iostream>
# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>

namespace ft {

    template< class T, class Alloc = std::allocator<T> >
        class vector {

            public :

            //MEMBER TYPES

                typedef T                                                   value_type;
                typedef Alloc                                               allocator_type;
                typedef value_type&                                         reference;
                typedef const value_type&                                   const_reference;
                typedef value_type*                                         pointer;
                typedef const value_type*                                   const_pointer;
                typedef ft::random_access_iterator<value_type>              iterator;
                typedef ft::random_access_iterator<const value_type>        const_iterator;
                typedef ft::reverse_iterator<iterator>                      reverse_iterator;
                typedef ft::reverse_iterator<const_iterator>                const_reverse_iterator;
                typedef typename iterator_traits<iterator>::difference_type difference_type;
                typedef size_t                                              size_type;

            //MEMBER FUNCTIONS

                //Contructors
                explicit    vector(const allocator_type& alloc = allocator_type()) {
                    
                    this->_alloc = alloc;
                    this->_ptr = this->_alloc.allocate(0);
                    this->_size = 0;
                    this->_capacity = 0;
                }
                explicit    vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
                    
                    this->_alloc = alloc;
                    this->_ptr = this->_alloc.allocate(n);
                    this->_size = n;
                    this->_capacity = n;

                    for (size_type i = 0; i < n; i++)
                        this->_alloc.construct(this->_ptr + i, val);
                }
                template <class InputIterator>
                    vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {
                        
                    size_type       i = 0;
                    InputIterator   tmp = first;
                    while (tmp != last)
                    {
                        tmp++;
                        i++;
                    }
                    this->_alloc = alloc;
                    this->_ptr = this->_alloc.allocate(i);
                    this->_capacity = i;
                    this->_size = i;
                    i = 0;
                    while (first != last)
                    {
                        this->_alloc.construct(this->_ptr + i, *first);
                        first++;
                        i++;
                    }
                }
                vector(const vector& x) {

                    this->_alloc = x._alloc;
                    this->_size = x._size;
                    this->_capacity = x._capacity;
                    this->_ptr = this->_alloc.allocate(this->_capacity);

                    for (size_type i = 0; i < this->_size; i++)
                        this->_alloc.construct(this->_ptr + i, x[i]);
                }

                //Destructor
                ~vector(void) {

                    for (size_type i = 0; i < this->_size; i++)
                        this->_alloc.destroy(this->_ptr + i);
                    this->_alloc.deallocate(this->_ptr, this->_capacity);
                }

                //Assign
                vector& operator=(const vector &x) {

                    if (this == &x)
                        return (*this);
                    for (size_type i = 0; i < this->_size; i++)
                        this->_alloc.destroy(this->_ptr + i);
                    if (x._size > this->_capacity)
                    {
                        this->_alloc.deallocate(this->_ptr, this->_capacity);
                        this->_capacity = x._size;
                        this->_ptr = this->_alloc.allocate(this->_capacity);
                    }
                    this->_size = x._size;
                    for (size_type i = 0; i < this->_size; i++)
                        this->_alloc.construct(this->_ptr + i, x[i]);
                    return (*this);
                }

                //Iterators
                iterator                begin(void) { return (iterator(this->_ptr)); }
                const_iterator          begin(void) const { return (iterator(this->_ptr)); }
                iterator                end(void) { return (iterator(this->_ptr + this->_size)); }
                const_iterator          end(void) const { return (const_iterator(this->_ptr + this->_size)); }
                reverse_iterator        rbegin(void) { return (reverse_iterator(this->end())); }
                const_reverse_iterator  rbegin(void) const { return (const_reverse_iterator(this->end())); }
                reverse_iterator        rend(void) { return (reverse_iterator(this->begin())); }
                const_reverse_iterator  rend(void) const { return (const_reverse_iterator(this->begin())); }

                //Capacity
                size_type   size(void) const { return (this->_size); }
                size_type   max_size(void) const { return (this->_alloc.max_size()); }
                void        resize(size_type n, value_type val = value_type()) {

                    if (n < this->_size)
                    {
                        for (size_type i = n; i < this->_size; i++)
                            this->_alloc.destroy(this->_ptr + i);
                    }
                    else if (n > this->_size && n <= this->_capacity)
                    {
                        while (n >= this->_size - 1)
                        {
                            this->push_back(val);
                            n--;
                        }
                    }
                    else if (n > this->_capacity)
                    {
                        this->reserve(n);
                        for (size_type i = _size; i < n; i++)
                            this->_alloc.construct(this->_ptr + i, val);
                    }
                    this->_size = n;
                }
                size_type   capacity(void) const { return (this->_capacity); }
                bool        empty(void) const { return (this->_size == 0 ? true : false); }
                void        reserve(size_type n) {
                    
                    if (n > this->_alloc.max_size())
                        throw std::length_error("vector::reserve");
                    if (n > _capacity)
                    {
                        pointer new_vector = this->_alloc.allocate(n);

                        for (size_type i = 0; i < this->_size && i < n; i++)
                        {
                            this->_alloc.construct(new_vector + i, this->_ptr[i]);
                            this->_alloc.destroy(this->_ptr + i);
                        }
                        this->_alloc.deallocate(this->_ptr, this->_capacity);
                        this->_capacity = n;
                        this->_ptr = new_vector;
                    }
                }

                //Element access
                reference       operator[](size_type n) { return (*(this->_ptr + n)); }
                const_reference operator[](size_type n) const { return (*(this->_ptr + n)); }
                reference       at(size_type n) {

                    if (n >= this->_size)
                        throw std::out_of_range("Out of range");
                    return (this->_ptr[n]);
                }
                const_reference at(size_type n) const {

                    if (n >= this->_size)
                        throw std::out_of_range("Out of range");
                    return (this->_ptr[n]);
                }
                reference       front(void) { return (this->_ptr[0]); }
                const_reference front(void) const { return (this->_ptr[0]); }
                reference       back(void) { return (this->_ptr[this->_size - 1]); }
                const_reference back(void) const { return (this->_ptr[this->_size - 1]); }

                //Modifiers
                template <class InputIterator>
                    void    assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {

                        this->clear();
                        for (InputIterator it = first; it != last; it++)
                            this->push_back(*it);
                    }
                void        assign(size_type n, const value_type& val) {
  
                    this->clear();
                    for (size_type tmp = 0; tmp < n; tmp++)
                        this->push_back(val);
                }
                void        push_back(const value_type& val) {
                
                    if (this->_size + 1 > this->_capacity)
                    {
                        if (this->_size > 0)
                            this->reserve(this->_size * 2);
                        else
                            this->reserve(1);
                    }
                    this->_alloc.construct(this->_ptr + this->_size, val);
                    this->_size++;
                }
                void        pop_back(void) {

                    if (this->_size)
                    {
                        this->_alloc.destroy(this->_ptr + this->_size - 1);
                        this->_size--;
                    }
                }
                iterator    insert(iterator position, const value_type& val) {
                    
                    difference_type diff = position - this->begin();
                    this->insert(position, 1, val);
                    return (this->begin() + diff);
                }
                void        insert(iterator position, size_type n, const value_type& val) {

                    size_type diff = position - this->begin();
                    
                    this->reserve(this->_size + n);
                    for (size_type i = 0; i < n; i++)
                        this->_alloc.construct(this->_ptr + this->_size + i, val);
                    for (int i = this->_size - 1; i >= 0 && i >= (int)diff; i--)
                        this->_ptr[i + n] = this->_ptr[i];
                    for (size_type i = diff; i < diff + n; i++)
                        this->_ptr[i] = val;
                    this->_size += n;
                }
                template <class InputIterator>
                    void    insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {

                        size_type   diff = position - this->begin();
                        size_type   n = 0;

                        for (InputIterator tmp = first; tmp != last && n <= this->max_size(); tmp++)
                            n++;
                        if (this->_size + n > this->_capacity)
                        {
                            if (this->_size + n > this->_size * 2)
                                this->reserve(this->_size + n);
                            else if (this->_size > 0)
                                this->reserve(this->_size * 2);
                            else
                                this->reserve(1);
                        }
                        for (size_type i = 0; i < n; i++)
                            this->_alloc.construct(this->_ptr + this->_size + i, *first);
                        for (int i = this->_size - 1; i >= 0 && i >= (int)diff; i--)
                            this->_ptr[i + n] = this->_ptr[i];
                        for (size_type i = diff; i < diff + n; i++)
                            this->_ptr[i] = *first++;
                        this->_size += n;
                }
                iterator    erase(iterator position) {

                    vector	tmp(position + 1, this->end());

                    for (size_type i = 0; i < tmp.size(); i++)
                        this->pop_back();
                    this->pop_back();
                    for (iterator it = tmp.begin(); it != tmp.end(); it++)
                        this->push_back(*it);
                    return (position);
                }
                iterator    erase(iterator first, iterator last) {

                    difference_type diff = last - first;

                    while (diff-- > 0)
                        this->erase(first);
                    return (first);
                }
                void        swap(vector& x) {

                    ft::swap(this->_ptr, x._ptr);
                    ft::swap(this->_capacity, x._capacity);
                    ft::swap(this->_size, x._size);
                    ft::swap(this->_alloc, x._alloc);
                }
                void        clear(void) {

                    for (size_type i = 0; i < this->_size; i++)
                        this->_alloc.destroy(this->_ptr + i);
                    this->_size = 0;
                }

                //Allocator
                allocator_type  get_allocator(void) const { return (this->_alloc); }

            private :

            //MEMBER TYPES

                pointer         _ptr;
                size_t          _capacity;
                size_t          _size;
                allocator_type  _alloc;

        }; //VECTOR

    //NON-MEMBER FUNCTION OVERLOADS

        template <class T, class Alloc>
            bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

                if (lhs.size() != rhs.size())
                    return (false);
                if (lhs.empty() && rhs.empty())
                    return (true);
                typename ft::vector<T>::const_iterator first1 = lhs.begin();
                typename ft::vector<T>::const_iterator first2 = rhs.begin();
                while (first1 != lhs.end())
                {
                    if (first2 == rhs.end() || *first1 != *first2)
                        return (false);
                    ++first1;
                    ++first2;
                }
                return (true);
            }
        template <class T, class Alloc>
            bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

                if (!(lhs == rhs))
                    return (true);
                return (false);
            }
        template <class T, class Alloc>
            bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

                if ((lhs.empty() && !rhs.empty()))
                    return (true);
                if ((lhs.empty() && rhs.empty()))
                    return (false);
                return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
            }
        template <class T, class Alloc>
            bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

                if ((lhs.empty() && !rhs.empty()))
                    return (true);
                return ( ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) || lhs == rhs);
            }
        template <class T, class Alloc>
            bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

                if ((!lhs.empty() && rhs.empty()))
                    return (true);
                if ((lhs.empty() && rhs.empty()))
                    return (false);
                return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
            }
        template <class T, class Alloc>
            bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

                if ((!lhs.empty() && rhs.empty()))
                    return (true);
                return ( ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()) || lhs == rhs);
            }
        
        template <class T, class Alloc>
            void swap(vector<T, Alloc> &lhs, vector<T, Alloc> &rhs) { lhs.swap(rhs); }
}

#endif