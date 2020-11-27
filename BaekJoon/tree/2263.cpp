#include <bits/stdc++.h>
using namespace std;
#define MaxSize 100001
#define f(i, j, k) for (int i = j; i <= k; i++)
int N;
int In_Order[MaxSize];
int Post_Order[MaxSize];
class node
{
public:
    int number;
    node *left;
    node *right;

    node(int number)
    {
        this->number = number;
        left = NULL;
        right = NULL;
    }
    int get() { return number; }
};
class Tree
{
    public:
    node *root;
    Tree(int num){
        root=new node(num);
    }
    void PreOrderSearch(const node *now)
    {
        if (root->get() == NULL)
            return;
        cout << root->get() << " ";
        PreOrderSearch(root->left);
        PreOrderSearch(root->right);
    }
    node* getRoot(){
        return root;
    }
};
void FindChildNode(int left,int right,node *Parent) 
{
    int OrderNumber=In_Order[Parent->get()];
    //이때 In_Order기준으로
    int right_number=right-OrderNumber;
    int left_number=OrderNumber-left;
    if(right_number>0) FindChildNode(OrderNumber+1,right-1,Parent->right=new node(Post_Order[right-1]));
    if(left_number>0) FindChildNode(left,OrderNumber-1,Parent->left=new node(Post_Order[right_number-1]));
}
int main(void)
{   /*
    10
    2 4 3 1 6 9 8 5 7 10
    4 3 2 9 8 6 10 7 5 1
    */

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    f(i, 1, N) {
        int k;
        cin >>k; In_Order[k]=i;
    }
    f(i, 1, N) cin >> Post_Order[i];
    Tree *tree=new Tree(Post_Order[N]);
    FindChildNode(1,N,tree->getRoot());
    cout<<"";
    return 0;
}