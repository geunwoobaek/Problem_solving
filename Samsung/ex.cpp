#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define Max 100000
//성적입력할때는 학번 이름 국 영 수 총점 평균 그리고 학생들 전체평균
int Score_Array[Max][7];
char name[Max][100];
int rank[Max];

//3 2 1 10 11
void sorting(int size)
{
    for (int i = 1; i <= size; i++)
    {
        int cur = i;
        string name=*name[i];
        for (int j = i + 1; j <= size; j++)
        {
            if (Score_Array[i][4] < Score_Array[j][4])
            {
                cur = j;
            }
        }
        *name[i] = *name[cur];
        *name[cur] = *temp;

        for (int k = 0; k < 6; k++)
        {
            int temp = Score_Array[cur][k];
            Score_Array[cur][k] = Score_Array[i][k];
            Score_Array[i][k] = temp;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int number = 0;
    int TotalScore = 0;
    cout << "성적 입력 및 처리 프로그램" << endl;
    while (1)
    {
        number++;
        cout << "---------성적----------" << endl;
        cout << "1.학생성적입력" << endl;
        cout << "Q.프로그램종료" << endl;
        char k;
        cin >> k;
        if (k == 113)
            break;
        else if (k != '1')
            continue;
        cout<<"학번:";
        cin >> Score_Array[number][0];
        cout << "이름:";
        cin >> name[number];
        cout << "국어:";
        cin >> Score_Array[number][1];
        cout << "영어:";
        cin >> Score_Array[number][2];
        cout << "수학:";
        cin >> Score_Array[number][3];
        Score_Array[number][4] = Score_Array[number][1] + Score_Array[number][2] + Score_Array[number][3];

        TotalScore += Score_Array[number][4] / 3;
        Score_Array[number][5] = Score_Array[number][4] / 3;
        sorting(number);
        cout<<"학번      이름      국어    영어    수학    총점    평균  석차\n";
        for (int i = 1; i <= number; i++)
        {
            cout << Score_Array[i][0] << " " << name[i];
            for (int j = 1; j <= 5; j++)
                cout << Score_Array[i][j] << " ";
            cout << i << endl;
        }
        cout << "전체평균: " << TotalScore / number << endl;
    }
    cout << "종료";
    return 0;
}