#include <vector>
#include <iostream>
using namespace std;

//time complexity: O(n^n)
class Solution{
public:
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        int n = A.size();
        vector< vector<int> > backpack;
        backpack.resize(n+1);
        for (int i = 0; i < n+1; i++) {
            backpack[i].resize(m+1);
            fill(backpack[i].begin(), backpack[i].end(), 0);
        }
        //遍历n个物品的大小
        for(int i = 0;i < n;++i){
            for(int j = 0;j <= m;++j){
                backpack[i+1][j] = backpack[i][j];
                if(j >= A[i]){
                    backpack[i+1][j] = max(backpack[i+1][j],backpack[i][j-A[i]]+V[i]);
                }
            }
        }
        return backpack[n][m];
    }
};


int main(){
    int n[] = {77,22,29,50,99} ;
    int n1[] = {92,22,87,46,90};
    vector<int> a(n, n+5) ;
    vector<int> b(n1, n1+5) ;
    Solution s;
    cout << s.backPackII(100,a,b);
}