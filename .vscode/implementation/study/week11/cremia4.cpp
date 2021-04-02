#include <bits/stdc++.h>
using namespace std;
int droppedRequests(vector<int> requestTime)
{   
    int removed=0;
    for(int i=0;i<requestTime.size();i++){
         if(i  >2 && requestTime[i] == requestTime[i-3]){
            removed++;
        } else if(i > 19 && (requestTime[i] - requestTime[i-20]) <10){
            removed++;
        } else if( i > 59 && (requestTime[i] - requestTime[i-60]) <60 ){
            removed++;
        }
    }
    return removed;
}
int main(){
    cout<<droppedRequests({1,1,1,1,2});
}