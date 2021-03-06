#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<pair<int,int>> item;
int dp[101][100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    item.push_back(make_pair(0,0));
    for(int i = 0; i < N; i++){
        int a,b;
        cin >> a >> b;
        item.push_back(make_pair(a,b));
    }
    sort(item.begin(),item.end());
    for(int i = 0; i <= N; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i <= K; i++){
        dp[0][i] = 0;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K; j++){
            if(item[i].first > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(item[i].second+dp[i-1][j-item[i].first], dp[i-1][j]);
            }
        }
    }

    cout << dp[N][K];

	return 0;
}
