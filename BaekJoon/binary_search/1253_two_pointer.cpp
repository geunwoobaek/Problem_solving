#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int N,check[2001],cnt;
vector<int> v;
void two_pointer(int idx){
    int target = v[idx];
    int l = 0, r = N-1;
    while(l<r){
        int lv = v[l], rv = v[r];
        if(lv+rv == target){
            if(l!=idx && r!=idx){
                cnt++;
                break;
            }
            else if(r==idx) r--;
            else l++;
        }
        else if(lv+rv<target) l++;
        else r--;
    }
}
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++) two_pointer(i);
    cout << cnt ;
}