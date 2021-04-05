#include <bits/stdc++.h>
using namespace std;
// 오름 차순으로 정렬된 배열이 있다. 이 배열 안에 들어 있는 원소는 정수이며
// 중복된 값이 없다고 했을때 가장 높이가 최소가 되는 이진 탐색 트리를 만드는 알고리즘을 작성하라.
// 높이 최소화 위해선 CompleteBinaryTree를 구현하면 된다.
// CompleteBinaryTree가 될려면 좌우에 있는 자식의 갯수가 균일해야한다
// 이를 위해서 알고리즘은 다음과 같다.
// 이미 배열이 정렬된것을 이용하자.
// (1).배열의 중간 값을 노드에 삽입
// (2).삽입한 배열의 중간인덱스를 끝점으로 왼쪽범위에서 (1) 진행
// (3).삽입한 배열의 오른쪽인덱스를 시작점으로 오른쪽범위에서 (2)진행
// (1~3)을 진행하면 된다. 이때 BFS방식으로 균일하게 삽입해야한다.
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node node()
    {
        data = 2e9;
        left = nullptr;
        right = nullptr;
    }
};
struct state
{
    int start, end;
    Node *node;
};
struct CompleteBST
{
    Node *root;
    int capaicity = 0;
    int size;
    CompleteBST(int arr[], int size)
    {
        root = new Node();
        this->size = size;
        queue<state> que;
        que.push({0, size - 1, root});
        while (!que.empty()) 
        {
            state cur = que.front();
            que.pop();
            int mid = (cur.end + cur.start);
            if ((mid & 1))
                mid = (mid >> 1) + 1;
            else
                mid >>= 1;
            cur.node->data = arr[mid];
            capaicity++;
            if (mid - 1 - cur.start >= 0)
            {
                cur.node->left = new Node();
                que.push({cur.start, mid - 1, cur.node->left});
            }
            if (cur.end - mid - 1 >= 0)
            {
                cur.node->right = new Node();
                que.push({mid + 1, cur.end, cur.node->right});
            }
        }
    }
    int getDepth()
    {
        int max_depth = 0;
        queue<pair<int, Node>> que;
        que.push({1, *root});
        while (!que.empty())
        {
            pair<int, Node> node = que.front();
            max_depth = node.first;
            que.pop();
            if (&node != nullptr)
            {
           //     cout << node.second.data << ", ";
                if (node.second.left != nullptr)
                    que.push({node.first + 1, *node.second.left});
                if (node.second.right != nullptr)
                    que.push({node.first + 1, *node.second.right});
            }
        }
        return max_depth;
    }
};

int main()
{
    int arr[(1<<14)];
    for (int i = 0; i < (1<<14); i++)
        arr[i] = i;
    CompleteBST *tree = new CompleteBST(arr, (1<<14));
    cout << tree->getDepth();
    return 0;
}