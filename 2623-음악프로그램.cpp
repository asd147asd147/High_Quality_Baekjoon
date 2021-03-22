#include <bits/stdc++.h>

using namespace std;

int N,M;
int pre[1001] = {0,};
vector<set<int>> vec(1001);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int num;
        cin >> num;
        int t1, t2 = 0;
        for(int j = 0; j < num; j++){
            cin >> t1;
            if(t2){
                if(vec[t2].find(t1) == vec[t2].end()){
                    pre[t1]++;
                    vec[t2].insert(t1);
                }
            }
            t2 = t1;
        }
    }

    queue<int> q;
    for(int i = 1; i <= N; i++){
        if(!pre[i]) q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        auto p = q.front();
        ans.push_back(p);
        q.pop();
        for(auto s : vec[p]){
            pre[s]--;
            if(!pre[s]){
                q.push(s);
            }
        }
    }
    if(ans.size() != N) cout << 0;
    else{
        for(auto a : ans)
            cout << a << "\n";
    }
	return 0;
}
