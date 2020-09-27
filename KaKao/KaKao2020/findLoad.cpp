#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define Pair pair<int, int>
#define pair_now(i)                    \
    {                                  \
        nodeinfo[i][0], nodeinfo[i][1] \
    }
#define newnode(i)                  \
    {                               \
        M[pair_now(i)], pair_now(i) \
    }
map<Pair, int> M;
bool compare(vector<int> a, vector<int> b)
{
    if (a[1] != b[1])
        return a[1] > b[1];
    else
        return a[0] < b[0];
}
class node
{
public:
    int data;
    Pair pos;
    node *left = NULL;
    node *right = NULL;
    node(int data, Pair pos)
    {
        this->data = data;
        this->pos = pos;
    }
    void push_data(int data, Pair pos_)
    {
        if (pos.first > pos_.first)
        {
            if (left == NULL)
            {
                left = new node(data, pos_);
            }
            else
            {
                left->push_data(data, pos_);
            }
        }
        else
        {
            if (right == NULL)
            {
                right = new node(data, pos_);
            }
            else
            {
                right->push_data(data, pos_);
            }
        }
    }
};
void preorder(node &parent, vector<int> &answer)
{
    answer.push_back(parent.data);
    if (parent.left != NULL)
        preorder(*parent.left, answer);
    if (parent.right != NULL)
        preorder(*parent.right, answer);
}
void postorder(node &parent, vector<int> &answer)
{
    node *left_node = parent.left;
    if (left_node != NULL)
        postorder(*left_node, answer);
    node *right_node = parent.right;
    if (right_node != NULL)
        postorder(*right_node, answer);
    answer.push_back(parent.data);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> answer(2);
    vector<vector<node>> NodeSet;
    for (int i = 0; i < nodeinfo.size(); i++)
        M[make_pair(nodeinfo[i][0], nodeinfo[i][1])] = i + 1;
    sort(nodeinfo.begin(), nodeinfo.end(), compare);
    node *P = new node(newnode(0));
    vector<vector<Pair>> Grade;
    int cur_grade = nodeinfo[0][1];
    Grade.push_back(vector<Pair>(1, pair_now(0)));
    vector<node> vec;
    NodeSet.push_back(vector<node>(1, newnode(0)));
    Pair cur_Range = {1, 1};
    for (int i = 1, j = 0; i < nodeinfo.size(); i++)
    {
        P->push_data(M[pair_now(i)], pair_now(i));
        if (nodeinfo[i - 1][1] != nodeinfo[i][1]) //다른층이라면
        {
            NodeSet.push_back(vector<node>(1, newnode(i)));
            j++;
        }
        else
        {
            NodeSet[j].push_back(newnode(i));
        }
    }
    for (int i = 0; i < NodeSet.size() - 1; i++)
    {
        vector<node> &Parent = NodeSet[i];
        vector<node> &Child = NodeSet[i + 1];
        for (int p = 0, c = 0; p < Parent.size() && c < Child.size(); c++)
        {
            int Parent_x = Parent[p].pos.first;
            int Child_x = Child[c].pos.first;
            if (Parent_x > Child_x)
            {
                Parent[p].left = &Child[c];
            }
            else
            {
                Parent[p].right = &(Child[c]);
                p++;
            }
        }
    }
    preorder(*P, answer[0]);
    postorder(*P, answer[1]);
    return answer;
}
