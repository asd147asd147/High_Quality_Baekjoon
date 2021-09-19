#include <bits/stdc++.h>

using namespace std;

int N;
int num[10] = {0,};
int power = 1;

void cnt(int n) {
    while(n) {
        num[n%10]+=power;
        n /= 10;
    }
}

void func1() {
    int start = 1;
    while(start <= N) {
        while(0 != start % 10 && start <= N) {
            cnt(start);
            start++;
        }
        if(N < start)return;
        while(9 != N % 10 && start <= N) {
            cnt(N);
            N--;
        }
        start /= 10;
        N /= 10;
        for (int i = 0; i < 10; i++) num[i] += (N - start + 1) * power;
        power *= 10;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    func1();
    for(auto n : num) {
        cout << n << " ";
    }


    return 0;
}
