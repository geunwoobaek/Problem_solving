#include <bits/stdc++.h>
using namespace std;

//{[( 이렇게 앞으로 오는게 있음
//]닫는 문자는 먼저 여는 문자가 있어야함
map<char, char> closem;
vector<string> braces(vector<string> values)
{   
    closem['}'] = '{';
    closem[')'] = '(';
    closem[']'] = '[';
    vector<string> answers;
    for (string &value : values)
    {
        string answer = "YES";
        stack<char> st;
        for (char c : value)
        {
            if(closem.find(c)==closem.end()){
                st.push(c);       
            }
            else {
                if(!st.empty()&&closem[c]==st.top())
                    st.pop();
                else {
                    answer="NO";
                    break;
                }
            }
        }
        if(!st.empty()) answers.push_back("NO");
        else    answers.push_back(answer);
    }
    return answers;
}
int main()
{
    braces({"{[}]"});
    return 0;
}