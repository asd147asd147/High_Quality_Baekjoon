#include <iostream>

using namespace std;

int N,M;
int arr[8] = {0,};
bool check[8] = {false,};

void backTracking(int m){
    if(m == M){
        for(int i = 0; i < M; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = 1; i <= N; i++){
        if(check[i] == true) continue;
        arr[m] = i;
        check[i] = true;
        backTracking(m+1);
        check[i] = false;
    }
}

int main(){
    cin >> N >> M;

    backTracking(0);
	return 0;
}
