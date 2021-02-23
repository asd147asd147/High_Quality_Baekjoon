#include <iostream>
#include <string.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    int num[N], asc[N], des[N];

    for(int i = 0; i < N; i++){
        cin >> num[i];
        asc[i] = des[i] = 1;
    }

    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(num[i] < num[j]){
                asc[j] = max(asc[i]+1, asc[j]);
            }
        }
    }

    for(int i = N-1; i >= 0; i--){
        for(int j = i-1; j >= 0; j--){
            if(num[i] < num[j]){
                des[j] = max(des[i]+1, des[j]);
            }
        }
    }

    int answer = 1;
    for(int i = 0; i < N; i++){
        answer = max(asc[i] + des[i], answer);
    }
    cout << answer-1;
	return 0;
}
