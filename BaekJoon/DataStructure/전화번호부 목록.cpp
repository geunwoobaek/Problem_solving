#include <stdio.h>
#define num 10
#define maxn 10000
 
struct trie {
    trie* pan[num];
    bool end;
 
    trie() {
        for (int i = 0; i < num; ++i)
            pan[i] = nullptr;
        end = false;
    }
    ~trie() {
        for (int i = 0; i < num; ++i)
            if (pan[i] != nullptr)
                delete pan[i];
    }
 
    void insert(char* str) {
        if (*str == '\0') {
            end = true;
            return;
        }
        //종료
        int cur = *str - '0';
        if (pan[cur] == nullptr)
            pan[cur] = new trie();
        pan[cur]->insert(str + 1);
    }
 
    int find(char* str) {
        if (*str == '\0')
            return 0;
 
        if (end)
            return 1;
 
        int cur = *str - '0';
        return pan[cur]->find(str + 1);
    }
};
 
int t, n;
char buf[maxn][11];
 
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
 
        trie* root = new trie();
 
        for (int i = 0; i < n; ++i) {
            scanf("%s", buf[i]);
            root->insert(buf[i]);
        }
        
        bool ans = true;
        for (int i = 0; i < n; ++i) {
            if (root->find(buf[i])) {
                ans = false;
                break;
            }
        }
        if (ans)
            puts("YES");
        else
            puts("NO");
 
        delete root;
    }
}
