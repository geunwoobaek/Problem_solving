#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(i, s, e) for (int i = s; i <= e; i++)
#define Max_ 90000000000000000 //max값
int arr[123456][3];           //mon_atk,mon_hp,potion;
struct Soldier
{
    ll MaxHp, CurHp, ATK;
} soldier;
int N, init_atk; //방의갯수
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> init_atk;
    F(i, 1, N)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    ll left = 1, right = Max_;
    while (left < right)
    {
        ll mid = (left + right) >> 1;
        soldier.CurHp = soldier.MaxHp = mid;
        soldier.ATK = init_atk;
        bool isLife = true;
        F(i, 1, N)
        {   if(mid==25)
            cout<<"";
            if (arr[i][0] == 1)
            {
                ll mon_atk = arr[i][1], mon_hp = arr[i][2];
                ll turn = mon_hp / soldier.ATK;
                if (turn > 0 && (mon_hp % soldier.ATK) == 0)  turn--;
                soldier.CurHp -= turn * mon_atk;
                if (soldier.CurHp <= 0)
                {
                    left = mid + 1;
                    isLife = false;
                    break;
                }
            }
            else
            {
                ll hp_potion = arr[i][2], atk_potion = arr[i][1];
                soldier.CurHp = min(soldier.CurHp + hp_potion, soldier.MaxHp);
                soldier.ATK += atk_potion;
            }
        }
        if (isLife)
            right = mid;
    }
    cout << left;
    return 0;
}