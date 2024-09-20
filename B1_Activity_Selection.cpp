// 1. Implement a problem of activity selection problem 
// with K persons.
// Statement: Given two arrays S[] and E[] of size N denoting starting 
// and closing time of the shops and an integer value K denoting the 
// number of people, the task is to find out the maximum number of 
// shops they can visit in total if they visit each shop optimally based 
// on the following conditions:
//  A shop can be visited by only one person
//  A person cannot visit another shop if its timing collide with it
// Input: S[] = {1, 8, 3, 2, 6}, E[] = {5, 10, 6, 5, 9}, K = 2
// Output: 4
// Input: S[] = {1, 2, 3}, E[] = {3, 4, 5}, K = 2
// Output: 3


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxShops(vector<int>& S, vector<int>& E, int K) {
    vector<pair<int, int>> shops;
    for (int i = 0; i < S.size(); i++) {
        shops.push_back({E[i], S[i]});
    }
  
    sort(shops.begin(), shops.end());
    
    vector<int> persons(K, 0);
    
    int count = 0;
    
    for (auto& shop : shops) {
        int start = shop.second;
        int end = shop.first;
        
        for (int i = 0; i < K; i++) {
            if (persons[i] <= start) {  
                persons[i] = end;  
                count++;
                break;  
            }
        }
    }
    
    return count;
}

int main() {
    vector<int> S1 = {1, 8, 3, 2, 6};
    vector<int> E1 = {5, 10, 6, 5, 9};
    int K1 = 2;
    cout << "Maximum number of shops visited: " << maxShops(S1, E1, K1) << endl;  // Output: 4

    vector<int> S2 = {1, 2, 3};
    vector<int> E2 = {3, 4, 5};
    int K2 = 2;
    cout << "Maximum number of shops visited: " << maxShops(S2, E2, K2) << endl;  // Output: 3

    return 0;
}