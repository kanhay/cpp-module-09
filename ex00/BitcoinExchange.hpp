/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:25:46 by khanhayf          #+#    #+#             */
/*   Updated: 2024/03/17 20:02:36 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

# include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>


class BitcoinExchange{
    private:
    std::string databeseFile, inputFile;
    std::map<std::string, double> mymap;
    BitcoinExchange();
    public:
    BitcoinExchange(std::string &file);
    BitcoinExchange(const BitcoinExchange& ob);
    BitcoinExchange& operator=(const BitcoinExchange& ob);
    ~BitcoinExchange();
    void    fillMymap();
    void    checkInputfile();
    void    BtcExchange();
};
#endif