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
	bool check_avl(int a);
	bool sub_set(set s);
	set set_union(set s);
	set set_intersection(set s);
	set set_cmpl(set s);
	set set_difference(set s);
	set sym_Diff(set s);
	void cartesian_Product(set s);
		
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

bool set::check_avl(int a)
{
	for(int i=0;i<size;i++)
	{
		if(a==arr[i])
		   return true;
	}
	return false;
}

bool set::sub_set(set s)
{
	set temp=*this;
	for(int i=0;i<s.size;i++)
	{
		if(temp.check_avl(s.arr[i]))
		   {
		   }
		else 
		   return false;
	}
	return true;
}

set set::set_union(set s)
{
	set temp;
	temp.size=size+s.size;
	temp.arr=new int[temp.size];
	for(int i=0;i<size;i++)
	{
		temp.arr[i]=arr[i];
	}
	for(int j=0;j<s.size;j++)
	{
		temp.arr[size+j]=s.arr[j];
	}
    temp.unique();
    return temp;
	
}

set set::set_intersection(set s)
{
	set temp,s1,s2;
	int n,j=0;
	if(size>s.size)
	{
		n=s.size;
		s1=*this;
		s2=s;
	}
	else
	{
		n=size;
		s1=s;
		s2=*this;
	}
	  
	for(int i=0;i<n;i++)
	{
		if(s1.check_avl(s2.arr[i]))
		{
			temp.size++;
		}
	}
	temp.arr=new int[temp.size];
	for(int i=0;i<n;i++)
	{
		if(s1.check_avl(s2.arr[i]))
		{
			temp.arr[j++]=s2.arr[i];
		}
	}
	return temp;
}

set set::set_cmpl(set s)
{
	set temp,s1,s2;
	int n,j=0;
	if(size>s.size)
	{
		n=size;
		s1=*this;
		s2=s;
	}
	else
	{
		n=s.size;
		s1=s;
		s2=*this;
	}
	  
	for(int i=0;i<n;i++)
	{
		if(s2.check_avl(s1.arr[i]))
		{
			
		}
		else
		{
			temp.size++;
		}
	}
	temp.arr=new int[temp.size];
	for(int i=0;i<n;i++)
	{
		if(s2.check_avl(s1.arr[i]))
		{
			
		}
		else
		{
			temp.arr[j++]=s1.arr[i];
		}
	}
	return temp;
	
}

set set :: set_difference(set s){
	int j,k=0,m=0;
	set temp;
	for(int i=0; i<size; i++){
		for(j=0; j<s.size; j++)
			if(arr[i]==s.arr[j])
				break;
		if(j==s.size)
			k++;
	}
	temp.size=k;
	temp.arr=new int[temp.size];
	for(int i=0; i<size; i++){
		for(j=0; j<s.size; j++)
			if(arr[i]==s.arr[j])
				break;
		if(j==s.size)
			temp.arr[m++]=arr[i];
	}
	return temp;
}

set set :: sym_Diff(set s){
	int i,j,k=0,m=0;
	set temp;
	for(i=0; i<size; i++){
		for(j=0; j<s.size; j++)
			if(arr[i]==s.arr[j])
				break;
		if(j==s.size)
			k++;
	}
	for(int i=0; i<s.size; i++){
		for(j=0; j<size; j++)
			if(s.arr[i]==arr[j])
				break;
		if(j==size)
			k++;
	}
	temp.size=k;
	temp.arr=new int[temp.size];
	for(i=0; i<size; i++){
		for(j=0; j<s.size; j++)
			if(arr[i]==s.arr[j])
				break;
		if(j==s.size)
			temp.arr[m++]=arr[i];
	}
	for(int i=0; i<s.size; i++){
		for(j=0; j<size; j++)
			if(s.arr[i]==arr[j])
				break;
		if(j==size)
			temp.arr[m++]=s.arr[i];
	}
	return temp;
}

void set :: cartesian_Product(set s){
	cout<<"{";
	for(int i=0; i<size; i++)
		for(int j=0; j<s.size; j++)
			cout<<" ("<<arr[i]<<","<<s.arr[j]<<") ";
	cout<<"}";
	cout<<"\n";
}


int main()
{
	set s1,s2,z,U;
	cout<<"For the first set:"<<endl<<endl;
	s1.input();
	cout<<"The entered array is:\n";
	s1.print();
	cout<<"The entered set is:\n";
	s1.unique();
	s1.print();
	cout<<"For the second set:"<<endl<<endl;
	s2.input();
	cout<<"The entered array is:\n";
	s2.print();
	cout<<"The entered set is:\n";
	s2.unique();
	s2.print();
    int choice;
    for(char ch='y';ch=='y'||ch=='Y';)
    {
    cout<<"choose the task to perform: \n1.Check whether the first set is subset of second set or not.\n2.Check "
        <<"whether the second set is subset of first set or not.\n3.Find the union of the sets.\n4.Find the intersection "
		<<"of the sets\n5.Complement of set\n6.Set difference of sets\n7.symmetric difference of sets\n8.Cartesian product of sets\n9.Exit\n";
        cin>>choice;
	switch(choice)
    {
    	case 1: 
    	        if(s1.sub_set(s2))
	                cout<<"The second set is the subset of the first set"<<endl;
	            else
	                cout<<"The second set is not the subset of the first set"<<endl;
    	        break;
    	case 2: 
    	        if(s2.sub_set(s1))
	               cout<<"The first set is the subset of the second set"<<endl;
	            else
	               cout<<"The first set is not the subset of the second set"<<endl;
    	        break;
    	case 3:
	            z=s1.set_union(s2);
	            cout<<"The union of first and second set is: "<<endl;
				z.print();
    		    break;
    	case 4:
	            z=s1.set_intersection(s2);
	            cout<<"The intersection of first and second set is: "<<endl;
				z.print();
    		    break;
    	case 5:
    		    cout<<"For the universal set:"<<endl<<endl;
            	U.input();
            	cout<<"The entered array is:\n";
	            U.print();
	            cout<<"The entered set is:\n";
            	U.unique();
	            U.print();
	            cout<<"Choose one from given options\n1.Complement of first set\n2.Compliment of second set\n";
	            cin>>choice;
	            switch(choice)
	            {
	            	case 1:
	            		if(U.sub_set(s1))
	                    {
	                      	z=s1.set_cmpl(U);
	                     	z.cardinality();
	                        cout<<"Complement of first set is:"<<endl;
	                        z.print();
				        }
	                    else
	                        cout<<"the set is not the subset of universal set"<<endl;
	                    break; 
					case 2:
						if(U.sub_set(s2))
	                    {
	                      	z=s2.set_cmpl(U);
	                     	z.cardinality();
	                        cout<<"Complement of second set is:"<<endl;
	                        z.print();
				        }
	                    else
	                        cout<<"the set is not the subset of universal set"<<endl;
	                    break; 
	                default:
    		            cout<<"Error100:you have chose a wrong choice."<<endl;
					}
				break;
	    case 6:
	         	cout<<"Choose one from given options\n1.Set difference of second set from first set\n2.Set difference of first set from second set\n";
	            cin>>choice;
	            switch(choice)
	            {
	            	case 1:
	                      	z=s1.set_difference(s2);
	                        cout<<"The output set S1-S2=:"<<endl;
	                        z.print();
	                    break; 
					case 2:
	                      	z=s2.set_difference(s1);
	                        cout<<"The output set s2-s1=:"<<endl;
	                        z.print();
	                        break;
	                default:
    		            cout<<"Error100:you have chose a wrong choice."<<endl;
					}
						break;
					
		case 7 :
						cout<<"Symmetric Difference of set A and Set B :\n";
						z=s1.sym_Diff(s2);
						z.print();
						break;
		case 8 :
						cout<<"Cartesian Product AXB :\n";
						s1.cartesian_Product(s2);
						cout<<"Cartesian Product BXA :\n";
						s2.cartesian_Product(s1);
						break;
		case 9 :   
						
    		        cout<<endl<<"The program executed successfully\nTHANK YOU!!!!";
    	    	    exit(0);
    	    	    break;
    	default:
    		    cout<<"Error100:you have chose a wrong choice."<<endl;
    }
    cout<<endl<<"Do you want to do some other operations!!!(Y/N)"<<endl;
    cin>>ch;
    }
    cout<<endl<<"The program executed successfully\nTHANK YOU!!!!";
}

