/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:44:53 by khanhayf          #+#    #+#             */
/*   Updated: 2024/03/17 19:58:21 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>

class Rpn{
    private:
        std::string rpNotation;
        long doOperation(long nbr1, long nbr2, char op);
        Rpn();
    public:
        Rpn(std::string &arg);
        Rpn(const Rpn &ob);
        Rpn& operator=(const Rpn& ob);
        ~Rpn();
        
        void    rpnCalculator();
};
#endif
