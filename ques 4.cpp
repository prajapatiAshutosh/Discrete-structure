#include<iostream>
using namespace std;

class relation
{
	int** ar;
	int n;
	
	public:
		void input();	
		bool reflexive();
		bool symmetric();
		bool antisymmetric();
		bool transitive();
		void display();
};

void relation::input()
{
	cout<<"enter the size of set as an array : ";
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
	cout<<"Enter the no of relations you want:";
	cin>>m;
	int a[m],b[m];
	cout<<"Enter the relation:";
	for(int i=0;i<m;i++)
		cin>>a[i]>>b[i];
	for(int i=0;i<m;i++)
		ar[(a[i]-1)][(b[i]-1)]=1;		
}

void relation::display()
{
	cout<<"\nThe Relation Matrix is:\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<ar[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool relation::reflexive()
{
	int f=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j && ar[i][j]!=1)
			{
				f=0;
				break;
			}
		}
		if(f==0)
			break;
	}
	if(f==1)
		return true;
	else
		return false;
}

bool relation::symmetric()
{
	int f=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(ar[i][j]!=ar[j][i])
			{
				f=0;
				break;
			}
		}
		if(f==0)
			break;
	}
	if(f==1)
		return true;
	else
		return false;
}

bool relation::transitive()
{
	int f=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(ar[i][j]==1)
			{
				for(int x=0;x<n;x++)
				{
					if(ar[j][x]==1 && ar[i][x]!=1)
					{
						f=0;
						break;
					}
				}
			}
			if(f==0)
				break;
		}
		if(f==0)
			break;
	}
	if(f==1)
		return true;
	else
		return false;
}

bool relation::antisymmetric()
{
	int f=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(ar[i][j]==1 && ar[j][i]==1 && i!=j)
			{
				f=0;
				break;
			}
		}
		if(f==0)
			break;
	}
	if(f==1)
		return true;
	else
		return false;
}

int main()
{
	relation r;
	r.input();
	r.display();
	if(r.reflexive()&&r.symmetric()&&r.transitive())
	    cout<<"The given relation is Equivalence";
	else if(r.reflexive()&&r.antisymmetric()&&r.transitive())
	    cout<<"The given relation is a partial order relation";
	else
	    cout<<"The relation is neither equivalence nor partial order relation";
	return 0;
}
