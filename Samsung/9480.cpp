#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
using namespace std;
static int Start = 'a';
int FULL = (1 << 26) - 1;
int MaxCount = 0;
void dfs(vector<int> &word_set, int start, int result)
{
    if (start == word_set.size())
    {
        if (FULL == result)
            MaxCount++;
        return;
    }
    if (result == FULL)
    {
        MaxCount += pow(2, word_set.size() - start);
        return;
    }
    dfs(word_set,start+1,result|word_set[start]);
    dfs(word_set,start+1,result);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int TestCase;
    cin >> TestCase;
    for (int Now = 1; Now <= TestCase; Now++)
    {
        int N;
        MaxCount=0;
        cin >> N;
        vector<int> word_set(N);
        for (int i = 0; i < N; i++)
        {
            string str;
            int state = 0;
            cin >> str;
            for (auto it : str)
            {
                state |= 1<<(it - Start);
            }
            word_set[i] = state;
        }
        dfs(word_set,0,0);
        cout<<"#"<<Now<<" "<<MaxCount<<endl;
    }
    return 0;
}