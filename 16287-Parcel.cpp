#include <bits/stdc++.h>

using namespace std;

int W, N;
vector<int> parcel;
bool weight[800000] = {0,};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> W >> N;
	parcel.resize(N);
	for(int i = 0; i < N; i++){
        cin >> parcel[i];
	}

	for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(parcel[i]+parcel[j] > W) continue;
            if(weight[W-parcel[i]-parcel[j]]){
                cout << "YES";
                return 0;
            }
        }
        for(int j = 0; j < i; j++){
            weight[parcel[i]+parcel[j]] = true;
        }
	}
	cout << "NO";

	return 0;
}
