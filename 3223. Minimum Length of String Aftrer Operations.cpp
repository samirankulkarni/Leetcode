class Solution {
public:
    int minimumLength(string s) {
        map<char,int> mp;
        for(auto c:s) mp[c]++;
        int ans = 0;
        for(auto p:mp){
            int n = p.second;
            if(n&1) ans++;
            else ans += 2;
        }
        return ans;
    }
};
