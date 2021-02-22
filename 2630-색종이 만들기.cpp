#include <bits/stdc++.h>

using namespace std;

int N;
int cPaper[129][129];
int color[2] = {0,};

void recursion(int n, int I, int J){
    if(n==1){
        color[cPaper[I][J]]++;
        return;
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sum += cPaper[I+i][J+j];
        }
    }
    if(sum == 0 || sum == n*n){
        color[!!sum]++;
        return;
    }
    else{
        recursion(n/2,I,J);
        recursion(n/2,I+n/2,J+n/2);
        recursion(n/2,I+n/2,J);
        recursion(n/2,I,J+n/2);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> cPaper[i][j];
        }
    }
    recursion(N,0,0);
    for(auto s : color)
        cout << s << "\n";
	return 0;
}
