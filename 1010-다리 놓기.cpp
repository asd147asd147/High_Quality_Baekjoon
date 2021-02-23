#include <iostream>

using namespace std;

unsigned long long combi[31][31];

void init(){
    for(int i = 0; i < 31; i++)
        combi[i][0] = combi[i][i] = 1;

    for(int i = 2; i < 31; i++){
        for(int j = 1; j <= i; j++){
            combi[i][j] = combi[i-1][j-1] + combi[i-1][j];
        }
    }
}

int main(){
    int T;
    cin >> T;

    init();

    while(T--){
        int N,M;
        cin >> N >> M;
        cout << combi[M][N] << "\n";
    }

	return 0;
}
