#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int N,K;
bool visit[101];
bool check[101];
vector<int> order;
vector<int> list;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>N>>K;
int cnt=0,answer=0; //정답
order.resize(K);
for(int i=0;i<K;i++) cin>>order[i];
for(int i=0;i<K;i++)
{  
    if(!visit[order[i]]) //현재 탭에 없을경우
    {      
        if(list.size()<N) {visit[order[i]]=true; cnt++;list.push_back(order[i]);} //구멍남을때
        else //구멍남지 않았을때
        {  answer++;
            int last_index=0;
            memset(check,false,sizeof(check));
            for(int j=i+1;j<K;j++) //한번도 사용하지 않거나 마지막에 사용한것찾기
            {
                if(visit[order[j]])
                {
                    last_index=order[j];
                    check[order[j]]=true;
                }
            }
            for(int j=0;j<N;j++)
            {
                if(!check[list[j]])
                {   
                    last_index=list[j]; 
                    list.erase(list.begin()+j,list.begin()+j+1); //지우기
                    break;
                }
                if(j==N-1)
                {
                    for(vector<int>::iterator it=list.begin();it!=list.end();it++)
                    {
                        if(*it==last_index) {list.erase(it); break;}
                    }
                    break;
                }
            }
            visit[last_index]=false;
            visit[order[i]]=true;
            list.push_back(order[i]);
        }
    }   
}
cout<<answer;
return 0;
}