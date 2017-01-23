//  loop.c 
//  COP_2220C-23863 
//  Prof. HUNCHUCK
//  Chris Marquis 1/9/17 

#include <stdio.h> 

int output(n, x)
{  
	return printf("%2i. x equals %2i.\n", n, x);
} 

int main() 
{ 
	output(1, 10); 
	output(2, 9); 
	output(3, 8); 
	output(4, 7); 
	output(5, 6); 
	output(6, 5); 
	output(7, 4); 
	output(8, 3); 
	output(9, 2); 
	output(10, 1); 
	// using getchar() instead of system pause, which would return press any key to continue. . . 
	getchar(); 
} 
