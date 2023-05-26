#include <iostream>

using namespace std;

int main(){
    string K;
    unsigned long long L;
    cin >> K >> L;

    for(unsigned long long i = 2; i < L; i++){
        int ans = 0, temp = 1;
        for(int j = K.length()-1; j >= 0; j--){
            ans = (ans + (K[j] - '0') * temp) % i;
            temp *= 10;
            temp %= i;
        }
        if(ans == 0){
            cout << "BAD " << i;
            return 0;
        }
    }
    cout << "GOOD";

	return 0;
}
