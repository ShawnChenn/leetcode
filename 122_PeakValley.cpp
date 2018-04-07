#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices){
        //初始化
        int i = 0;
        int valley = prices[0];
        int peak = prices[0];
        int maxprofit = 0;
        while (i< prices.size() - 1){
            while(i < prices.size() - 1 && prices[i] >= prices[i+1])
                 i++;
            valley = prices[i];
            while(i < prices.size() - 1 && prices[i] <= prices[i+1])
                 i++;
            peak = prices[i];
            maxprofit += peak - valley;
        }
        return maxprofit;
        }
};

int main(){
    int n[] = {1, 2, 3, 4, 5} ;
    vector<int> a(n, n+5) ;
    Solution s;
    cout << s.maxProfit(a);
}