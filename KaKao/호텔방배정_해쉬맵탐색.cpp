#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Hotel map<ll, bool, less<>>
Hotel hotel;
vector<ll> solution(ll k, vector<ll> room_number)
{
    vector<ll> answer;
    for (auto room : room_number)
    {
        if (hotel[room])
        {
            auto cur_ = hotel.find(room);
            auto next_ = hotel.upper_bound(room);
            while (1)
            {
                //1.이때 현재방과 다음방의 차이가 2이상나면 그사이에 집어넣고
                //2.upper_bound에서 찾은 next_room의 second가 false일경우 그값에 방집어넣기
                ll next_room = (*next_).first;
                bool next_exist = (*next_).second;
                ll cur_room = (*cur_).first;
                if (!next_exist || (next_exist && next_room - cur_room > (ll)1))
                {
                    room = cur_room + (ll)1;
                    break;
                }
                else
                    ++cur_;
                    ++next_;
            }
        }
        hotel[room] = true;
        answer.push_back(room);
    }
    return answer;
}
int main()
{
   solution(10, vector<ll>({1, 3, 4, 1, 3, 1}));
  cout<<"hello";
  return 0;
}