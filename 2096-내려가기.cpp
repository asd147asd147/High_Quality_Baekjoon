#include <bits/stdc++.h>

using namespace std;

pair<int,int> dp[3][3];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for(int i = 0; i < 3; i++){
        cin >> dp[0][i].first;
        dp[0][i].second = dp[0][i].first;
	}
    int t;
	for(int i = 1; i < N; i++){
        cin >> t;
        dp[i%3][0].first = max(dp[(i-1)%3][0].first,dp[(i-1)%3][1].first) + t;
        dp[i%3][0].second = min(dp[(i-1)%3][0].second,dp[(i-1)%3][1].second) + t;
        cin >> t;
        dp[i%3][1].first = max({dp[(i-1)%3][0].first,dp[(i-1)%3][1].first,dp[(i-1)%3][2].first}) + t;
        dp[i%3][1].second = min({dp[(i-1)%3][0].second,dp[(i-1)%3][1].second,dp[(i-1)%3][2].second}) + t;
        cin >> t;
        dp[i%3][2].first = max(dp[(i-1)%3][1].first,dp[(i-1)%3][2].first) + t;
        dp[i%3][2].second = min(dp[(i-1)%3][1].second,dp[(i-1)%3][2].second) + t;
	}
	cout << max({dp[(N-1)%3][0].first,dp[(N-1)%3][1].first,dp[(N-1)%3][2].first}) << " " << min({dp[(N-1)%3][0].second,dp[(N-1)%3][1].second,dp[(N-1)%3][2].second});
	return 0;
}
