#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	vector<int> vec(N+2,0);
	vector<vector<bool>> dp(N+2, vector<bool>(N+2,false));
	for(int i = 1; i <= N; i++)
        cin >> vec[i];
    for(int i = 1; i <= N; i++)
        dp[i][i] = true;
    for(int i = 1; i < N; i++)
        if(vec[i] == vec[i+1]) dp[i][i+1] = true;
    for(int i = 3; i <= N; i++){
        for(int j = 1; j <= N - i + 1; j++){
            int to = j+i-1;
            if(dp[j+1][to-1] && vec[j] == vec[to])
                dp[j][to] = true;
        }
    }

    int M;
    cin >> M;
    for(int i = 0; i < M; i++){
        int from,to;
        cin >> from >> to;
        cout << dp[from][to] << "\n";
    }

	return 0;
}
