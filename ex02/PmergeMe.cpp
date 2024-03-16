/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanhayf <khanhayf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:09:05 by khanhayf          #+#    #+#             */
/*   Updated: 2024/03/16 18:08:45 by khanhayf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void Parsing::parser(int ac, char **av, std::vector<int> &range){
    try{
        if (ac < 2)
            throw (std::invalid_argument("There is nothing to sort!\n"));
        for (int i = 1; i < ac; i++)
        {
            std::istringstream iss(av[i]);
            long element;
            iss >> element;
            if (iss.fail())
                throw (std::invalid_argument("Invalid input\n"));
            else{
                if (element < 0 || element > INT_MAX)
                    throw (std::invalid_argument("Invalid input\n"));
                range.push_back(element);
            }
        }
    }
    catch (std::exception &e){
        std::cerr << "Exception: " << e.what();
        exit(1);
    }
}

void Sorting::compPairedElements(std::vector<std::pair<int, int> > &chain){
    for (unsigned int i = 0; i < chain.size(); i++){
        if(chain[i].first < chain[i].second)
            std::swap(chain[i].first, chain[i].second);
    }
}

void Sorting::compPairedElements(std::deque<std::pair<int, int> > &chain){
    for (unsigned int i = 0; i < chain.size(); i++){
        if(chain[i].first < chain[i].second)
            std::swap(chain[i].first, chain[i].second);
    }
}

void    Sorting::merge(std::vector<std::pair<int, int> >::iterator begin,
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

void    Sorting::merge(std::deque<std::pair<int, int> >::iterator begin,
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

void    Sorting::mergeSortAlgo(std::vector<std::pair<int, int> > &chain, std::vector<std::pair<int, int> >::iterator begin, 
std::vector<std::pair<int, int> >::iterator end){
    std::vector<std::pair<int, int> >::iterator mid = begin + ((end - begin) / 2);
    if (begin == mid)
        return ;
    mergeSortAlgo(chain, begin, mid);
    mergeSortAlgo(chain, mid, end);
    merge(begin, mid, end);
}

void    Sorting::mergeSortAlgo(std::deque<std::pair<int, int> > &chain, std::deque<std::pair<int, int> >::iterator begin, 
std::deque<std::pair<int, int> >::iterator end){
    std::deque<std::pair<int, int> >::iterator mid = begin + ((end - begin) / 2);
    if (begin == mid)
        return ;
    mergeSortAlgo(chain, begin, mid);
    mergeSortAlgo(chain, mid, end);
    merge(begin, mid, end);
}


void Jacobsthal::myJacobsthal(std::vector<int>& vJacobsthal, std::vector<std::pair<int, int> > &chain){
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

void Jacobsthal::myJacobsthal(std::deque<int>& vJacobsthal, std::deque<std::pair<int, int> > &chain){
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

void container1(std::vector<int> &argVec){
    std::vector<std::pair<int, int> > paired;
    std::cout << "Before Sorting: ";
    for (unsigned int i = 0; i < argVec.size(); i++)
        std::cout << argVec[i] << " ";
    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now(); //chrono
    for (unsigned int i = 0; i < argVec.size(); i += 2){
        if (argVec.size() % 2 && (i + 1) == argVec.size()){
            paired.push_back(std::make_pair(argVec[i], -1));
            break;}
        paired.push_back(std::make_pair(argVec[i], argVec[i + 1]));
    }
    Sorting::compPairedElements(paired);
    if (paired.size() > 1)
        Sorting::mergeSortAlgo(paired, paired.begin(), paired.end());
    std::vector<int> firsts;
    // firsts.reserve(ac - 1);
    std::vector<int> seconds;
    separatePaired1(paired, firsts, seconds);
    std::vector<int> vJacobsthal;
    Jacobsthal::myJacobsthal(vJacobsthal, paired);
    if (seconds[0] >= 0) //only if the number of arguments is not odd
        firsts.insert(firsts.begin(), seconds[0]);
    unsigned int oldindex = 0;
    for (unsigned int i = 2; i < vJacobsthal.size(); i++){ //index 2 which contain number 3
        unsigned int newindex = i; //no need to deducte 1 because number 3 in JS is also in index 2
        if(newindex >= seconds.size())
            break;
        while (newindex > oldindex){
            std::vector<int>::iterator it;
            it = std::upper_bound(firsts.begin(), firsts.end(), seconds[newindex]);
            firsts.insert(it, seconds[newindex]);
            newindex--;
        }
        oldindex = i;
    }
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now(); //chrono
    std::cout << "\nAfter  Sorting: "; //printing arguments after sorting
    for (unsigned int i = 0; i < firsts.size(); i++)
        std::cout << firsts[i] << " ";
    std::chrono::microseconds time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "\nTime to process a range of " << argVec.size() << " elements with std::vector<int> : " << time.count() << " us\n";
}

void container2(std::vector<int> &argVec){
    std::deque<std::pair<int, int> > paired;
    std::cout << "Before Sorting: "; //printing arguments before sorting
    for (unsigned int i = 0; i < argVec.size(); i++)
        std::cout << argVec[i] << " ";
    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now(); //chrono
    for (unsigned int i = 0; i < argVec.size(); i += 2){
        if (argVec.size() % 2 && (i + 1) == argVec.size()){
            paired.push_back(std::make_pair(argVec[i], -1));
            break;}
        paired.push_back(std::make_pair(argVec[i], argVec[i + 1]));
    }
    Sorting::compPairedElements(paired);
    if (paired.size() > 1)
        Sorting::mergeSortAlgo(paired, paired.begin(), paired.end());
    std::deque<int> firsts;
    // firsts.reserve(ac - 1);
    std::deque<int> seconds;
    separatePaired2(paired, firsts, seconds);
    std::deque<int> vJacobsthal;
    Jacobsthal::myJacobsthal(vJacobsthal, paired);
    if (seconds[0] >= 0) //only if the number of arguments is not odd
        firsts.insert(firsts.begin(), seconds[0]);
    unsigned int oldindex = 0;
    for (unsigned int i = 2; i < vJacobsthal.size(); i++){ //index 2 which contain number 3
        unsigned int newindex = i; //no need to deducte 1 because number 3 in JS is also in index 2
        if(newindex >= seconds.size())
            break;
        while (newindex > oldindex){
            std::deque<int>::iterator it;
            it = std::upper_bound(firsts.begin(), firsts.end(), seconds[newindex]);
            firsts.insert(it, seconds[newindex]);
            newindex--;
        }
        oldindex = i;
    }
    std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now(); //chrono
    std::cout << "\nAfter  Sorting: "; //printing arguments after sorting
    for (unsigned int i = 0; i < firsts.size(); i++)
        std::cout << firsts[i] << " ";
    std::chrono::microseconds time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "\nTime to process a range of " << argVec.size() << " elements with std::deque<int> : " << time.count() << " us\n";
}
