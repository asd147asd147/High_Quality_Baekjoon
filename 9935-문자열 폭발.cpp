#include <bits/stdc++.h>

using namespace std;

string target,pattern;
char result[10000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> target >> pattern;
    int idx = 0;
    for(int i = 0; i < target.size(); i++){
        result[idx++] = target[i];
        if(result[idx-1] == pattern[pattern.size()-1]){
            if(idx - pattern.size() < 0) continue;

            bool check = true;
            for(int j = 1; j < pattern.size(); j++){
                if(result[idx-1-j] != pattern[pattern.size()-1-j]){
                    check = false;
                    break;
                }
            }
            if(check) idx -= pattern.size();
        }
    }
    if(!idx) cout << "FRULA";
    else{
        for(int i = 0; i < idx; i++){
            cout << result[i];
        }
    }


	return 0;
}
