#include <bits/stdc++.h>
using namespace std;
//코딩테스트 연습 2021 KAKAO BLIND RECRUITMENT 메뉴 리뉴얼

unordered_map<string, int> combi_count;
vector<string>combivec[11]; //글자갯수별 가장많은것 넣고 있음..
//orderes배열크기 20이하 //글자크기 10개이하 //course 10이하
bool compare(string a, string b){ return combi_count[a] > combi_count[b];}
void check(string &str, string& cur, int idx)
{
    if (idx == (int)str.length()) return;
    cur += str[idx];
    if((int)cur.length()>1) {
        combi_count[cur]++;
        if(combi_count[cur]==2)
            combivec[cur.length()].push_back(cur);
    }
    check(str, cur, idx + 1);
    cur.pop_back();
    check(str, cur, idx + 1);
}
vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    for(auto &order:orders){
        string cur="";
        sort(order.begin(),order.end());
        check(order,cur,0);
    }
    for(int i:course){
        sort(combivec[i].begin(),combivec[i].end(),compare);
        if(!combivec[i].empty()){
            int max_cnt=combi_count[combivec[i][0]];
            for(auto str:combivec[i]){
                if(combi_count[str]!=max_cnt) break;
                else answer.push_back(str);
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}
int main()
{   
    solution({"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"}, {1,2,3});
    return 0;
}