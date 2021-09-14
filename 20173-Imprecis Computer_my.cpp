#include <bits/stdc++.h>

using namespace std;

int N;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int memo = 0;
	for(int i=0;i<N;++i){
        int temp;
        cin >> temp;
		if(abs(memo-temp)>1||(i==N-1&&memo!=temp)){
			cout << "NO";
			return 0;;
		}
        memo = memo!=temp ? 1 : 0;
	}
	cout << "YES";
    return 0;
}

