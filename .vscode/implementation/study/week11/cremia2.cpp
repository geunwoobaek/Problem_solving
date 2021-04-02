#include <bits/stdc++.h>
#define Pair pair<int,int>
#define value first
#define idx second
using namespace std;

int getMostVisited(int n, vector<int> sprints)
{
    vector<int> Load = vector<int>(n + 2);
    for (int i = 0; i < sprints.size()-1; i++)
    {
        int start = min(sprints[i], sprints[i + 1]);
        int end = max(sprints[i], sprints[i + 1]);
        Load[start]++;
        Load[end + 1]--;
    }
    vector<int> scores=vector<int>(n+1);
    int score=0;
    for(int i=1;i<n+1;i++){
        score+=Load[i];
        scores[i]=score;
    }
    Pair result={0,0};
    for(int i=1;i<n+1;i++){
        if(scores[i]>result.value){
            result={scores[i],i};
        }
    }
    return result.idx;
}
int main(){
    cout<<getMostVisited(10,{1,5,10,3});
    return 0;
}