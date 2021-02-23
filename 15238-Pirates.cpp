#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    int alpha[26] = {0,};
    for(int i = 0; i < n; i++){
        char temp;
        cin >> temp;
        alpha[temp - 'a'] += 1;
    }

    int max = *max_element(alpha,alpha+26);
    for(int i = 0; i < 26; i++){
        if(max == alpha[i]){
            cout << (char)('a'+i) << " " << max;
            return 0;
        }
    }

	return 0;
}
