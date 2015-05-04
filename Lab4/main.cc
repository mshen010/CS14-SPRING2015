//Name: Michaella Sheng
//SID: 861162403
//Date: 5-3-15

#include "lab4.h"

int main(int argc, char* argv[])
{
    //Checking if right number or command-line arguments have been entered.
	if(argc != 2)
	{
		std::cout << "Error: Usage: <program file> <int>.\n";
		return -1;
	}
	//Checking if valid numbers have been entered.
	if(atoi(argv[1]) <= 0)
	{
	    std::cout << "Error: Enter a positive integer.\n";
	    return -1;
	}
	
    coprime tree(atoi(argv[1]));
    std::cout << "pre-order\n";
	tree.preorder(2, 1);
	tree.preorder(3, 1);
	std::cout << "post-order\n";
	tree.postorder(2, 1);
	tree.postorder(3, 1);
	tree.inorder(2, 1);
	tree.inorder(3, 1);
	std::cout << "sorted\n";
	tree.sorted();

	return 0;
}
