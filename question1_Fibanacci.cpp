/*
By definition the first two numbers in the fibonacci sequence are 0,1 and each subsequent number is the sum of the previous two.
For example, the first ten Fibonacci numbers are:
0,1,1,2,3,5,8,13,21,34
Write afunction that accepts a number and returns the number at that position in the Finacci sequence.
Write in C++.
*/

#include <iostream>
#include <vector>
using namespace std;

//defining and declaring Fibanacci function
int Fib(int n)
{
	vector<int> Fib(n+1);
	Fib[0] = 0;
	Fib[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		Fib[i] = Fib[i - 1] + Fib[i - 2];
	}

	return Fib[n];
}

//drive code
int main()
{
	int FibNumber = Fib(6);
	cout << "Fibonacci number at position 6 is " << FibNumber << endl;
	system("PAUSE");
	return 0;
}