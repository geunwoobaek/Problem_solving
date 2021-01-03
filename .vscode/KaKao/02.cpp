#include <bits/stdc++.h>
using namespace std;
#define F(i, j, k) for (int i = j; i <= k; i++)
#define LEFT -1
#define RIGHT +1
#define y first
#define x second
pair<int, int> start_idx; //key를 읽어드릴 시작지점
vector<int> _Lock, _Key;
int key_Size, lock_Size, Full;
void makeBit(const vector<vector<int>> &key, const vector<vector<int>> &lock); //비트로바꾸기
void goRotate(vector<int> &key);                                               //키 회전시키기
bool isCorrect(const vector<int> &key);                                        //맞는지 검사
bool checkAllRow(const vector<int> &key);                                      //해당렬 전부검사
bool checkDirection(vector<int> key, int cmd);                                 //해당 index에서 해당 방향검사
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
        start_idx = {0, 0};
        goRotate(_Key);
        if (isCorrect(_Key)) return true;
        vector<int> temp = _Key;
        F(up, 1, key_Size - 1)
        {
            start_idx.y--; //위로
            if (checkAllRow(temp)) return true;
        }
        temp = _Key;
        start_idx.y = 0;
        F(down, 1, lock_Size - 1)
        {
            start_idx.y++; //밑으로
            if (checkAllRow(temp))
                return true;
        }
    }
    return false;
}
void makeBit(const vector<vector<int>> &key, const vector<vector<int>> &lock) //비트로바꾸기
{
    F(i, 0, lock_Size - 1)
    {
        F(j, 0, lock_Size - 1)
        {
            if (i < key_Size && j < key_Size)
                _Key[i] += (key[i][j] << j);
            _Lock[i] += (lock[i][j] << j);
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
bool checkAllRow(const vector<int> &key)
{
    if (isCorrect(key)) return true;
    if (checkDirection(key, LEFT)) return true;
    if (checkDirection(key, RIGHT)) return true;
    return false;
}
bool checkDirection(vector<int> key, int cmd)
{
    int number = cmd == LEFT ? key_Size - 1 : lock_Size - 1;
    F(k, 1, number) //한쪽으로 쭉탐색
    {
        start_idx.x += cmd;
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