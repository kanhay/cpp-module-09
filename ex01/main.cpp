/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:44:28 by khanhayf          #+#    #+#             */
/*   Updated: 2024/03/17 18:07:09 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av){
    if (ac != 2)
        return (std::cerr << "Error: Invalid number of arguments\n", 1);
    try{
        std::string rpNotation = av[1];
        Rpn ob(rpNotation);
        ob.rpnCalculator();
    }
    catch (std::exception &e){
        std::cerr << e.what();
    }
}
