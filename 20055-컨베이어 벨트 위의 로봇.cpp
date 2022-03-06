#include <bits/stdc++.h>

using namespace std;

int n, k;
int up;
vector<int> belt;
vector<bool> robot;
void init(){
    cin >> n >> k;
    belt.resize(2*n);
    robot.resize(n);
    for(int i = 0; i < 2*n; i++){
        cin >> belt[i];
    }
    up = 0;
}

void solve(){
    int step = 0;
    while(1){
        up = (up+2*n-1)%(2*n);
        for(int i = n-2; i >= 0; i--){
            robot[i+1] = robot[i];
        }
        robot[n-1] = false;
        robot[0] = false;
        for(int i = n-2; i >= 0; i--){
            int nextbelt = (up+i+1)%(2*n);
            if(robot[i] && !robot[i+1] && belt[nextbelt] != 0){
                robot[i+1] = robot[i];
                robot[i] = false;
                belt[nextbelt]--;
                if(belt[nextbelt] == 0) k--;
            }
        }
        robot[n-1] = false;
        if(!robot[0] && belt[up] != 0){
            belt[up]--;
            robot[0] = true;
            if(belt[up] == 0) k--;
        }

        step++;
        if(k <= 0){
            cout << step;
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();

    return 0;
}

