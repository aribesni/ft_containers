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

    std::map<int, int>::iterator    og_iterator;
    ft::map<int, int>::iterator     my_iterator;

    std::cout << std::endl << "-----     ORIGINAL MAP     -----" << std::endl << std::endl;

    std::cout << "insert : ";

    og_iterator = og_map.begin();

    while (i < 10)
    {
        const std::map<int, int>::value_type    pair(i, i);
        og_map.insert(og_iterator, pair);
        std::cout << og_map[i] << " ";
        i++;
    }

    std::cout << std::endl;

    std::cout << std::endl << "-----     MY MAP     -----" << std::endl << std::endl;

    std::cout << "insert : ";

    i = 0;
    
    my_iterator = my_map.begin();

    while (i < 10)
    {
        const ft::map<int, int>::value_type    pair(i, i);
        my_map.insert(my_iterator, pair);
        std::cout << my_map[i] << " ";
        i++;
    }

    std::cout << std::endl;

    std::cout << std::endl << "-----     ORIGINAL MAP     -----" << std::endl << std::endl;

    std::cout << "erase : ";

    std::map<int, int>::key_type    og_key = 4;

    og_map.erase(og_key);

    for (int i = 0; i < 10; i++)
        std::cout << og_map[i] << " ";

    std::cout << std::endl;

    std::cout << std::endl << "-----     MY MAP     -----" << std::endl << std::endl;

    std::cout << "erase : ";

    ft::map<int, int>::key_type    my_key = 4;

    my_map.erase(my_key);

    for (int i = 0; i < 10; i++)
        std::cout << my_map[i] << " ";

    std::cout << std::endl;

    return (0);
}