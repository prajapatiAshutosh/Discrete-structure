#include<iostream>
using namespace std;

class relation
{
	int** ar;
	int n;
	
	public:
		void input();	
		bool complete();
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
	cout<<"Enter the no of edges :";
	cin>>m;
	int a[m],b[m];
	cout<<"Enter the vertices having edges in between :";
	for(int i=0;i<m;i++)
		cin>>a[i]>>b[i];
	for(int i=0;i<m;i++)
	{
		ar[(a[i]-1)][(b[i]-1)]=1;
		ar[(b[i]-1)][(a[i]-1)]=1;
    }
}

bool relation::complete()
{
	for(int i=0;i<n;i++)
	{
		if(ar[i][i]==1)
		   return false;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j!=i)
			{
				if(ar[i][j]==0)
				  return false;
			}
		}
	}
	return true;
	
}

void relation::display()
{
	cout<<"\nThe Matrix for the graph:\n";
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
	if(r.complete())
		cout<<"The graph is a complete graph....";
	else
	    cout<<"The graph is not a complete graph...";
}
