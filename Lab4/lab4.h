//Name: Michaella Sheng
//SID: 861162403
//Date: 5-3-15
#ifndef LAB4_H
#define LAB$_H

#include <stack>
#include <queue>
#include <iostream>
#include <utility>

class coprime {
    private:
        int usernum; //Set as the number the user passes in
        std::pair<int, int> p1;
        std::priority_queue<std::pair<int, int> > q; //Queue of pairs
    public:
        coprime(int x)
            : usernum(x)
        {}
        //Recursively outputs the coprime elements passed in from the command 
        //line in a preorder format.
        void preorder(int m, int n) 
        {
            //Base case
            if(m + n >= usernum) 
            {
                return;
            }
            std::cout << m << ' ' << n << std::endl;
            preorder(2*m - n, m);
            preorder(2*m + n, m);
            preorder(m + 2*n, n);
        }
        //Recursively outputs the coprime elements passed in from the command 
        //line in a postorder format.
        void postorder(int m, int n)
        {
            //Base case
            if(m + n >= usernum)
            {
                return;
            }
            postorder(2*m - n, m);
            postorder(2*m + n, m);
            postorder(m + 2*n, n);
            std::cout << m << ' ' << n << std::endl;
        }
        //Recursively creates and pushes into the priority queue a pair while 
        //the sum of the two elements is less than the number passed in from 
        //the command line
        void inorder(int m, int n)
        {
            if(m + n >= usernum) 
            {
                return;
            }
            p1.first = m;
            p1.second = n;
            q.push(p1);
            inorder(2*m - n, m);
            inorder(2*m + n, m);
            inorder(m + 2*n, n);
            return;
        }
        //Outputs in order of smallest to highest based on first value of pair,
        //then the second value if first values are equal.
        void sorted()
        {
            std::stack<std::pair<int, int> > s;
            //Pushes pairs into a stack, as outputting directly from the 
            //priority queue qould result in descending order.
            while(!q.empty())
            {
                s.push(q.top());
                q.pop();
            }
            //Outputs in ascending order
            while(!s.empty())
            {
                std::cout << s.top().first << ' ' << s.top().second << std::endl;
                s.pop();
            }
        }
};

#endif