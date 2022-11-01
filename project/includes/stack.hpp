/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:49:41 by aribesni          #+#    #+#             */
/*   Updated: 2022/09/28 16:49:46 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "vector.hpp"
# include "utils.hpp"

namespace ft {

    template <class T, class Container = ft::vector<T> >
        class stack {

            public :

            //MEMBER TYPES

                typedef Container                           container_type;
                typedef T                                   value_type;
                typedef typename Container::size_type       size_type;
                typedef typename Container::reference       reference;
                typedef typename Container::const_reference const_reference;

            //MEMBER FUNCTIONS

                //Constructor
                explicit stack(const container_type& ctnr = container_type()) : _ctnr(ctnr) {}
                stack(const stack& src) : _ctnr(src._ctnr) {}

                stack&  operator=(const stack& src) { _ctnr = src._ctnr; return (*this); }

                //Capacity
                bool                empty(void) const { return (this->_ctnr.empty()); }
                size_type           size(void) const { return (this->_ctnr.size()); }

                //Element access
                value_type&         top(void) { return (this->_ctnr.back()); }
                const value_type&   top(void) const { return (this->_ctnr.back()); }

                //Modifiers
                void                push(const value_type& val) { this->_ctnr.push_back(val); }
                void                pop(void) { this->_ctnr.pop_back(); }

                template < class TYPE, class CONT >
                friend  bool operator==(const stack<TYPE, CONT>& lhs, const stack<TYPE, CONT>& rhs);
                template < class TYPE, class CONT >
                friend  bool operator<(const stack<TYPE, CONT>& lhs, const stack<TYPE, CONT>& rhs);

            protected :

                container_type  _ctnr;

    }; //STACK

        //NON-MEMBER FUNCTION OVERLOADS

            //Operator overloads
            template < class TYPE, class CONT >
                bool operator==(const stack<TYPE, CONT>& lhs, const stack<TYPE, CONT>& rhs) { return (lhs._ctnr == rhs._ctnr); };
            template < class TYPE, class CONT >
                bool operator<(const stack<TYPE, CONT>& lhs, const stack<TYPE, CONT>& rhs) { return (lhs._ctnr < rhs._ctnr); };
            template <class T, class Container>
                bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return (!(lhs == rhs)); }
            template <class T, class Container>
                bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return (!(rhs < lhs)); }
            template <class T, class Container>
                bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return (!(lhs <= rhs)); }
            template <class T, class Container>
                bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) { return (!(lhs < rhs)); }
}

#endif
