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

int binarysearch(int a[],int start,int end,int element)
{
	if(start>end)
		return -1;
	int mid=(start+end)/2;
	if(a[mid]==element)
	    return mid;
	else if(element<a[mid])
	    binarysearch(a,start,mid-1,element);
    else
        binarysearch(a,mid+1,end,element);
}

void insertionsort(int arr[],int n)
{
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
	}
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
	cout<<"\nInput array after sorting: \n\n";
	display(arr,n);
	cout<<"\nEnter the element to be searched: ";
	int k;
	cin>>k;
	cout<<k<<" is found at Index "<<(binarysearch(arr,0,n-1,k)+1);
	return 0;
}
