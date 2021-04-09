#include <bits/stdc++.h>
using namespace std;

#define Matrix vector<vector<char>>
#define Pair pair<int, int>
#define y first
#define x second
#define Point vector<int>

bool CheckRectangle(Pair a, Pair b, Matrix &matrix)
{
    for (int c = a.y; c < b.y; c++)
    {
        for (int r = a.x; r < b.x; r++)
            if (matrix[c][r] == '0')
                return false;
    }
    return true;
}
// int maximalRectangle(Matrix &matrix)
// {
//     int col = matrix.size();
//     if (col == 0)
//         return 0;
//     int row = matrix[0].size();
//     int max_sum = 0;
//     for (int c = col; c >= 1; c--) //c=2 r=2
//     {
//         for (int r = row; r >= 1; r--) //세로 c 가로 r의 4각형만들기
//         {
//             int next_sum = (c) * (r);
//             if (next_sum < max_sum)
//                 break;
//             for (int i = 0; i <= col - c; i++)
//             {
//                 for (int j = 0; j <= row - r; j++)
//                     if (CheckRectangle({i, j}, {i + c, j + r}, matrix))
//                         max_sum = max(max_sum, next_sum);
//             }
//         }
//     }
//     return max_sum;
// }
int maximalRectangle(vector<vector<char> > &matrix) {
    if(matrix.empty()) return 0;
    const int m = matrix.size();
    const int n = matrix[0].size();
    int left[n], right[n], height[n];
    fill_n(left,n,0); fill_n(right,n,n); fill_n(height,n,0);
    int maxA = 0;
    for(int i=0; i<m; i++) {
        int cur_left=0, cur_right=n; 
        for(int j=0; j<n; j++) { // compute height (can do this from either side)
            if(matrix[i][j]=='1') height[j]++; 
            else height[j]=0;
        }
        for(int j=0; j<n; j++) { // compute left (from left to right)
            if(matrix[i][j]=='1') left[j]=max(left[j],cur_left);
            else {left[j]=0; cur_left=j+1;}
        }
        // compute right (from right to left)
        for(int j=n-1; j>=0; j--) {
            if(matrix[i][j]=='1') 
                right[j]=min(right[j],cur_right);
            else {
                right[j]=n; cur_right=j;
                }    
        }
        // compute the area of rectangle (can do this from either side)
        for(int j=0; j<n; j++)
            maxA = max(maxA,(right[j]-left[j])*height[j]);
    }
    return maxA;
} //0 0 2 0 0=> 0 0 2 2 2 , 1 5 3 5 5 =>1 5 3 5 5
int main()
{
    vector<vector<char>> matrix({{'1', '0', '1', '0', '0'},
                                 {'1', '0', '1', '1', '1'},
                                 {'1', '1', '1', '1', '1'},
                                 {'1', '0', '0', '1', '0'}});
    maximalRectangle(matrix);
    // vector<vector<char>> matrix1({});
    // maximalRectangle(matrix1);
    return 0;
}