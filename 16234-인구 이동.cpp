#include <bits/stdc++.h>

using namespace std;

int N,L,R;
int nation[51][51];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void init(){
    cin >> N >> L >> R;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> nation[i][j];
        }
    }
}

bool mergeUnion(){
    int visited[51][51];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            visited[i][j] = 0;
        }
    }

    vector<set<pair<int,int>>> uniNation;
    uniNation.push_back(set<pair<int,int>>());
    int cnt = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){
                uniNation.push_back(set<pair<int,int>>());
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = cnt;
                while(!q.empty()){
                    auto p = q.front();
                    uniNation[cnt].insert({p.first, p.second});
                    q.pop();
                    for(int k = 0; k < 4; k++){
                        if(0 > p.first+dy[k] || p.first+dy[k] >= N || 0 > p.second+dx[k] || p.second+dx[k] >= N) continue;
                        int diff = abs(nation[p.first][p.second] - nation[p.first+dy[k]][p.second+dx[k]]);
                        if(L<= diff && diff <= R && !visited[p.first+dy[k]][p.second+dx[k]]){
                            q.push({p.first+dy[k], p.second+dx[k]});
                            visited[p.first+dy[k]][p.second+dx[k]] = cnt;
                        }
                    }
                }
                cnt++;
            }
        }
    }

    bool flag = false;
    for(int k = 1; k < cnt; k++){
        int allPopulation = 0;
        for(auto u : uniNation[k]){
            allPopulation += nation[u.first][u.second];
        }
        for(auto u : uniNation[k]){
            if(nation[u.first][u.second] != allPopulation / uniNation[k].size()){
                flag = true;
            }
            nation[u.first][u.second] = allPopulation / uniNation[k].size();
        }
    }
    return flag;
}

void solve(){
    bool flag = true;
    int day = 0;
    while(flag){
        day++;
        flag = mergeUnion();
    }
    cout << day - 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    init();
    solve();

    return 0;
}

