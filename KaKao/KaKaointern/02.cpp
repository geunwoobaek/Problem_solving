#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include <string> 
#include <stdlib.h>
#include<map>
using namespace std;
#define L long long

L search(vector<L> num,string ordering,string priority)
{
for(int i=0;i<3;i++)
{
for(int j=0;j<priority.size();j++)
{
    if(priority[j]==ordering[i])
    {
        if(ordering[i]=='*') num[j]=num[j]*num[j+1];
        else if(ordering[i]=='+') num[j]=num[j]+num[j+1];
        else if(ordering[i]=='-') num[j]=num[j]-num[j+1];
           
        num.erase(num.begin()+j+1,num.begin()+j+2);
        priority.erase(priority.begin()+j,(priority.begin()+j+1));
        j--;
    }
}
}
return abs(num[0]);
}
L result(string expression)
{   vector<L> number;
    string priority="";
    int index=0;
    for(int i=0;i<expression.size();i++)
    {
        if(expression[i]=='*'||expression[i]=='+'||expression[i]=='-')
        {  
            string temp=expression.substr(index,i);
            number.push_back(atoi(temp.c_str()));
            priority+=expression[i];
            index=i+1;
        }
    }
    string temp=expression.substr(index,expression.size());
    number.push_back(atoi(temp.c_str()));
    string pri="*+-";
    L max=0; L comp;
    comp=search(number,pri,priority);
    max=max>comp?max:comp;
    while(next_permutation(pri.begin(),pri.end()))
    {
      comp= search(number,pri,priority);
    max=max>comp?max:comp;
    }
    return max;
    
}
//stoi //tostring //map //copy //fill sort
int N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
string A="50*6-3*2";
//vector<string> number;
//number.push_back(A.substr(0,5));
//cout<<number[0];
//cout<<A.c_str();
cout<<result(A);
return 0;
}