//Name: Michaella Sheng
//SID: 861162403
//Date: 5-25-15

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>
#include <set>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

using namespace std::chrono;

//Stores list of words into a vector of strings
void storeList(std::vector<std::string> &vector)
{
    std::ifstream infs;
    std::string file = "words.txt";
    std::string word;
    infs.open(file.c_str());
    if(!infs)
    {
        std::cout << "Error opening " << file << ".\n";
        return;
    }
    while(infs >> word)
    {
        vector.push_back(word);
    }
    infs.close();
}
//Randomizes the list of words
void randomizeList(std::vector<std::string> &v)
{
    srand(time(0));
    for(unsigned i = v.size() - 1; i > 0; --i)
    {
        std::swap(v.at(i), v.at(rand() % v.size()));
    }
}
//Inserts a given number of words from the vector into the container
template<typename T>
void insertionTest(T &container, const std::vector<std::string> &v, const int n)
{
    for(int i = 0; i < n; ++i)
    {
        container.insert(v.at(i));
    }
}
//Finds every word in that container 
template<typename T>
void findTest(T &container)
{
    for(auto it = container.begin(); it != container.end(); ++it)
    {
        container.find(*it);
    }
}
//Stores every recorded runtime into a vector
void storeTimes(std::vector<int> &v, const int duration)
{
    v.push_back(duration);
}
//Calculates the average for each container type, word number size, and operation
//and writes all the data into a file called "data.txt" Formatting of that data
//is left up to user as gnuplot may not be used in all cases.
void calcAverage(const std::vector<int> &v)
{
    std::ofstream ofs("data.txt");
    int average = 0;
    int sum = 0;
    for(int j = 0; j < 40; ++j) //Marks the start of each run through
    {
        sum = 0;
        for(unsigned k = 0; k < v.size(); k += 40) //Finds average 
        {
            sum += v.at(k+j);
        }
        average = sum / 10;
        ofs << average << std::endl;
    }
}
//Calls all the above functions to test the runtimes of insertion and find on
//Hash Tables and Self-Balancing Trees, then stores the data into a file
void runtimeTest()
{
    std::vector<std::string> words;
    std::vector<int> runtimes;
    storeList(words);
    
    high_resolution_clock::time_point t1, t2;
    auto duration = 0;
    for(int i = 1; i <= 10; ++i)
    {
        randomizeList(words);
        for(int n = 5000; n <= 50000; n += 5000)
        {
            std::unordered_set<std::string> uoset;
            std::set<std::string> oset;
            
            t1 = high_resolution_clock::now();
            insertionTest(oset, words, n);
            t2 = high_resolution_clock::now();
            duration = duration_cast<milliseconds>(t2 - t1).count();
            storeTimes(runtimes, duration);
            
            t1 = high_resolution_clock::now();
            insertionTest(uoset, words, n);
            t2 = high_resolution_clock::now();
            duration = duration_cast<milliseconds>(t2 - t1).count();
            storeTimes(runtimes, duration);
            
            t1 = high_resolution_clock::now();
            findTest(oset);
            t2 = high_resolution_clock::now();
            duration = duration_cast<milliseconds>(t2 - t1).count();
            storeTimes(runtimes, duration);
            
            t1 = high_resolution_clock::now();
            findTest(uoset);
            t2 = high_resolution_clock::now();
            duration = duration_cast<milliseconds>(t2 - t1).count();
            storeTimes(runtimes, duration);
        }
    }
    calcAverage(runtimes);
}