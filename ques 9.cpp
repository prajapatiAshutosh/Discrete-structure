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

void insertionsort(int arr[],int n)
{
	cout<<"The sorting process started: \n";
	for(int i=0;i<n;i++)
	{
		int key=arr[i];
		int j=i-1;
		while(j>=0&&arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
		display(arr,n);
	}
	cout<<"The sorting process ended....\n";
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
	insertionsort(arr,n);
	cout<<"\nInput array after insertion sorting: \n\n";
	display(arr,n);
	return 0;
}
