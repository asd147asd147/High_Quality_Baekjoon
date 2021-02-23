#include <iostream>

using namespace std;

int main(){
    unsigned long long K,L;
    cin >> K >> L;

    for(unsigned long long i = 2; i < L; i++){
        if(K%i == 0){
            cout << "BAD " << i;
            return 0;
        }
    }
    cout << "GOOD";

	return 0;
}
