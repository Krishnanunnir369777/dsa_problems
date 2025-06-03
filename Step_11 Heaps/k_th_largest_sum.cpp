
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate Kth largest element
// in contiguous subarray sum
int kthLargest(vector<int> &arr, int k) {                           ///O(n2 * log n) Time
    int n = arr.size();

    // to store all subarray sums
    vector<int> sums;

    // Generate all subarrays
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            sums.push_back(sum);
        }
    }

    // Sort in decreasing order
    sort(sums.begin(), sums.end(), greater<int>());

    // return the Kth largest sum
    return sums[k - 1];
}

int main() {
    vector<int> arr = {20, -5, -1};\
    int k = 3;
    cout << kthLargest(arr, k);
    return 0;
}






#include <vector>
#include <queue>
using namespace std;

class Solution {        ////O(n² log k) —time comple
  public:
    int kthLargest(vector<int> &arr, int k) {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += arr[j];
                if (minHeap.size() < k) {
                    minHeap.push(sum);
                } else if (sum > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }

        return minHeap.top();
    }
};

