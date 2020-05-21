#include<iostream>
using namespace std;
int main()
{

    int colum=10;
    int row=6;
    for(int i=1;i<=colum*row;i++)
    {
        int y=i/row+1;
        int x=i%row;
        if(x==0) x=row, y-=1;
        cout<<y<<","<<x<<endl;
    }
}