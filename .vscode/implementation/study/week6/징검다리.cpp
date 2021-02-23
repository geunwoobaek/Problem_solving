#include <bits/stdc++.h>
using namespace std;


int solution(int distance, vector<int> rocks, int n)
{
    int left = 0, right = distance;
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    while(left<right){ 
        int mid=(left+right)>>1;
        int remove_rocks=0,before=0; //mid보다 작은 크기일 경우 제거
        for(int i=0;i<rocks.size()&&remove_rocks<=n;++i){
            int next_=rocks[i]-before;
            if(next_<mid) remove_rocks++; //제거
            else before=rocks[i]; //제거 안했을경우
        }
        if(remove_rocks>n) right=mid; //rocks가 n개보다 클때 
        else left=mid+1;//rocks가 n개이거나 n개보다 적을때 
    }
    return left-1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << solution(25, {2, 14, 11, 21, 17}, 2);
    return 0;
}
