#include <bits/stdc++.h>

using namespace std;

int N;
vector<long long> vec;
vector<long long> LIS;
vector<long long> P;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	vec.resize(N);
	P.resize(N);
	for(int i = 0; i < N; i++){
        cin >> vec[i];
	}
	LIS.push_back(vec[0]);
	for(int i = 1; i < N; i++){
        auto pos = lower_bound(LIS.begin(), LIS.end(), vec[i]);
        if(pos == LIS.end()){
            LIS.push_back(vec[i]);
            pos = LIS.end()-1;
        }
        else{
            *pos = vec[i];
        }
        P[i] = distance(LIS.begin(), pos);
	}
	cout << LIS.size() << "\n";
    vector<long long> ans;
	long long cnt = LIS.size()-1;
    ans.resize(LIS.size());
	for(int i = N-1; i >= 0; i--){
        if(cnt == P[i]){
            ans[cnt--] = vec[i];
        }
	}

	for(auto a : ans)
        cout << a << " ";

	return 0;
}
