class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size();
        int b = nums2.size();
        int ans = 0;
        if(b&1){
            for(int i:nums1) ans ^= i;
        }
        if(a&1){
            for(int i:nums2) ans ^= i;
        }
        return ans;
    }
};
