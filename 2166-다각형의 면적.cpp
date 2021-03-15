#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<long long,long long>> point;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        int x,y;
        cin >> x >> y;
        point.push_back({x,y});
    }

    long long ans = 0;
    for(int i = 1; i < N-1; i++){
        ans += (point[i].first-point[0].first)*(point[i+1].second-point[0].second) - (point[i+1].first-point[0].first)*(point[i].second-point[0].second);
    }
    if(ans%2 == 0) cout << abs(ans/2) << ".0";
    else cout << abs(ans/2) << ".5";
	return 0;
}
