#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    set<int> homeplus;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        if(s=="all"){
            homeplus = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
        }
        else if(s== "empty"){
            homeplus.clear();
        }
        else{
            int num;
            cin >> num;
            if(s=="add"){
                homeplus.insert(num);
            }
            else if(s=="remove"){
                homeplus.erase(num);
            }
            else if(s=="check"){
                int ans = find(homeplus.begin(),homeplus.end(),num) == homeplus.end() ? 0 : 1;
                cout << ans << "\n";
            }
            else if(s=="toggle"){
                if(find(homeplus.begin(),homeplus.end(),num) != homeplus.end()){
                    homeplus.erase(num);
                }
                else{
                    homeplus.insert(num);
                }
            }
        }

    }
	return 0;
}
