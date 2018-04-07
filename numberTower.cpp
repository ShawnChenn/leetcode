#include <algorithm>
#include <iostream>
using namespace std;
const int maxn =1000;
int f[maxn][maxn],dp[maxn][maxn];

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<= i; j++){
            cin >> f[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<= i; j++){
            cout << f[i][j];
        }
    }
}