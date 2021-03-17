#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	int ans = 0;
	array<int,10001> work;
	for(int i = 1; i <= N; i++){
        int t, pre, cost = 0;
        cin >> t >> pre;
        for(int j = 0; j < pre; j++){
            int p;
            cin >> p;
            cost = max(cost,work[p]);
        }
        work[i] = t + cost;
        ans = max(ans, work[i]);
	}
	cout << ans;
	return 0;
}
