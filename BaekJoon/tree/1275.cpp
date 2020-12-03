#include<bits/stdc++.h>
using namespace std;
class SegmentTree {
    int node[200004];
    int length;
public:
    SegmentTree(int arr[],int count)
    {
        length = count;
        for (int i = 1, j = length+1;i <=length;) 
            node[j++] = arr[i++];
        build();
    }
    void build() {
        for (int i = length;i >= 1;i--) 
            node[i] = node[i << 1] + node[(i << 1) | 1];
    }
    int findSum(int s, int e) {
        int sum = 0;
        int start = s + length;
        int end = e + length;
        while (start < end) {
            if (start & 1) sum += node[start++];
            start >>= 1;
            if ((end & 1) == 0) sum += node[end--];
            end >>= 1;
        }
        if (start == end) sum += node[start];
        return sum;
    }
    void update(int where, int how) {
        where = where + length + 1;
        node[where] = how;
        while (where > 1) {
            node[where >> 1] = node[where | 1] + node[where | 0];
            where >>= 1;
        }
    }
};
int N, M;
int* arr;
SegmentTree* Tree;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> N >> M;
    arr = new int[N+1];
    for (int i = 1;i <= N;i++) cin >> arr[i];
    Tree = new SegmentTree(arr,N);
    for (int i = 0;i <= M;i++) {
        int start, end, where, how;
        cin >> start >> end >> where >> how;
        cout << Tree->findSum(start , end ) << "\n";
        Tree->update(where, how);
    }
    return 0;
}