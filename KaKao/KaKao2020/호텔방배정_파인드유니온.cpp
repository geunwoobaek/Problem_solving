#include<bits/stdc++.h>
#define ll long long
using namespace std;
unordered_map<ll,ll> P;
ll find(ll room){
    if(P[room]==0) return room; 
    else return P[room]=find(P[room]);
}
vector<ll> solution(ll k, vector<ll> room_number)
{   vector<ll> answer;
    for(auto number:room_number){
        ll room=find(number);
        P[room]=room+1;
        answer.push_back(room);
    }   
    return answer;
}
int main(){
     solution(10, vector<ll>({1, 3, 4, 1, 3, 1}));
     
}