/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:18:01 by aribesni          #+#    #+#             */
/*   Updated: 2022/08/26 19:18:05 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

void test_vector(void)
{
    std::cout << std::endl << "\033[0;33m" << "          ----------          VECTOR          ----------" << "\033[0m" << std::endl << std::endl;
    
    NAMESPACE::vector<int>     my_vector;
    
    NAMESPACE::vector<int>::iterator my_iterator = my_vector.begin();

    std::cout << "push_back : ";

    my_vector.push_back(8);
    my_vector.push_back(7);
    my_vector.push_back(6);

    for (unsigned long i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";

    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "insert : ";

    my_iterator = my_vector.begin();
    my_vector.insert(my_iterator, 1);

    for (unsigned long i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";

    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "push_back : ";
   
    my_vector.push_back(5);
    my_vector.push_back(4);
    my_vector.push_back(3);

    for (unsigned long i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";

    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "pop_back : ";
    
    my_vector.pop_back();
    my_vector.pop_back();

    for (unsigned long i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";
    
    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "erase : ";

    NAMESPACE::vector<int>::iterator my_iterator_2 = my_vector.begin(); // need to fix this
   
    my_iterator_2 = my_vector.begin();
    my_iterator_2 += 2;

    my_vector.erase(my_iterator_2);
    
    for (unsigned long i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";

    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "insert : ";

    my_iterator = my_vector.begin();
    my_iterator += 2;

    my_vector.insert(my_iterator, 7);

    for (unsigned long i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";

    std::cout << std::endl;
    std::cout << std::endl;
   
    std::cout << "begin : " << *my_vector.begin() << "   ";
    std::cout << "end : " << *my_vector.end() << "   ";
    std::cout << "front : " << my_vector.front() << "   ";
    std::cout << "back : " << my_vector.back() << "   ";
    std::cout << "size : " << my_vector.size() << "   ";
    std::cout << "capacity : " << my_vector.capacity() << "   ";

    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "copying vector, new vector : " << std::endl << std::endl;

    NAMESPACE::vector<int> my_vector_2(my_vector);

    for (unsigned long i = 0; i < my_vector_2.size(); i++)
        std::cout << my_vector_2[i] << " ";

    std::cout << std::endl << std::endl;
    
    std::cout << "begin : " << *my_vector_2.begin() << "   ";
    std::cout << "end : " << *(--my_vector_2.end()) << "   ";
    std::cout << "front : " << my_vector_2.front() << "   ";
    std::cout << "back : " << my_vector_2.back() << "   ";
    std::cout << "size : " << my_vector_2.size() << "   ";
    std::cout << "capacity : " << my_vector_2.capacity() << "   ";

    std::cout << std::endl << std::endl;

    std::cout << "creating new vector" << std::endl << std::endl;

    std::vector<int>::size_type my_n = 6;
    
    NAMESPACE::vector<int> my_vector_3(my_n, 8);

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
    std::cout << std::endl;
   
    std::cout << "assign : ";

    NAMESPACE::vector<int>::size_type my_n2 = 3;

    my_vector.assign(my_n2, 9);

    for (unsigned long i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";

    std::cout << std::endl;
    std::cout << std::endl;
   
    std::cout << "resize : ";

    NAMESPACE::vector<int>::size_type my_n3 = 6;

    my_vector.resize(my_n3, 1);

    for (unsigned long i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << " ";

    std::cout << "contructor with iterator : ";

    NAMESPACE::vector<int>    my_vector_4(3, 8);
    NAMESPACE::vector<int>::iterator  it;

    for (unsigned long i = 0; i < my_vector_4.size(); i++)
        std::cout << my_vector_4[i] << " ";

    std::cout << std::endl;
    std::cout << std::endl;

}
