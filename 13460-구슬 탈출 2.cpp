#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<char>> vvc;
typedef pair<int,int> pii;

int N,M,ans=100;
pair<int,int> O;
void up(vvc,int,pii,pii);
void down(vvc,int,pii,pii);
void left(vvc,int,pii,pii);
void right(vvc,int,pii,pii);
void (*fp[4])(vvc, int, pii, pii) = {up, down, left, right};
set<pair<pii,pii>> visited;

bool check_pre(pii& R, pii& B, int c){
    if(c==0){
        return R.second < B.second;
    }
    else{
        return R.first < B.first;
    }
}

void up(vvc vec, int idx, pii R, pii B){
    if(idx == 10)
        return;
    pii pos[2] = {B,R};
    int sel = check_pre(R,B,1);
    int cnt = 0;
    int tmp = 200;
    while(cnt != 2){
        for(int i = pos[sel].first-1; i > 0; i--){
            if(vec[i][pos[sel].second] == 'O' && sel == 1){
                tmp = idx+1;
                vec[i+1][pos[sel].second] = '.';
                break;
            }
            else if(vec[i][pos[sel].second] == 'O' && sel == 0){
                return;
            }
            else if(vec[i][pos[sel].second] != '.'){
                break;
            }
            else{
                vec[i][pos[sel].second] = vec[i+1][pos[sel].second];
                vec[i+1][pos[sel].second] = '.';
                pos[sel].first = i;
            }
        }
        sel = !sel;
        cnt++;
    }
    if(tmp != 200){
        ans = min(ans,tmp);
        return;
    }
    if(visited.find({pos[0],pos[1]})!=visited.end()){
        return;
    }
    for(int i = 0; i < 4; i++){
        fp[i](vec, idx+1, pos[1], pos[0]);
    }
}
void down(vvc vec, int idx, pii R, pii B){
    if(idx == 10)
        return;
    pii pos[2] = {B,R};
    int sel = !check_pre(R,B,1);
    int cnt = 0;
    int tmp = 200;
    while(cnt != 2){
        for(int i = pos[sel].first+1; i < N-1; i++){
            if(vec[i][pos[sel].second] == 'O' && sel == 1){
                tmp = idx+1;
                vec[i-1][pos[sel].second] = '.';
                break;
            }
            else if(vec[i][pos[sel].second] == 'O' && sel == 0){
                return;
            }
            else if(vec[i][pos[sel].second] != '.'){
                break;
            }
            else{
                vec[i][pos[sel].second] = vec[i-1][pos[sel].second];
                vec[i-1][pos[sel].second] = '.';
                pos[sel].first = i;
            }
        }
        sel = !sel;
        cnt++;
    }
    if(tmp != 200){
        ans = min(ans,tmp);
        return;
    }
    if(visited.find({pos[0],pos[1]})!=visited.end()){
        return;
    }
    for(int i = 0; i < 4; i++){
        fp[i](vec, idx+1, pos[1], pos[0]);
    }
}
void left(vvc vec, int idx, pii R, pii B){
    if(idx == 10)
        return;
    pii pos[2] = {B,R};
    int sel = check_pre(R,B,0);
    int cnt = 0;
    int tmp = 200;
    while(cnt != 2){
        for(int i = pos[sel].second-1; i > 0; i--){
            if(vec[pos[sel].first][i] == 'O' && sel == 1){
                tmp = idx+1;
                vec[pos[sel].first][i+1] = '.';
                break;
            }
            else if(vec[pos[sel].first][i] == 'O' && sel == 0){
                return;
            }
            else if(vec[pos[sel].first][i] != '.'){
                break;
            }
            else{
                vec[pos[sel].first][i] = vec[pos[sel].first][i+1];
                vec[pos[sel].first][i+1] = '.';
                pos[sel].second = i;
            }
        }
        sel = !sel;
        cnt++;
    }
    if(tmp != 200){
        ans = min(ans,tmp);

        return;
    }
    if(visited.find({pos[0],pos[1]})!=visited.end()){
        return;
    }
    for(int i = 0; i < 4; i++){
        fp[i](vec, idx+1, pos[1], pos[0]);
    }
}
void right(vvc vec, int idx, pii R, pii B){
    if(idx == 10)
        return;
    pii pos[2] = {B,R};
    int sel = !check_pre(R,B,0);
    int cnt = 0;
    int tmp = 200;
    while(cnt != 2){
        for(int i = pos[sel].second+1; i < M-1; i++){
            if(vec[pos[sel].first][i] == 'O' && sel == 1){
                tmp = idx+1;
                vec[pos[sel].first][i-1] = '.';
                break;
            }
            else if(vec[pos[sel].first][i] == 'O' && sel == 0){
                return;
            }
            else if(vec[pos[sel].first][i] != '.'){
                break;
            }
            else{
                vec[pos[sel].first][i] = vec[pos[sel].first][i-1];
                vec[pos[sel].first][i-1] = '.';
                pos[sel].second = i;
            }
        }
        sel = !sel;
        cnt++;
    }
    if(tmp != 200){
        ans = min(ans,tmp);
        return;
    }
    if(visited.find({pos[0],pos[1]})!=visited.end()){
        return;
    }
    for(int i = 0; i < 4; i++){
        fp[i](vec, idx+1, pos[1], pos[0]);
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
    pair<int,int> R,B;
    vvc vec(11,vector<char>(11));
	for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        for(int j = 0; j < M; j++){
            vec[i][j] = s[j];
            if(vec[i][j] == 'R'){
                R = {i,j};
            }
            else if(vec[i][j] == 'B'){
                B = {i,j};
            }
            else if(vec[i][j] == 'O'){
                O = {i,j};
            }
        }
	}
	visited.insert({B,R});
    for(int i = 0; i < 4; i++){
        fp[i](vec, 0, R, B);
    }
    if(ans == 100) cout << -1;
    else cout << ans;

	return 0;
}
