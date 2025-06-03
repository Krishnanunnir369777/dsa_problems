#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to return the minimum cost of connecting the ropes.
int minCost(vector<int>& arr) {  //O(n^2*log(n)) Time
    int totalCost = 0;
    while (arr.size() > 1) {
        sort(arr.begin(), arr.end());
        int first = arr[0];
        int second = arr[1];
        arr.erase(arr.begin());
        arr.erase(arr.begin());
        int cost = first + second;
        totalCost += cost;
        arr.push_back(cost);
    }
    return totalCost;
}

int main() {
    vector<int> ropes = {4, 3, 2, 6};
    cout << minCost(ropes) << endl;
    return 0;
}






// C++ program for connecting n rope
// with minimum cost using min-heap
#include <bits/stdc++.h>
using namespace std;

int minCost(vector<int> &arr) {

    // Create a priority queue
    // By default 'less' is used which is for decreasing
    // order and 'greater' is used for increasing order
    priority_queue<int, vector<int>,
               greater<int>> pq(arr.begin(), arr.end());

    // Initialize result
    int res = 0;

    // While size of priority queue is more than 1
    while (pq.size() > 1) {

        // Extract shortest two ropes from pq
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        // Connect the ropes: update result and
        // insert the new rope to pq
        res += first + second;
        pq.push(first + second);
    }

    return res;
}

int main() {

    vector<int> arr = {4, 3, 2, 6};
    cout << minCost(arr);
    return 0;
}