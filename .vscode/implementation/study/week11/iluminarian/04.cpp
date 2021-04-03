#include <bits/stdc++.h>
using namespace std;
//perfect binary tree
//4. 오름 차순으로 정렬된 배열이 있다.
//이 배열 안에 들어 있는 원소는 정수이며 중복된 값이 없다고 했을때
//가장 높이가 최소가 되는 이진 탐색 트리를 만드는 알고리즘을 작성하라.
// 답: Complete binary tree인 minheap구현 하면된다. 높이 최소화
class Minheap
{
    int *arr;
    int capacity;
    int heap_size;

public:
    Minheap(int capacity)
    {   
        this->capacity = capacity;
        arr = new int[capacity + 1];
        heap_size=0;
    }
    void insert(int num) //이미 정렬 되있으므로
    {   arr[heap_size++]=num; }
    void search(int idx){

    }
    
} int main()
{
}