#include <bits/stdc++.h>
#define INF 10000000

using namespace std;

int city[101][101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N,M,c,src,des;
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            city[i][j] = INF;
        }
    }

    for(int i = 0; i < M; i++){
        cin >> src >> des >> c;
        city[src-1][des-1] = min(city[src-1][des-1],c);
    }

    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                city[i][j] = min(city[i][k]+city[k][j], city[i][j]);
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(city[i][j] == INF || i==j)
                cout << 0 << " ";
            else
                cout << city[i][j] << " ";
        }
        cout << "\n";
    }

	return 0;
}
