#include <bits/stdc++.h>

using namespace std;

int N,K;
long long cost = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> N >> K;
    vector<pair<long long,long long>> jewelry;
    vector<long long> backpack;
    for(int i = 0; i < N; i++){
        long long a,b;
        cin >> a >> b;
        jewelry.push_back({b,a});
    }
    for(int i = 0; i < K; i++){
        long long a;
        cin >> a;
        backpack.push_back(a);
    }

    sort(jewelry.begin(), jewelry.end());
    sort(backpack.begin(), backpack.end());

    for(auto i = backpack.rbegin(); i != backpack.rend(); i++){
        if(jewelry.empty()) break;
        if(jewelry.back().second <= *i){
            cost += jewelry.back().first;
        }
        else{
            i--;
        }
        jewelry.pop_back();
    }
    cout << cost;

	return 0;
}
