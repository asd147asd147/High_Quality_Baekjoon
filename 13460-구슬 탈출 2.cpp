#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<char>> vvc;
typedef pair<int,int> pii;

int N,M,ans=0;
vvc vec(11,vector<char>(11));
pair<int,int> O;
void up(vvc,int,pii,pii);
void down(vvc,int,pii,pii);
void left(vvc,int,pii,pii);
void right(vvc,int,pii,pii);
void (*fp[4])(vvc, int, pii, pii) = {up, down, left, right};

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
    for(int i = pos[sel].first-1; i > 0; i--){
        if(vec[i][pos[sel].second] == 'O' && sel == 1){
            ans = max(ans,idx+1);
            return;
        }
        else if(vec[i][pos[sel].second] != '.'){
            sel = sel;//TODO
            break;
        }
        else{
            pos[sel].first = i;
        }
    }
}
void down(vvc vec, int idx, pii R, pii B){
    if(idx == 10)
        return;
}
void left(vvc vec, int idx, pii R, pii B){
    if(idx == 10)
        return;
}
void right(vvc vec, int idx, pii R, pii B){
    if(idx == 10)
        return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
    pair<int,int> R,B;
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


	return 0;
}
