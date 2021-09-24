#include <bits/stdc++.h>

using namespace std;

int N,M;
long long box[1001][1001];
bool check[1001][1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> box[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        int idx = 0;
        for(int j = 0; j < M; j++){
            if(box[i][idx] <= box[i][j]){
                idx = j;
            }
        }
        check[i][idx] = 1;
    }
    for(int j = 0; j < M; j++){
        int idx = 0;
        for(int i = 0; i < N; i++){
            if(box[idx][j] <= box[i][j]){
                idx = i;
            }
        }
        check[idx][j] = 1;
    }
    long long ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!check[i][j]){
                ans += box[i][j];
            }
        }
    }
    cout << ans;


    return 0;
}

