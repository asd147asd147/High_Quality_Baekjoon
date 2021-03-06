#include <bits/stdc++.h>
#define INF 6000000
using namespace std;

long long p[501][501];

void solve(){
    int N,M,W;
    cin >> N >> M >> W;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            p[i][j] = INF;
        }
        p[i][i] = 0;
    }

    long long S,E,T;
    for(int i = 0; i < M; i++){
        cin >> S >> E >> T;
        p[S-1][E-1] = p[E-1][S-1] = min(p[E-1][S-1],T);
    }
    for(int i = 0; i < W; i++){
        cin >> S >> E >> T;
        p[S-1][E-1] = min(p[S-1][E-1],-T);
    }

    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                p[i][j] = min(p[i][j], p[i][k]+p[k][j]);
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(p[i][i] < 0){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }

	return 0;
}
