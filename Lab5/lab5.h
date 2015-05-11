// Name: Michaella Sheng
// SID: 861162403
// Date: 5-10-15

#ifndef LAB5_H
#define LAB5_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <vector>
#include <map>

#define nil 0

template <typename Value>
class BST 
{
    //Binary Tree Node
    class Node 
    { 
        public:
            Node* left;
            Node* right;
            Value value;
            bool selected;
            
            Node(const Value v = Value())
                : left(nil), right(nil), value(v), selected(false) {}
            Value& content() { return value; }
            bool isInternal() { return left != nil && right != nil; }
            bool isExternal() { return left != nil || right != nil; }
            bool isLeaf() { return left == nil && right == nil;}
            //Returns the height of the tree/subtree at this node
            int height() {
                if(this == nil) 
                {
                    return -1;
                }
                int l = left->height();
                int r = right->height();
                if(l > r) 
                {
                    return l + 1;
                }
                return r + 1;
            }
            //Returns the number of nodes rooted at this node
            int size() 
            {
                if(this == nil) 
                {
                    return 0;
                }
                if(isLeaf())
                {
                    return 1;
                }
                return left->size() + right->size() + 1;
            }
            //Outputs the value of the nodes in the tree in preorder format.
            void preorder_()
            {
                if(this == nil)
                {
                    return;
                }
                std::cout << value << std::endl;
                left->preorder_();
                right->preorder_();
            }
            //Outputs the value of the nodes in the tree in postorder format.
            void postorder_()
            {
                if(this == nil)
                {
                    return;
                }
                left->postorder_();
                right->postorder_();
                std::cout << value << std::endl;
            }
            //Outputs the value of the nodes in the tree in inorder format.
            void inorder_() 
            { 
                if(this == nil)
                {
                    return;
                }
                left->inorder_();
                std::cout << value << std::endl;
                right->inorder_();
            }
            void find(int& count, std::vector<Node*>& v)
            {
                if(this == nil)
                {
                    return;
                }
                if(count == 0)
                {
                    v.push_back(this);
                    return;
                }
                v.push_back(this);
                --count;
                left->find(count, v);
                right->find(count, v);
                return;
            }
            //Passes in the size by reference to allow for updates in a 
            //recursive solution
            void displayMinCoverH(int& size)
            {
                //No cover exists. Root is not a cover.
                if(this == nil || isLeaf())
                {
                    return;
                }
                left->displayMinCoverH(size);
                //If a node found is selected, will increase the size of the 
                //cover and output that node's value
                if(this->selected)
                {
                    ++size;
                    std::cout << value << ' ';
                }
                right->displayMinCoverH(size);
            }
            void minCover()
            {
                if(this == nil || isLeaf())
                {
                    return;
                }
                left->minCover();
                right->minCover();
                //A node is only part of a cover if it has at least one child and 
                //neither of them are marked as selected.
                if((left != nil && left->selected == 0) || (right != nil && right->selected == 0))
                {
                    selected = true;
                    return;
                }
                //If there are children and they are selected, then the parent
                //node will not be part of the cover
                if((left != nil && left->selected) || (right != nil && right->selected))
                {
                    selected = false;
                    return;
                }
                return;
            }
            bool makePath(int &count, int sum, std::vector<int> &v)
            {
                if(this == nil)
                {
                    return false;
                }
                //End of path is reached, in which case the node must be checked
                //to see if its value plus the current sum is equal to the sum
                //of comparison
                if(isLeaf())
                {
                    //Node is inserted into the vector as part of the path.
                    if(count + value == sum) 
                    {
                        count += value;
                        v.insert(v.begin(), value);
                        return true;
                    }
                    //Node is not part of the path
                    return false;
                }
                //Within each step, the current node may be equal to the sum
                //itself, which is what this tests
                if(count == sum) 
                {
                    return true;
                }
                count += value;
                v.insert(v.begin(), value);
                if(count == sum) 
                {
                    return true;
                }
                left->makePath(count, sum, v); 
                if(count == sum) 
                {
                    return true;
                }
                right->makePath(count, sum, v); 
                if(count == sum) 
                {
                    return true;
                }
                count -= value; 
                v.erase(v.begin());
                return false;
            } 
            void displaySumPath(bool found, int buffer[])
            {
                //If path for the sum cannot be found display 0 as the sum.
                if(!found) 
                {
                    std::cout << "0\n";
                    return;
                } 
                //Else if a path is found, display the path by accessing the
                //proper nodes through the buffer.
                for(int i = 0; buffer[i] != '\0'; ++i)
                {
                    std::cout << buffer[i] << ' ';
                }
                std::cout << std::endl;
            }
            void vertSum_H(int& offset, std::map<int, int>& m)
            {
                if(this == nil)
                {
                    return;
                }
                //Searches for all nodes to the left with the new decremented hd
                --offset; 
                left->vertSum_H(offset, m);
                //Searches and sets all nodes to the right by incrementing offset
                offset += 2; 
                right->vertSum_H(offset, m);
                //Resets offset to original number
                --offset; 
                //If node is found with the hd, then it is set into the map
                if(m.find(offset) == m.end()) 
                {
                    m[offset] = value;
                    return;
                }
                m[offset] += value;
                return;
            }
    };
    // const Node* nil; // later nil will point to a sentinel node.
    public:
    Node* root;
    // public:
    BST() : root(nil) {}
    int size() 
    {
        return root->size();
    }
    bool empty() 
    { 
        return size() == 0; 
    }
    void print_node(const Node* n) 
    {
        std::cout << n->content() << std::endl;
    }
    bool search(Value x) 
    {
        Node* it = root;
        while(it != nil)
        {
            if(x == it->value){
                std::cout << "Value found.\n";
                return true;
            }
            else if(x < it->value){
                it = it->left;
            }
            else if(x > it->value){
                it = it->right;
            }
        }
        std::cout << "Value not found.\n";
        return false;
    }
    void preorder() const 
    {
        root->preorder_();
    }
    void postorder() const 
    {
        root->postorder_();
    }
    void inorder() const 
    {
        root->inorder_();
    }
    //Returns a reference to the value of the Node at the nth index.
    Value& operator[](int n) 
    {
        //Checking for invalid user-entered indeces.
        if(empty() || n < 0 || n > size())
        {
            std::cout << "Error: Invalid index.\n";
            exit(-1);
        }
        std::vector<Node*> v;
        int index = n;
        //Calls helper function to find the value at position n using a vector
        //to store the values in the proper order.
        root->find(n, v);
        //Accesses the now ordered and filled vector at the correct index
        return v.at(index)->value;
    }
    void displayMinCover()
    {
        int size = 0;
        if(root == nil)
        {
            std::cout << "Empty tree.\n";
            return;
        }
        //Finds cover for left and right nodes of root, since root itself 
        //cannot be part of the cover
        root->left->minCover();
        root->right->minCover();
        //Displays covers, which are essentially inorder. Only difference is 
        //size is calculated.
        root->left->displayMinCoverH(size);
        root->right->displayMinCoverH(size);
        std::cout << std::endl;
        std::cout << size << std::endl;
    }
    void findSumPath(Node* n, int sum, int buffer[])
    {
        int i;
        int count = 0;
        std::vector<int> v;
        bool found = n->makePath(count, sum, v);
        //Adds all nodes in the path into the buffer
        for(i = 0; i < v.size(); ++i)
        {
            buffer[i] = v.at(i);
        }
        buffer[i] = '\0';
        //Displays the path
        n->displaySumPath(found, buffer);
    }
    void vertSum(Node* node, int hd, std::map<int, int>& m)
    {
        if(node == nil)
        {
            return;
        }
        node->vertSum_H(hd, m);
        //Iterates through the map and prints out the value in the Node
        for(auto it : m)
        {
            std::cout << it.second << ' ';
        }
        std::cout << std::endl;
    }
    void insert(Value X) 
    { 
        root = insert(X, root);
    }
    Node* insert(Value X, Node* T) 
    {
        if (T == nil) 
        {
            T = new Node(X);
        } 
        else if (X < T->value) 
        {
            T->left = insert(X, T->left);
        } 
        else if (X > T->value) 
        {
            T->right = insert(X, T->right);
        } 
        else 
        {
            T->value = X;
        }
    // Rebalancing code will be installed here.
    return T;
    }
};

#endif