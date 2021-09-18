#include <bits/stdc++.h>

using namespace std;

int dp[15000] = {0,};
vector<int> price;
vector<tuple<int,int,int>> mines;

int M,N;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> M >> N;
    price.resize(M+1);
    for(int i = 1; i <= M; i++){
        cin >> price[i];
    }
    for(int i = 0; i < N; i++){
        int s,e,t;
        cin >> s >> e >> t;
        mines.push_back({e, s, (e-s)*price[t]});
    }
    long long ans = 0;
    sort(mines.begin(), mines.end());

    int idx = 1;
    for(auto m : mines){
        while(idx < get<0>(m)){
            dp[idx] = max(dp[idx-1], dp[idx]);
            idx++;
        }
        dp[get<0>(m)] = max(dp[get<0>(m)], dp[get<1>(m)] + get<2>(m));
        ans = max((long long)dp[get<0>(m)], ans);
    }
    cout << ans;

	return 0;
}
