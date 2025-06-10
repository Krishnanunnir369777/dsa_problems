class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {  //Time Complexity: O(n+m) + O(n+m),
        vector<int> ans;
        int s1=0,s2=0;

        while(s1<m && s2<n){
            if(nums1[s1]<=nums2[s2]){
                ans.push_back(nums1[s1]);
                s1++;
            }
            else{
                ans.push_back(nums2[s2]);
                s2++;
            }
        }

        while(s1<m){
            ans.push_back(nums1[s1]);
            s1++;
        }
        while(s2<n){
            ans.push_back(nums2[s2]);
            s2++;
        }
        int idx=0;
        for(int i=0;i<n+m;i++){
            nums1[idx]=ans[i];
            idx++;
        }
    
    }
};





class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {  //O(n+m)
        int i = m - 1;  
        int j = n - 1;
        int k = m + n - 1;
        
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};


