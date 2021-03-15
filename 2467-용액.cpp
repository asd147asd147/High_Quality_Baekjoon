#include <bits/stdc++.h>
#define INF 2000000001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	vector<long long> arr;
	arr.resize(N);
	for(int i = 0; i < N; i++){
        cin >> arr[i];
	}
	int lower = 0, upper = N-1;
	long long ans = INF;
	pair<int,int> pos = {lower,upper};
    while(lower < upper){
        if(abs(arr[upper] + arr[lower]) < abs(ans)){
            ans = arr[upper] + arr[lower];
            pos = {lower, upper};
            if(ans == 0){
                cout << arr[lower] << " " << arr[upper];
                return 0;
            }
        }
        if(arr[upper] + arr[lower] > 0) upper--;
        else lower++;
    }
    cout << arr[pos.first] << " " << arr[pos.second];

	return 0;
}
