#include <bits/stdc++.h>

using namespace std;

int N,S, cnt = 0;
vector<int> vec;
map<int,int> mp1, mp2;

void leftMap(int idx, int sum){
    if(idx == N/2){
        mp1[sum]++;
        return;
    }
    leftMap(idx+1, sum);
    leftMap(idx+1, sum+vec[idx]);
}

void rightMap(int idx, int sum){
    if(idx == N){
        mp2[sum]++;
        return;
    }
    rightMap(idx+1, sum);
    rightMap(idx+1, sum+vec[idx]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> S;
    vec.resize(N);
	for(int i = 0; i < N; i++){
        cin >> vec[i];
	}

	leftMap(0,0);
	rightMap(N/2,0);

	auto frontIndex = mp1.begin();
	auto backIndex = mp2.rbegin();
	while(frontIndex != mp1.end() && backIndex != mp2.rend();)


	if(S == 0) cnt--;
	cout << cnt;

	return 0;
}
