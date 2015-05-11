#include <iostream>
#include <stack>

template<typename T>
class TwoStackFixed
{
    private:
        int size; //Fixed size of array
        int maxtop; //Maximum number of array allocations per stack.
        T* array; //Dynamically allocated array
        int stack1; //Size of front stack
        int stack2; //Size of back stack
        
        //Private helper functions
        //Tests if the front end stack is full by comparing the size of the
        //stack to the max partition.
        bool isFullStack1()
        {
            if(stack1 == maxtop)
            {
                return true;
            }
            return false;
        }
        //Tests if the back end stack is full by comparing the size of the
        //stack to the max partition.
        bool isFullStack2()
        {
            if(stack2 == maxtop)
            {
                return true;
            }
            return false;
        }
        //Tests if the front end stack is empty.
        bool isEmptyStack1()
        {
            if(stack1 == 0)
            {
                return true;
            }
            return false;
           
        }
        //Tests if the back end stack is empty.
        bool isEmptyStack2()
        {
            if(stack2 == 0)
            {
                return true;
            }
            return false;
        }
    public:
        //Default constructor, creates an array with empty stacks
        TwoStackFixed(int size, int maxtop)
            : size(size), maxtop(maxtop), stack1(0), stack2(0)
        {
            array = new T[size];
        }
        //Destructor, deallocates all memory in array
        ~TwoStackFixed()
        {
            delete[] array;
        }
        //Displays array, and stacks from top to bottom.
        void display() const
        {
            std::cout << "Stack 1: \n";
            for(int i = 0; i < stack1; ++i)
            {
                std::cout << array[i] << ' ';
            }
            std::cout << std::endl;
            std::cout << "Stack 2: \n";
            for(int i = 0; i < stack2 ; ++i)
            {
                std::cout << array[size -1 - i] << ' ';
            }
            std::cout << std::endl;
            std::cout << "Array: \n";
            for(int i = 0; i < size; ++i)
            {
                std::cout << array[i] << ' ';
            }
            std::cout << std::endl;
        }
        //Allocates a value of type T using stack-style pushing, where the
        //bottom of the stack, in this case the front of the array, gets 
        //allocated first.
        void pushStack1(T value)
        {
            if(stack1 >= maxtop)
            {
                std::cout << "Stack 1 full.\n";
                return;
            }
            array[stack1] = value;
            ++stack1;
        }
        //Allocates a value of type T using stack-style pushing, where the
        //bottom of the stack, in this case the back of the array, gets 
        //allocated first.
        void pushStack2(T value)
        {
            if(stack2 >= maxtop)
            {
                std::cout << "Stack 2 full.\n";
                return;
            }
            array[size - stack2 - 1] = value;
            ++stack2;
        }
        //Pops top element off of the front stack, with the last element of the
        //stack being the first element in the array.
        T popStack1()
        {
            if(stack1 == 0)
            {
                std::cout << "Stack 1 empty.\n";
                exit(-1);
            }
            T temp = array[stack1 - 1];
            array[stack1 - 1] = T();
            --stack1;
            return temp;
        }
        //Pops top element off the back stack, ending at the back of the array
        T popStack2()
        {
            if(stack2 == 0)
            {
                std::cout << "Stack 2 empty.\n";
                exit(-1);
            }
            T temp = array[size - stack2];
            array[size - stack2] = T();
            --stack2;
            return temp;
        }
};
 
template<typename T>
class TwoStackOptimal
{
    private:
        int size; //Fixed size of array
        T* array;
        int stack1; //Size of front stack
        int stack2; //Size of back stack
        
        //Private helper functions
        //Checks if array is full
        bool isFullStack1()
        {
            if(stack1 + stack2 == size)
            {
                return true;
            }
            return false;
        }
        bool isFullStack2()
        {
            if(stack1 + stack2 == size)
            {
                return true;
            }
            return false;
        }
        //Checks if front stack is empty
        bool isEmptyStack1()
        {
            if(stack1 == 0)
            {
                return true;
            }
            return false;
        }
        //Checks if back stack is empty
        bool isEmptyStack2()
        {
            if(stack2 == 0)
            {
                return true;
            }
            return false;
        }
    public:
        //Default constructor
        TwoStackOptimal(int size)
            : size(size), stack1(0), stack2(0)
        {
            array = new T[size];
        }
        //Destructor
        ~TwoStackOptimal()
        {
            delete[] array;
        }
        //Displays arrays and stacks from top to bottom. For testing.
        void display() const
        {
            std::cout << "Stack 1: \n";
            for(int i = 0; i < stack1; ++i)
            {
                std::cout << array[i] << ' ';
            }
            std::cout << std::endl;
            std::cout << "Stack 2: \n";
            for(int i = 0; i < stack2 ; ++i)
            {
                std::cout << array[size -1 - i] << ' ';
            }
            std::cout << std::endl;
            std::cout << "Array: \n";
            for(int i = 0; i < size; ++i)
            {
                std::cout << array[i] << ' ';
            }
            std::cout << std::endl;
            
        }
        //Pushes element onto stack by simply allocating the value in the
        //corresponding array position
        void pushFlexStack1(T value)
        {  
            if(isFullStack1())
            {
                std::cout << "Error: Stack 1 filled.\n";
                return;
            }
            array[stack1] = value;
            ++stack1;
        }
        //Pushes element onto stack by simply allocating the value in the
        //corresponding array position.
        void pushFlexStack2(T value)
        {
            if(isFullStack2())
            {
                std::cout << "Error: Stack 2 filled.\n";
                return;
            }
            array[size - stack2 - 1] = value;
            ++stack2;
            return;
        }
        //Pops element off the front stack, ending at the front of the array.
        T popFlexStack1()
        {
            if(isEmptyStack1())
            {
                std::cout << "Error: Stack 1 empty.\n";
                exit(-1);
            }
            T temp = array[stack1 - 1];
            array[stack1 - 1] = T();
            --stack1;
            return temp;
        }
        //Pops element off the back stack, ending at the back of the array.
        T popFlexStack2()
        {
            if(isEmptyStack2())
            {
                std::cout << "Error: Stack 2 empty/\n";
                exit(-1);
            }
            T temp = array[size - stack2];
            array[size - stack2] = T();
            --stack2;
            return temp;
        }
};

template<typename T>
void showTowerStates(int n, std::stack<T>& A, std::stack<T>& B, std::stack<T>& C)
{
    // if(C.size() == n)
    // {
    //     return;
    // }
    // if(A.size() % 2 == 1)
    // {
    //     showTowerStates(n, A, B, C);
    //     std::cout << "Moved " << A.top() << "from peg A to C";
    // }
    // if(A.size() % 2 == 0)
    // {
    //     showTowerStates(n, A, B, C);
    //     std::cout << "Moved " << A.top() << "from peg A to B";
    // }
    return;
}
