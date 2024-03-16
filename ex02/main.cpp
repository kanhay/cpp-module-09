/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:09:33 by khanhayf          #+#    #+#             */
/*   Updated: 2024/03/16 15:25:21 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av){
    std::vector<int> argVec;
    Parsing::parser(ac, av, argVec);
    container1(argVec);
    container2(argVec);
}