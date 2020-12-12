#include <iostream>
using namespace std;
int ans, n, pi[5001];
char t[5001];

int main(){
    cin.sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    for(int i = 0; t[i] != '\0'; i++){
        int k = 0;
        for(int j = i + 1; t[j] != '\0'; j++){
            while(k > 0 && t[j] != t[i + k]) k = pi[k - 1];
            if(t[j] == t[i + k]){
                k++;
                if(ans < k)ans = k;
            }
            pi[j - i] = k;
        }
    }
    cout << ans;
    
}