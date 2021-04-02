#include <bits/stdc++.h>
#define ll unsigned long long
#define modulo 1000007
map<ll, int> cache;
using namespace std;
//N<10^6
//N<10^6
int findNumber(ll num) //이것의 약수는 전부 그것의 약수가됨
{   int& result=cache[num];
    if(result!=0) return result;
    for (int i = 1; i*i <num; i++)
    {
        if(num%i==0) result+=findNumber(num);
    }
    return result;
}
int ArithmeticEquation(int n)
{
    // n!=M
    // M^2=a*b
    ll pactorialN = 1;
    for (int i = 2; i <= n; i++)
    {
        pactorialN *= i;
    }
    ll pactorialNN = (pactorialN * pactorialN);
    for (int i = 1; i <= pactorialN; i++)
    {
        if (pactorialN % i == 0)
        {
            findNumber(pactorialN/i);
        }
    }
}
int main()
{
    cout << ArithmeticEquation(7);
}