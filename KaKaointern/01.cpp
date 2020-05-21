#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
using namespace std;
//stoi //tostring //map //copy //fill sort
int N;
string solution(vector<int> numbers, string hand) {
    //1 2 3
    //4 5 6
    //7 8 9
    //* 0 #
    pair<int,int> left={4,1};
    pair<int,int> right={4,3};
    string answer="";
    for(int i=0;i<numbers.size();i++)
    {
        int k=numbers[i];
        pair<int,int> current={k/3+1,k%3};
        if(k==0) current={4,2};
        else if(current.second==0) {current.first-=1;current.second=3;}
        int L=abs(current.first-left.first)+abs(current.second-left.second);
        int R=abs(current.first-right.first)+abs(current.second-right.second);
        
        if(current.second==2)
        {
        if(R>L)
        {left={current.first,current.second};
        answer+='L'; }
        else if(R<L)
        {right={current.first,current.second};
         answer+='R';}
        else if(hand=="right")
        {right={current.first,current.second}; answer+='R';}
        else{left={current.first,current.second}; answer+='L';}
        }
        else{
            if(current.second==1) {left={current.first,current.second}; answer+="L";}
            else {
                right={current.first,current.second};
                answer+="R";
                }
        }
    }
    return answer;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
vector<int> num={1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
string h="right";
cout<<solution(num,h);
return 0;
}