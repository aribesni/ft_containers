/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:15:36 by aribesni          #+#    #+#             */
/*   Updated: 2022/06/21 17:15:38 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iostream>

int main(void)
{
    std::vector<int>    og_vector;
    ft::vector<int>     my_vector;
    
    std::vector<int>::iterator og_iterator = og_vector.begin();
    ft::vector<int>::iterator my_iterator = my_vector.begin();

    std::cout << std::endl << "-----     ORIGINAL VECTOR     -----" << std::endl << std::endl;

    std::cout << "push_back : ";

    og_vector.push_back(8);
    og_vector.push_back(7);
    og_vector.push_back(6);

    for (unsigned long i = 0; i < og_vector.size(); i++)
        std::cout << og_vector[i] << " ";

    std::cout << std::endl << std::endl << "-----     MY VECTOR     -----" << std::endl << std::endl;

    std::cout << "push_back : ";

    my_vector.push_back(8);
    my_vector.push_back(7);
    my_vector.push_back(6);

    for (unsigned long i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";

    std::cout << std::endl << std::endl << "-----     ORIGINAL VECTOR     -----" << std::endl << std::endl;

    std::cout << "insert : ";
   
    og_iterator = og_vector.begin();
    og_vector.insert(og_iterator, 1);

    for (unsigned long i = 0; i < og_vector.size(); i++)
        std::cout << og_vector[i] << " ";

    std::cout << std::endl << std::endl << "-----     MY VECTOR     -----" << std::endl << std::endl;

    std::cout << "insert : ";

    my_iterator = my_vector.begin();
    my_vector.insert(my_iterator, 1);

    for (unsigned long i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";

    std::cout << std::endl << std::endl << "-----     ORIGINAL VECTOR     -----" << std::endl << std::endl;

    std::cout << "push_back : ";
   
    og_vector.push_back(5);
    og_vector.push_back(4);
    og_vector.push_back(3);

    for (unsigned long i = 0; i < og_vector.size(); i++)
        std::cout << og_vector[i] << " ";

    std::cout << std::endl << std::endl << "-----     MY VECTOR     -----" << std::endl << std::endl;

    std::cout << "push_back : ";
   
    my_vector.push_back(5);
    my_vector.push_back(4);
    my_vector.push_back(3);

    for (unsigned long i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";

    std::cout << std::endl << std::endl << "-----     ORIGINAL VECTOR     -----" << std::endl << std::endl;

    std::cout << "pop_back : ";
   
    og_vector.pop_back();
    og_vector.pop_back();

    for (unsigned long i = 0; i < og_vector.size(); i++)
        std::cout << og_vector[i] << " ";

    std::cout << std::endl << std::endl << "-----     MY VECTOR     -----" << std::endl << std::endl;

    std::cout << "pop_back : ";
    
    my_vector.pop_back();
    my_vector.pop_back();

    for (unsigned long i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";
    
    std::cout << std::endl << std::endl << "-----     ORIGINAL VECTOR     -----" << std::endl << std::endl;

    std::cout << "erase : ";
   
    og_iterator = og_vector.begin();
    og_iterator += 2;

    og_vector.erase(og_iterator);

    for (unsigned long i = 0; i < og_vector.size(); i++)
        std::cout << og_vector[i] << " ";

    std::cout << std::endl << std::endl << "-----     MY VECTOR     -----" << std::endl << std::endl;

    std::cout << "erase : ";

    ft::vector<int>::iterator my_iterator_2 = my_vector.begin(); // need to fix this
   
    my_iterator_2 = my_vector.begin();
    my_iterator_2 += 2;

    my_vector.erase(my_iterator_2);
    for (unsigned long i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";

    std::cout << std::endl << std::endl << "-----     ORIGINAL VECTOR     -----" << std::endl << std::endl;

    std::cout << "insert : ";
   
    og_iterator = og_vector.begin();
    og_iterator += 2;

    og_vector.insert(og_iterator, 7);

    for (unsigned long i = 0; i < og_vector.size(); i++)
        std::cout << og_vector[i] << " ";

    std::cout << std::endl << std::endl << "-----     MY VECTOR     -----" << std::endl << std::endl;

    std::cout << "insert : ";

    my_iterator = my_vector.begin();
    my_iterator += 2;

    my_vector.insert(my_iterator, 7);

    for (unsigned long i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";

    std::cout << std::endl << std::endl << "-----     ORIGINAL VECTOR     -----" << std::endl << std::endl;

    std::cout << "begin : " << *og_vector.begin() << "   ";
    std::cout << "end : " << *og_vector.end() << "   ";
    std::cout << "front : " << og_vector.front() << "   ";
    std::cout << "back : " << og_vector.back() << "   ";
    std::cout << "size : " << og_vector.size() << "   ";
    std::cout << "capacity : " << og_vector.capacity() << "   ";

    std::cout << std::endl << std::endl << "-----     MY VECTOR     -----" << std::endl << std::endl;

    std::cout << "begin : " << *my_vector.begin() << "   ";
    std::cout << "end : " << *my_vector.end() << "   ";
    std::cout << "front : " << my_vector.front() << "   ";
    std::cout << "back : " << my_vector.back() << "   ";
    std::cout << "size : " << my_vector.size() << "   ";
    std::cout << "capacity : " << my_vector.capacity() << "   ";


    std::cout << std::endl << std::endl << "-----     ORIGINAL VECTOR     -----" << std::endl << std::endl;

    std::cout << "copying vector, new vector : " << std::endl << std::endl;
    
    std::vector<int> og_vector_2(og_vector);

    for (unsigned long i = 0; i < og_vector_2.size(); i++)
        std::cout << og_vector_2[i] << " ";

    std::cout << std::endl << std::endl;
    
    std::cout << "begin : " << *og_vector_2.begin() << "   ";
    std::cout << "end : " << *og_vector_2.end() << "   ";
    std::cout << "front : " << og_vector_2.front() << "   ";
    std::cout << "back : " << og_vector_2.back() << "   ";
    std::cout << "size : " << og_vector_2.size() << "   ";
    std::cout << "capacity : " << og_vector_2.capacity() << "   ";

    std::cout << std::endl << std::endl << "-----     MY VECTOR     -----" << std::endl << std::endl;

    std::cout << "copying vector, new vector : " << std::endl << std::endl;

    ft::vector<int> my_vector_2(my_vector);

    for (unsigned long i = 0; i < my_vector_2.size(); i++)
        std::cout << my_vector_2[i] << " ";

    std::cout << std::endl << std::endl;
    
    std::cout << "begin : " << *my_vector_2.begin() << "   ";
    std::cout << "end : " << *my_vector_2.end() << "   ";
    std::cout << "front : " << my_vector_2.front() << "   ";
    std::cout << "back : " << my_vector_2.back() << "   ";
    std::cout << "size : " << my_vector_2.size() << "   ";
    std::cout << "capacity : " << my_vector_2.capacity() << "   ";

    std::cout << std::endl << std::endl << "-----     ORIGINAL VECTOR     -----" << std::endl << std::endl;

    std::cout << "creating new vector" << std::endl << std::endl;

    std::vector<int> og_vector_3(6, 8);

    std::cout << "vector 1 : ";

    for (unsigned long i = 0; i < og_vector.size(); i++)
        std::cout << og_vector[i] << " ";

    std::cout << "  vector 2 : ";

    for (unsigned long i = 0; i < og_vector_3.size(); i++)
        std::cout << og_vector_3[i] << " ";
    
    std::cout << std::endl << std::endl;
    
    std::cout << "swap : " << std::endl << std::endl;

    og_vector.swap(og_vector_3);

    std::cout << "vector 1 : ";

    for (unsigned long i = 0; i < og_vector.size(); i++)
        std::cout << og_vector[i] << " ";

    std::cout << "  vector 2 : ";

    for (unsigned long i = 0; i < og_vector_3.size(); i++)
        std::cout << og_vector_3[i] << " ";

    std::cout << std::endl << std::endl << "-----     MY VECTOR     -----" << std::endl << std::endl;

    std::cout << "creating new vector" << std::endl << std::endl;

    ft::vector<int> my_vector_3(6, 8);

    std::cout << "vector 1 : ";

    for (unsigned long i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";

    std::cout << "  vector 2 : ";

    for (unsigned long i = 0; i < my_vector_3.size(); i++)
        std::cout << my_vector_3[i] << " ";
    
    std::cout << std::endl << std::endl;
    
    std::cout << "swap : " << std::endl << std::endl;

    my_vector.swap(my_vector_3);

    std::cout << "vector 1 : ";

    for (unsigned long i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";

    std::cout << "  vector 2 : ";

    for (unsigned long i = 0; i < my_vector_3.size(); i++)
        std::cout << my_vector_3[i] << " ";

    std::cout << std::endl;

    return (0);
}