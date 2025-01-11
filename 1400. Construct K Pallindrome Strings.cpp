class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(k>n) return 0;
        if(k==n) return 1;
        map<char,int> mp;
        for(auto c:s) mp[c]++;
        int esum = 0;
        int ones = 0;
        for(auto p:mp) {
            if(p.second % 2 == 0) esum += p.second;
            else{
                esum += p.second - 1;
                ones++;
            }
        }
        if(ones > k) return 0;
        return 1;
    }
};
