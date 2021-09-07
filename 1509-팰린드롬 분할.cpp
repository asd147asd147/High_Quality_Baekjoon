#include <bits/stdc++.h>

using namespace std;

int N;
bool dp[2501][2501];
int dp2[2501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    N = s.size();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dp[i][j] = 0;
        }
        dp[i][i] = 1;
    }
    for(int i = 0; i < N-1; i++){
        if(s[i] == s[i+1]){
            dp[i][i+1] = 1;
        }
    }
    for(int len = 3; len <= N; len++){
        for(int start = 0; start + len - 1 <= N; start++){
            int end = start + len - 1;
            if(s[start] == s[end] && dp[start+1][end-1]){
                dp[start][end] = 1;
            }
        }
    }

    for(int end = 0; end < N; end++){
        dp2[end] = 3000;
        for(int start = 0; start < N; start++){
            if(dp[start][end]){
                dp2[end] = min(dp2[end], start-1 >= 0 ? dp2[start-1] + 1 : 1);
            }
        }
    }
    cout << dp2[N-1];

    return 0;
}

