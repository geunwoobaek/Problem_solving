#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int N;
vector<int> lis(1, 2e9);
int arr[1000001];
int arr2[1000001];
stack<int> answer;
void binaryInsert(int i,int temp)
{
    int left = 0, right = lis.size() - 1;
    while (left < right)
    {
        int mid = (right + left) / 2;
        if (lis[mid] >= temp) right = mid;
        else left = mid + 1;
    }
    lis[left] = temp;
    arr2[i]=left;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
        if (lis.back() < temp) {
            lis.push_back(temp);
            arr2[i]=i;
        }
        else binaryInsert(i, temp);
    }
    cout << lis.size() << "\n";
    for(int i=N-1,j=lis.size()-1;i>=0;i--)
    {
        if(arr2[i]==j) {
            answer.push(arr[i]);
            j--;
        }
    }
    while (!answer.empty())
    {
        cout << answer.top() << " ";
        answer.pop();
    }
    return 0;
}