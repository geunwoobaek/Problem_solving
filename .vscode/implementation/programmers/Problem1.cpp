#include <bits/stdc++.h>
using namespace std;
struct character {
    int y=5, x=5;
};
bool Isvisit[11][11][11][11];
int dxy[2][4] = { {1,0,0,-1},{0,-1,1,0} }; //y,x
//ULURRDLLU
int solution(string dirs) {
    int answer = 0;
    character c;
    for (auto& command : dirs) {
        character next;
        int d=3;
        if (command == 'U') {
            d = 0;
        }
        else if (command == 'L') {
            d = 1;
        }
        else if (command == 'R') {
            d = 2;
        }
        next.y=c.y + dxy[0][d];
        next.x=c.x + dxy[1][d];
        if ( next.y <= 10 && next.y >= 0 && next.x >= 0 && next.x <= 10) {
            if (!Isvisit[c.y][c.x][next.y][next.x]) {
                Isvisit[c.y][c.x][next.y][next.x] =true;
                Isvisit[next.y][next.x][c.y][c.x] =true;
                answer++;
                
            }
            c=next;
        }
  
    }
    return answer;
}