#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
//1234 i가 1000 i/10 100 i
int num=1
int solution(int num)
{

    int check = 0;
    if (num < 0) check = 1;
    string str = to_string(num);

    for (int i = check; i < str.size(); i++)
    {
        if (check == 0)
        {
            if (str[i] < '5')
            {
                str.insert(str.begin() + i, 5);
                return stoi(str);
            }
        }
        else
        {
            if (str[i] > '5')
            {
                str.insert(str.begin() + i, 5);
                return stoi(str);
            }
        }
    }
}
int main()
{
    cout << solution(268);
    return 0;
}