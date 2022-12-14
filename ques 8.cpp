#include<iostream>
using namespace std;

void input(int arr[],int n)
{
	cout<<"Enter the values of the array: "<<endl;
	for(int i=0;i<n;i++)
	  cin>>arr[i];
	return;
}

void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
	 cout<<arr[i]<<" ";
	cout<<endl;
	return;
}

void swap(int *a,int *b)
{
	int temp =*b;
	*b=*a;
	*a=temp;
	return;
}

void bubblesort(int arr[],int n)
{
	cout<<"The sorting process start: \n";
	for(int i=0;i<n-1;i++)
	{
		bool flag=true;
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
				flag=false;
			}
			display(arr,n);	
		}
		if(flag)
		{
			break;
		}
	}
	cout<<"The sorting process ended.....\n";
	return;
}

int main()
{
	int n;
	cout<<"Enter the size of the array:  ";
	cin>>n;
	int arr[n];
	input(arr,n);
	cout<<"The entered array is: "<<endl;
	display(arr,n);
	bubblesort(arr,n);
	cout<<"Array after bubble sorting: "<<endl;
	display(arr,n);
	return 0;
}
