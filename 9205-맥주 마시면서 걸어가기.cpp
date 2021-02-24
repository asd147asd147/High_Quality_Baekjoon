#include <bits/stdc++.h>

using namespace std;

typedef struct __pos{
    int x = 0, y = 0;
} pos;

void solve(){
    int n;
    pos build[103];
    bool check[103][103];
    cin >> n;

    for(int i = 0; i < n+2; i++){
        for(int j = 0; j < n+2; j++){
            check[i][j] = 0;
        }
    }
    check[0][0] = 1;
    for(int i = 0; i < n+2; i++){
        cin >> build[i].x >> build[i].y;
    }

    for(int i = 0; i < n+2; i++){
        for(int j = i; j < n+2; j++){
            if((abs(build[i].x - build[j].x) + abs(build[i].y - build[j].y)) <= 1000) check[i][j] = check[j][i] = 1;
        }
    }

    for(int k = 0; k < n+2; k++){
        for(int i = 0; i < n+2; i++){
            for(int j = 0; j < n+2; j++){
                if(check[i][k] && check[k][j]) check[i][j] = 1;
            }
        }
    }
    if(check[0][n+1]) cout << "happy\n";
    else cout << "sad\n";
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
