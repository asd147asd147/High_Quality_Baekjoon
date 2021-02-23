#include <iostream>

using namespace std;

int main(){
    int M,N,ans=0,min=10001;
    cin >> M >> N;

    for(int i = N; i >= M; i--){
        int toggle = 0;
        if(i == 1) continue;
        for(int j = 2; j*j <= i; j++){
            if(i % j == 0){
                toggle = 1;
                break;
            }
        }
        if(toggle == 0) ans += i, min = i;
    }
    if(ans == 0) cout << -1;
    else cout << ans << "\n" << min;
	return 0;
}
