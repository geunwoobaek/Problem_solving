#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (1)
    {
        cin >> n;
        cout << n << "\n";
        for (int i = 0; i < n; i++)
        {
            int a = rand() % 3;
            printf("%d %d %d\n", rand() % 2 + 2, rand() % 3, rand() % 3);
        }
    }
}