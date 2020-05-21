    #include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> V(1);
int main()
{
cin>>N>>V[0];
for(int i=1;i<N;i++)
{   int temp;
    cin>>temp;
    if(temp>V.back())
    {
        V.push_back(temp);
    }	
    else {
        vector<int>::iterator it=lower_bound(V.begin(),V.end(),temp);       
        *it=temp;
    }
}
cout<<V.size();
return 0;
}