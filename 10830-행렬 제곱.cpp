#include <bits/stdc++.h>

using namespace std;

int N;
long long B;
typedef vector<vector<int>> matrix;

matrix operator * (const matrix &a, const matrix &b) {
    matrix res(N, vector<int>(N));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            for (int k = 0; k < a.size(); k++) {
                res[i][j] += a[i][k] * b[k][j] % 1000;
            }
            res[i][j] %= 1000;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> B;
    matrix m(N,vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> m[i][j];
        }
    }
    matrix res(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        res[i][i] = 1;
    }
    while(B > 0){
        if(B%2){
            res = res * m;
        }
        B /= 2;
        m = m * m;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

	return 0;
}
