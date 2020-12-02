#include <bits/stdc++.h>
using namespace std;
#define MaxSize 100001
#define f(i, j, k) for (int i = j; i <= k; i++)
#define range pair<int, int>
#define start first
#define end second
int N;
int In_Order[MaxSize];
int Post_Order[MaxSize];

int number(range A) {
    int num = (A.end - A.start + 1);
    return num > 0 ? num : 0;
}
//현재까지 탐색한 InOrder의 범위를 가지고있어야함
//현재까지 탐색한 PostOrder의 범위도 가지고 있어야함.

//in_range,post_range 두개변수
//1.먼저 post_range안의 맨마지막 수A를 찾음 출력
//2.inOrder안에 A의 순서를 찾음
//3.in_range안의 A의 왼쪽과 오른쪽의 갯수를 찾음
//4.오른쪽갯수가 존재할경우 해당범위 재지정및 1~4,(오른쪽갯수+1)왼쪽출력(1~4)
void FindChildNode(range in_range, range post_range)
{   
    int left_num = 0, right_num = 0;
    range in_left, in_right, post_left, post_right;
    in_left = in_right = in_range;
    int mid = Post_Order[post_range.end];
    cout << mid << " ";
    in_left.end = In_Order[mid] - 1;
    in_right.start = In_Order[mid] + 1;
    left_num = number(in_left);
    right_num = number(in_right);
    if (left_num > 0)
    {
        post_left.end = post_range.end - 1 - right_num, post_left.start = post_left.end + 1 - left_num;
        FindChildNode(in_left, post_left);
    }
    if (right_num > 0)
    {
        post_right.end = post_range.end-1, post_right.start = post_range.end - right_num;
        FindChildNode(in_right, post_right);
    }
}
int main(void)
{ /*
    10
    2 4 3 1 6 9 8 5 7 10
    4 3 2 9 8 6 10 7 5 1
    */

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    f(i, 1, N)
    {
        int k;
        cin >> k;
        In_Order[k] = i; //위치를담고있다.
    }
    f(i, 1, N) cin >> Post_Order[i];
    FindChildNode({ 1,N }, { 1,N });
    return 0;
}