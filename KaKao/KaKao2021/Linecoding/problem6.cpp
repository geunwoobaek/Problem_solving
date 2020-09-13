#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
using namespace std;
int total=0;
int applinum=0;
// 1단계. 지원자는 거절당하지 않았던 기업 중에서 자신의 선호도가 가장 높은 기업 한 곳에 지원합니다. 입사 희망 기업으로부터 모두 거절당하면 지원을 중단합니다.

// 2단계. 기업은 채용 인원수를 넘지 않는 한도 내에서 선호도가 높은 순서대로 지원자를 잠정 선택합니다. 선택하지 않은 지원자들은 거절합니다.

// 3단계. 거절당한 지원자들 중에서 다른 기업에 지원할 지원자가 있다면 1단계부터 반복하고, 없다면 현재의 잠정 선택을 최종 매칭으로 결정합니다.
//company=["A fabdec 2", "B cebdfa 2", "C ecfadb 2"]
//지원자 ["a BAC 1", "b BAC 3", "c BCA 2", "d ABC 3", "e BCA 3", "f ABC 2"]
//결과 ["A_bf", "B_ce", "C_d"]

//지원자가 먼저 선택을하고 그다음 리스트보기
void simulation(map<char, vector<char>> &company_map, map<char, vector<char>> &application_map,map<char,int> &situation_company)
{   
    map<char,bool> visit;
    int k=total; //회사수
    while (k>0)
    {
        map<char, char> list;
        map<char, vecotr<char>> erect;//선출
        map<char, vector<char>>::iterator it = application_map.begin();
        while (it != application_map.end()) //지원자로부터 1지망받기
        {
            list[((*it).first)]=application_map.begin();
            vector<char> cur=(*it).second;
            cur.erase(cur.begin(),cur.begin()+1);
            if(cur.size()==0) application_map.erase(it);
            else it++;
        }
        map<char, vector<char>>::iterator list_it = list.begin();
        while (list_it != list.end()) //받은리스트로부터 사람뽑기
        {
            if(visit[(*list_it).second]!=true) //방문안했을경우
            {
                erect[(*list_it).second].push_back((*list_it).first);
            }
            list_it++;
        }
        //거르기
        map<char, vector<char>>::iterator erect_it = erect.begin();//회사 //지원자수
        while (erect_it != erect_it.end()) //받은리스트로부터 사람뽑기
        {
           if(situation_company[(*erect_it).first]>=0)
           {
               vector<char> &now=(*erect_it).second;
               vector<char> &com=company_map[(*erect_it).first];
               for(int i=0;i<now.size();i++)
               {
                    for(int j=0;j<com.size();j++)
                    {
                        if(com.j==0)
                    }

               }
           }
          erect_i++;
        }   
    }
}
vector<string> solution(vector<string> companies, vector<string> applicants)
{
    map<char, vector<char>> company_map;
    map<char,int> situation_company;
    total=companies.size();
    map<char, vector<char>> application_map;
    for (int i = 0; i < companies.size(); i++)
    {
        string &now = companies[i];
        char key = now[0];
        situation_company[key]=now.back() - '0';
        for (int j = 0; j < applicants.size(); j++)
        {
            company_map[key].push_back(now[j + 2]);
        }
    }
    for (int i = 0; i < applicants.size(); i++)
    {
        string &now = applicants[i];
        char key = now[0];
        int number = now.back() - '0';
        for (int j = 0; j < number; j++)
        {
            application_map[key].push_back(now[j + 2]);
        }
    }
    vector<string> answer;
    return answer;
}
int main()
{
    vector<string> companies;
    companies.push_back("A fabdec 2");
    companies.push_back("B cebdfa 2");
    companies.push_back("C ecfadb 2");
    vector<string> applicants;
    ////지원자 ["a BAC 1", "b BAC 3", "c BCA 2", "d ABC 3", "e BCA 3", "f ABC 2"]
    applicants.push_back("a BAC 1");
    applicants.push_back("b BAC 3");
    applicants.push_back("c BCA 2");
    applicants.push_back("d ABC 3");
    applicants.push_back("e BCA 3");
    applicants.push_back("f ABC 2");
    solution(companies, applicants);
    return 0;
}
