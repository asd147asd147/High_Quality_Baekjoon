#include <iostream>
#include <cmath>
using namespace std;

int paper[2187][2187];
int neg=0,zero=0,pos=0;

void solve(int k, int i, int j){
    int p = pow(3,k);
    int cnt[3] = {0,};
    for(int I = 0; I < p; I++){
        for(int J = 0; J < p; J++){
            cnt[paper[i+I][j+J]+1]++;
        }
    }
    if(cnt[0] == p*p) neg++;
    else if(cnt[1] == p*p) zero++;
    else if(cnt[2] == p*p) pos++;
    else{
        for(int I = 0; I < p; I+=pow(3,k-1)){
            for(int J = 0; J < p; J+=pow(3,k-1)){
                solve(k-1,i+I,j+J);
            }
        }
    }
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> paper[i][j];
        }
    }
    int k=0;
    while(N>0){
        if(N%3 == 0) k++;
        N/=3;
    }
    solve(k,0,0);
    cout << neg << "\n" << zero << "\n" << pos;
	return 0;
}
