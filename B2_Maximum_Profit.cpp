// 2. Implement a problem of maximize Profit by trading
// stocks based on given rate per day.
// CO2
// Statement: Given an array arr[] of N positive integers
// which denotes the cost of selling and buying a stock on
// each of the N days. The task is to find the maximum
// profit that can be earned by buying a stock on or selling
// all previously bought stocks on a particular day.
// Input: arr[] = {2, 3, 5} Output: 5
// Input: arr[] = {8, 5, 1} Output: 0

#include <bits/stdc++.h>
using namespace std;
 
int maxProfit(int* prices, int n)
{
    int profit = 0, currentDay = n - 1;
 
    while (currentDay > 0) {
 
        int day = currentDay - 1;
 
        while (day >= 0
            && (prices[currentDay]
                > prices[day])) {
 
            profit += (prices[currentDay]
                    - prices[day]);
 
            day--;
        }
        currentDay = day;
    }

    return profit;
}
 
int main()
{
    int prices[] = { 2, 3, 5 };
 
    int N = sizeof(prices) / sizeof(prices[0]);

    cout << maxProfit(prices, N);
 
    return 0;
}