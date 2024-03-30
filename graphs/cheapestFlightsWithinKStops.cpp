/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
*/

#include <vector>

using std::vector;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, 100000);
        prices[src] = 0;
        int s = 0, d = 1, p = 2;
        for (int i = 0; i < k + 1; i++) {
            vector<int> tempPrices = prices;
            for (int j = 0; j < flights.size(); j++) {
                if (prices[flights[j][s]] == 100000){
                    continue;
                }
                if (prices[flights[j][s]] + flights[j][p] < tempPrices[flights[j][d]]) {
                    tempPrices[flights[j][d]] = prices[flights[j][s]] + flights[j][p];
                }
            }
            prices = tempPrices;
        }
        if (prices[dst] == 100000) {
            return -1;
        } else {
            return prices[dst];
        }
    }   
};