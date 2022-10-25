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
                explicit    vector(const allocator_type& alloc = allocator_type()) : _array(new T), _ptr(_array), _capacity(0), _size(0), _alloc(alloc) {}
                explicit    vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _array(new T[n]), _ptr(_array), _capacity(n), _size(n), _alloc(alloc) {
                    
                    for (size_t i = 0; i < this->_size; i++)
                        this->_array[i] = val;
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
                    this->_array = new T[i];
                    this->_ptr = this->_array;
                    this->_capacity = i;
                    this->_size = i;
                    this->_alloc = alloc;
                    i = 0;
                    while (first != last)
                    {
                        this->push_back(*first); // this doesn't seem to work
                        first++;
                    }
                }
                vector(const vector& x) : _array(new T[x._capacity]), _ptr(x._array), _capacity(x._size), _size(x._size) { // not sure about capacity

                    for (size_t i = 0; i < x._size; i++)
                        this->_array[i] = x._array[i];
                }

                //Destructor
                ~vector(void) { delete[] this->_array; }

                //Assign
                vector& operator=(const vector &x) {

                    if (*this != x)
                    {
                        this->_capacity = x._capacity;
                        this->_size = x._size;
                        for (size_t i = 0; i < x._size; i++)
                            this->_array[i] = x._array[i];
                    }
                    return (*this);
                }

                //Iterators
                iterator                begin(void) { return (this->_ptr); }
                const_iterator          begin(void) const { return (this->_ptr); }
                iterator                end(void) { return (iterator(this->_ptr + this->_size)); }
                const_iterator          end(void) const { return const_iterator(this->_ptr + this->_size); }
                reverse_iterator        rbegin(void) { return (reverse_iterator(this->end())); }
                const_reverse_iterator  rbegin(void) const { return (const_reverse_iterator(this->end())); }
                reverse_iterator        rend(void) { return (reverse_iterator(this->begin())); }
                const_reverse_iterator  rend(void) const { return (const_reverse_iterator(this->begin())); }

                //Capacity
                size_type   size(void) const { return (this->_size); }
                size_type   max_size(void) const { return (this->_capacity); }
                void        resize(size_type n, value_type val = value_type()) {

                    if (n < this->_size)
                    {
                        size_type   tmp = 0;
                        for (pointer test = this->_array; tmp < n; test++)
                        {
                            this->_alloc.destroy(test);
                            tmp++;
                        }
                        this->_size = n;
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
                        T*  new_array = new T[n];
                        size_type i = -1;
                        while (++i < this->_size)
                            new_array[i] = this->_array[i];
                        while (i < n)
                        {
                            new_array[i] = val;
                            i++;
                            this->_size++;
                        }
                        delete[] this->_array;
                        this->_array = new_array;
                    }
                }
                size_type   capacity(void) const { return (this->_capacity); }
                bool        empty(void) const { return (this->_size == 0 ? true : false); }
                void        reserve(size_type n) { this->_capacity = (n > this->_capacity ? n : this->_capacity); }

                //Element access
                reference       operator[](size_type n) { return (this->_array[n]); }
                const_reference operator[](size_type n) const { return (this->_array[n]); }
                reference       at(size_type n) {

                    if (n > this->_size)
                        throw std::length_error("Out of range");
                    return (this->_array[n]);
                }
                const_reference at(size_type n) const {

                    if (n > this->_size)
                        throw std::length_error("Out of range");
                    return (this->_array[n]);
                }
                reference       front(void) { return (this->_array[0]); }
                const_reference front(void) const { return (this->_array[0]); }
                reference       back(void) { return (this->_array[this->_size - 1]); }
                const_reference back(void) const { return (this->_array[this->_size - 1]); }

                //Modifiers
                template <class InputIterator>
                    void    assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {

                        this->clear();
                        for (InputIterator it = first; it != last; it++)
                            this->push_back(*it);
                    }
                void        assign(size_type n, const value_type& val) {
  
                    if (n > this->_capacity)
                    {
                        size_type i = 0;
                        T*  new_array = new T[this->_size + n];
                        while (i < this->_size)
                        {
                            new_array[i] = this->_array[i];
                            i++;
                        }
                        while (i < n)
                        {
                            new_array[i] = val;
                            i++;
                            this->_size++;
                        }
                        delete[] this->_array;
                        this->_array = new_array;
                        this->_capacity = this->_size;
                    }
                    else
                    {
                        for (size_type i = 0; i < n; i++)
                            this->_array[i] = val;
                        while (this->_size > n)
                            this->_size--;
                    }
                }
                void        push_back(const value_type& val) {
                
                    if (this->_size + 1 > this->_capacity)
                    {
                        size_type   i = 0;
                        T*  new_array = new T[this->_size + 1];
                        
                        while (i < this->_size)
                        {
                            new_array[i] = this->_array[i];
                            i++;
                        }
                        this->_size++;
                        this->_capacity += 2;
                        new_array[i] = val;
                        delete[] this->_array;
                        this->_array = new_array;
                    }
                    else
                    {
                        this->_array[this->_size] = val;
                        this->_size++;
                    }
                }
                void        pop_back(void) {

                    if (this->_size == 0)
                        throw std::length_error("Pop back fail : size == 0");
                    this->_size--;
                }
                iterator    insert(iterator position, const value_type& val) {
                    
                    iterator    i = this->begin();
                    size_type   j = 0;
                    T*  new_array = new T[this->_size + 1];
                    while (i < position)
                    {
                        new_array[j] = this->_array[j];
                        i++;
                        j++;
                    }
                    this->_size++;
                    new_array[j] = val;
                    j++;
                    while (j < this->_size)
                    {
                        new_array[j] = this->_array[j - 1];
                        j++;
                    }
                    this->_capacity += this->_size > this->_capacity ? 1 : 0;
                    delete[] this->_array;
                    this->_array = new_array;
                    return (position);
                }
                void        insert(iterator position, size_type n, const value_type& val) {

                    T*          new_array = new T[this->_size + n];
                    size_type   i = 0;
                    size_type   j = 0;
                    iterator    it = this->begin();

                    this->_size += n;
                    while (it != position)
                    {
                        new_array[i] = this->_array[i];
                        it++;
                        i++;
                    }
                    while (j < n)
                    {
                        new_array[i++] = val;
                        it++;
                        j++;
                    }
                    it++;
                    while (it != this->end())
                    {
                        new_array[i] = this->_array[i - 1];
                        it++;
                        i++;
                    }
                    this->_capacity += n + 2;
                    delete[] this->_array;
                    this->_array = new_array;
                }
                template <class InputIterator>
                    void    insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {

                        InputIterator   tmp;
                        int             i = 0;
                        int             n = 0;

                        for (tmp = first; tmp != last; tmp++)
                            n++;
                        T*  new_array = new T[this->_size + n];
                        this->_size += n;
                        for (iterator it = this->begin(); it != position; it++)
                        {
                            new_array[i] = this->_array[i];
                            i++;
                        }
                        while (first != last)
                            new_array[i] = *first++;
                        if (*last != *this->end())
                        {
                            for (size_type i = *last; i < this->_size; i++)
                                new_array[i] = *position++;
                        }
                        this->_capacity += n + 2;
                        delete[] this->_array;
                        this->_array = new_array;
                    }
                iterator    erase(iterator position) {

                    if (position < this->begin() || position >= this->end())
                        throw std::length_error("Erase : position out of range");
                    iterator    tmp = this->begin();
                    size_type   i = 0;
                    T*  new_array = new T[this->_size];
                    while (tmp != position)
                    {
                        new_array[i] = this->_array[i];
                        i++;
                        tmp++;
                    }
                    this->_size--;
                    while (i < this->_size)
                    {
                        new_array[i] = this->_array[i + 1];
                        i++;
                    }
                    delete[] this->_array;
                    this->_array = new_array;
                    return (position);
                }
                iterator    erase(iterator first, iterator last) {

                    difference_type n = last - first;
                    iterator        it = this->begin();
                    T               *new_array = new T[this->_size + n];
                    int             i = 0;

                    this->_size += n;
                    while (it != first)
                    {
                        new_array[i] = this->_array[i];
                        it++;
                        i++;
                    }
                    for (iterator tmp = last; tmp != this->end(); tmp++)
                    {
                        new_array[i] = this->_array[i];
                        i++;
                    }
                    delete[] this->_array;
                    this->_array = new_array;
                    return (it);
                }
                void        swap(vector& x) {

                    size_t  tmp_capacity = x._capacity;
                    size_t  tmp_size = x._size;
                    pointer tmp_ptr = x._ptr;
                    T       *tmp_array = x._array;

                    x._capacity = this->_capacity;
                    x._size = this->_size;
                    x._ptr = this->_ptr;
                    x._array = this->_array;
                    for (size_t i = 0; i < this->_size; i++)
                        x._array[i] = this->_array[i];

                    this->_capacity = tmp_capacity;
                    this->_size = tmp_size;
                    this->_ptr = tmp_ptr;
                    this->_array = tmp_array;
                    for (size_t i = 0; i < tmp_size; i++)
                        this->_array[i] = tmp_array[i];
                }
                void        clear(void) {
                    
                    vector  tmp;
                    this->swap(tmp);
                    this->_size = 0;
                }

                //Allocator
                allocator_type  get_allocator(void) const { return (allocator_type()); }

            private :

            //MEMBER TYPES

                T*              _array;
                pointer         _ptr;
                size_t          _capacity;
                size_t          _size;
                allocator_type  _alloc;

        }; //VECTOR

    //NON-MEMBER FUNCTION OVERLOADS

        template <class T, class Alloc>
            bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

                if (lhs.size() == rhs.size())
                {
                    for (unsigned long i = 0; i < lhs.size(); i++)
                    {
                        if (lhs[i] != rhs[i])
                            return (false);
                    }
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

                unsigned long   i;

                i = 0;
                while (i < lhs.size() && i < rhs.size())
                {
                    if (lhs[i] >= rhs[i])
                        return (false);
                    i++;
                }
                return (true);
            }
        template <class T, class Alloc>
            bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

                if (!(rhs < lhs))
                    return (true);
                return (false);
            }
        template <class T, class Alloc>
            bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

                if (rhs < lhs)
                    return (true);
                return (false);
            }
        template <class T, class Alloc>
            bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {

                if (!(lhs < rhs))
                    return (true);
                return (false);
            }
}

#endif