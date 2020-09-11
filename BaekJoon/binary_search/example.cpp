#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
#include<vector>
using namespace std;
int main() {
    map<string, int> mapOfWordCount;
    map<int, vector<int>> mapOfWordCount2;
    // Insert Element in map
      map<int, vector<int>>::it=mapOfWordCount2.begin();
    mapOfWordCount.insert(pair<string, int>("first", 1));
    mapOfWordCount.insert(pair<string, int>("second", 2));
    mapOfWordCount.insert(pair<string, int>("third", 3));
    mapOfWordCount.insert(pair<string, int>("third", 4));
    mapOfWordCount.insert(pair<string, int>("third", 5));
    // Create a map iterator and point to beginning of map
    map<string, int>::iterator it = mapOfWordCount.begin();
    // Iterate over the map using Iterator till end.
    while (it != mapOfWordCount.end())
    {
        // Accessing KEY from element pointed by it.
        string word = it->first;
        // Accessing VALUE from element pointed by it.
        int count = it->second;
        cout << word << " :: " << count << endl;
        // Increment the Iterator to point to next entry
        it++;
    }
    return 0;
}