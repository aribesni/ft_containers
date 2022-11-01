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

}