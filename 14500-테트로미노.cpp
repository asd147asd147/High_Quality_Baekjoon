#include <bits/stdc++.h>

using namespace std;

int board[508][508];

int dx1[4] = {0,1,2,3}, dy1[4] = {0,0,0,0};//bar-x
int dx2[4] = {0,0,0,0}, dy2[4] = {0,1,2,3};//bar-y
int dx3[4] = {0,1,0,1}, dy3[4] = {0,0,1,1};//square
int dx4[4] = {0,0,0,1}, dy4[4] = {0,1,2,2};//L-1
int dx5[4] = {0,1,2,2}, dy5[4] = {0,0,0,-1};//L-2
int dx6[4] = {0,1,1,1}, dy6[4] = {0,0,1,2};//L-3
int dx7[4] = {0,1,2,0}, dy7[4] = {0,0,0,1};//L-4
int dx8[4] = {0,1,1,1}, dy8[4] = {0,0,-1,-2};//L_reverse-1
int dx9[4] = {0,1,2,2}, dy9[4] = {0,0,0,1};//L_reverse-1
int dx10[4] = {0,1,0,0}, dy10[4] = {0,0,1,2};//L_reverse-1
int dx11[4] = {0,0,1,2}, dy11[4] = {0,1,1,1};//L_reverse-1
int dx12[4] = {0,1,2,1}, dy12[4] = {0,0,0,-1};//で-1
int dx13[4] = {0,1,1,1}, dy13[4] = {0,-1,0,1};//で-2
int dx14[4] = {0,1,2,1}, dy14[4] = {0,0,0,1};//で-3
int dx15[4] = {0,0,0,1}, dy15[4] = {-1,0,1,0};//で-4
int dx16[4] = {0,0,1,1}, dy16[4] = {0,1,1,2};
int dx17[4] = {0,0,1,1}, dy17[4] = {0,1,0,-1};
int dx18[4] = {0,1,1,2}, dy18[4] = {0,0,-1,-1};
int dx19[4] = {0,1,1,2}, dy19[4] = {0,0,1,1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N+6; i++){
        for(int j = 0; j < M+6; j++){
            board[i][j] = 0;
        }
    }

    for(int i = 3; i < N+3; i++){
        for(int j = 3; j < M+3; j++){
            cin >> board[i][j];
        }
    }

    int* x_pos[20] = {dx1,dx2,dx3,dx4,dx5,dx6,dx7,dx8,dx9,dx10,dx11,dx12,dx13,dx14,dx15,dx16,dx17,dx18,dx19};
    int* y_pos[20] = {dy1,dy2,dy3,dy4,dy5,dy6,dy7,dy8,dy9,dy10,dy11,dy12,dy13,dy14,dy15,dy16,dy17,dy18,dy19};

    int ans = 0;
    for(int i = 3; i < N+3; i++){
        for(int j = 3; j < M+3; j++){
            for(int k = 0; k < 19; k++){
                int sum = 0;
                for(int l = 0; l < 4; l++){
                    int y = i + x_pos[k][l];
                    int x = j + y_pos[k][l];
                    sum += board[y][x];
                }
                ans = max(ans, sum);
            }
        }
    }
    cout << ans << "\n";
	return 0;
}
