#include <iostream>
#include <cmath>

using namespace std;
int A,B;

int LCS(int a, int b){
    int d_a[45001] = {0,};
    int d_b[45001] = {0,};
    int i = 2;
    while(a>1){
        if(a%i == 0){
            d_a[i]++;
            a/=i;
        }
        else{
            i++;
        }
    }
    i = 2;
    while(b>1){
        if(b%i == 0){
            d_b[i]++;
            b/=i;
        }
        else{
            i++;
        }
    }

    int ans = 1;
    for(i = 2; i <= max(A,B); i++){
        ans *= pow(i,max(d_a[i],d_b[i]));
    }
    return ans;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> A >> B;
        cout << LCS(A,B) << endl;
    }

	return 0;
}
