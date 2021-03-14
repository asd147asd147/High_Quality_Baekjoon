#include <bits/stdc++.h>
#define INF 2000

using namespace std;

int n,m,r;
int item[101] = {0,};
int graph[101][101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++){
        cin >> item[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            graph[i][j] = INF;
        }
        graph[i][i] = 0;
    }

    int a,b,c;
    for(int i = 0; i < r; i++){
        cin >> a >> b >> c;
        graph[a][b] = graph[b][a] = c;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(graph[i][j] <= m) cnt+=item[j];
        }
        ans = max(ans,cnt);
    }
    cout << ans;

	return 0;
}
