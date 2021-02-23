#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> divisor;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        divisor.push_back(temp);
    }

    sort(divisor.begin(), divisor.end());

    cout << divisor[0]*divisor[divisor.size()-1];

	return 0;
}
