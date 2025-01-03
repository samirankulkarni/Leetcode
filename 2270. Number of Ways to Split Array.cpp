#define ll long long 
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        ll n = nums.size();
        vector<ll> p(n),s(n);
        p[0] = nums[0];
        for(ll i=1;i<n;i++) p[i] = p[i-1] + nums[i];
        s[n-1] = nums[n-1];
        for(ll i=n-2;i>=0;i--) s[i] = s[i+1] + nums[i];
        ll ans = 0;
        for(ll i=0;i<n-1;i++) if(p[i] >= s[i+1]) ans++;
        return ans;
    }
};