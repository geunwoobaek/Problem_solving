#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> um;
void solution(vector<int>& arr){

    for(int i:arr){  
        um[i]++;
    }
    for(auto it=um.begin();it!=um.end();it++){
        if(it->second>1) cout<<"숫자: "<<it->first<<", 횟수:"<<it->second<<"\n";
    }
}
int main(){
vector<int> arr={1,2,3,1,4,4,5,6};
solution(arr);
return 0;
}