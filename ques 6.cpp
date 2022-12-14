#include<iostream>
using namespace std;

int hanoitower(int n)
{
	int a=1;
	if(n>1)
	   a = 2*hanoitower(n-1)+1;
	else
	   return a;
}

int main()
{
	int n;
	cout<<"Enter the number of stacks on Tower of Hanoi: "<<endl;
	cin>>n;
	cout<<"The minimum number of shifts of stack is: "<<hanoitower(n);
	return 0;	
}
