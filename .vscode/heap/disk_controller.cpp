#include<bits/stdc++.h>
using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/42627?language=cpp
/*
문제 요구사항
시작가능시간, 소모시간의 리스트로 데이터를 넘겨줌
이에 대해서 최대한 평균이 적은 시간을 반환
이때 작업수행할때 먼저 요청들어온것부터 처리

시작가능시간이 모두 동일하다면..
1,1
1,2
1,3
   a0
   a1
   a2
t1=a0
t2=t1+a1
t3=t2+a2
..
sum(T(N))= a0+(a0+a1)+(a0+a1+a2)...
sum(T(N))= N*a0+(N-1)*a1+....an
이때 처음나오는 a0갯수가 제일많이나옴 즉 초반에나오는 a0의 수가 제일 적어야함
작업 수행하지 않을때는 먼저 요청이 들어온 작업부터 처리
그렇다면 다르다면 어떻게 처리해야할까?
현재 처리 가능한것들중 가장 처리시간이 적은것들 부터 처리하면 어떻게 될까? 논리적 결함이 있나?
놉
정렬을 해보자
현재 시간동안 처리 가능한것들 리스트에 추가
만약 현재시간보다 늦게시작하는 것들이 리스트에 추가될려고 할때, 리스트 싹 비우기
*/
#define Job pair<int,int>
#define start_time_ first
#define cost_ second
bool compare(vector<int>& a,vector<int>& b){ //들어온순서가 작은순으로 리턴
    return a[0]<b[0];
}
struct job_compare{
bool operator()(Job& a,Job& b){
    return a.cost_-a.start_time_>b.cost_-b.start_time_;
}
};
int solution(vector<vector<int>> jobs){
    sort(jobs.begin(),jobs.end(),compare); //jobs 들어오는 순서별로 넣기
    int cur_time=0, answer=0;
    priority_queue<Job,vector<Job>,job_compare> que;
    for(auto job:jobs){
        int job_start_time=job[0];
        int job_cost=job[1];
        while(cur_time<job_start_time&&!que.empty()){
                auto job_info=que.top();
                que.pop();
                cur_time+=job_info.cost_;
                answer+=cur_time-job_info.start_time_;
        }
        if(cur_time<job_start_time)
            cur_time=job_start_time;
        que.push({job_start_time,job_cost});
    }
    while(!que.empty()){
        auto job_info=que.top();
        que.pop();
        cur_time+=job_info.cost_;
        answer+=cur_time-job_info.start_time_;
    }
    return answer/jobs.size();
}
int main(){
   // solution({{0,3},{1,9},{2,6}});
    vector<int> as={1,2,3};
    cout<<as.size();
}