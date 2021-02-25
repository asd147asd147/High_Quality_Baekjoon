#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    string s;
    cin >> N >> M >> s;
    int num = 0;
    int answer = 0;
    for(int i = 0; i < M-2; i++){
        if(s[i]=='I' && s[i+1]=='O' && s[i+2]=='I'){
            num++;
            if(num == N){
                answer++;
                num--;
            }
            i++;
        }
        else num = 0;
    }
    cout << answer;

	return 0;
}
