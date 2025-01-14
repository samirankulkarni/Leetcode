class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int,int> mp;
        set<int> st;
        int n = A.size();
        vector<int> ans(n,0);
        int ct = 0;
        for(int i=0;i<n;i++){
            mp[A[i]]++;
            mp[B[i]]++;
            if(st.find(A[i]) == st.end() && mp[A[i]]==2){
                st.insert(A[i]);
                ct++;
            }
            if(st.find(B[i]) == st.end() && mp[B[i]]==2){
                st.insert(B[i]);
                ct++;
            }
            ans[i]  = ct;
        }
        return ans;
    }
};
