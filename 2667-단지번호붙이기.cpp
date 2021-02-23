#include <bits/stdc++.h>

using namespace std;

int N;
int apt[27][27];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 0; i < N+2; i++){
        for(int j = 0; j < N+2; j++){
            apt[i][j] = 0;
        }
    }

    for(int i = 1; i < N+1; i++){
        string s;
        cin >> s;
        for(int j = 1; j < N+1; j++){
            apt[i][j] = s[j-1] - '0';
        }
    }

    vector<int> ans = {0};
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < N+1; j++){
            if(apt[i][j]){
                int cnt = 0;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                apt[i][j] = 0;
                ans[0]++;
                while(!q.empty()){
                    pair<int,int> pos = q.front();
                    q.pop();
                    cnt++;
                    for(int k = 0; k < 4; k++){
                        if(apt[pos.first+dy[k]][pos.second+dx[k]]){
                            q.push(make_pair(pos.first+dy[k],pos.second+dx[k]));
                            apt[pos.first+dy[k]][pos.second+dx[k]] = 0;
                        }
                    }
                }
                ans.push_back(cnt);
            }
        }
    }

    sort(ans.begin()+1,ans.end());
    for(auto a : ans)
        cout << a << "\n";
	return 0;
}
