#include <bits/stdc++.h>
using namespace std;
#define Pair pair<int, int>
#define pos first
#define height second
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int __maxSize = 0, pos_length = heights.size();
        stack<Pair> st;
        for (int pos = 0; pos < pos_length; pos++)
        {
            int cur_height = heights[pos];
            if (!st.empty() && cur_height == st.top().height)
                continue;
            else
            {
                int next_pos = pos;
                while (!st.empty() && st.top().height > cur_height)
                {
                    Pair next = st.top();
                    next_pos = next.pos;
                    st.pop();
                    // int before = st.empty() ? 0 : st.top().pos;
                    __maxSize = max(__maxSize, (pos - next_pos) * next.height);
                }
                if (!st.empty() && cur_height == st.top().height)
                    continue;
                st.push({next_pos, cur_height});
            }
        }
        while (!st.empty())
        {
            Pair next = st.top();
            st.pop();
            __maxSize = max(__maxSize, (pos_length - next.pos) * next.height);
        }
        return __maxSize;
    }
};
int main()
{
    vector<int> vec({2, 1, 5, 6, 2, 3});
    vector<int> vec2({5, 4, 1, 2});
    Solution *solution = new Solution();
    cout << solution->largestRectangleArea(vec) << endl;
    cout << solution->largestRectangleArea(vec2) << endl;
}