#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int backPackII(int m, vector<int> &A, vector<int> &V) {
       // write your code here
       //一维数组优化
       int n = A.size();
       vector<int> f;
       f.resize(m+1);
       fill(f.begin(),f.end(),0);
       for (int i = 0; i < n; i++) {
           for (int j = m; j >= V[i]; j--) {
               f[j] = max(f[j], f[j - A[i]] + V[i]);
           }
       }
       return f[m];
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