#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
   string makeLargestSpecial(string s) {
      string ret = "";
      vector<string> v;
      int i = 0;
      for (int j = 0, cnt = 0; j < s.size(); j++) {
         if (s[j] == '1') {
            cnt++;
         }
         else
         cnt--;
         if (cnt == 0) {
            v.push_back("1" + makeLargestSpecial(s.substr(i + 1,
            j - i - 1)) + "0");
            i = j + 1;
         }
      }
      sort(v.rbegin(), v.rend());
      for (int i = 0; i < v.size(); i++)
      ret += v[i];
      return ret;
   }
};