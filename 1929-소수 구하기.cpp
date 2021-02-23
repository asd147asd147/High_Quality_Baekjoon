#include <iostream>

using namespace std;

int main(){
    int M,N;
    cin >> M >> N;

    for(int i = M; i <= N; i++){
        int check = 0;
        for(int j = 2; j*j <= i; j++){
            if(i % j == 0){
                check = 1;
                break;
            }
        }
        if(i == 1) continue;
        if(check == 0) cout << i << "\n";
    }
	return 0;
}
