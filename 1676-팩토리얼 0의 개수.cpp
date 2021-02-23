#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int t = 0, f = 0;
    for(int i = 1; i <= N; i++){
        int temp = i;
        while(temp % 2 == 0){
            t++;
            temp /= 2;
        }
        while(temp % 5 == 0){
            f++;
            temp /= 5;
        }
    }
    cout << min(t,f);

	return 0;
}
