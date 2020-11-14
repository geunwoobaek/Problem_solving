#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool Exist(const string& str)
{
    for (auto s : str)
    {
        if (s == '-')
            return true;
    }
    return false;
}
vector<int> solution(vector<string> card_numbers)
{
    vector<int> answer(card_numbers.size());
    for (int i = 0; i < card_numbers.size(); i++)
    {
        int even = 0, odd = 0;
        int index = 0, all = 0;
        bool isExist = Exist(card_numbers[i]);

        for (auto c : card_numbers[i])
        {
            all++;
            int now = 0;
            if (isExist)
            {
                if ((all % 5 == 0 && c != '-') || ((all % 5 != 0) && (c == '-'))) {
                    all = -1;
                    break;
                }
            }
                if (c == '-')
                {
                    continue;
                }
                else if (index % 2 != 0)
                    odd += (c - '0');
                else
                {
                    now = 2 * (c - '0');
                    even += (now % 10 + now / 10);
                }
                index++;
            }
            if (all > -1 && (odd + even) % 10 == 0)
                answer[i] = 1;
        }

        return answer;
    }