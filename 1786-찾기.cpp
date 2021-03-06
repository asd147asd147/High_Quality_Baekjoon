#include <bits/stdc++.h>

using namespace std;

string T, P;
vector<int> match;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    getline(cin, T);
    getline(cin, P);
    int pi[P.size()] = {0,},j=0;
    for(int i = 1; i < P.size(); i++){
        while(j > 0 && P[i] != P[j])
            j = pi[j-1];
        if(P[i] == P[j])
            pi[i] = ++j;
    }
    j = 0;
    for(int i = 0; i < T.size(); i++){
        while(j > 0 && T[i] != P[j])
            j = pi[j-1];
        if(T[i] == P[j]){
            if(j == P.size()-1){
                match.push_back(i-P.size()+2);
                j = pi[j];
            }
            else{
                j++;
            }
        }
    }
    cout << match.size() << "\n";
    for(auto m : match)
        cout << m << " ";


	return 0;
}
