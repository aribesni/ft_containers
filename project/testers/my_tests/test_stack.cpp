/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:18:40 by aribesni          #+#    #+#             */
/*   Updated: 2022/11/01 15:18:42 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.hpp"

void    test_stack(void) 
{
    std::cout << "\033[0;34m" << "          ----------          STACK          ----------" << "\033[0m" << std::endl << std::endl;

    NAMESPACE::stack<int>     my_stack;

    std::cout << "push : 8, 7, 6" << std::endl;

    my_stack.push(8);
    my_stack.push(7);
    my_stack.push(6);

    std::cout << std::endl;
    
    std::cout << "top of stack : " << my_stack.top() << " " << std::endl;

    std::cout << std::endl;

    std::cout << "pop value on top" << std::endl;

    my_stack.pop();

    std::cout << std::endl;

    std::cout << "top of stack : " << my_stack.top() << " ";

    std::cout << std::endl;
    std::cout << std::endl;    
    
}