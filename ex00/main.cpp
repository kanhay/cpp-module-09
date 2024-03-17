/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:26:31 by khanhayf          #+#    #+#             */
/*   Updated: 2024/03/17 17:21:30 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char **av){
    if (ac != 2)
        return(std::cerr << "Error: invalid number of arguments\n", 1);
    try{
        std::string file = av[1];
        BitcoinExchange ob(file);
        ob.fillMymap();
        ob.checkInputfile();
        ob.BtcExchange();
    }
    catch (std::exception &e){
        std::cerr << "Exception: " << e.what();
    }
}
