/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:19:40 by aribesni          #+#    #+#             */
/*   Updated: 2022/10/25 15:19:43 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

namespace ft {

    //IS INTEGRAL
    template <bool is_integral, typename T>
        struct is_integral_res {

        //MEMBER TYPES

            typedef T           type;
            static const bool   value = is_integral;
    };

    template<typename>
        struct is_integral_type : is_integral_res<false, bool> {};
    template<>
        struct is_integral_type<bool> : is_integral_res<true, bool> {};
    template<>
        struct is_integral_type<char> : is_integral_res<true, char> {};
    template<>
        struct is_integral_type<signed char> : is_integral_res<true, signed char> {};
    template<>
        struct is_integral_type<short int> : is_integral_res<true, short int> {};
    template<>
        struct is_integral_type<int> : is_integral_res<true, int> {};
    template<>
        struct is_integral_type<long int> : is_integral_res<true, long int> {};
    template<>
        struct is_integral_type<long long int> : is_integral_res<true, long long int> {};
    template<>
        struct is_integral_type<unsigned char> : is_integral_res<true, unsigned char> {};
    template<>
        struct is_integral_type<unsigned short int> : is_integral_res<true, unsigned short int> {};
    template<>
        struct is_integral_type<unsigned int> : is_integral_res<true, unsigned int> {};
    template<>
        struct is_integral_type<unsigned long int> : is_integral_res<true, unsigned long int> {};
    template<>
        struct is_integral_type<unsigned long long int> : is_integral_res<true, unsigned long long int> {};

    template<typename T>
        struct is_integral : is_integral_type<T> {};

    //EQUAL
    template<class InputIterator1, class InputIterator2>
        bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
            
            while (first1 != last1)
            {
                if (first2 == last2 || *first1 != *first2)
                    return (false);
                ++first1;
                ++first2;
            }
            return (first2 == last2);
    }

    //LEXICOGRAPHICAL COMPARE
    template <class InputIterator1, class InputIterator2>
        bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
            while (first1 != last1)
            {
                if (first2 == last2 || *first2 < *first1)
                    return (false);
                else if (*first1 < *first2)
                    return (true);
                ++first1;
                ++first2;
            }
            return (first2 != last2);
    }

    //PAIR
    template<class T1, class T2>
        struct pair {

        //MEMBER TYPES

            typedef T1  first_type;
            typedef T2  second_type;

            first_type  first;
            second_type second;

        //MEMBER FUNCTIONS

            //Constructors
            pair(void) : first(), second() {}
            template<class U, class V>
                pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {}
            pair(const first_type& a, const second_type& b) : first(a), second(b) {}

            pair&   operator=(const pair& pr) {
                
                this->first = pr.first;
                this->second = pr.second;
                return (*this);
            }
    };

    template< bool Cond, class T = void >
        struct enable_if {};
    template<class T>
        struct enable_if<true, T> {

            //MEMBER TYPES

                typedef T   type;
    };

    //PAIR OPERATORS
    template<class T1, class T2>
        bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); }
    template<class T1, class T2>
        bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (!(lhs == rhs)); }
    template<class T1, class T2>
        bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second)); }
    template<class T1, class T2>
        bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (!(rhs < lhs)); }
    template<class T1, class T2>
        bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (rhs < lhs); }
    template<class T1, class T2>
        bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (!(lhs < rhs)); }

    //MAKE PAIR
    template<class T1, class T2>
        pair<T1, T2>    make_pair(T1 x, T2 y) { return (pair<T1, T2>(x, y)); }

    template <class T>
        void swap (T & a, T & b)
        {
            T	tmp(a);
            a = b;
            b = tmp;
        }
}

#endif