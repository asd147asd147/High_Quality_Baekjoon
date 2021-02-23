#include <iostream>

using namespace std;

int main(){
    int N, i=0,six=666;
    cin >> N;
    while(1){
        int t = six;
        int flag = 0;
        while(t > 0){
            if(t%10 != 0 && t%10 % 6 == 0){
                flag++;
            }
            else{
                if(flag <= 2) flag = 0;
            }
            t/=10;
        }
        if(flag >= 3){
            i++;
        }
        if(i == N) break;
        six++;
    }
    cout << six;

	return 0;
}
