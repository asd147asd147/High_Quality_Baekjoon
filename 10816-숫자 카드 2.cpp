#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N,M;
    cin >> N;
    vector<int>num(20000002);
    for(int i = 0; i < N; i++ ){
        int t;
        cin >> t;
        num[t+10000000]++;
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        int t;
        cin >> t;
        cout << num[t+10000000] << " ";
    }
	return 0;
}
