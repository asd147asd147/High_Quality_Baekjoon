#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> vvi;

int N, ans = 0;
void up(vvi vec, int m);
void down(vvi vec, int m);
void left(vvi vec, int m);
void right(vvi vec, int m);
void (*moving[4])(vvi,int) = {up,down,left,right};

void up(vvi vec, int m){
    if(m == 5) return;
    for(int i = 0; i < N; i++){
        int b = 0;
        for(int j = 1; j < N; j++){
            if(vec[j][i] == 0) continue;
            if(vec[j][i] == vec[b][i]){
                vec[b][i] *= 2;
                vec[j][i] = 0;
                ans = max(ans,vec[b][i]);
                b+=1;
            }
            else if(vec[b][i] == 0){
                vec[b][i] = vec[j][i];
                vec[j][i] = 0;
            }
            else{
                b += 1;
                vec[b][i] = vec[j][i];
                if(b!=j) vec[j][i] = 0;
            }
            ans = max(ans,vec[b][i]);
        }
    }

    for(int i = 0; i < 4; i++)
        moving[i](vec,m+1);

}

void down(vvi vec, int m){
    if(m == 5) return;
    for(int i = 0; i < N; i++){
        int b = N-1;
        for(int j = 1; j < N; j++){
            if(vec[N-1-j][i] == 0) continue;
            if(vec[N-1-j][i] == vec[b][i]){
                vec[b][i] *= 2;
                vec[N-1-j][i] = 0;
                ans = max(ans,vec[b][i]);
                b-=1;
            }
            else if(vec[b][i] == 0){
                vec[b][i] = vec[N-1-j][i];
                vec[N-1-j][i] = 0;
            }
            else{
                b -= 1;
                vec[b][i] = vec[N-1-j][i];
                if(b!=N-1-j) vec[N-1-j][i] = 0;
            }
            ans = max(ans,vec[b][i]);
        }
    }

    for(int i = 0; i < 4; i++)
        moving[i](vec,m+1);

}

void left(vvi vec, int m){
    if(m == 5) return;
    for(int i = 0; i < N; i++){
        int b = 0;
        for(int j = 1; j < N; j++){
            if(vec[i][j] == 0) continue;
            if(vec[i][j] == vec[i][b]){
                vec[i][b] *= 2;
                vec[i][j] = 0;
                ans = max(ans,vec[i][b]);
                b+=1;
            }
            else if(vec[i][b] == 0){
                vec[i][b] = vec[i][j];
                vec[i][j] = 0;
            }
            else{
                b+=1;
                vec[i][b] = vec[i][j];
                if(b!=j) vec[i][j] = 0;
            }
            ans = max(ans,vec[i][b]);
        }
    }

    for(int i = 0; i < 4; i++)
        moving[i](vec,m+1);
}
void right(vvi vec, int m){
    if(m == 5) return;
    for(int i = 0; i < N; i++){
        int b = N-1;
        for(int j = 1; j < N; j++){
            if(vec[i][N-1-j] == 0) continue;
            if(vec[i][N-1-j] == vec[i][b]){
                vec[i][b] *= 2;
                vec[i][N-1-j] = 0;
                ans = max(ans,vec[i][b]);
                b-=1;
            }
            else if(vec[i][b] == 0){
                vec[i][b] = vec[i][N-1-j];
                vec[i][N-1-j] = 0;
            }
            else{
                b -= 1;
                vec[i][b] = vec[i][N-1-j];
                if(b!=N-1-j) vec[i][N-1-j] = 0;
            }
            ans = max(ans,vec[i][b]);
        }
    }

    for(int i = 0; i < 4; i++)
        moving[i](vec,m+1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	vvi vec(N,vector<int>(N));
	for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            cin >> vec[i][j];
            ans = max(ans,vec[i][j]);
        }

    for(int i = 0; i < 4; i++)
        moving[i](vec,0);
    cout << ans;
	return 0;
}
