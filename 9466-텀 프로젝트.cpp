#include <bits/stdc++.h>

using namespace std;

int N,ans = 0;
int student[100001];
vector<int> uni;

void cycle(int init){
    uni = vector<int>();
    int cur = init;
    int next = student[cur];
    while(cur != student[cur] && next != 0){
        uni.push_back(cur);
        if(next == init){
            ans += uni.size();
            for(auto u : uni){
                student[u] = 0;
            }
            return;
        }
        cur = next;
        next = student[next];
    }
    if(!uni.size() && next != 0){
        ans++;
        student[init] = 0;
    }
    return;
}

void solve(){
    cin >> N;
    ans = 0;
    for(int i = 1; i <= N; i++)
        cin >> student[i];

    for(int i = 1; i <= N; i++){
        if(student[i]){
            cycle(i);
        }
    }
    cout << N - ans << "\n";
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
