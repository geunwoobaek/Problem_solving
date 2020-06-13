#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int W, N;
    while (scanf("%d\n%d", &W, &N) == 2) {
        vector<int> blocks(N);
        W *= 10000000;
        for(int i=0; i<N; i++) {
            scanf(" %d", &blocks[i]);
        }
        sort(blocks.begin(), blocks.end());
        
        int l = 0, r = N-1;
        while (l < r) {
            int sum = blocks[l] + blocks[r];
            if(sum == W) {
                break;
            }
            else if(sum < W) {
                l++;
            }
            else {
                r--;
            }
        }
        if(l >= r) {
            printf("danger\n");
        }
        else {
            printf("yes %d %d\n", blocks[l], blocks[r]);
        }
    }
}
 
