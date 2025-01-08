class Solution {
public:
    
    int fun(string a,string b){
        int m = a.size();
        int n = b.size();
        if(m>n) return 0;
        if(b.substr(0,m)==a && b.substr(n-m,m)==a) return 1;
        return 0;
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++) if(fun(words[i],words[j])) ans++;
        }
        return ans;
    }
};
