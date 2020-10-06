#include <iostream>

using namespace std;
int current[100]; // current[x] : x 번 원판이 현재 있는 막대의 번호
int n, goal;
int answer=0; //갯수
void hanoi(int number, int start, int to) {  // number 라는 원판이 start 에서 to 로 가고 싶은 상황
   if (start == to) { // 이미 목표를 달성함
      return;
   }
   int via = 6 - start - to;
   // 1 ~ number-1 번 원판을 전부 via 로 옮기자
   for (int i = number - 1; i >= 1; i--) {
      hanoi(i, current[i], via);
   }
    answer++; //갯수
   //cout << number << " 번 원판이 " << start << " 막대에서 " << to << " 막대로 간다." << '\n';
   current[number] = to;

   // 1 ~ number-1 번 원판이 지금 전부 via 에 있을텐데, 이것들을 to 로 옮겨줘야한다.
   for (int i = number - 1; i >= 1; i--) {
      hanoi(i, current[i], to);
   }
}
int main() {
   cin >> n >> goal;
   for (int pole = 1; pole <= 3; pole++) { //input과정
      int cnt;
      cin >> cnt;
      for (int i = 1; i <= cnt; i++) {
         int x; cin >> x;
         current[x] = pole;
      }
   }
   for (int i = n; i >= 1; i--) { //전체를 해당지점에 몰아넣음
      hanoi(i, current[i], goal);  
   }
   cout<<answer;
   return 0;
}