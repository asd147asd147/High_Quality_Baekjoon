#include <bits/stdc++.h>

using namespace std;
int N, M;
set<int> s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        int t;
        cin >> t;
        s.insert(t);
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        int t;
        cin >> t;
        if(s.find(t) == s.end()){
            cout << "0 ";
        }
        else{
            cout << "1 ";
        }
    }
    return 0;
}

