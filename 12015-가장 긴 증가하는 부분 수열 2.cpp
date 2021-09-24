#include <bits/stdc++.h>

using namespace std;

vector<int> vec;
int N;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	vec.resize(N);
	for(int i=0; i < N; i++){
        cin >> vec[i];
	}

	vector<int> LIS;
	LIS.push_back(vec[0]);
	for(int i = 1; i < N; i++){
        if(LIS[0] > vec[i]) LIS[0] = vec[i];
        else if(LIS.back() < vec[i]) LIS.push_back(vec[i]);
        else{
            auto it = upper_bound(LIS.begin(), LIS.end(), vec[i]-1);
            *it = vec[i];
        }
	}

	cout << LIS.size();

	return 0;
}
