#include <bits/stdc++.h>

using namespace std;

int N;
unsigned long long ans = 0;

void stair(string s, int check){
    //cout << s << " " << check << endl;
    if((int)s.size() == N){
        if(!check){
            ans++;
            ans %= 1000000000;
        }

        return;
    }
    int b = s.back() - '0';
    if(b == 0){
        stair(s+"1", check & ~(1 << 1));
    }
    else if(b == 9){
        stair(s+"8", check & ~(1 << 8));
    }
    else{
        string post1 = "";
        post1 += '0'+b-1;
        string post2 = "";
        post2 += '0'+b+1;
        stair(s+post1, check & ~(1 << (b-1)));
        stair(s+post2, check & ~(1 << (b+1))); 
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 1; i <= 9; i++){
        string s = "";
        s += '0' + i;
        int check = 1023;
        check &= ~(1 << i);
        stair(s, check);
    }
    cout << ans;

    return 0;
}

