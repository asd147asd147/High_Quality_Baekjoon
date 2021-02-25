#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    int f[101][101];
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            f[i][j] = N+1;

    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        f[a-1][b-1] = f[b-1][a-1] = 1;
    }

    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(f[i][k] && f[k][j]){
                    f[i][j] = min(f[i][k]+f[k][j],f[i][j]);
                }
            }
        }
    }

    int m = N*N;
    int ans = 1;
    for(int i = 0; i < N; i++){
        int sum = 0;
        for(int j = 0; j < N; j++){
            if(i==j) continue;
            sum += f[i][j];
        }
        if(m > sum){
            m = sum;
            ans = i+1;
        }
    }
    cout << ans;
	return 0;
}
