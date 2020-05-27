#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> vec;
int N,total_Party,change=0;
int all;
bool people[51];
vector<vector<int>> Party; 
int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>total_Party>>all;
    Party.resize(total_Party);
    for(int i=0;i<all;i++)
    {   
        int temp;
        cin>>temp;
        people[temp]=true;
    }
    for(int i=0;i<total_Party;i++)
    {
        int t;cin>>t;
        Party[i].resize(t);
        for(int j=0;j<t;j++) cin>>Party[i][j];
    }
    while(change!=Party.size())
    {   
        change=Party.size();
        for(vector<vector<int>>::iterator it=Party.begin();it!=Party.end();it++)
        {
            for(int i=0;i<it->size();i++)
            {
                if(people[(*it)[i]])
                {
                    for(int j=0;j<it->size();j++)
                    {
                        people[(*it)[j]]=true;
                    }
                    Party.erase(it--);
                    break;
                }
            }
        }
    }
    cout<<change;
    return 0;
}
// 4 3
// 0
// 2 1 2
// 1 3
// 3 2 3 4