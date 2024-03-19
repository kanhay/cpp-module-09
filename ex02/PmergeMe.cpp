/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:09:05 by khanhayf          #+#    #+#             */
/*   Updated: 2024/03/19 22:50:31 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe& ){}
PmergeMe& PmergeMe::operator=(const PmergeMe& ){
    return *this;
}
PmergeMe::~PmergeMe(){}

void PmergeMe::parser(int ac, char **av, std::vector<int> &range){
    if (ac < 2)
        throw (std::invalid_argument("There is nothing to sort!\n"));
    for (int i = 1; i < ac; i++)
    {
        std::istringstream iss(av[i]);
        long element;
        iss >> element;
        if (iss.fail() || !iss.eof())
            throw (std::invalid_argument("Invalid input\n"));
        else{
            if (element < 0 || element > INT_MAX)
                throw (std::invalid_argument("Invalid input\n"));
            range.push_back(element);
        }
    }
}

void PmergeMe::compPairedElements(std::vector<std::pair<int, int> > &chain){
    for (unsigned int i = 0; i < chain.size(); i++){
        if(chain[i].first < chain[i].second)
            std::swap(chain[i].first, chain[i].second);
    }
}

void PmergeMe::compPairedElements(std::deque<std::pair<int, int> > &chain){
    for (unsigned int i = 0; i < chain.size(); i++){
        if(chain[i].first < chain[i].second)
            std::swap(chain[i].first, chain[i].second);
    }
}

void    PmergeMe::merge(std::vector<std::pair<int, int> >::iterator begin,
std::vector<std::pair<int, int> >::iterator mid, std::vector<std::pair<int, int> >::iterator end){
    std::vector<std::pair<int, int> >::iterator i = begin;
    std::vector<std::pair<int, int> >::iterator j = mid;
    
    std::vector<std::pair<int, int> > sortedfirsts(end - begin);
    std::vector<std::pair<int, int> >::iterator k = sortedfirsts.begin();
    while (i < mid && j < end){
        if (*i < *j)
            *k++ = *i++;
        else
            *k++ = *j++;
    }
    while (i < mid)
        *k++ = *i++;
    while (j < end)
        *k++ = *j++;
    std::copy(sortedfirsts.begin(), sortedfirsts.end(), begin);
}

void    PmergeMe::merge(std::deque<std::pair<int, int> >::iterator begin,
std::deque<std::pair<int, int> >::iterator mid, std::deque<std::pair<int, int> >::iterator end){
    std::deque<std::pair<int, int> >::iterator i = begin;
    std::deque<std::pair<int, int> >::iterator j = mid;
    
    std::deque<std::pair<int, int> > sortedfirsts(end - begin);
    std::deque<std::pair<int, int> >::iterator k = sortedfirsts.begin();
    while (i < mid && j < end){
        if (*i < *j)
            *k++ = *i++;
        else
            *k++ = *j++;
    }
    while (i < mid)
        *k++ = *i++;
    while (j < end)
        *k++ = *j++;
    std::copy(sortedfirsts.begin(), sortedfirsts.end(), begin);
}

void    PmergeMe::mergeSortAlgo(std::vector<std::pair<int, int> >::iterator begin, 
std::vector<std::pair<int, int> >::iterator end){
    std::vector<std::pair<int, int> >::iterator mid = begin + ((end - begin) / 2);
    if (begin == mid)
        return ;
    
    mergeSortAlgo(begin, mid);
    mergeSortAlgo(mid, end);
    merge(begin, mid, end);
}

void    PmergeMe::mergeSortAlgo(std::deque<std::pair<int, int> >::iterator begin, 
std::deque<std::pair<int, int> >::iterator end){
    std::deque<std::pair<int, int> >::iterator mid = begin + ((end - begin) / 2);
    if (begin == mid)
        return ;
    mergeSortAlgo(begin, mid);
    mergeSortAlgo(mid, end);
    merge(begin, mid, end);
}


void PmergeMe::myJacobsthal(std::vector<int>& vJacobsthal, std::vector<std::pair<int, int> > &chain){
    vJacobsthal.push_back(1);
    vJacobsthal.push_back(1);
    std::vector<int>::iterator j = --vJacobsthal.end();
    std::vector<int>::iterator i;
    for (unsigned int k = 0; k < chain.size(); k++){
        i = j - 1;
       vJacobsthal.push_back(*j + (*i * 2));
       j = --vJacobsthal.end();
    }
}

void PmergeMe::myJacobsthal(std::deque<int>& vJacobsthal, std::deque<std::pair<int, int> > &chain){
    vJacobsthal.push_back(1);
    vJacobsthal.push_back(1);
    std::deque<int>::iterator j = --vJacobsthal.end();
    std::deque<int>::iterator i;
    for (unsigned int k = 0; k < chain.size(); k++){
        i = j - 1;
        vJacobsthal.push_back(*j + (*i * 2));
        j = --vJacobsthal.end();
    }
}

void    separatePaired1(std::vector<std::pair<int, int> > &paired, std::vector<int> &firsts, std::vector<int> &seconds){
    for (unsigned int i = 0; i < paired.size(); i++){
            firsts.push_back(paired[i].first);
            seconds.push_back(paired[i].second);
    }
}

void    separatePaired2(std::deque<std::pair<int, int> > &paired, std::deque<int> &firsts, std::deque<int> &seconds){
    std::deque<std::pair<int, int> >::iterator it;
    
    for (it = paired.begin(); it != paired.end(); it++){
        firsts.push_back(it->first);
        seconds.push_back(it->second);
    }
}

void PmergeMe::container1(std::vector<int> &argVec){
    std::cout << "Before Sorting: ";
    for (unsigned int i = 0; i < argVec.size(); i++)
        std::cout << argVec[i] << " ";
    std::vector<std::pair<int, int> > paired;
    std::vector<int> firsts;
    clock_t start = clock();
    if (argVec.size() > 1){
        for (unsigned int i = 0; i < argVec.size(); i += 2){
            if (argVec.size() % 2 && (i + 1) == argVec.size()){
                paired.push_back(std::make_pair(argVec[i], -1));
                break;}
            paired.push_back(std::make_pair(argVec[i], argVec[i + 1]));
        }
        compPairedElements(paired);
        mergeSortAlgo(paired.begin(), paired.end());
        std::vector<int> seconds;
        separatePaired1(paired, firsts, seconds);
        std::vector<int> vJacobsthal;
        myJacobsthal(vJacobsthal, paired);
        firsts.insert(firsts.begin(), seconds[0]);
        unsigned int oldindex = 0;
        unsigned int i = 2;
        if (seconds.size() - 1 < 2)
            i = seconds.size() - 1;
        while (i < seconds.size()){
            unsigned int newindex = i;
            if(newindex >= seconds.size())
                break;
            while (newindex > oldindex){
                std::vector<int>::iterator it;
                it = std::upper_bound(firsts.begin(), firsts.end(), seconds[newindex]);
                firsts.insert(it, seconds[newindex]);
                newindex--;
            }
            oldindex = i;
            i++;
        }}
    clock_t end = clock();
    std::cout << "\nAfter  Sorting: ";
    for (unsigned int i = 0; i < firsts.size(); i++){
        if (firsts[i] >= 0)
        std::cout << firsts[i] << " ";}
    if (argVec.size() == 1)
        std::cout << argVec[0];
    clock_t diff = end - start;
    std::cout << "\nTime to process a range of " << argVec.size() << " elements with std::vector<int> : " << ((double)diff / CLOCKS_PER_SEC)  * 1e6 << " us\n";
}

void PmergeMe::container2(std::vector<int> &argVec){
    std::cout << "Before Sorting: ";
    for (unsigned int i = 0; i < argVec.size(); i++)
        std::cout << argVec[i] << " ";
    std::deque<std::pair<int, int> > paired;
    std::deque<int> firsts;
    
    clock_t start = clock();
    if (argVec.size() > 1){
        for (unsigned int i = 0; i < argVec.size(); i += 2){
            if (argVec.size() % 2 && (i + 1) == argVec.size()){
                paired.push_back(std::make_pair(argVec[i], -1));
                break;}
            paired.push_back(std::make_pair(argVec[i], argVec[i + 1]));
        }
        compPairedElements(paired);
        mergeSortAlgo(paired.begin(), paired.end());
        std::deque<int> seconds;
        separatePaired2(paired, firsts, seconds);
        std::deque<int> vJacobsthal;
        myJacobsthal(vJacobsthal, paired);
        firsts.insert(firsts.begin(), seconds[0]);
        unsigned int oldindex = 0;
        unsigned int i = 2;
        if (seconds.size() <= 2)
            i = seconds.size() - 1;
        while (i < seconds.size()){
            unsigned int newindex = i;
            if(newindex >= seconds.size())
                break;
            while (newindex > oldindex){
                std::deque<int>::iterator it;
                it = std::upper_bound(firsts.begin(), firsts.end(), seconds[newindex]);
                firsts.insert(it, seconds[newindex]);
                newindex--;
            }
            oldindex = i;
            i++;
        }}
    clock_t end = clock();
    std::cout << "\nAfter  Sorting: ";
    for (unsigned int i = 0; i < firsts.size(); i++){
        if (firsts[i] >= 0)
            std::cout << firsts[i] << " ";
    }
    if (argVec.size() == 1)
        std::cout << argVec[0];
    clock_t diff = (end - start);
    std::cout << "\nTime to process a range of " << argVec.size() << " elements with std::deque<int> : " << ((double)diff / CLOCKS_PER_SEC) * 1e6 << " us\n";
}
