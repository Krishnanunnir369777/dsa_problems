#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int searchInsert(vector<int>& arr, int x) {
    int n = arr.size(); // size of the array
    int s = 0, e = n - 1;
    int ans = n;

    while (s <= e) {
        int mid = (s + e) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            e = mid - 1;
        }
        else {
            s = mid + 1; // look on the right
        }
    }
    return ans;
}


int main()
{
    vector<int> arr = {1, 2, 4, 7};
    int x = 6;
    int ind = searchInsert(arr, x);
    cout << "The index is: " << ind << "\n";
    return 0;
}