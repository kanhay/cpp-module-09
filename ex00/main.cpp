/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:26:31 by khanhayf          #+#    #+#             */
/*   Updated: 2024/03/19 13:14:16 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char **av){
    try{
        if (ac != 2)
            throw std::invalid_argument("Invalid number of arguments\n");
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
