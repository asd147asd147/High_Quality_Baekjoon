#include <bits/stdc++.h>

using namespace std;

char room[101][101];
int N,h,w;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int cnt;
int test = 1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> N;
	for(int i = 0; i < N; i++){
        bool key[27] = {false,};
        cnt = 0;
        cin >> h >> w;
        for(int j = 0; j < h; j++){
            string s;
            cin >> s;
            for(int k = 0; k < w; k++){
                room[j][k] = s[k];
            }
        }
        string K;
        cin >> K;
        if(K != "0"){
            for(int k = 0; k < K.size(); k++){
                key[K[k] - 'a'] = true;
            }
        }
        queue<pair<int,int>> q;
        for(int t = 0; t < h; t++){
            if(room[t][0] != '*'){
                q.push({t,0});
            }
            if(room[t][w-1] != '*'){
                q.push({t,w-1});
            }
        }
        for(int t = 1; t < w-1; t++){
            if(room[0][t] != '*'){
                q.push({0,t});
            }
            if(room[h-1][t] != '*'){
                q.push({h-1,t});
            }
        }
        int check = 0;
        while(!q.empty() && check < 200){
            auto p = q.front();
            q.pop();
            check++;
            if(room[p.first][p.second] == '*'){
                continue;
            }
            else if(room[p.first][p.second] == '$'){
                cnt++;
                room[p.first][p.second] = '.';
            }
            else if('A' <= room[p.first][p.second] && room[p.first][p.second] <= 'Z'){
                if(key[room[p.first][p.second] - 'A']){
                    room[p.first][p.second] = '.';
                }
                else{
                    q.push(p);
                    continue;
                }
            }
            else if('a' <= room[p.first][p.second] && room[p.first][p.second] <= 'z'){
                key[room[p.first][p.second] - 'a'] = true;
                room[p.first][p.second] = '.';
            }

            for(int k = 0; k < 4; k++){
                if(p.first + dy[k] < 0 || p.first + dy[k] > h-1 || p.second + dx[k] < 0 || p.second + dx[k] > w-1) continue;
                q.push({p.first + dy[k], p.second + dx[k]});
                room[p.first][p.second] = '*';
            }
            check = 0;
//            for(int j = 0; j < h; j++){
//                for(int k = 0; k < w; k++){
//                    cout << room[j][k];
//                }
//                cout << endl;
//            }
//            cout << endl;
        }
        cout << cnt << "\n";
	}

	return 0;
}
