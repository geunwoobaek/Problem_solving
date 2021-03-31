#include <iostream>
#include <vector>
using namespace std;

int total_cnt=0, how_many;


void findLength(int& cur_start, int& start){
    cout<<cur_start<<","<<start<<"\n";
    if(cur_start>start){
      int cur_length=cur_start-start+1;
        total_cnt+=(cur_length)/how_many;
        if(cur_length%how_many!=0) total_cnt+=1;
    }
}
void func_(int& start,int &end, int where,int how){
    int cur_start=where-how-1;
    int cur_end=where+how;
    findLength(cur_start,start);
    start=cur_end+1;
}
int solution(int n, vector<int> stations, int w)
{
    int start=1,end=n,how=w;
    how_many=2*w+1;
    for(int& cur:stations){
        func_(start,end,cur,how);
    }
    findLength(end,start);
    return total_cnt;
}

int main(){
    cout<<solution(11,{4,11},1);
    return 0;
}