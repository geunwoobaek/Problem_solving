#include <bits/stdc++.h>

using namespace std;
//2016-09-15 01:00:04.002 2.0s
int solution(vector<string> lines) {
    int answer = 0;
    
    vector<int> times(lines.size());
    priority_queue<int> pq;
    
    // ms로 변환
    for(int i = 0; i < lines.size(); i++) {
        int hour = stod(lines[i].substr(11, 2));
        int minute = stod(lines[i].substr(14, 2));
        double second = stod(lines[i].substr(17, 6));
        int secTime = hour * 3600000 + minute * 60000 + second * 1000;
        times[i] = secTime;
    }
    
    // 끝 데이터부터 처음 데이터 방향으로 탐색
    int cnt = 0;
    int max = 0;
    for(int i = times.size() - 1; i >= 0; i--) {
        cnt++;

        // 전송 시점을 priority queue에 넣어준다. (priority queue를 쓴 이유는 빠른 탐색을 위해서)
        int temp = times[i] - (int)(stod(lines[i].substr(24, lines[i].size() - 25)) * 1000) + 1;
        pq.push(temp);
        
        // 거리가 1 넘어가는 건 다 꺼내기
        while(!pq.empty()) {
            if(times[i] + 1000 <= pq.top()) {
                pq.pop();
                cnt--;
            } else {
                break;
            }
        }
        if(cnt > max) max = cnt;
    }
    answer = max;
    return answer;
}