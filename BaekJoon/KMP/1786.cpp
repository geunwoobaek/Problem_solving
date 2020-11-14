#include <iostream>
#include <vector>
#include <string>
using namespace std;
string T, P;
//N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해 pi[] 계산
//pi[i] = N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
vector<int> getPartialMatch(const string& N)
{   string a="asc-a";
    int M = N.size();
    vector<int> pi(M, 0);
    int begin = 1, matched = 0;
    while (begin + matched < M)
    {
        if (N[begin + matched] == N[matched])
        {
            matched++;
            pi[begin + matched - 1] = matched;
        }
        else
        {
            if (matched == 0)
                begin++;
            else
            {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
    }
vector<int> getPartialMatchMySelf(const string& N)
{
    int M = N.size();
    vector<int> pi(M, 0);
    int prefix = 0;
    int suffix = 1;
    while (suffix < M)
    {
        while (prefix>=0&&(N[prefix] != N[suffix]))
           prefix--;
        pi[suffix] = prefix + 1;
        suffix++;
        prefix++;
    }
    return pi;
}


vector<int> kmpSearch2(const string& H, const string& N)
{
    int n = H.size(), m = N.size();
    vector<int> result;
   // vector<int> pi = getPartialMatch(N);
    vector<int> pi = getPartialMatchMySelf(N);
    //현재 대응된 글자의 수
    int matched = 0;
    //짚더미의 각 글자를 순회
    for (int i = 0; i < n; i++)
    {
        //matched번 글자와 짚더미의 해당 글자가 불일치할 경우,
        //현재 대응된 글자의 수를 pi[matched-1]로 줄인다
        while (matched > 0 && H[i] != N[matched])
            matched = pi[matched - 1];
        //글자가 대응될 경우
        if (H[i] == N[matched])
        {
            matched++;
            if (matched == m)
            {
                //문제에서 인덱스는 0이 아닌 1부터 시작
                result.push_back(i - m + 2);
                matched = pi[matched - 1];
            }
        }
    }
    return result;
}
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 속도 향상 위해
    cout.tie(NULL);
    getline(cin, T); //공백 포함해서 입력받기 위해
    getline(cin, P);
    vector<int> result = kmpSearch2(T, P);
    //endl 쓰면 시간 초과
    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << "\n";
    return 0;
}

