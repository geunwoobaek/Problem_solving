#include <bits/stdc++.h>
#define ll long long
using namespace std;
//다음삽이 부분 결정해야한다]
// 1,2,3,4,6
//MaxNum=6
//넣고싶은 값1
//6까지의 size=5( 5-1+1)
//6까지 capacity=1~6 (6-1+1)
//capacity>size mid= 3

//maxnum=3
//size=now_index-start_index(3-1+1)
//capacity=1~3(3-1+1)
//size==capacity
//left=mid+1 :4
//size==capacity

//1,3
//2
int lower_bound_insert(vector<ll> &vec,int left, int target)
{
    int right = vec.size() - 1;
    while (left < right)
    { //lower_bound //1,2,3,4 2
        int mid = (left + right) >> 1;
        int size_ = mid - left + 1;
        int capacity_ = vec[mid] - vec[left] + 1;
        if (capacity_ > size_)
            right = mid;
        else
            left = mid + 1;
    }
    vec.insert(vec.begin() + left, target);
}
int find(vector<ll> &vec, int target)
{
    int left = 0;
    int right = vec.size() - 1;
    while (left < right)
    { //lower_bound //1,2,3,4 2
        int mid = (left + right) >> 1;
        if (vec[mid] >= target)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}
vector<ll> solution(ll k, vector<ll> room_number)
{
    vector<ll> answer;
    for (auto room : room_number)
    {
        if (answer.empty() || answer.back() < room) answer.push_back(room);
        else{
            int find_room=find(answer,room);
            if(answer[find_room]!=room) answer.insert(answer.begin()+find_room,room);
            else lower_bound_insert(answer,find_room,room);
        }
    }
    return answer;
}
int main(){
    solution(10,vector<ll>({1,3,4,1,3,1}));
}