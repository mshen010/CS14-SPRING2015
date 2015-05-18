#include "selectionsort.h"
#include <list>
#include <vector>
#include <map>

void vectorTest()
{
    std::vector<int> v;
    
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    v.push_back(8);
    v.push_back(9);
    std::cout << "pre: ";
    for(unsigned i = 0; i < v.size(); ++i)
    {
        std::cout << v.at(i) << ' ';
    }
    std::cout << std::endl;
    selectionsort(v);
    std::cout << "post: ";
    for(unsigned i = 0; i < v.size(); ++i)
    {
        std::cout << v.at(i) << ' ';
    }
    std::cout << std::endl;
}
void emptyVectorTest()
{
    std::vector<int> v;
    
    std::cout << "pre: ";
    for(unsigned i = 0; i < v.size(); ++i)
    {
        std::cout << v.at(i) << ' ';
    }
    std::cout << std::endl;
    selectionsort(v);
    std::cout << "post: ";
    for(unsigned i = 0; i < v.size(); ++i)
    {
        std::cout << v.at(i) << ' ';
    }
    std::cout << std::endl;
}
void listTest()
{
    std::list<int> l;
    l.push_back(2);
    l.push_back(4);
    l.push_back(5);
    l.push_back(1);
    l.push_back(8);
    l.push_back(9);
    std::cout << "pre: ";
    for(auto it = l.begin(); it != l.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
    selectionsort(l);
    std::cout << "post: ";
    for(auto it = l.begin(); it != l.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}
void vectorPairTest1()
{
    std::vector<std::pair<int, int> > v;
    v.push_back(std::pair<int, int> (1,2));
    v.push_back(std::pair<int, int> (3,-1));
    v.push_back(std::pair<int, int> (-1,3));
    v.push_back(std::pair<int, int> (0,0));
    v.push_back(std::pair<int, int> (2,3));
    v.push_back(std::pair<int, int> (1,2));
    v.push_back(std::pair<int, int> (1,-2));
    v.push_back(std::pair<int, int> (8,10));
    std::cout << "pre: ";
    for(unsigned i = 0; i < v.size(); ++i)
    {
        std::cout << "(" << v.at(i).first << "," << v.at(i).second << ") ";
    }
    std::cout << std::endl;
    int moves = selSortCounter(v);
    std::cout << "post: ";
    for(unsigned i = 0; i < v.size(); ++i)
    {
        std::cout << "(" << v.at(i).first << "," << v.at(i).second << ") ";
    }
    std::cout << std::endl;
    std::cout << "0 copies and " << moves << " moves\n";
}
void vectorPairTest2()
{
    std::vector<std::pair<int, int> > v;
    v.push_back(std::pair<int, int> (10,2));
    v.push_back(std::pair<int, int> (-3,-1));
    v.push_back(std::pair<int, int> (-8,0));
    v.push_back(std::pair<int, int> (1,1));
    v.push_back(std::pair<int, int> (1,1));
    v.push_back(std::pair<int, int> (0,0));
    v.push_back(std::pair<int, int> (10,2));
    v.push_back(std::pair<int, int> (5,5));
    v.push_back(std::pair<int, int> (5,-5));
    v.push_back(std::pair<int, int> (0,0));
    v.push_back(std::pair<int, int> (10,2));
    std::cout << "pre: ";
    for(unsigned i = 0; i < v.size(); ++i)
    {
        std::cout << "(" << v.at(i).first << "," << v.at(i).second << ") ";
    }
    std::cout << std::endl;
    int moves = selSortCounter(v);
    std::cout << "post: ";
    for(unsigned i = 0; i < v.size(); ++i)
    {
        std::cout << "(" << v.at(i).first << "," << v.at(i).second << ") ";
    }
    std::cout << std::endl;
    std::cout << "0 copies and " << moves << " moves\n";
}
void vectorPairTest3()
{
    std::vector<std::pair<int, int> > v;
    v.push_back(std::pair<int, int> (-1,3));
    v.push_back(std::pair<int, int> (0,0));
    v.push_back(std::pair<int, int> (1,-2));
    v.push_back(std::pair<int, int> (1,2));
    v.push_back(std::pair<int, int> (1,2));
    v.push_back(std::pair<int, int> (2,3));
    v.push_back(std::pair<int, int> (3,-1));
    v.push_back(std::pair<int, int> (8,10));
    std::cout << "pre: ";
    for(unsigned i = 0; i < v.size(); ++i)
    {
        std::cout << "(" << v.at(i).first << "," << v.at(i).second << ") ";
    }
    std::cout << std::endl;
    int moves = selSortCounter(v);
    std::cout << "post: ";
    for(unsigned i = 0; i < v.size(); ++i)
    {
        std::cout << "(" << v.at(i).first << "," << v.at(i).second << ") ";
    }
    std::cout << std::endl;
    std::cout << "0 copies and " << moves << " moves\n";
}
//Question 2 Part b
void stableTest()
{
    std::vector<int> v1;
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(1);
    v1.push_back(1);
    int moves = selSortUnstable(v1);
    std::cout << moves << std::endl;
    
    std::vector<int> v2;
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(1);
    v2.push_back(1);
    moves = selSortCounter(v2);
    std::cout << moves << std::endl;
}
int main()
{
    vectorTest();
    emptyVectorTest();
    // listTest();
    vectorPairTest1();
    vectorPairTest2();
    vectorPairTest3();
    // stableTest();
    return 0;
}