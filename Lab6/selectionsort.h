//Name: Michaella Sheng
//SID: 861162403
//Date: 5-18-15
//Approach:
#include <iostream>

template<typename L>
void selectionsort(L &l)
{
    typename L::iterator it1;
    typename L::iterator it2;
    typename L::iterator smallest;
    for(it1 = l.begin(); it1 != l.end(); ++it1)
    {
        smallest = it1;
        //it2 = it1 + 1 replaced with it2 = i21, which is slightly less 
        //efficient, but allows the algorithm to work for lists.
        for(it2 = it1; it2 != l.end(); ++it2) 
        {
            if(*it2 < *smallest)
            {
                smallest = it2;
            }
        }
        if(*smallest != *it1)
        {
            std::swap(*smallest, *it1);
        }
    }
}
//This function is called if the programmer wants to know the number of moves
template<typename L>
int selSortCounter(L &l)
{
    typename L::iterator it1;
    typename L::iterator it2;
    typename L::iterator smallest;
    int moves = 0;
    for(it1 = l.begin(); it1 != l.end(); ++it1)
    {
        smallest = it1;
        for(it2 = it1; it2 != l.end(); ++it2) 
        {
            if(*it2 < *smallest)
            {
                smallest = it2;
            }
        }
        if(*smallest != *it1)
        {
            std::swap(*smallest, *it1);
            ++moves;
        }
    }
    return moves*3;
}

template<typename L>
int selSortUnstable(L &l)
{
    typename L::iterator it1;
    typename L::iterator it2;
    typename L::iterator smallest;
    int moves = 0;
    for(it1 = l.begin(); it1 != l.end(); ++it1)
    {
        smallest = it1;
        for(it2 = it1; it2 != l.end(); ++it2) 
        {
            if(*it2 < *smallest)
            {
                smallest = it2;
            }
        }
        std::swap(*smallest, *it1);
        ++moves;
    }
    return moves*3;
}