/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation:
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
*/

#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    struct ComparePair {
        bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) const {
            return p1.first > p2.first;
        }
    };

    int euclideanDistToOrigin(int x, int y) {
        return ((x * x) + (y * y));
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePair> pq;
        for (int i = 0; i < points.size(); i++) {
            pq.push(make_pair(euclideanDistToOrigin(points[i][0], points[i][1]), i));
        }
        while (k) {
            result.push_back(points[pq.top().second]);
            pq.pop();
            k--;
        }
        return result;
    }
};