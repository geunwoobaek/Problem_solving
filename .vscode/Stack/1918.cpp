#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;
string str;
stack<char> op;
string postfix;
map<char, int> pri_op;
//+- 우선순위 0 */우선순위 1
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> str;
    //우선순위조정
    pri_op[')'] = pri_op['('] = -1;
    pri_op['+'] = pri_op['-'] = 0;
    pri_op['*'] = pri_op['/'] = 1;
    //
    for (auto i : str)
    {
        if (i >= 'A' && i <= 'Z')
            postfix += i;
        else if (i == ')')
        {
            while (op.top() != '(')
            {
                postfix += op.top();
                op.pop();
            }
            op.pop();
        }
        else if (i=='('||op.empty() || pri_op[op.top()] < pri_op[i]) //우선순위가 큰게 걸렸을경우
            op.push(i);
        else
        {  
            while(!op.empty()&&op.top()!='('&&pri_op[op.top()]>=pri_op[i])
            {
                postfix+=op.top();
                op.pop();
            }
            op.push(i); //현재연산자
        }
    }
    while(!op.empty())
    {
        postfix+=op.top();op.pop();
    }
    cout<<postfix;
    return 0;
}