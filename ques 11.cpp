#include<iostream>
using namespace std;

int nprfun(int n,int r)
{
	if(r>n)return 0;
	else if (r==0) return 1;
	else return n*nprfun(n-1,r-1);
}

int ncrfun(int n,int r)
{
	if(r>n) return 0;
	else if(n==0||r==0||n==r) return 1;
	else return ncrfun(n-1,r-1)+ncrfun(n-1,r);
}

int main()
{
	int n,r;
	cout<<"Enter the value of n: ";
	cin>>n;
	cout<<"Enter the value of r: ";
	cin>>r;
	cout<<"The permutation of given n and r is: "<<nprfun(n,r);
	cout<<endl<<"The combination of given n and r is: "<<ncrfun(n,r);
	return 0;
}
