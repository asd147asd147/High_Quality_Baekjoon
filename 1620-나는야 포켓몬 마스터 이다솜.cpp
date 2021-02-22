#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    map<string,int> dict1;
    map<int,string> dict2;

    for(int i = 0; i < N; i++){
        string t;
        cin >> t;
        dict1[t] = i+1;
        dict2[i+1] = t;
    }

    for(int i = 0; i < M; i++){
        string t;
        cin >> t;
        if('0'<=t[0] && t[0]<='9'){
            stringstream sstream(t);
            int num;
            sstream >> num;
            cout << dict2[num] << "\n";
        }
        else{
            cout << dict1[t] << "\n";
        }
    }

	return 0;
}
