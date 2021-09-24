#include <bits/stdc++.h>
#define MOD 1000000007LL

using namespace std;

typedef vector<vector<long long>> Matrix;
Matrix M = {{0,1,1,0,0,0,0,0},
            {1,0,1,1,0,0,0,0},
            {1,1,0,1,0,1,0,0},
            {0,1,1,0,1,1,0,0},
            {0,0,0,1,0,1,1,0},
            {0,0,1,1,1,0,0,1},
            {0,0,0,0,1,0,0,1},
            {0,0,0,0,0,1,1,0}};
Matrix operator * (const Matrix &a, const Matrix &b){
    Matrix res(8, vector<long long>(8));
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            for(int k = 0; k < 8; k++){
                res[i][j] += a[i][k] * b[k][j] % MOD; 
            }
            res[i][j] = res[i][j] % MOD;
        }
    }
    return res;
}

int N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    Matrix res(8, vector<long long>(8, 0));
    for(int i = 0; i < 8; i++){
        res[i][i] = 1;
    }
    while(N > 0){
        if(N%2){
            res = res * M;
        }
        N /= 2;
        M = M * M;
    }
    cout << res[0][0];
    
    
    return 0;
}

