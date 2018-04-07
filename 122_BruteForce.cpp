#include <vector>
#include <iostream>
using namespace std;

//time complexity: O(n^n)
class Solution{
public:
    int maxProfit(vector<int>& prices){
        return calculate(prices, 0);
    }
    int calculate(vector<int> prices,int s){
        if (s >= prices.size())
            return 0;
        int max = 0;
        for(int start = s; start < prices.size(); start++){
            int maxprofit = 0;
            for(int i = start+1; i<prices.size(); i++){
                 if(prices[start] < prices[i]){
                     int profit = calculate(prices, i+1) + prices[i] - prices[start];
                     if(profit > maxprofit){
                         maxprofit = profit;
                     }   
                 }
            }
            if (maxprofit > max){
                max = maxprofit;
            }
        }
       return max;
    }
};


int main(){
    int n[] = {1, 2, 3, 4, 5} ;
    vector<int> a(n, n+5) ;
    Solution s;
    cout << s.maxProfit(a);
}