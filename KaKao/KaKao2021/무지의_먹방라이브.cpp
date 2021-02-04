#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<int,int> foodMap;
vector<int> foodVec;
ll findSum(vector<int>& vec,int target){
    ll sum=0;
    for(int i:vec){
        if(target>=i) sum+=i;
        else sum+=target;
    }
    return sum;
}
int solution(vector<int> food_times, long long k) {
    k++;
    for(auto food:food_times){
        foodMap[food]++;
    }
    for(auto it=foodMap.begin();it!=foodMap.end();it++) //벡터에 구간합 구하기
        foodVec.push_back(it->first);
    
    int left=0;
    int right=foodVec.size()-1;
    while(left<right){
        int mid=(left+right)>>1;
        ll midSum=findSum(food_times,foodVec[mid]);
        if(midSum>=k) right=mid;
        else left=mid+1;
    }
    ll temp=findSum(food_times,foodVec[left]);
    if(temp>=k) k-=findSum(food_times,foodVec[--left]);
    else k-=temp;
    for(int i=0;i<food_times.size();i++){
        int food=food_times[i];
        if(food>foodVec[left]) k--;
        if(k==0) return i+1;
    }
    return -1;
}