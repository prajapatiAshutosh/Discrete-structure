#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int degree,x,sum=0;
    char ch;
    do
    {
        cout<<"Enter the degree of the polynomial :";
        cin>>degree;
        int arr[degree];
        for(int i=degree; i>=0;i--)
        {
            cout<<"Enter the coefficient of degree "<<i<<" :";
            cin>>arr[i];
        }
        cout<<"The required polynomial is :";
        cout<<arr[degree]<<"x^"<<degree;
        for(int i=degree-1;i>0;i--)
        {
            if(arr[i]>0)
                cout<<"+"<<arr[i]<<"x^"<<i;
            else
                cout<<"-"<<arr[i]<<"x^"<<i;
        }
        cout<<"+"<<arr[0]<<"x^"<<0;
        cout<<"\nEnter the value of x : ";
        cin>>x;
        for(int i=degree;i>=0;i--)
        {
            sum+=(arr[i]*pow(x,i));
        }
        cout<<"\nThe solution of this polynomial is :"<<sum;
        char ch;
        cout<<"\nDo you want to continue?(y/n):";
        cin>>ch;

    }while(ch=='y'||ch=='Y');
}


