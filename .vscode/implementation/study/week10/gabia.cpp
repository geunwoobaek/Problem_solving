#include <bits/stdc++.h>
using namespace std;

int solution(int n) //n보다 작거나 같으면서 10의배수의 갯수
{       
   	if (n == 0) return 0;
		return (n / 5) + solution(n / 5);
}
int main(){
cout<<solution(100000);
return 0;
}