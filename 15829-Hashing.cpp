#include <bits/stdc++.h>

using namespace std;

int main(){
    int L;
    unsigned long long ans=0;
    string s;
    cin >> L >> s;
    unsigned long long p=1;
    for(int i = 0; i < L; i++){
        ans += p*((unsigned long long)(s[i]-'a'+1)) % 1234567891;
        p = p*31 % 1234567891;
        ans %= 1234567891;
    }
    cout << ans;
	return 0;
}
