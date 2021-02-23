#include <iostream>

using namespace std;

void solve(int N){
    int p,q;
    p = q = N/2;
    int toggle = 0;

    do{
        toggle = 0;
        for(int i = 2; i*i <= p; i++){
            if(p%i == 0){
                --p,++q;
                toggle = 1;
                continue;
            }
        }
        for(int i = 2; i*i <= q; i++){
            if(q%i == 0){
                --p,++q;
                toggle = 1;
                continue;
            }
        }
    }while(toggle != 0);
    cout << p << " " << q << "\n";
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        solve(N);
    }

	return 0;
}
