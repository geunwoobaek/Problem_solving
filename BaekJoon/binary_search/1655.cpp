// 1. 최대 힙의 크기는 최소 힙의 크기와 같거나, 하나 더 크다.
// 2. 최대 힙의 최대 원소는 최소 합의 최소 원소보다 작거나 같다.
// 이때 알고리즘에 맞지 않다면 최대 힙, 최소 힙의 가장 위의 값을 swap해준다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N;
priority_queue<int, vector<int>, greater<>> Minheap;
priority_queue<int, vector<int>, less<>> MaxHeap;
vector<int> vec;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        if (i % 2 == 0)
        {
            if (!Minheap.empty()) //maxheap에 넣을것
            {
                int MinValue = Minheap.top();
                if (temp > MinValue)
                {
                    Minheap.pop();
                    Minheap.push(temp);
                    temp = MinValue;
                }
            }
            MaxHeap.push(temp);
        }
        else
        {
            int MinValue = MaxHeap.top();
            if (temp < MinValue)
            {
                MaxHeap.pop();
                MaxHeap.push(temp);
                temp = MinValue;
            }
            Minheap.push(temp);
        }
        printf("%d\n", MaxHeap.top());
    }
    return 0;
}