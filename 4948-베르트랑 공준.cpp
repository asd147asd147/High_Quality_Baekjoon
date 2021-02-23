#include <iostream>

using namespace std;

void solve(int n){
    int cnt = n;
    for(int i = n+1; i <= 2*n; i++){
        for(int j = 2; j*j <= i; j++){
            if(i % j == 0){
                cnt--;
                break;
            }
        }
    }
    cout << cnt << "\n";
}

int main(){
    int N;
    cin >> N;
    while(N!=0){
        if(N==1){
            cout << 1 <<"\n";
        }
        else{
            solve(N);
        }
        cin >> N;
    }

	return 0;
}
