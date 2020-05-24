#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
void rotate(vector<vector<int>>& key) //90도 회전
{
    vector<vector<int>> key2(key.size(), vector<int>(key.size(), 0));
    int size = key.size() - 1;
    for (int i = 0;i <= size;i++)
    {
        for (int j = 0;j <= size;j++)
        {
            key2[j][size - i] = key[i][j];
        }
    }
    key = key2;
}
bool compare(vector<int> bitlock, vector<int> bitkey) //자리수 이동
{
    int locksize = bitlock.size();
    int keysize = bitkey.size();
    int num = keysize;
    int full = (1 << locksize) - 1;
    while (num--)
    {
        int num2 = keysize;
        vector<int> bitkey2 = bitkey;
        while (num2--)
        {   
            for (int i = 0;i < locksize;i++)
            {
                if (i<keysize)
                {
                    if ((bitkey2[i] ^ bitlock[i]) != full) break;
                }
                else {
                    if (bitlock[i] != full) break;
                }
                if (i == locksize-1) 
                    return true;
            }
            for (int j = 0;j < keysize;j++) bitkey2[j] = bitkey2[j] >> 1;
        }
        bitkey.insert(bitkey.begin(),0);
    }
    return false;
}

vector<int> making_bit(vector<vector<int>> D)
{
    vector<int> bit(D.size(), 0);
    for (int i = 0;i < D.size();i++)
    {
        for (int j = 0;j < D.size();j++)
        {
            bit[i] += D[i][j] << (D.size() - 1 - j);
        }
    }
    return bit;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    vector<int> key_bit = making_bit(key);
    vector<int> lock_bit = making_bit(lock);
    for (int i = 0;i < 4;i++)
    {
        if (compare(lock_bit, key_bit)) return true;
        rotate(key);
        key_bit = making_bit(key);
    }
    return false;
}
int main()
{
    vector<vector<int>> key(3, vector<int>(3, 0));
    vector<vector<int>> lock(3, vector<int>(3, 0));
    key[0][0] = 1;
    key[0][1] = 1;
    key[0][2] = 1;
    key[1][0] = 1;
    key[1][1] = 1;
    key[1][2] = 0;
    key[2][0] = 1;
    key[2][1] = 0;
    key[2][2] = 1;
    lock[1][0] = 1; lock[2][1] = 1; lock[2][2] = 1;
    if (solution(lock, key)) cout << "true";
    else cout << "false";
    return 0;
}