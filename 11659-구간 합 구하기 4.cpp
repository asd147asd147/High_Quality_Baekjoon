#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> vec(N+1,0);
    for(int i = 1; i <= N; i++){
        cin >> vec[i];
        vec[i] += vec[i-1];
    }

    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        cout << vec[b] - vec[a-1] << "\n";
    }

	return 0;
}
