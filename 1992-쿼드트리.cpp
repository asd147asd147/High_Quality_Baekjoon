#include <bits/stdc++.h>

using namespace std;

int N;
int info[64][64];

void quad(int n, int y, int x){
    if(n == 1) {
        cout << info[y][x];
        return;
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sum+=info[y+i][x+j];
        }
    }
    if(sum == 0 || sum == n*n){
        cout << !!sum;
        return;
    }
    else{
        cout << "(";
        quad(n/2,y,x);
        quad(n/2,y,x+n/2);
        quad(n/2,y+n/2,x);
        quad(n/2,y+n/2,x+n/2);
        cout << ")";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < N; j++){
            info[i][j] = s[j] - '0';
        }
    }
    quad(N,0,0);

	return 0;
}
