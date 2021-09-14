#include <bits/stdc++.h>

using namespace std;

bool dp[1000010][2][2];

int N;
vector<int> v;

void memo(int idx, int m1, int m2){
    if(dp[idx][m1][m2]) return;
    dp[idx][m1][m2] = true;
    if(idx > N) return;
    if(v[idx] == 0){
        if(m1 == m2){
            memo(idx+1, 0, 0);
            memo(idx+1, 1, 1);
        }
        else{
            if(m1 > m2){
                memo(idx+1, 1, 0);
            }
            else{
                memo(idx+1, 0, 1);
            }
        }
    }
    else if(v[idx] == 1){
        if(abs(m1 - m2) == 1){
            memo(idx+1, 0, 0);
            memo(idx+1, 1, 1);
        }
        else if(m1 == m2){
            memo(idx+1, 0, 1);
            memo(idx+1, 1, 0);
        }
    }
    else{
        if(m1 == m2) return;
        else if(m1 > m2){
            memo(idx+1, 0, 1);
        }
        else{
            memo(idx+1, 1, 0);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    cin >> N;
    v.resize(N+1);
    for(int i = 1; i <= N; i++){
        cin >> v[i];
        if(v[i] > 2){
            cout << "NO";
            return 0;
        }
    }

    if(v[1] > 1 || v[N] > 1){
        cout << "NO";
        return 0;
    }

    memset(dp, 0, sizeof(dp));
    if(v[1] == 0){
        memo(2, 0, 0);
        memo(2, 1, 1);
    }
    else if(v[1] == 1){
        memo(2, 0, 1);
        memo(2, 0, 1);
    }
    
    if(v[N] == 1 && (dp[N][1][0] || dp[N][0][1])){
        cout << "YES";
    }
    else if(v[N] == 0 && (dp[N][0][0] || dp[N][1][1])){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}

