#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
    int R,G,B;

    int cost[N][3];
    int dp[N][3];

	for(int i = 0; i < N; i++){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	dp[0][0] = dp[0][1] = dp[0][2] = cost[0][0];

	dp[1][0] = min(dp[0][1], dp[0][2]) + 1000000;
	dp[1][1] = min(dp[0][0], dp[0][2]) + cost[1][1];
	dp[1][2] = min(dp[0][0], dp[0][1]) + cost[1][2];
	for(int i = 2; i < N-1; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
	}
	dp[N-1][1] = min(dp[N-2][0], dp[N-2][2]) + cost[N-1][1];
	dp[N-1][2] = min(dp[N-2][0], dp[N-2][1]) + cost[N-1][2];
	int ans = min(dp[N-1][1], dp[N-1][2]);

	dp[0][0] = dp[0][1] = dp[0][2] = cost[0][1];

	dp[1][0] = min(dp[0][1], dp[0][2]) + cost[1][0];
	dp[1][1] = min(dp[0][0], dp[0][2]) + 1000000;
	dp[1][2] = min(dp[0][0], dp[0][1]) + cost[1][2];
	for(int i = 2; i < N-1; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
	}
	dp[N-1][0] = min(dp[N-2][1], dp[N-2][2]) + cost[N-1][0];
	dp[N-1][2] = min(dp[N-2][0], dp[N-2][1]) + cost[N-1][2];
	ans = min({ans, dp[N-1][0], dp[N-1][2]});

	dp[0][0] = dp[0][1] = dp[0][2] = cost[0][2];

	dp[1][0] = min(dp[0][1], dp[0][2]) + cost[1][0];
	dp[1][1] = min(dp[0][0], dp[0][2]) + cost[1][1];
	dp[1][2] = min(dp[0][0], dp[0][1]) + 1000000;
	for(int i = 2; i < N-1; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
	}
	dp[N-1][0] = min(dp[N-2][1], dp[N-2][2]) + cost[N-1][0];
	dp[N-1][1] = min(dp[N-2][0], dp[N-2][2]) + cost[N-1][1];
	ans = min({ans, dp[N-1][0], dp[N-1][1]});
    cout << ans;
	return 0;
}
