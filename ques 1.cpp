/*
	Name: Gagan kumar soni
	Copyright: 
	Author: Gagan kumar soni
	Date: 16-01-20 08:44
	Description: menu driven basic operational program on set
*/

#include<iostream>
#include<math.h>
using namespace std;

class set
{
	int *arr;
	int size;
	
public:
	set();
	void input();
	void unique();
	void print();
	int cardinality();
	void powerset();
	bool check_avl(int a);
	
};

set::set()
{
	arr=new int[0];
	size=0;
	return;
}

void set::input()
{
	int n;
	cout<<"Enter the size of the array:\n";
	cin>>n;
	size=n;
	arr=new int[size];
	cout<<"Enter the values of the set:\n";
	for(int i=0;i<n;i++)
	   cin >>arr[i];
	return;
}

void set::unique()
{
	for(int i=0;i<size;++i)
		for(int j=i+1;j<size;)
		{
			if(arr[i]==arr[j])
			{
				for(int k=j;k<size-1;++k)
					arr[k]=arr[k+1];
					
				--size;
			}
			else
				++j;
		}

}

void set::print()
{
	cout<<"{";
	for(int i=0;i<size;i++)
	   {
	    cout<<arr[i];
	    if((i+1)!=size)
	       cout<<",";
	   }
	cout<<"}"<<endl;
}

int set::cardinality()
{
	return size;
}

void set::powerset()
{
	int count=pow(2,size);
	int temp;
	cout<<"{ {},";
	for(int i=1;i<count;i++)
	{
		temp=i;
		int counter=-1;
		cout<<"{";
		for(int j=0;j<size;j++)
		{
			if(temp&1)
			{
				counter++;
			}
			temp=temp>>1;
		}
		temp=i;
		for(int j=0;j<size;j++)
		{
			if(temp&1)
			{
				cout<<arr[j];
				if(counter!=0)
				{
					cout<<",";
					counter--;
				}
			}
			temp=temp>>1;
		}
		cout<<"}";
		if((i+1)!=count)
			cout<<",";
	}
    cout<<"}";
}

bool set::check_avl(int a)
{
	for(int i=0;i<size;i++)
	{
		if(a==arr[i])
		   return true;
	}
	return false;
}

int main()
{
	set s;
	s.input();
	cout<<"The entered set is:\n";
	s.unique();
	s.print();
    int choice;
    for(char ch='y';ch=='y'||ch=='Y';)
    {
    cout<<"choose the task to perform: \n1.Find the cardinality of the set\n2.Check "
        <<"whether input number belongs to the set or not\n3.Find the power set of the set.\n";
    cin>>choice;
	switch(choice)
    {
    	case 1: 
    	        cout<<"The cardinality  of the set is: "<<s.cardinality()<<endl;
    	        break;
    	case 2: 
    	        cout<<"Enter a number to check: ";
    	        int n;
    	        cin>>n;
    	        if(s.check_avl(n))
    	        	cout<<"The entered number exist in the given set."<<endl;
    	        else
    	            cout<<"The entered number does not exist in the given set."<<endl;
    	        break;
    	case 3:
    		    cout<<"The power set of the given set is:"<<endl;
    		    s.powerset();
    		    cout<<endl;
    		    break;
    	default:
    		    cout<<"Error100:you have chose a wrong choice."<<endl;
    }
    cout<<endl<<"Do you want to do some other operations!!!(Y/N)"<<endl;
    cin>>ch;
    }
    cout<<endl<<"The program executed successfully\nTHANK YOU!!!!";
}
