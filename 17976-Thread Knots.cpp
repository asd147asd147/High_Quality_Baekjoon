#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<long long,long long>> vec;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	vec.resize(N);
	for(int i = 0; i < N; i++){
        cin >> vec[i].first >> vec[i].second;
        vec[i].second+= vec[i].first;
	}
	sort(vec.begin(), vec.end());

	long long low = 0, high = 2e10, mid;
    long long ans = 0;
	while(low <= high){
        mid = (low+high)/2LL;
        bool check = true;
        long long init = vec[0].first;
        for(int i = 1; i < N; i++){
            if(vec[i].second - init < mid){
                check = false;
                break;
            }
            init = max(vec[i].first, init+mid);
        }
        if(check){
            low = mid+1;
            ans = max(ans, mid);
        }
        else{
            high = mid-1;
        }
	}
    cout << ans;

	return 0;
}
