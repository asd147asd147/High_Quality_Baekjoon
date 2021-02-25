#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,M;
    map<string,string> pass;
    string address, word;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> address >> word;
        pass[address] = word;
    }
    for(int i = 0; i < M; i++){
        cin >> address;
        cout << pass[address] << "\n";
    }
	return 0;
}
