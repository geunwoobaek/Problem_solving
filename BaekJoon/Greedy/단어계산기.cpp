#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
using namespace std;
bool compare(pair<char,int> a,pair<char,int> b) {return a.second>b.second;}
map<char,int> M;
vector<pair<char,int>> vec(10);
int index=9;
int N,Sum=0;
int main()
{ ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++)
    { 
        string A;
        cin>>A;
        for(int j=1;j<=A.size();j++)
        {
            M[A[A.size()-j]]+=pow(10,j-1);
        }
    }
copy(M.begin(),M.end(),vec.begin());
sort(vec.begin(),vec.end(),compare);
for(auto i:vec)
{
Sum+=i.second*index;
index--;
}
cout<<Sum;
return 0;
}