#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Node
{
    ll data;
    Node *left, *right;
    Node(ll data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
struct BinaryTree
{
    Node *root = NULL;
    ll insert(ll data)
    {
        if (root == NULL)
        {
            root = new Node(data);
        }
        else
        {
            Node *now = root;
            Node *next = root;
            while (next != NULL)
            {   
                now=next;
                if (now->data == data) data++;
                if (now->data < data)
                {
                    next = now->right;
                    if (next == NULL) now->right = new Node(data);
                }
                else
                {
                    next = now->left;
                    if (next == NULL) now->left = new Node(data);
                }
            }
        }
        return data;
    }
} Btree;
vector<ll> solution(ll k, vector<ll> room_number)
{   
    vector<ll> answer;
    for (auto room : room_number)
    {
        answer.push_back(Btree.insert(room));
    }
    return answer;
}
int main()
{
    solution(10, vector<ll>({1, 3, 4, 1, 3, 1}));
}