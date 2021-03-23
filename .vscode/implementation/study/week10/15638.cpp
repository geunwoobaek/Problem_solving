#include <bits/stdc++.h>

using namespace std;
#define Cameras vector<Camera>
#define Direction pair<int,int>
#define y first
#define x second
#define Visit vector<vector<bool>>
#define F(i, s, e) for (int i = s; i <= e; i++)
int Room[9][9];                         //최대크기
Visit visit_(9, vector<bool>(9, false)); //최대크기
int N, M;
int max_ = 0;
struct Camera
{
    int y, x;
    vector<Direction> directions;
};
Cameras cameras;
Direction right_ ={0, 1};
Direction left_ ={0, -1};
Direction up_ = {1, 0};
Direction down_ = {-1, 0};
map<Direction, int> umMap;
map<int, Direction> ConMap;
vector<vector<Direction>> directions({vector<Direction>(),
                                      vector<Direction>({right_}),
                                      vector<Direction>({right_, left_}),
                                      vector<Direction>({up_, right_}),
                                      vector<Direction>({left_, right_, up_}),
                                      vector<Direction>({left_, right_, up_, down_})});
vector<int> direction_size({0, 4, 2, 4, 4, 1});
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
void map_init()
{
    umMap[right_] = 0;
    umMap[up_] = 1;
    umMap[left_] = 2;
    umMap[down_] = 3;

    ConMap[0] = right_;
    ConMap[1] = up_;
    ConMap[2] = left_;
    ConMap[3] = down_;
    ConMap[4] = right_;
}
void rotate(Camera &camera)
{
    for (auto &cur : camera.directions)
        cur = ConMap[umMap[cur] + 1];
}
int go(Camera &camera, Visit &cur_visit)
{
    int result = 0;
    for (auto now : camera.directions)
    {
        Camera cur = camera;
        while (1)
        {
            Camera next_ = {cur.y + now.y, cur.x + now.x};
            if (next_.y > 0 && next_.x > 0 && next_.y <= N && next_.x <= M && Room[next_.y][next_.x] != 6)
            {
                if (!cur_visit[next_.y][next_.x])
                    result++;
                cur_visit[next_.y][next_.x] = true;
                swap(cur, next_);
            }
            else
                break;
        }
    }
    return result;
}
void dfs(int depth, int result, Visit &cur_visit)
{
    max_ = max(result, max_);
    if (depth == cameras.size())
        return;
    Camera next_camera = cameras[depth];
    for (int i = 0; i < 4; i++)
    {
        Visit next_visit = cur_visit;
        int how_many = go(next_camera, next_visit);
        dfs(depth + 1, result + how_many, next_visit);
        rotate(next_camera);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map_init();

    cin >> N >> M;
    F(i, 1, N)
    F(j, 1, M)
    {
        int what;
        cin >> what;
        Room[i][j] = what;
        if (what != 0)
        {
            if (what != 6)
                cameras.push_back({i, j, directions[what]});
            visit_[i][j] = true;
            max_++;
        }
    }
    dfs(0, max_, visit_);
    cout << N * M - max_;
    return 0;
}