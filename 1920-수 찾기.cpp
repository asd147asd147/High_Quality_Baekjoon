#include <bits/stdc++.h>

using namespace std;

vector<int> check;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,M;
    cin >> N;
    for(int i = 0; i < N; i++){
        int t;
        cin >> t;
        check.push_back(t);
    }

    sort(check.begin(),check.end());
    cin >> M;
    for(int i = 0; i < M; i++){
        int t;
        cin >> t;
        if(binary_search(check.begin(),check.end(),t)) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
	return 0;
}
