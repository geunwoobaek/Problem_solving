#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> GemsMap; // key:보석이름 value:정수로 변환된 보석종류
vector<int> GemsVec;
unordered_map<int, int> KindsCount; //key=보석종류,value=수
queue<int> Gemque;
int start_ = 0, end_ = 0, tempStart = 0, tempEnd = 0;
int Kinds = 0;
int MinLength = 2e9;

vector<int> solution(vector<string> gems)
{
    for (auto &gem : gems)
    {
        if (GemsMap[gem] == 0)
        {
            ++Kinds;
            GemsMap[gem] = Kinds;
        }
        GemsVec.push_back(GemsMap[gem]);
    }
    for (auto gem : GemsVec)
    {
        Gemque.push(gem);                      //1
        KindsCount[gem]++;                     //1
        while (KindsCount[Gemque.front()] > 1) //2~3
        {
            KindsCount[Gemque.front()]--;
            tempStart++;
            Gemque.pop();
        }
        if ((int)KindsCount.size() == Kinds && (int)Gemque.size() < MinLength) //4
        {
            MinLength = Gemque.size();
            start_ = tempStart;
            end_ = tempEnd;
        }
        tempEnd++;
    }
    return vector<int>({start_ + 1, end_ + 1});
};
