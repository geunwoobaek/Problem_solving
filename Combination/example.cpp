#include <iostream>
#include <string>
using namespace std;

//성적입력할때는 학번 이름 국 영 수 총점 평균 그리고 학생들 전체평균
int number = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int number = 0;
    int TotalScore = 0;
    string totalmessage;
    cout << "성적 입력 및 처리 프로그램" << endl;
    while (1)
    {
        number++;
        cout << "---------성적----------" << endl;
        cout << "1.학생성적입력" << endl;
        cout << "Q.프로그램종료" << endl;
        char k;
        cin >> k;

        if (k == 'Q'||k=='q')
            break;
        else if (k !='1')
            continue;
        string message;
        int english, math, korean, total, hakbun;
        string name;
        printf("학번:");
        cin >> hakbun;
        printf("이름:");
        cin >> name;
        printf("국어:");
        cin >> korean;
        printf("영어:");
        cin >> english;
        printf("수학:");
        cin >> math;
        total = math + english + korean;
        TotalScore += total / 3;
        printf("학번      이름      국어    영어    수학    총점    평균\n");
        message = to_string(hakbun) + " " + name + "     " + to_string(korean) + "     " + to_string(english) + "     " + to_string(math) + "       " + to_string(total) + "     " + to_string(total / 3) + "\n";
        totalmessage += message;
        cout << totalmessage;
        cout << "전체평균: " << TotalScore / number << endl;
    }
    cout << "종료";
    return 0;
}