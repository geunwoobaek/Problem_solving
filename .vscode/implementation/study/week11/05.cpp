#include <bits/stdc++.h>

using namespace std;
 vector<vector<int>> from;
 int findsqrt(int a){
     int res=sqrt(a);
     if(res*res!=a) res++;
     return res;
 }
 bool visit[100000];
//findParent한후 parent별로 갯수 더하기
int connectedSum(int graph_nodes, vector<int> graph_from, vector<int> graph_to) {
    int res=0;
    from.resize(graph_nodes+1);
    for(int i=0;i<graph_from.size();i++)
    {
        from[graph_from[i]].push_back(graph_to[i]);
        from[graph_to[i]].push_back(graph_from[i]);
    }
   queue<int> que;
   for(int i=1;i<=graph_nodes;i++){
       int cur_sum=0;
       if(!visit[i]){
           cur_sum++;
           visit[i]=true;
           que.push(i);
           while(!que.empty()){
               int now=que.front();
               que.pop();
               for(int to:from[now]){
                   if(!visit[to]){
                       visit[to]=true;
                       cur_sum++;
                       que.push(to);
                   }
               }
           }
       }
       res+=findsqrt(cur_sum);
   }
   return res;
}

int main(){
    connectedSum(4,{1,1},{2,4});
}