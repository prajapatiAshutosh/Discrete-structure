#include<iostream>
using namespace std;

int main()
{
	int m,l,k;
	cout<<"Enter the degree of tree: \n";
	cin>>m;
	cout<<"Enter the number of internal vertices: \n";
	cin>>k;
	l=k*(m-1)+1;
	cout<<"The number of leaf nodes is: "<<l<<endl;
}
