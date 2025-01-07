class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        map<string,int> mp,mp2;
        for(auto word:words){
            int n = word.size();
            for(int i=0;i<n;i++){
                for(int sz=1;sz<=(n-i);sz++) mp[word.substr(i,sz)]++;
            }
            mp2[word]++;
        }
        vector<string> ans;
        for(auto p:mp2) if(mp.find(p.first)!=mp.end() && mp[p.first]>1){
            ans.push_back(p.first);
        }
        return ans;
    }
};
