#include <bits/stdc++.h>
using namespace std;

int solution(int distance, vector<int> rocks, int n)
{
    int left = 0, right = distance,mid;
    rocks.push_back(0);
    sort(rocks.begin(), rocks.end());
    while(left<right){
        int mid=(left+right)>>1;
        int remove_rocks=0;
        for(int i=1;i<=rocks.size();++i){
            int cur=rocks[i]-rocks[i-1];
            if(cur>mid) remove_rocks--;
            
        }
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << solution(25, {2, 14, 11, 21, 17}, 2);
    return 0;
}
