#include <iostream>

using namespace std;

int GCD(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return GCD(b,a%b);
    }
}

int main(){
    int N;
    int gear[101] = {0,};
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> gear[i];
    }
    for(int i = 1; i < N; i++){
        int gcd = GCD(gear[0],gear[i]);
        cout << gear[0]/gcd << "/" << gear[i]/gcd << "\n";
    }

	return 0;
}
