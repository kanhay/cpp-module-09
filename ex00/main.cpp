/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:26:31 by khanhayf          #+#    #+#             */
/*   Updated: 2024/03/16 12:38:29 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void    parsing(char *av){
    std::ifstream mydata;
    mydata.open("data.csv");
    if (!mydata.is_open())
        return(std::cerr << "Error: Can not open the Data base\n", exit(1));
    std::string line;
    std::getline(mydata, line); //first line
    std::map<std::string, double> mymap;
    //reading data base
    while(std::getline(mydata, line)){ 
        std::string date;
        double value;
        std::istringstream istr(line);
        getline(istr, date, ',');
       istr >> value;
        mymap[date] = value;}
    // open and check input in file.txt
    std::ifstream myinput;
    myinput.open(av);
    if (!myinput.is_open())
        return(std::cerr << "Error: can not open input file\n", mydata.close(), exit(1));
    std::string input;
    getline(myinput, input);
    std::istringstream istr(input);
    std::string s1;
    std::string s2;
    getline(istr, s1, '|');//read input file head
    getline(istr, s2);
    if (s1.empty() || s2.empty() || s1 != "date " || s2 != " value")
        return(std::cerr << "Error: Invalid head for input file\n", mydata.close(), myinput.close(), exit(1));
    double d; //to be able to use it outside the loop
    while(std::getline(myinput, line)){
        std::string date;
        std::string del;
        std::string value;
        std::istringstream iss(line);
        getline(iss, date, ' ');
        getline(iss, del, ' ');
        getline(iss, value);
        char *end;
        d = strtod(value.c_str(), &end);
        if (end[0] || value.empty() || del != "|" || d < 0 || d > 1000){
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;}
        int year, month, day;
        char del1;
        char del2;
        std::istringstream istr(date);
        if (!(istr >> year >> del1 >> month >> del2 >> day) || !istr.eof()
        || (del1 != '-' || del2 != '-') || (year < 0 || year > 9999)
        || (month < 1 || month > 12) || (day < 1 || day > 31)
        || (day == 29 && !(year % 4 == 0 && year % 100))){
            std::cerr << "Error: bad date => " << line << std::endl;
            continue ;}
        std::map<std::string, double>::iterator it;
        it = mymap.upper_bound(date);
        if (it == mymap.begin()){
            std::cerr << "Error: No element found before " << date << std::endl;
            continue ;}
        else{
            it--;
            std::cout << date << " => " << value << " = " << it->second * d << "\n";}
    }
    mydata.close();
    myinput.close();
}

int main(int , char **av){
    // if (ac != 2)
    //     return(std::cerr << "Error: invalid number of arguments\n", 1);
    parsing(av[1]);
}