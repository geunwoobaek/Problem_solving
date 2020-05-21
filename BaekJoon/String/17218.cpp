#include<iostream>
#include<string>
using namespace std;
int D[41][41];

int main(){
	string A,B; cin>>A>>B; 
	
	for(int i=1; i<=A.size(); ++i){
		for(int j=1; j<=B.size(); ++j){
			if(A[i-1]==B[j-1]) D[i][j] = D[i-1][j-1]+1;
			else D[i][j] = max(D[i-1][j], D[i][j-1]); 	
		}
	}
	
	string pw = "";
	int v = 0; 
	int i=A.size(),j=B.size();
	while(D[i][j]){
		if(D[i][j] == D[i][j-1]) j--;
		else if(D[i][j] == D[i-1][j]) i--;
		else if(D[i][j]-1 == D[i-1][j-1]){
			pw=A[i-1]+pw;	
			i--,j--; 
		}
	}
	
	cout<<pw;
	return 0;
}