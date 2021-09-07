#include <bits/stdc++.h>

using namespace std;

int R,C,M;
int aquarium[102][102];
typedef struct _shark{
    int r,c,s,d,z;
} Shark;
vector<Shark> sharks;
int ans = 0;

void calc_pos(Shark& shark){
    if(shark.d == 1 || shark.d == 2){
        int d = shark.d == 1 ? -1 : 1;
        int step = shark.s % (2*(R-2)+2);
        int next = shark.r + step*d;
        while(1 > next || next > R){
            if(next < 1){
                next = -1*next + 2;
                shark.d = 2;
            }
             else if(next > R){
                next = R-(next-R);
                shark.d = 1;
            }
        }
        shark.r = next;
    }
    else{
        int d = shark.d == 3 ? 1 : -1;
        int step = shark.s % (2*(C-2)+2);
        int next = shark.c + step*d;
        while(1 > next || next > C){
            if(next < 1){
                next = -1*next + 2;
                shark.d = 3;
            }
            else if(next > C){
                next = C-(next-C);
                shark.d = 4;
            }
        }
        shark.c = next;
    }
}

void aqua_reset(){
    for(int i = 0; i <= R; i++){
        for(int j = 0; j <= C; j++){
            aquarium[i][j] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C >> M;
    aqua_reset();
    sharks.resize(M+1);
    for(int i = 1; i <= M; i++){
        Shark temp;
        cin >> temp.r >> temp.c >> temp.s >> temp.d >> temp.z;
        aquarium[temp.r][temp.c] = i;
        sharks[i] = temp;
    }

    for(int time = 1; time <= C; time++){
//        cout << time << endl;
//        for(int i = 1; i <= R; i++){
//            for(int j = 1; j <= C; j++){
//                cout << aquarium[i][j];
//            }
//            cout << endl;
//        }
//        cout << endl;
        for(int row = 1; row <= R; row++){
            if(aquarium[row][time] != 0){
                ans += sharks[aquarium[row][time]].z;
                sharks[aquarium[row][time]].z = 0;
                break;
            }
        }
        for(int shark_n = 1; shark_n <= M; shark_n++){
            if(sharks[shark_n].z != 0){
                calc_pos(sharks[shark_n]);
            }
        }
        aqua_reset();
        for(int shark_n = 1; shark_n <= M; shark_n++){
            if(sharks[shark_n].z != 0){
                int pos = aquarium[sharks[shark_n].r][sharks[shark_n].c];
                if(pos != 0){
                    if(sharks[pos].z < sharks[shark_n].z){
                        aquarium[sharks[shark_n].r][sharks[shark_n].c] = shark_n;
                        sharks[pos].z = 0;
                    }
                    else{
                        sharks[shark_n].z = 0;
                    }
                }
                else{
                    aquarium[sharks[shark_n].r][sharks[shark_n].c] = shark_n;
                }
            }
        }
    }
    cout << ans;
    return 0;
}

