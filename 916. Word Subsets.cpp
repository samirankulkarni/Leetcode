class Solution {
public:
    bool fun(map<char,int> &x,map<char,int> &mp){
        for(auto p:mp){
            if(x.find(p.first) == x.end() || x[p.first]<p.second) return false;
        }
        return true;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<map<char,int>> a;
        for(string s:words1){
            map<char,int> mp;
            for(char c:s) mp[c]++;
            a.push_back(mp);
        }
        map<char,int> mp;
        for(auto s:words2){
            map<char,int> t;
            for(auto c:s){
                t[c]++;
            }
            for(auto p:t){
                if(mp.find(p.first) == mp.end()) mp[p.first] = p.second;
                else mp[p.first] = max(mp[p.first],p.second);
            }
        }
        vector<string> ans;
        for(int i=0;i<words1.size();i++){
            map<char,int> x = a[i];
            if(fun(x,mp)) ans.push_back(words1[i]);
        }
        return ans;
    }
};
