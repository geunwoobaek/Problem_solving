#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define Pair pair<int, int>
int num_sim_user_topk, num_item_rec_topk, num_users, num_items, num_rows;
vector<vector<double>> usersinfo;
vector<vector<double>> usersNewRating;
map<Pair, double> SimiliarMap;
void input();
void MakeNewRatings();
void MakeSimiliarMap();
void MakeSimilarity(int user1, int user2);
void SortUserBySimliarMap();
bool cmp(pair<Pair, double> &a, pair<Pair, double> &b)
{
    return a.second > b.second;
}
void MakeNewRatings()
{
    for (int user = 1; user <= num_users; user++)
    {
        double average = 0;
        int count = 0;
        for (auto rate : usersinfo[user])
        {
            if (rate != 0)
                count++, average += rate;
        }
        average /= count;
        for (int i = 1; i < usersinfo[user].size(); i++)
        {
            if (usersinfo[user][i] != 0)
            {
                usersNewRating[user][i] = usersinfo[user][i] - average;
            }
        }
    }
}
void MakeSimiliarMap()
{
    for (int cur = 1; cur < num_users; cur++)
        for (int i = cur + 1; i <= num_users; i++)
            MakeSimilarity(cur, i);
}
void MakeSimilarity(int user1, int user2)
{
    Pair key = {user1, user2};
    const vector<double> &user1rating = usersNewRating[user1];
    const vector<double> &user2rating = usersNewRating[user2];
    double user1sigma = 0, user2sigma = 0, user1user2;
    for (int i = 1; i < user1rating.size(); i++)
    {
        if (usersinfo[user1][i] == 0 || usersinfo[user2][i] == 0)
            continue; //점수없는것
        user1sigma += user1rating[i] * user1rating[i];
        user2sigma += user2rating[i] * user2rating[i];
        user1user2 += user1rating[i] * user2rating[i];
    }
    SimiliarMap[key] = user1user2 / ((sqrt(user1sigma)) * (sqrt(user2sigma)));
}
void input()
{
    cin >> num_sim_user_topk >> num_item_rec_topk >> num_users >> num_items >> num_rows;
    usersinfo.resize(num_users + 1, vector<double>(num_items + 1));
    usersNewRating.resize(num_users + 1, vector<double>(num_items + 1));
    for (int i = 0; i < num_rows; i++)
    {
        int user, item;
        double rating;
        cin >> user >> item >> rating;
        usersinfo[user][item] = rating;
    }
}
void SortUserBySimliarMap()
{
    sort(SimiliarMap.begin(), SimiliarMap.end(), cmp);
}
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    MakeNewRatings();
    MakeSimiliarMap();
    SortUserBySimliarMap();
    for (auto &it : SimiliarMap)
    {
        cout<<it.second << "\n";
    }
    return 0;
}