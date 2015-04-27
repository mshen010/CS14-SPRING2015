#include "lab3.h"
#include <string>

using namespace std;

void intFixedStackTest()
{
    cout << "Testing fixed stack class constructor and display.\n";
    TwoStackFixed<int> x(5, 2);
    x.display();
    
    cout << "Testing push on both stacks.\n";
    x.pushStack1(3);
    x.pushStack2(2);
    x.pushStack1(4);
    x.pushStack2(6);
    x.display();
    
    cout << "Testing push on full stacks.\n";
    x.pushStack1(9);
    x.pushStack2(9);
    x.display();
    
    cout << "Testing pop on both stacks.\n";
    x.popStack1();
    x.popStack1();
    x.popStack2();
    x.popStack2();
    x.display();
    
    cout << "Testing pop on empty stacks.\n";
    x.popStack1();
    x.popStack2();
}
void stringFixedStackTest()
{
    cout << "Testing fixed stack class constructor and display.\n";
    TwoStackFixed<string> x(5, 2);
    x.display();
    
    cout << "Testing push on both stacks.\n";
    x.pushStack1("a");
    x.pushStack2("bc");
    x.pushStack1("f");
    x.pushStack2("cat");
    x.display();
    
    cout << "Testing push on full stacks.\n";
    x.pushStack1("full");
    x.pushStack2("full");
    x.display();
    
    cout << "Testing pop on both stacks.\n";
    x.popStack1();
    x.popStack1();
    x.popStack2();
    x.popStack2();
    x.display();
    
    cout << "Testing pop on empty stacks.\n";
    x.popStack1();
    x.popStack2();
}
void intFlexStackTest()
{
    cout << "Testing flexible stack class constructor and display.\n";
    TwoStackOptimal<int> x(6);
    x.display();
    
    cout << "Testing push on both stacks.\n";
    x.pushFlexStack1(3);
    x.pushFlexStack1(1);
    x.pushFlexStack1(4);
    x.pushFlexStack1(6);
    x.pushFlexStack2(2);
    x.pushFlexStack2(22);
    x.display();
    
    cout << "Testing push on full stacks.\n";
    x.pushFlexStack1(9);
    x.pushFlexStack2(9);
    x.display();
    
    cout << "Testing pop on both stacks.\n";
    x.popFlexStack1();
    x.popFlexStack1();
    x.popFlexStack1();
    x.popFlexStack2();
    x.popFlexStack2();
    x.popFlexStack2();
    x.display();
    
    cout << "Testing pop on empty stacks.\n";
    x.popFlexStack1();
    x.popFlexStack2();
    x.display();
}
int main()
{
    // intFixedStackTest();
    // stringFixedStackTest();
    // intFlexStackTest();
    return 0;
}
