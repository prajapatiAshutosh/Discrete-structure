#include<iostream>
using namespace std;

class relation
{
	int** ar;
	int n;
	
	public:
		void input();	
		void deg();
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
	cout<<"Enter the number of edges :";
	cin>>m;
	int a[m],b[m];
	cout<<"Enter the vertices having edges in between :";
	for(int i=0;i<m;i++)
		cin>>a[i]>>b[i];
	for(int i=0;i<m;i++)
		ar[(a[i]-1)][(b[i]-1)]=1;		
}

void relation::deg()
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
	for(int i=0;i<n;i++)
	    arr[i]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(ar[i][j]==1)
			  arr[i]--;
		}
	}
	cout<<"Degree of elements for the given graph is: \n";
	for(int i=0;i<n;i++)
	{
		if(arr[i]<0)
		   arr[i]*=-1;
	}
	for(int i=0;i<n;i++)
	    cout<<"For "<<i+1<<" : "<<arr[i]<<endl;
	int c=0;
	for(int i=0;i<n;i++)
	{
		if((arr[i]%2)!=0)
		   c++;
	}
	if(c==0)
	  cout<<"There is Euler circuit exist\n";
	else
	  cout<<"There is no Euler circuit exist\n";
	if(c==2)
	  cout<<"There is a Euler path\n";
	else
	  cout<<"There is no Euler path\n";
	return;
}

void relation::display()
{
	cout<<"\nThe Matrix of the graph is:\n";
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
	r.deg();
	
	
}
