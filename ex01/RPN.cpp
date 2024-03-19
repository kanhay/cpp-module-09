/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:31:52 by khanhayf          #+#    #+#             */
/*   Updated: 2024/03/19 20:24:44 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::Rpn(){}

Rpn::Rpn(std::string &arg){
    if (arg.empty())
        throw std::invalid_argument("Error");
    rpNotation = arg;}

Rpn::Rpn(const Rpn &ob){
    *this = ob;
}

Rpn& Rpn::operator=(const Rpn& ob){
    if (this != &ob)
        rpNotation = ob.rpNotation;
    return(*this);
}

Rpn::~Rpn(){
    
}

long Rpn::doOperation(long nbr1, long nbr2, char op){
    if (op == '+')
        return (nbr1 + nbr2);
    else if (op == '-')
        return (nbr1 - nbr2);
    else if (op == '/')
        return (nbr1 / nbr2);
    else
        return (nbr1 * nbr2);
}

void    Rpn::rpnCalculator(){
    std::stack<int> mystack;
    std::istringstream iss(rpNotation);
    std::string element;
    int f = 0;
    while (iss >> element){
        f++;
        if (element.size() == 1 && std::strchr("+-/*", element[0])){
            if (mystack.size() < 2)
                throw (std::invalid_argument("Error\n"));
            if (element[0] == '/' && mystack.top() == 0)
                throw (std::invalid_argument("Error\n"));
            long nbr2 = mystack.top();
            mystack.pop();
            long nbr1 = mystack.top();
            mystack.pop();
            long res = doOperation(nbr1, nbr2, element[0]);
            if (res < INT_MIN || res > INT_MAX)
                throw (std::invalid_argument("Error\n"));
            mystack.push(res);
        }
        else if ((std::isdigit(element[0]) || element[0] == '-' || element[0] == '+')){
            char *end;
            double d = std::strtod(element.c_str(), &end);
            if (end[0])
                throw (std::invalid_argument("Error\n"));
            mystack.push(d);
        }
        else
            throw (std::invalid_argument("Error\n"));
    }
    if (f == 0)
        throw (std::invalid_argument("Error\n"));
    if (!mystack.empty() && mystack.size() == 1)
        std::cout << mystack.top() << "\n";
    else
        throw (std::invalid_argument("Error\n"));
}
