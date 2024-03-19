/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:09:33 by khanhayf          #+#    #+#             */
/*   Updated: 2024/03/19 21:59:07 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av){
    try{
        PmergeMe ob;
        std::vector<int> argVec;
        ob.parser(ac, av, argVec);
        ob.container1(argVec);
        ob.container2(argVec);
    }
    catch (std::exception &e){
        std::cerr << "Exception: " << e.what();
    }
}