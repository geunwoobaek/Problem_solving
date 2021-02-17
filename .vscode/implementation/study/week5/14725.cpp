#include <bits/stdc++.h>
#define F(i, s, e) for (int i = s; i < e; i++)
using namespace std;
int N;
struct Trie
{
    map<string, Trie *> child;
    string data;
    int depth;
    Trie(string data, int depth)
    {  
        this->data = data;
        this->depth = depth;
    }
    void insert(string data)
    {
        if (child[data] == nullptr) child[data] = new Trie(data, depth + 1);
        else child[data]->insert(data);
    }
    void search()
    {
        cout << data << "\n";
        for (auto it = child.begin(); it != child.end(); it++)
        {
            stack<pair<string, Trie *>> st; //stack탐색
            st.push(*it);
            while (!st.empty())
            {
                auto now = st.top();
                st.pop();
                for (int i = 0; i <(now.second->depth); i++) //출력부분
                     cout <<"--";
                cout << now.first << "\n";
                for (auto it = now.second->child.rbegin(); it != now.second->child.rend(); it++) //자식노드 쌓기
                    st.push(*it);
            }
        }
    }
};
map<string, Trie *> root;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    F(i, 0, N)
    {
        int k;
        string p, c;
        cin >> k >> p;
        if (root[p] == nullptr)
        {
            root[p] = new Trie(p, 0);
        }
        auto *r = root[p];
        F(j, 0, k - 1)
        {
            cin >> c;
            if(r->child[c]==nullptr)
                r->insert(c);
            r = r->child[c];
        }
    }
    for (auto it = root.begin(); it != root.end(); it++)
        it->second->search();
    }
    return 0;
}