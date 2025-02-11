#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> func1(int n, vector<int> &arr) {
    set<vector<int>> st;

    // check all possible triplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    //store the set elements in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


vector<vector<int>> func2(int n, vector<int> &arr) {
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            //Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            //Find the element in the set:
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    //store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
//optimised
vector<vector<int>> func3(vector<int> &arr){
    vector<vector<int>> ans;
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(i!=0 && arr[i]==arr[i-1]){
            continue;
        }
        int front=i+1;
        int back=n-1;

        while(front<back){
            int sum=arr[i]+arr[front]+arr[back];
            if(sum>0){
                back--;
            }
            else if(sum<0){
                front++;
            }
            else{
                vector<int> temp={arr[i],arr[front],arr[back]};
                ans.push_back(temp);
                front++;
                back--;
                while(front<back && arr[front]==arr[front-1]){
                    front++;
                }
                while(front<back && arr[back]==arr[back+1]){
                    back--;
                }
            }
        }

    }
    return ans;
    

}
int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = func3(arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
