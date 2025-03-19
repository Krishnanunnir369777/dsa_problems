#include <bits/stdc++.h>
using namespace std;

vector<int> func1(vector<int>& arr){   // nlog(m) + m
    map<int,int> mpp;
    vector<int> ans;
    for(auto it:arr){
        mpp[it]++;
    }
    for(auto i:mpp){
        if(i.second==1){
            ans.push_back(i.first);
        }
    }

    return ans;

}

vector<int> func2(vector<int>& nums) {         //T(n) = O(n) and S(n) = O(1)
    int first=0,firstxorsec=0,mask=1;

    for(int ele:nums){
        firstxorsec=firstxorsec^ele;
    }
    while(not(mask&firstxorsec)){
        mask=mask<<1;
    }
    for(auto i:nums){
        if(mask&i){
            first=first^i;
        }
    }
    return {first,firstxorsec^first};
    
}

vector<int> func2(vector<int> &nums) {
	int firstXorSec = 0, mask = 1, first = 0;
	// get xor of first and sec
	for (auto &num: nums) firstXorSec ^= num;
	// get rightmost set bit in above xor
	while (not (firstXorSec & mask)) mask <<= 1;
	// get first distinct number
	for (auto &num: nums)
		if (num & mask) first ^= num;
	// return ans
	return {first, firstXorSec ^ first};
}

int main(){
    vector<int> arr={1,2,1,3,5,2};
    vector<int> ans=func2(arr);
    for(auto i:ans){
        cout<<i<<endl;
    }


}