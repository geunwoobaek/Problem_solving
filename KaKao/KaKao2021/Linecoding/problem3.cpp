#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int minimum = 2e9;
int minimum_result = 10;
void dfs(int result, int number)
{
    if (minimum <= result)
        return;
    if (number < 10)
    {
        minimum = result;
        minimum_result = number;
        return;
    }
    int k = 10;
    while (number>=k)
    {
        int a = number / k;
        int b = number % k;
        k *= 10;
        if(b*100<k) continue;
        dfs(result + 1, a + b);
    }
}
vector<int> solution(int n)
{
    vector<int> answer(2);
    dfs(0, n);
    answer[0] = minimum;
    answer[1] = minimum_result;
    return answer;
}
int main()
{ solution(10007);
    solution(10007);
}