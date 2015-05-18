Question 2 Part a: 
The selection sort algorithm I have implemented is a stable sort
because the smallest address is only stored if the value of comparison is
smaller than (as opposed to smaller or equal to) it. So in my test case, the
first "1" is stored as the smallest value, and is swapped into pos 0. 
In the next round, the second "1" is stored as the smallest value and is
swapped into pos 1. Thus they have retained their order.