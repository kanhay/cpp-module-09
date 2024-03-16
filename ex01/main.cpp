/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:31:52 by khanhayf          #+#    #+#             */
/*   Updated: 2024/03/13 14:16:59 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void    rpn(std::string av){
    std::stack<int> mystack;
    std::istringstream iss(av);
    std::string element;
    while (iss >> element){
        if (!element.empty() && element.size() == 1 && std::strchr("+-/*", element[0])){
            if (mystack.size() < 2)
                return(std::cerr << "Error\n", exit(1));
            int nbr2 = mystack.top();
            mystack.pop();
            int nbr1 = mystack.top();
            mystack.pop();
            // std::cout << nbr1 << element[0] << nbr2 << std::endl;
            int res;
            if (element[0] == '+')
                res = nbr1 + nbr2;
            else if (element[0] == '-')
                res = nbr1 - nbr2;
            else if (element[0] == '/'){
                if (nbr2 == 0)
                    return(std::cerr << "Error\n", exit(1));
                res = nbr1 / nbr2;
            }
            else
                res = nbr1 * nbr2;
            mystack.push(res);
        }
        else if (!element.empty() && (std::isdigit(element[0]) || element[0] == '-' || element[0] == '+')){
            char *end;
            std::strtod(element.c_str(), &end);
            if (end[0])
                return(std::cerr << "Error\n", exit(1));
            mystack.push(std::stoi(element));
        }
        else
            return(std::cerr << "Error\n", exit(1));
    }
    if (!mystack.empty())
        std::cout << mystack.top();
}

int main(int ac, char **av){
    if (ac != 2)
        return (std::cerr << "Error: Invalid number of arguments\n", 1);
    rpn(av[1]);
}
