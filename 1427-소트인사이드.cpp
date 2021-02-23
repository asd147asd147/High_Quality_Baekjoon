#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string num;
    cin >> num;
    sort(num.begin(), num.end(), greater<char>());
    cout << num;

	return 0;
}
