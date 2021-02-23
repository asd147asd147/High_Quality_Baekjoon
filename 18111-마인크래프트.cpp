#include <bits/stdc++.h>

using namespace std;

int land[501][501];
int N,M,B,H=0;

int check_land(){
    int res = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            res += H-land[i][j];
        }
    }
    return res;
}

int main(){
    cin >> N >> M >> B;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> land[i][j];
            H = max(H,land[i][j]);
        }
    }
    unsigned int time = -1;

    while(1){
        if(res == 0) break;

    }


	return 0;
}
