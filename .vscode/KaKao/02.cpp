#include <bits/stdc++.h>
using namespace std;
#define F(i, j, k) for (int i = j; i <= k; i++)
#define LEFT 0
#define RIGHT 1
#define y first
#define x second
pair<int, int> start_idx;
vector<int> _Lock,_Key;
int key_Size, lock_Size,Full;
void makeBit(const vector<vector<int>> &key, const vector<vector<int>> &lock);
void goLeft(vector<int> &key) { start_idx.x -= 1; }
void goRight(vector<int> &key) { start_idx.x += 1; }
void goUp(vector<int> &key) { start_idx.y -= 1; }
void goDown(vector<int> &key) { start_idx.y += 1; }
void goRotate(vector<int> &key);
bool isCorrect(const vector<int> &key);
bool checkAllRow(vector<int> key, int cmd);
bool solution(vector<vector<int>> key, vector<vector<int>> lock);
// int main()
// {
//     vector<vector<int>> key = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};//true
//     vector<vector<int>> key2 = {{1,1 ,1}, {1, 1, 1}, {0, 1, 1}}; //false
//     vector<vector<int>> key3 = {{1, 1, 0}, {1, 1, 1}, {1, 1, 1}}; //true
//     vector<vector<int>> lock = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
//     // if (solution(key, lock))
//     //     cout << "true";
//      if (solution(key2, lock))
//         cout << "true";
//      if (solution(key3, lock))
//         cout << "true";
//     else cout<<"false";
// }

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    key_Size = key.size();
    lock_Size = lock.size();
    Full = (1 << lock_Size) - 1;
    _Key.resize(key_Size);
    _Lock.resize(lock_Size);
    makeBit(key, lock); //비트키만들기
    F(rotate, 0, 3)
    {
        if (rotate != 0)
            goRotate(_Key);
        if (isCorrect(_Key))
            return true;
        vector<int> temp = _Key;
        F(up, 0, key_Size - 2)
        {
            goUp(temp);
            if (isCorrect(temp))
                return true;
            if (checkAllRow(temp, LEFT))
                return true;
            if (checkAllRow(temp, RIGHT))
                return true;
        }
        temp = _Key;
        start_idx.y = 0;
        F(down, 0, lock_Size - 2)
        {
            goDown(temp);
            if (isCorrect(temp))
                return true;
            if (checkAllRow(temp, LEFT)) //왼쪽으로
                return true;
            if (checkAllRow(temp, RIGHT)) //오른쪽으로
                return true;
        }
        start_idx.y = 0;
    }
    return false;
}
void makeBit(const vector<vector<int>> &key, const vector<vector<int>> &lock)
{
    F(i, 0, lock_Size - 1)
    {
        F(j, 0, lock_Size - 1)
        {
            if (i < key_Size && j < key_Size)
                _Key[i] += (key[i][j] <<j);
            _Lock[i] += (lock[i][j] <<j);
        }
    }
}
void goRotate(vector<int> &key)
{
    vector<int> new_key(key_Size);
    F(i, 0, key_Size - 1)
    F(j, 0, key_Size - 1)
    new_key[i] += (key[j] & (1 << (key_Size - 1 - i))) != 0 ? (1 << j) : 0;
    key = new_key;
}
bool checkAllRow(vector<int> key, int cmd)
{   
    int number=cmd==LEFT?key_Size-2:lock_Size-2;
    F(k, 0, number) //한쪽으로 쭉탐색
    {
        if (cmd == LEFT)
            goLeft(key);
        else if (cmd == RIGHT)
            goRight(key);
        if (isCorrect(key))
            return true;
    }
    start_idx.x = 0;
    return false;
}
bool isCorrect(const vector<int> &key)
{
    F(i, 0, lock_Size - 1)
    {
        int now_row;
        if (start_idx.y > i || start_idx.y + key_Size <= i)
            now_row = 0;
        else
        {
            int rowShift = lock_Size - start_idx.x - key_Size; //4 2
            if (rowShift >= 0)
                now_row = (key[i - start_idx.y] << rowShift) & Full;
            else
                now_row = key[i - start_idx.y] >> (-rowShift);
        }
        if ((now_row ^ _Lock[i]) != Full)
            return false;
    }
    return true;
};