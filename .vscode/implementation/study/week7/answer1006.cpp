#include<bits/stdc++.h>
using namespace std;
int n, w, res;
int e[10000][2], a[10001], b[10000], c[10000];
 
void solve(int start) {
    for (int i = start; i < n; i++) {
        a[i+1] = min(b[i] + 1, c[i] + 1);
        if (e[i][0] + e[i][1] <= w)
            a[i+1] = min(a[i+1], a[i] + 1);
        if (i > 0 && e[i-1][0] + e[i][0] <= w && e[i-1][1] + e[i][1] <= w)
            a[i+1] = min(a[i+1], a[i-1] + 2);
        if (i < n-1) {
            b[i+1] = a[i+1] + 1;
            if (e[i][0] + e[i+1][0] <= w)
                b[i+1] = min(b[i+1], c[i] + 1);
            c[i+1] = a[i+1] + 1;
            if (e[i][1] + e[i+1][1] <= w)
                c[i+1] = min(c[i+1], b[i] + 1);
        }
    }
}
 
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
     
    cin >> t;
    while (t--) {
        cin >> n >> w;
        res = 30000;
 
        for (int i = 0; i < n; i++)
            cin >> e[i][0];
        for (int i = 0; i < n; i++)
            cin >> e[i][1];
         
        a[0] = 0;
        b[0] = c[0] = 1;
        solve(0);
        res = min(res, a[n]);
 
        if (n > 1 && e[0][0] + e[n-1][0] <= w) {
            a[1] = 1;
            b[1] = 2;
            c[1] = e[0][1] + e[1][1] <= w? 1 : 2;
            solve(1);
            res = min(res, c[n-1] + 1);
        }
 
        if (n > 1 && e[0][1] + e[n-1][1] <= w) {
            a[1] = 1;
            b[1] = e[0][0] + e[1][0] <= w? 1 : 2;
            c[1] = 2;
            solve(1);
            res = min(res, b[n-1] + 1);
        }
 
        if (n > 1 && e[0][0] + e[n-1][0] <= w && e[0][1] + e[n-1][1] <= w) {
            a[1] = 0;
            b[1] = c[1] = 1;
            solve(1);
            res = min(res, a[n-1] + 2);
        }
 
        cout << res << '\n';
    }
 
    return 0;
}