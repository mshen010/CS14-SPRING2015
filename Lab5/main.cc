#include "lab5.h"

void testcase1()
{
    BST<int> x;
    
    x.insert(50);
    x.insert(20);
    x.insert(60);
    x.insert(10);
    x.insert(40);
    x.insert(70);
    x.insert(35);
    x.insert(45);
    
    int arr[50];
    std::map<int, int> m;
    
    std::cout << "Part 1\n";
    x.displayMinCover();
    std::cout << "Part 2\n";
    x.findSumPath(x.root, 80, arr);
    std::cout << "Part 3\n";
    x.vertSum(x.root, 0, m);
}
void testcase2()
{
    BST<int> x;

    int arr[50];
    std::map<int, int> m;
    
    std::cout << "Part 1\n";
    x.displayMinCover();
    std::cout << "Part 2\n";
    x.findSumPath(x.root, 80, arr);
    std::cout << "Part 3\n";
    x.vertSum(x.root, 0, m);
}
void testcase3()
{
    BST<int> x;
    
    x.insert(50);
    
    int arr[50];
    
    std::cout << "Part 2\n";
    x.findSumPath(x.root, -10, arr);
}
int main()
{
    // std::cout << "Testing with BST from example:\n";
    testcase1();
    // std::cout << "Testing with empty BST:\n";
    // testcase2();
    // std::cout << "Testing with invalid user entries:\n";
    // testcase3();
    
    return 0;
}