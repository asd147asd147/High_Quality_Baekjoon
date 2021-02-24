#include <bits/stdc++.h>

using namespace std;

vector<unsigned long long> a = {1,1,1,2,2,3,4,5,7,9};
void solve(){
    int N;
    cin >> N;
    if(a.size() < N){
        for(int i = a.size()-1; i < N; i++){
            a.push_back(a[i]+a[i-4]);
        }
    }
    cout << a[N-1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
	return 0;
}
