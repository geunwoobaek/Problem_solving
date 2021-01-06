#include <bits/stdc++.h>
using namespace std;
#define buildings vector<vector<int>>
#define building vector<int>
const int X = 0, Y = 1;
const int What = 2, How = 3;
const int None = -1, Col = 0, Row = 1, Both = 2;
const int Build = 1, Destroy = 0;
vector<vector<int>> Map(101, vector<int>(101, -1));
/*
기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.
구조물은 교차점 좌표를 기준으로 보는 오른쪽, 기둥은 위쪽 방향으로 설치 또는 삭제합니다.
*/
//[x,y,a,b] :x,y좌표 a=0 기둥 1보 b=0 삭제 1설치
//return x,y, 기둥Or보
//return 방식 x좌표 기준오름차순 x좌표같을경우 y좌표기준으로
bool compare(building a, building b);
void process(building &answer, building &event);
//빌드
bool LeftUnderRow(building &event); //기둥의 왼쪽밑에 보가 있는지
bool UnderCol(building &event);//기둥의 밑에 기둥이있는지
bool RightUnderRow(building &event);//기둥의 오른쪽밑에 보가 있는지

bool LeftRow(building &event);//보의 왼쪽에 보가있는지
bool RightRow(building &event);//보의 오른쪽에 보가있는지
bool LeftUnderCol(building &event);//보의 왼쪽에 기둥이 있는지
bool RightUnderCol(building &event);//보의 오른쪽에 기둥이 있는지

//삭제
bool UpLeftRow(building &event);//기둥의 왼쪽위에 받치고있는 보가있는지
bool UpRightRow(building &event);//기둥의 오른쪽위에 받치고있는 보가있는지
bool UpCOl(building &event); //기둥위에 바치고있는 기둥이있는지
bool UpNotExit(building &event); //기둥위에 아무것도 없는지

bool LeftRowUnder(building &event);//왼쪽보밑에 바치는 기둥이있는지
bool RightRowUnder(building &event);//오른쪽보밑에 바치는 기둥있는지
bool RowsNotExit(building &event);//보의 양옆에 아무것도없는지
bool ColsNowExit(building &event);//보위에 받치고있는 기둥 없는지
void RemoveBuilding(buildings &answer,building &event); //빌딩삭제
buildings solution(int n, buildings build_frame)
{
    buildings answer;
    for (auto &event : build_frame)
    {
        process(answer, event);
    }
    sort(answer.begin(), answer.end(), compare);
    return answer;
}

void process(buildings &answer, building &event)
{
    if (event[How] == Build)
    {
        if (event[What] == Col)
        {
            if (LeftUnderRow(event) || RightUnderRow(event) || UnderCol(event) || event[Y] == 0) //설치할수 있을경우
            {
                answer.push_back({event[X], event[Y], Col});
                Map[event[X]][event[Y]] = Map[event[X]][event[Y]] == Row ? Both : Col;
            }
        }
        else if (event[What] == Row)
        {
            if ((LeftRow(event) && RightRow(event)) || LeftUnderCol(event) || RightUnderCol(event))
            {
                answer.push_back({event[X], event[Y], Row});
                Map[event[X]][event[Y]] = Map[event[X]][event[Y]] == Col ? Both : Row;
            }
        }
    }
    else //destroy
    {
        if (event[What] == Col)
        {
            bool checkUnder = (UnderCol(event) || RightUnderRow(event) || LeftUnderRow(event) || event[Y] == 0);
            bool checkUp = (UpLeftRow(event) && UpRightRow(event)) || UpNotExit(event);
            if (checkUnder && checkUp)
            {
                RemoveBuilding(answer, event);
                Map[event[X]][event[Y]] = Map[event[X]][event[Y]] == Both ? Row : None;
            }
        }
        else if (event[What] == Row)
        {
            if ((LeftRowUnder(event) && RightRowUnder(event))||(RowsNotExit(event)&&ColsNowExit(event)))
            {
                RemoveBuilding(answer, event);
                Map[event[X]][event[Y]] = Map[event[X]][event[Y]] == Both ? Col : None;
            }
        }
    }
}
bool compare(building a, building b)
{
    if (a[x] != b[x])
        return a[x] < b[x];
    else if (a[y] != b[y])
        return a[y] < b[y];
    else
        return a[What] < b[What];
}
bool LeftUnderRow(building &event) { return Map[event[X] - 1][event[Y - 1]] >= 1; };
bool RightUnderRow(building &event) { return Map[event[X]][event[Y - 1]] >= 1; };
bool UnderCol(building &event) { return Map[event[X]][event[Y - 1]] == Both || Map[event[X]][event[Y - 1]] == Col; };
bool LeftRow(building &event){
    return Map[event[X]-1][event[Y]]>=1;
}
bool RightRow(building &event){
    return Map[event[X]+1][event[Y]]>=1;
}
bool LeftUnderCol(building &event){
    return Map[event[X]][event[Y]-1]==Col|| Map[event[X]][event[Y-1]]==Both;
}
bool RightUnderCol(building &event){
    return Map[event[X]+1][event[Y]-1]==Col|| Map[event[X+1]][event[Y-1]]==Both;
}
bool UpLeftRow(building &event){
    return Map[event[X]][event[Y]+1]>=1;
}
bool UpRightRow(building &event){
    return Map[event[X]][event[Y]]>=1;
}
bool UpNotExit(building &event){
   return Map[event[X]][event[Y]]==None;
}
bool LeftRowUnder(building &event){
    return Map[event[X]][event[Y]]==None;
}
bool RightRowUnder(building &event){
    return event
}
bool RowUnder(building &event){
    return event
}
bool RowsNotExit(building &event){
    return event
}
bool ColsNowExit(building &event){

}
void RemoveBuilding(buildings &answer,building &event){
    return event
}
