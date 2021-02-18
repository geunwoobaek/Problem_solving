#include <bits/stdc++.h>
#define F(i, s, e) for (int i = s; i <= e; i++)
using namespace std;


int main(){
    vector<int> v={1,2,3};
    vector<int> v2={2,3,4};
    vector<int> v3={3,3,4};
    map<vector<int>,bool> m;
    m[v]=true;
    m[v2]=true;
    cout<< m[v3];
    cout<<"";
}