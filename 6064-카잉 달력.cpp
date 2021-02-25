#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    while(b!=0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b){
    return a*b / gcd(a,b);
}

void solve(){
    int M,N,x,y,X;
    cin >> M >> N >> x >> y;
    X = x;
    int limit = lcm(M,N);
    for(int i = x; i <= limit; i += M){
        int temp = (i%N == 0) ? N : i%N;
        if(temp == y){
            cout << i <<"\n";
            return;
        }
    }
    cout << -1 << "\n";
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
