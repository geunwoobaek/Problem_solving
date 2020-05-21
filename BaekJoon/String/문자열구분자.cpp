#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
string A="asd,dsa,vfd";
string B[3];
int index=0;
for(int i=0;i<3;i++)
{
    int second=A.find(',',index);
    B[i]=A.substr(index,second-index);
    index=second+1;
}
cout<<B[0];
    return 0;
}