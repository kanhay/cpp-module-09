/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:09:42 by khanhayf          #+#    #+#             */
/*   Updated: 2024/03/16 17:49:10 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGME
#define PMERGME

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <deque>
#include <chrono>

class Parsing{
    public:
    static void parser(int ac, char **av, std::vector<int> &range);
};

class Jacobsthal{
    public:
    static void myJacobsthal(std::vector<int>& vJacobsthal, std::vector<std::pair<int, int> > &chain);
    static void myJacobsthal(std::deque<int>& vJacobsthal, std::deque<std::pair<int, int> > &chain);
};

class Sorting{
    public:
    static void compPairedElements(std::vector<std::pair<int, int> > &chain);
    static void compPairedElements(std::deque<std::pair<int, int> > &chain);
    
    static void    mergeSortAlgo(std::vector<std::pair<int, int> > &chain, std::vector<std::pair<int, int> >::iterator begin, 
    std::vector<std::pair<int, int> >::iterator end);
    static void    mergeSortAlgo(std::deque<std::pair<int, int> > &chain, std::deque<std::pair<int, int> >::iterator begin, 
    std::deque<std::pair<int, int> >::iterator end);

    static void    merge(std::vector<std::pair<int, int> >::iterator begin,
    std::vector<std::pair<int, int> >::iterator mid, std::vector<std::pair<int, int> >::iterator end);
    static void    merge(std::deque<std::pair<int, int> >::iterator begin,
    std::deque<std::pair<int, int> >::iterator mid, std::deque<std::pair<int, int> >::iterator end);
};

void container1(std::vector<int> &argVec);
void container2(std::vector<int> &argVec);
#endif