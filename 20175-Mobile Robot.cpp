#include <bits/stdc++.h>

using namespace std;

int N;
long long d;
vector<long long> vec;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> d;
	vec.resize(N);
	for(int i = 0; i < N; i++){
        cin >> vec[i];
	}

	long long M = -30'000'000'000'000'010LL, m = 30'000'000'000'000'010LL;

	long long init = vec[0];

	for(long long i = 0; i < N; i++){
        long long temp = init+i*d - vec[i];
        M = max(M, temp);
        m = min(m, temp);
	}

	double ans1 = ((double)M-(double)m)/2.0;
	ans1 = round(abs(ans1)*10.0) / 10.0;

    M = -30'000'000'000'000'010LL, m = 30'000'000'000'000'010LL;

	init = vec[0];

	for(long long i = 0; i < N; i++){
        long long temp = init-i*d - vec[i];
        M = max(M, temp);
        m = min(m, temp);
	}
    double ans2 = ((double)M-(double)m)/2.0;
	ans2 = round(abs(ans2)*10.0) / 10.0;

	cout << fixed;
    cout.precision(1);
    cout << ans1 << " " << ans2 <<endl;
	cout << min(ans1, ans2);

	return 0;
}
