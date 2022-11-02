/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:18:46 by aribesni          #+#    #+#             */
/*   Updated: 2022/08/26 19:18:47 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

void test_map(void) {

    std::cout << "\033[0;31m" << "          ----------          MAP          ----------" << "\033[0m" << std::endl << std::endl;

    NAMESPACE::map<int, int>   my_map;

    int     i = 0;
    int     j = 1;

    NAMESPACE::map<int, int>::iterator     my_iterator;

    std::cout << "insert : ";

    i = 0;
    j = 1;

    my_iterator = my_map.begin();

    while (i < 10)
    {
        NAMESPACE::map<int, int>::value_type    pair(i, j);
        my_map.insert(my_iterator, pair);
        std::cout << my_map[i] << " ";
        i++;
        j++;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "size : " << my_map.size() << std::endl;

    std::cout << std::endl;
    
    std::cout << "erase : ";

    NAMESPACE::map<int, int>::key_type    my_key = 4;

    my_map.erase(my_key);

    for (size_t i = 0; i < my_map.size(); i++)
        std::cout << my_map[i] << " ";

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "copy constructor : ";

    NAMESPACE::map<int, int>   my_copy(my_map);

    for (size_t i = 0; i < my_map.size(); i++)
        std::cout << my_copy[i] << " ";

    std::cout << std::endl;
    std::cout << std::endl;

    my_iterator = my_map.begin();

    std::cout << "begin : " << my_iterator->second << "   ";
    
    my_iterator = --my_map.end();

    std::cout << "end : " << my_iterator->second << "   ";
    
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "find key 3 : " << my_map.count(3) << std::endl;

    std::cout << std::endl;

    std::cout << "find key 15 : " << my_map.count(15) << std::endl;
   
    std::cout << std::endl;
   
    std::cout << "is_empty : " << my_map.empty() << std::endl;

    std::cout << std::endl;
 
    std::cout << "* clear *" << std::endl;
    
    my_map.clear();
 
    std::cout << std::endl;
 
    std::cout << "is_empty : " << my_map.empty() << std::endl;
}