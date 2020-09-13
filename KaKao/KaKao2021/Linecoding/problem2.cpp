#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<cstring>
#include<map>
using namespace std;
int solution(vector<vector<int>> boxes) {
    map<int,int> Map;
    int answer=0;
    for(auto i:boxes)
    {
        for( auto j:i)
        {
            Map[j]++;
        }
    }
        map<int,int> ::iterator it=Map.begin();
        while(it!=Map.end())
        {
            if((*it).second%2==1)
                 answer++;
            it++;
        }
    cout<<answer;
    return answer/2;
}
int main()
{
vector<vector<int>> boxes(3);
vector<int> a(2);
vector<int> a1(2);
vector<int> a2(2);
a[0]=1;
a[1]=2;
a1[0]=3;
a1[1]=4;
a2[0]=5;
a2[1]=6;
boxes[0]=a;
boxes[1]=a1;
boxes[2]=a2;

solution(boxes);
    return 0;
}