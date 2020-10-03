#include <iostream>
#include <algorithm>

using namespace std;

int L, K, C, loc[10002];
bool isPossible(int s, int c, int l) { //s는 시작점 //c는 자를수 있는개수 ㅣ는 길이
    int rc = c;//갯수
    int cl = 0;
    for (int i = s; i <= K + 1; ++i) {
        if (loc[i] - loc[i - 1] > l) //전체길이 절반 1 4 8 10 이럴경우
            return false;
        if (cl + loc[i] - loc[i - 1] <= l) //cl 는 현재지점
            cl += loc[i] - loc[i - 1];
        else
            cl = loc[i] - loc[i - 1], --rc;
    }
    return rc >= 0;
}

int main() {
    cin>>L>>K>>C;
    loc[0] = 0;
    for (int i = 1; i <= K; ++i)
        cin>>loc[i];
    loc[K + 1] = L;
    sort(loc, loc + K + 2);

    int ll = 1, lm, lr = L;
    while (ll < lr) { //나눌위치 return 1 8 9 10 8보다 더크게나눌수이쓴거 없음 즉 ll=6 
        lm = (ll + lr) >> 1;
        if (isPossible(1, C, lm)) lr = lm;
        else ll = lm + 1;
    }

    int fl = 1, fm, fr = K;
    while (fl < fr) {
        fm = (fl + fr) >> 1;
        if (isPossible(fm + 1, C - 1, ll)) fr = fm;
        else fl = fm + 1;
    }

    printf("%d %d\n", ll, loc[fl]);
    return 0;
}