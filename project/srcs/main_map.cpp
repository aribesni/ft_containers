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

    og_iterator = og_map.begin();

    while (i < 5)
    {
        const std::map<int, int>::value_type    pair(i, i);
        og_map.insert(og_iterator, pair);
        std::cout << og_map[i] << std::endl;
        i++;
    }

    std::cout << std::endl << "-----     MY MAP     -----" << std::endl << std::endl;

    i = 0;
    
    my_iterator = my_map.begin();

    while (i < 5)
    {
        const ft::map<int, int>::value_type    pair(i, i);
        my_map.insert(my_iterator, pair);
        std::cout << my_map[i] << std::endl;
        i++;
    }

    return (0);
}