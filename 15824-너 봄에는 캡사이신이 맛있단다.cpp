#include <bits/stdc++.h>
#define MOD 1'000'000'007

using namespace std;

int N;
vector<int> vec;

long long pw(long long a, int b){
    long long ret = 1;
    while(b){
        if(b&1) ret = ret * a % MOD;
        b >>= 1;
        a = a*a%MOD;
    }
    return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	vec.resize(N);
	for(int i = 0; i < N; i++){
        cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	long long ans = 0;
	for(int i = 0; i < N; i++){
        long long low_cnt = pw(2, i);
        ans += (vec[i] % MOD) * low_cnt % MOD;
        long long high_cnt = pw(2, N-i-1);
        ans -= (vec[i] % MOD) * high_cnt % MOD;
        ans = ((ans % MOD)+MOD)%MOD;
	}
	cout << ans;

	return 0;
}
