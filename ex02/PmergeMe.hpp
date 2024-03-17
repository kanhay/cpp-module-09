/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:09:42 by khanhayf          #+#    #+#             */
/*   Updated: 2024/03/17 21:31:28 by khanhayf         ###   ########.fr       */
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

class PmergeMe{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& ob);
        PmergeMe& operator=(PmergeMe& ob);
        ~PmergeMe();

        void parser(int ac, char **av, std::vector<int> &range);
    
        void myJacobsthal(std::vector<int>& vJacobsthal, std::vector<std::pair<int, int> > &chain);
        void myJacobsthal(std::deque<int>& vJacobsthal, std::deque<std::pair<int, int> > &chain);
        
    
        void compPairedElements(std::vector<std::pair<int, int> > &chain);
        void compPairedElements(std::deque<std::pair<int, int> > &chain);
        
        void    mergeSortAlgo(std::vector<std::pair<int, int> > &chain, std::vector<std::pair<int, int> >::iterator begin, 
                std::vector<std::pair<int, int> >::iterator end);
        void    mergeSortAlgo(std::deque<std::pair<int, int> > &chain, std::deque<std::pair<int, int> >::iterator begin, 
                std::deque<std::pair<int, int> >::iterator end);
    
        void    merge(std::vector<std::pair<int, int> >::iterator begin,
                std::vector<std::pair<int, int> >::iterator mid, std::vector<std::pair<int, int> >::iterator end);
        void    merge(std::deque<std::pair<int, int> >::iterator begin,
                std::deque<std::pair<int, int> >::iterator mid, std::deque<std::pair<int, int> >::iterator end);
        
        void container1(std::vector<int> &argVec);
        void container2(std::vector<int> &argVec);
};

#endif