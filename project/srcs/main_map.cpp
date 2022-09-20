/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:18:46 by aribesni          #+#    #+#             */
/*   Updated: 2022/08/26 19:18:47 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <map>
#include <iostream>

int main(void) {

    std::map<int, int>  og_map;
    ft::map<int, int>   my_map;

    int     i = 0;
    int     j = 1;

    std::map<int, int>::iterator    og_iterator;
    ft::map<int, int>::iterator     my_iterator;

    std::cout << std::endl << "-----     ORIGINAL MAP     -----" << std::endl << std::endl;

    std::cout << "insert : ";

    og_iterator = og_map.begin();

    while (i < 10)
    {
        std::map<int, int>::value_type    pair(i, j);
        og_map.insert(og_iterator, pair);
        std::cout << og_map[i] << " ";
        i++;
        j++;
    }

    std::cout << std::endl;

    std::cout << std::endl << "-----     MY MAP     -----" << std::endl << std::endl;

    std::cout << "insert : ";

    i = 0;
    j = 1;
    
    my_iterator = my_map.begin();

    while (i < 10)
    {
        ft::map<int, int>::value_type    pair(i, j);
        my_map.insert(my_iterator, pair);
        std::cout << my_map[i] << " ";
        i++;
        j++;
    }
    
    std::cout << std::endl;
   
    std::cout << std::endl << "-----     ORIGINAL MAP     -----" << std::endl << std::endl;
    
    std::cout << "size : " << og_map.size() << std::endl;
    
    std::cout << std::endl << "-----     MY MAP     -----" << std::endl << std::endl;
    
    std::cout << "size : " << my_map.size() << std::endl;

    std::cout << std::endl << "-----     ORIGINAL MAP     -----" << std::endl << std::endl;

    std::cout << "erase : ";

    std::map<int, int>::key_type    og_key = 4;

    og_map.erase(og_key);

    for (size_t i = 0; i < og_map.size(); i++)
        std::cout << og_map[i] << " ";

    std::cout << std::endl;

    std::cout << std::endl << "-----     MY MAP     -----" << std::endl << std::endl;

    std::cout << "erase : ";

    ft::map<int, int>::key_type    my_key = 4;

    my_map.erase(my_key);

    for (size_t i = 0; i < my_map.size(); i++)
        std::cout << my_map[i] << " ";

    std::cout << std::endl;

    std::cout << std::endl << "-----     ORIGINAL MAP     -----" << std::endl << std::endl;

    std::cout << "copy constructor : ";

    std::map<int, int>  og_copy(og_map);

    for (int i = 0; i < 10; i++)
        std::cout << og_copy[i] << " ";

    std::cout << std::endl;

    std::cout << std::endl << "-----     MY MAP     -----" << std::endl << std::endl;

    std::cout << "copy constructor : ";

    ft::map<int, int>   my_copy(my_map);

    for (int i = 0; i < 10; i++)
        std::cout << my_copy[i] << " ";

    std::cout << std::endl;

    return (0);
}