#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    set<string> key;
    multimap<string,string> clothes;
    for(int i = 0; i < n; i++){
        string a,b;
        cin >> a >> b;
        key.insert(b);
        clothes.insert(pair<string,string>(b,a));
    }
    if(n==0){
        cout << 0 <<"\n";
        return;
    }
    int cnt = 1;
    for(auto i = key.begin(); i != key.end(); i++){
        cnt *= clothes.count(*i)+1;
    }
    cout << cnt-1 << "\n";
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
