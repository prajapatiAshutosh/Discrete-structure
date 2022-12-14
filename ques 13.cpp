#include<iostream>
using namespace std;

int main()
{
    int x[4];
	int y[4];
	int disjunction[4];
	int conjuction[4];
	int NOR[4];
	int NAND[4];
	int Cond[4];
	int Bicond[4];
	int Negative_x[4];
	int Negative_y[4];
    char ch;
    do
    {
        for(int i=0;i<4;i++)
        {
            cout<<"Enter the"<<" "<<(i+1)<<" "<<"value of x and y"<<endl;
            cin>>x[i]>>y[i];
            disjunction[i] = x[i]|y[i];
            conjuction[i] = x[i]&y[i];
            NOR[i] = !disjunction[i];
            NAND[i] = !conjuction[i];
            Cond[i] = !x[i]|y[i];
            Bicond[i] = ((!x[i]|y[i])&(!y[i]|x[i]));
            Negative_x[i] = !x[i];
            Negative_y[i] = !y[i];
        }

        cout<<"x |y  |or |and|NOR|NAND|Cond|Bicond|Negx|Negy"<<endl;
        for(int i=0;i<4;i++)
        {
            cout<<x[i]<<" | "<<y[i]<<" | "<<disjunction[i]<<" | "<<conjuction[i]<<" | "<<NOR[i]<<" | "<<NAND[i]<<"  | ";
            cout<<Cond[i]<<"  |"<<Bicond[i]<<"     |"<<Negative_x[i]<<"   |"<<Negative_y[i]<<endl;
        }

        cout<<"do you want to continue(y/n)\n";
        cin>>ch;
    }while(ch=='y');

    return 0;
}
