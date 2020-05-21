#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> V(1,2e9);
int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++)
    {   int temp; 
        cin>>temp;
        if(V.back()<temp)
        {
            V.push_back(temp);
        }
        else{
            vector<int>::iterator it=lower_bound(V.begin(),V.end(),temp);
            *it=temp;
        }
    }
    cout<<V.size();
    return 0;
}