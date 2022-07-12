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

    og_vector.push_back(8);
    og_vector.push_back(7);
    og_vector.push_back(6);

    for (unsigned long i = 0; i < og_vector.size(); i++)
        std::cout << og_vector[i] << std::endl;

    my_vector.push_back(5);
    my_vector.push_back(4);
    my_vector.push_back(3);

    for (unsigned long i = 0; i < my_vector.size(); i++)
        std::cout << my_vector[i] << std::endl;

    return (0);
}