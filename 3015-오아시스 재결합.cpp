#include <bits/stdc++.h>

using namespace std;

int N;
stack<pair<long long, int>> s;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    long long ans = 0;
    for(int i = 0; i < N; i++){
        int h, cnt=1;
        cin >> h;
        while(!s.empty()){
            if(s.top().first < h){
                ans += s.top().second;
                cnt = 1;
                s.pop();
            }
            else if(s.top().first == h){
                ans += s.top().second;
                cnt = s.top().second + 1;
                s.pop();
            }
            else{
                ans++;
                break;
            }
        }
        s.push({h,cnt});
    }
    cout << ans;

    return 0;
}

