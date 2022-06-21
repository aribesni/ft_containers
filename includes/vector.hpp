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

# include <memory.h>

namespace ft {

    template <class T, class Alloc = std::allocator<T> >
    class   vector {

        public :

        // MEMBER TYPES

            typedef T                                                   value_type;
            typedef Alloc                                               allocator_type;
            typedef value_type&                                         reference;
            typedef const value_type&                                   const_reference;
            typedef value_type*                                         pointer;
            typedef const value_type*                                   const_pointer;
            typedef ft::iterator<iterator>                              iterator;
            typedef ft::iterator<const_iterator>                        const_iterator;
            typedef ft::reverse_iterator<iterator>                      reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                const_reverse_iterator;
            typedef typename iterator_traits<iterator>::difference_type difference_type;
            typedef size_t                                              size_type;


        // MEMBER FUNCTIONS

            //Contructors
            explicit    vector(const allocator_type& alloc = allocator_type()) : _array(NULL) {}
            explicit    vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _array(new T[n]), _capacity(n), _size(n), _begin(0), end(n) {}
            template <class InputIterator>
                vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _array(new T[last - first]), _capacity(last - first), _size(last - first), _begin(first), _end(last) {

                for (InputIterator i = first; i < last, i++)
                    this->_array[i] = *i;
            }
            vector(const vector& x) : _array(new T[x._capacity]), _capacity(x._capacity), _size(x._size), _begin(x._begin), _end(begin._end) {

                *this = x;
                for (size_t i = 0; i < x._size; i++)
                    this->_array[i] = x._array[i];
            }

            //Destructor
            ~vector(void) {

                delete[] this->_array;
            }

            //Assign
            vector& operator=(const vector &x) {

                *this = x;
                this->_capacity = x._capacity;
                this->_size = x._size;
                for (size_t i = 0; i < x._size; i++)
                    this->_array[i] = x._array[i];
                return (*this);
            }

            //Iterators
            iterator                begin(void) { return (this->_begin); }
            const_iterator          begin(void) const { return (this->_begin); }
            iterator                end(void) { return (this->_end); }
            const_iterator          end(void) const { return (this->_end); }
            reverse_iterator        rbegin(void) { return (reverse_iterator(this->_end())); }
            const_reverse_iterator  rbegin(void) const { return (const_revers_iterator(this->_end())); }
            reverse_iterator        rend(void) { return (reverse_iterator(this->_begin())); }
            const_reverse_iterator  rend(void) const { return (const_reverse_iterator(this->_begin())); }

            //Capacity
            size_type   size(void) const { return (this->_size); }
            size_type   max_size(void) const { return (this->_capacity); }
            void        resize(size_type n, value_type val = value_type()) {

                if (n < this->_size)
                {
                    for (size_type i = n + 1; i < this->_size; i++)
                        delete array[i];
                    this->_size = n;
                }
                else if (n > this->_size)
                {
                    //push_back(value);
                }
                if (n > this->_capacity)
                {
                    T*  new_array = new T[n];
                    for (size_type i = 0; i < this->_size; i++)
                        new_array[i] = this->_array[i];
                    while (i < n)
                    {
                        new_array[i] = value;
                        i++;
                        this->_size++;
                    }
                    delete[] this->_array;
                    this->_array = new_array;
                }
            }
            size_type   capacity(void) const { return (this->_capacity); }
            bool        empty(void) const { return (this->_size == 0 ? true : false); }
            void        reserve(size_type n) {

                this->_capacity = (n > this->_capacity ? n : this->_capacity);
            }

            //Element access
            reference       operator[](size_type n) { return (this->_array[n]); }
            const_reference operator[](size_type n) const { return (this->_array[n]); }
            reference       at(size_type n) {

                if (n > this->_size)
                    throw std::exception("Out of range");
                return (this->_array[n]);
            }
            const_reference at(size_type n) const {

                if (n > this->_size)
                    throw std::exception("Out of range");
                return (this->_array[n]);
            }
            reference       front(void) { return (this->_array[0]); }
            const_reference front(void) const { return (this->_array[0]); }
            reference       back(void) { return (this->_array[size - 1]); }
            const_reference back(void) const { return (this->_array[size - 1]); }

            //Modifiers
            template <class InputIterator>
                void    assign(InputIterator first, InputIterator last) {

                    while (first != last)
                    {
                        this->_array[first] = *first;
                        *first++;
                        this->_size++;
                    }
                }
            void        assign(size_type n, const value_type& val) {
                
                if (n > this->_capacity)
                {
                    T*  new_array = new T[this->_size + n];
                    for (int i = 0; i < this->_size; i++)
                        new_array[i] = this->_array[i];
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
                else for (int i = 0; i < n; i++)
                    this->_array[i] = val;
            }
            void        push_back(const value_type& val) {
                
                if (this->_size + 1 > this->_capacity)
                {
                    T*  new_array = new T[this->_size + 5];
                    this->_size++;
                    for (int i = 0; i < this->size; i++)
                        new_array[i] = this->_array[i];
                    this->_capacity += 6;
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
                    throw std::exception("Pop back fail : size == 0");
                this->_size--;
            }
            iterator    insert(iterator position, const value_type& val) {
                
                if (this->_size + 1 > this->_capacity)
                {
                    T*  new_array = new T[this->_size + 5];
                    this->_size++;
                    for (int i = 0; i < position; i++)
                        new_array[i] = this->_array[i];
                    new_array[i] = val;
                    for (iterator i = position + 1; i < this->_size; i++)
                        new_array[i] = this->_array[i - 1];
                    this->_capacity += 6;
                    delete[] this->_array;
                    this->_array = new_array;
                }
                else
                {
                    for (iterator i = position; i < this->_size; i++)
                        this->_array[i + 1] = this->_array[i];
                    this->_array[position] = val;
                }
                return (this->_array[position]);
            }
            void        insert(iterator position, size_type n, const value_type& val) {

                T*  new_array = new T[this->_size + n];
                this->_size += n;
                for (int i = 0; i < position; i++)
                    new_array[i] = this->_array[i];
                for (int j = 0; j < n; j++)
                    new_array[j] = val;
                for (iterator i = position + n + 1; i < this->_size; i++)
                    new_array[i] = this->_array[i - 1];
                this->_capacity += n + 5;
                delete[] this->_array;
                this->_array = new_array;
            }
            template <class InputIterator>
                void    insert(iterator position, InputIterator first, InputIterator last) {

                    InputIterator   n;

                    n = first - last;
                    T*  new_array = new T[this->_size + n];
                    this->_size += n;
                    for (int i = 0; i < position; i++)
                        new_array[i] = this->_array[i];
                    for (int j = 0; j < n; j++)
                        new_array[j] = val;
                    for (iterator i = position + n + 1; i < this->_size; i++)
                        new_array[i] = this->_array[i - 1];
                    this->_capacity += n + 5;
                    delete[] this->_array;
                    this->_array = new_array;
                }
            iterator    erase(iterator position) {

                if (position < 0 || position >= this->_size)
                    throw std::exception("Erase : position out of range");
                for (int i = position; i < this->_size - 1; i++)
                    this->_array[i] = this->_array[i + 1];
                this->_size--;
            }
            iterator    erase(iterator first, iterator last) {

                iterator    n = last - first;
                T           *new_array = new T[this->_size + n];

                this->_size += n;
                for (int i = 0; i < first; i++)
                    new_array[i] = this->_array[i];
                for (int i = last; i < this->_size; i++)
                    new_array[i] = this->_array[i];
                delete[] this->_array;
                this->_array = new_array;
            }
            void        swap(vector& x) {

                if (*this == x)
                    return ;

                size_t  tmp_capacity = x._capacity;
                size_t  tmp_size = x._size;
                size_t  tmp_begin = x._begin;
                size_t  tmp_end = x._end;
                T       *tmp_array = x._array;

                x._capacity = this->_capacity;
                x._size = this->_size;
                x._begin = this->_begin;
                x._end = this->_end;
                delete[] x._array;
                x._array = this->_array;
                for (int i = 0; i < this->_size; i++)
                    x_array[i] = this->_array[i];

                this->_capacity = tmp_capacity;
                this->_size = tmp_size;
                this->_begin = tmp_begin;
                this->_end = tmp_end;
                delete[] this->_array;
                this->_array = tmp_array;
                for (int i = 0; i < tmp._size; i++)
                    this->_array[i] = tmp_array[i];
            }
            void        clear(void) {
                
                vector  tmp;
                this->swap(tmp);
                this->_size = 0;
            }

        private :

        // MEMBER TYPES
            T*      _array;
            size_t  _capacity;
            size_t  _size;
            size_t  _begin;
            size_t  _end;

    };
}

#endif