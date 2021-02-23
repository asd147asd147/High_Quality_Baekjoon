#include <bits/stdc++.h>

using namespace std;

int p(string N){
    for(int i = 0; i < N.size(); i++){
        if(N[i] != N[N.size()-1-i]) return 0;
    }
    return 1;
}

int main(){
    string N;
    cin >> N;
    while(N!="0"){
        if(p(N)) cout << "yes\n";
        else cout << "no\n";
        cin >> N;
    }
	return 0;
}
