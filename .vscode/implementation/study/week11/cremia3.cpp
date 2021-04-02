#include <bits/stdc++.h>
using namespace std;
 bool compare(string s1, string s2){
      return s1.size() < s2.size();
   }
   int longestChain(vector<string>& words) {
      unordered_map <string, int> cache;
      int n = words.size();
      sort(words.begin(), words.end(), compare);
      int result = 0;
      for(int i = 0; i < n; i++){
         int Max_value = 0;
         for(int j = 0; j < words[i].size(); j++){
            string word = words[i].substr(0, j) +
            words[i].substr(j + 1);
            Max_value = max(Max_value, cache[word] + 1);
         }
         cache[words[i]] = Max_value;
         result = max(result, cache[words[i]]);
      }
      return result;
   }

