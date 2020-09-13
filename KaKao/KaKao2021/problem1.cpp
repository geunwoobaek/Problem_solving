#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <sstream>
#include <fstream>
using namespace std;
// 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
// 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
// 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
// 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
// 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
// 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
//      만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
// 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
int N;

string solution(string new_id)
{
    string answer = "";
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower); //1단계
    string::iterator it = new_id.begin();                               //2단계
    while (it != new_id.end())
    {
        if (*it == '.' || *it == '_' || *it == '-')
        {
            it++;
        }
        else
        {
            if (*it >= 'a' && *it <= 'z' ||(*it<='9'&&*it>='0')) 
                it++;
            else
            {
                new_id.erase(it);
            }
        }
    }
    it = new_id.begin(); //3단계
    while (it != new_id.end())
    {
        if(*it=='.'&&*it==*(it+1)) new_id.erase(it);
        else it++;
    }
    //4단계
    if(new_id[0]=='.') new_id.erase(new_id.begin(),new_id.begin()+1);
    if(new_id.back()=='.') new_id.erase(new_id.end()-1,new_id.end());
    //5단계
    if(new_id.size()==0)new_id.push_back('a');
    //6단계
    if(new_id.size()>15) new_id.erase(new_id.begin()+15,new_id.end());
    if(new_id.back()=='.') new_id.erase(new_id.end()-1,new_id.end());
    //7단계
    if(new_id.size()<3)
    {   char c=new_id.back();
        while(new_id.size()!=3)
        {
            new_id.push_back(c);
        }
    }
    return new_id;
}
    int main()
    {
        int k=2;
        int &a=k;
        int c=a;
        c++;
        cout<<a;
        return 0;

    }