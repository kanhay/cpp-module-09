/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:44:28 by khanhayf          #+#    #+#             */
/*   Updated: 2024/03/19 13:16:01 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av){
    try{
        if (ac != 2)
            throw std::invalid_argument("Invalid number of arguments\n");
        std::string rpNotation = av[1];
        Rpn ob(rpNotation);
        ob.rpnCalculator();
    }
    catch (std::exception &e){
        std::cerr << e.what();
    }
}
