#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
vector<pair<string,string>> vec(7);
vector<double> win(5);
vector<pair<string,double>> v(4);
map<string,int> mindex;
string s[4];
double a;
bool compare(pair<string,double> x,pair<string,double> y) {return x.second>y.second;}
double arr[7][4];
void dfs(int depth,int start,vector<int> num)
{
    num.push_back(start);
    if(depth==6) {
        map<string,double> m;
    for(int j=1;j<=6;j++)
    {
        if(num[j]==1)
        {
            m[vec[j].first]+=3*arr[j][1];
        }
       else if(num[j]==2)
       {
          m[vec[j].first]+=arr[j][2];
          m[vec[j].second]+=arr[j][2];
       }
        else if(num[j]==3)
        {
            m[vec[j].second]+=3*arr[j][3];
        }
    }
     copy(m.begin(),m.end(),v.begin());
     sort(v.begin(),v.end(),compare);
     win[mindex[v[0].first]]++;
     if(v[1].second==v[2].second) {
         if(v[2].first=="CCC") 
         cout<<"";
         win[mindex[v[1].first]]+=0.5;
         win[mindex[v[2].first]]+=0.5;
         }
     else  win[mindex[v[1].first]]++;
     return ;
    }
    for(int i=1;i<=3;i++)
    {   
        dfs(depth+1,i,num);
    }
}
int main()
{
for(int i=0;i<4;i++)
{
    cin>>s[i];
    mindex[s[i]]=i;
}
for(int i=1;i<=6;i++)
{
    string a,b;
    double d1,d2,d3;
    cin>>a>>b>>d1>>d2>>d3;
    vec[i]={a,b};
    arr[i][1]=d1;
    arr[i][2]=d2;
    arr[i][3]=d3;
}
vector<int>vec_order;
dfs(0,0,vec_order);
double total=(win[0]+win[1]+win[2]+win[3])/2;
for(int i=0;i<4;i++) cout<<win[i]/total<<endl;
return 0;
}