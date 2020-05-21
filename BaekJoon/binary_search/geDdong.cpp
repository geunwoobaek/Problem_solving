#include <stdio.h>
#include <climits>
using namespace std;
int totaldown[500002] = {};
int totalup[500002] = {};
int total[500002] = {};
int down[500002] = {};
int up[500002] = {};
int main(void){
 
    int N, H;
    int upMax = 0;
    int downMax = 0;
    int min = INT_MAX;
    int count = 1;
    scanf("%d %d", &N, &H);
 
    for (int i = 0; i < N / 2; i++){
        int upS, downS;
        scanf("%d %d", &downS, &upS);
        up[upS]++;
        down[downS]++;
        if (upMax < upS)
            upMax = upS;
        if (downMax < downS)
            downMax = downS;
    }
    
    for (int i = downMax; i >= 1; i--)
        totaldown[i] = down[i] + totaldown[i + 1];
    for (int i = upMax; i >= 1; i--)
        totalup[i] = up[i] + totalup[i + 1];
 
    for (int i = 1; i <= H; i++){
 
        if (i == 1)
            total[i] = totaldown[1];
        else if (i == H)
            total[i] = totalup[1];
        else
            total[i] = totaldown[i] + totalup[H - i + 1];
 
        if (total[i] == min){
            count++;
        }
        else if (total[i]<min){
            count = 1;
            min = total[i];
        }
 
    }
 
    printf("%d %d\n", min, count);
 
    return 0;
}

