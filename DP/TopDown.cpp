#include <iostream>

using namespace std;

#define MIN_VALUE -200000000

int map[100001], n, cache[100001];

int sum(int idx)
{
  int& ret = cache[idx];

  if (ret != MIN_VALUE) 
  return ret;

  ret = max(map[idx], map[idx] + sum(idx + 1));

  return ret;
}

int main() 
{
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> map[i];
    cache[i] =  MIN_VALUE;
  }

  sum(0);

  int max = MIN_VALUE;

  for (int i = 0; i < n; i++)
   if (max < cache[i]) max = cache[i];

  cout << max;
}