#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int num[2];
    int divisor[2][10001];
    for(int i = 0; i < 10001; i++){
        divisor[0][i] = divisor[1][i] = 0;
    }
    cin >> num[0] >> num[1];

    for(int i = 0; i < 2; i++){
        int t = num[i];
        int n = 2;
        while(t>1){
            if(t%n == 0) t/=n, divisor[i][n]++;
            else n++;
        }
    }
    int LCM = 1;
    for(int i = 0; i < 10001; i++){
        if(divisor[0][i] || divisor[1][i]) LCM *= pow(i,max(divisor[0][i], divisor[1][i]));
    }
    cout << num[0]*num[1]/LCM << "\n" << LCM;

	return 0;
}
