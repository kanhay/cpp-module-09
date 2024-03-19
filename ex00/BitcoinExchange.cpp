/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:26:04 by khanhayf          #+#    #+#             */
/*   Updated: 2024/03/19 19:46:19 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange():databeseFile("data.csv"){
}

BitcoinExchange::BitcoinExchange(const std::string &file):databeseFile("data.csv"), inputFile(file){ 
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ob){
    *this = ob;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ob){
    if (this != &ob){
        databeseFile = ob.databeseFile;
        inputFile = ob.inputFile;
        mymap.clear();
        mymap.insert(ob.mymap.begin(), ob.mymap.end());
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange(){
}

void    BitcoinExchange::fillMymap(){
    std::ifstream mydata(databeseFile);
    if (!mydata.is_open())
        throw std::runtime_error("Can not open the Data base\n");
    std::string line;
    std::getline(mydata, line);
    while(std::getline(mydata, line)){ 
        std::string date;
        double value;
        std::istringstream istr(line);
        getline(istr, date, ',');
        istr >> value;
        mymap[date] = value;}
    mydata.close();
}

void    BitcoinExchange::checkInputfile(){
    std::ifstream myinput(inputFile);
    if (!myinput.is_open())
        throw std::invalid_argument("Can not open input file\n");
    std::string input;
    getline(myinput, input);
    std::istringstream istr(input);
    std::string s1, s2;
    getline(istr, s1, '|');
    getline(istr, s2);
    if (s1.empty() || s2.empty() || s1 != "date " || s2 != " value")
        throw std::runtime_error("Invalid head for input file\n");
    myinput.close();
}

void    BitcoinExchange::BtcExchange(){
    std::ifstream myinput(inputFile);
    std::string line;
    std::getline(myinput, line);
    while(std::getline(myinput, line)){
        std::string date, del, value;
        std::istringstream iss(line);
        iss >> date >> del >> value;
        char *end;
        double d = strtod(value.c_str(), &end);
        if (iss.fail() || !iss.eof() || del != "|"
        || date[0] == '+' || date[5] == '+' || date[8] == '+' || end[0] || d < 0 || d > 1000){
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;}
        int year, month, day;
        char del1, del2;
        std::istringstream istr(date);
        if (!(istr >> year >> del1 >> month >> del2 >> day) || !istr.eof()
        || (del1 != '-' || del2 != '-') || (year < 1 || year > 9999)
        || (month < 1 || month > 12) || (day < 1 || day > 31) ||
        ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        || (month == 2 && day > 29)
        || (month == 2 && day == 29 &&  !(year % 4 == 0 && (year % 100 || year % 400 == 0)))){
            std::cerr << "Error: bad date => " << line << std::endl;
            continue ;}
        std::map<std::string, double>::iterator it;
        it = mymap.upper_bound(date);
        if (it == mymap.begin()){
            std::cerr << "No data found for " << date << std::endl;
            continue ;}
        else{
            it--;
            std::cout << date << " => " << value << " = " << it->second * d << "\n";}
    }
    myinput.close();
}
