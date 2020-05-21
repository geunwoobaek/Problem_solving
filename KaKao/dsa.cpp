#include<iostream>
#include<vector>
using namespace std;
#define L long long
L Uclid(L a,L b)
{ 
    L q=a; 
    L w=b;  
    L t=q%w;
        while(t>0)
        {
            t=q%w;
            q=w; w=t;
        }
    return q;
}

int N;
L current_money=0;
vector<L> charge;
L minimum=1e18;
L mmm=1;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
cin>>N;
for(int i=0;i<N;i++)
{
L op,lest;
cin>>op>>lest;
L k=-(op+current_money-lest);
current_money=lest;
if(k>0) {
    charge.push_back(k);
    minimum=minimum<k?minimum:k;
    mmm=mmm>k+op?mmm:k+op;
}
}
L G=minimum;
for(auto i : charge)
{
G=Uclid(i,G);
}
if(G<=mmm) cout<<-1,exit(0); 
for(L i=2;i<=G;i++)
{   
   if(G%i==0&&G/i>mmm) G=i;
   else if(G/i<mmm) break;
}
cout<<G; 
return 0;
}