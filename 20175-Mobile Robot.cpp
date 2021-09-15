#include <bits/stdc++.h>

using namespace std;

int N;
vector<long long> vec;

inline long double dist(long long d){
    long long M = -1e17, m = 1e17;
	long long init = vec[0];
	for(long long i = 0; i < N; i++){
        long long temp = init+i*d - vec[i];
        M = max(M, temp);
        m = min(m, temp);
	}
	long double ans = ((long double)M-(long double)m)/2.0;
	return ans = round(abs(ans)*10.0) / 10.0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long d;
	cin >> N >> d;
	vec.resize(N);
	for(int i = 0; i < N; i++){
        cin >> vec[i];
	}
	cout << fixed;
    cout.precision(1);
	cout << min(dist(d), dist(-d));

	return 0;
}
