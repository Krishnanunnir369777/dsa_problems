class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.length();
        int min_white=1e9;
        for(int i=0;i<n;i++){
            int cnt_white=0;
            int cnt_black=0;
            for(int j=i;j<n;j++){
                if(blocks[j]=='W'){
                    cnt_white++;
                }
                if(blocks[j]=='B'){
                    cnt_black++;
                }
                if(cnt_black+cnt_white>=k){
                    min_white=min(min_white,cnt_white);
                }
            }
        }
        return min_white;
    }
};



//optimised

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.length();
        int count=0,ans=k;
        for(int i=0;i<n;i++){
            if(blocks[i]=='W'){
                count++;
            }
            if(i>=k && blocks[i-k]=='W'){
                count--;
            }
            if(i+1>=k){
                ans=min(ans,count);
            }
        }
        return min(ans,count);
    }
};