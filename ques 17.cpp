#include<iostream>
using namespace std;

class relation
{
	int** ar;
	int n;
	
	public:
		void input();	
		void indeg();
		void outdeg();
		void display();
};

void relation::input()
{
	cout<<"Enter the number of vertices in the graph : ";
	cin>>n;
	ar=new int*[n];
	for(int i=0;i<n;i++)
		ar[i]=new int[n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ar[i][j]=0;
		}
	}
	int m;
	cout<<"Enter number of edges:";
	cin>>m;
	int a[m],b[m];
	cout<<"Enter vertices having edges in between : ";
	for(int i=0;i<m;i++)
		cin>>a[i]>>b[i];
	for(int i=0;i<m;i++)
		ar[(a[i]-1)][(b[i]-1)]=1;		
}

void relation::indeg()
{
	int arr[n];
	for(int i=0;i<n;i++)
	    arr[i]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(ar[i][j]==1)
			  arr[j]++;
		}
	}
	cout<<"IN-degree of elements for the given graph is: \n";
	for(int i=0;i<n;i++)
	    cout<<"For "<<i+1<<" : "<<arr[i]<<endl;
	return;
}

void relation::outdeg()
{
	int arr[n];
	for(int i=0;i<n;i++)
	    arr[i]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(ar[i][j]==1)
			  arr[i]++;
		}
	}
	cout<<"OUT-degree of elements for the given graph is: \n";
	for(int i=0;i<n;i++)
	    cout<<"For "<<i+1<<" : "<<arr[i]<<endl;
	return;
}

void relation::display()
{
	cout<<"\nThe Matrix for the graph is:\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<ar[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	relation r;
	r.input();
	r.display();
	r.indeg();
	r.outdeg();
	
}
