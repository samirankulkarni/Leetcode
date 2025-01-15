class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int sb = __builtin_popcount(num2);
        vector<int> v;
        int n = num1;
        while(n){
            if(n&1) v.push_back(1);
            else v.push_back(0);
            n >>= 1;
        }
        int m = 32 - v.size();
        reverse(v.begin(),v.end());
        vector<int> e;
        while(m--) e.push_back(0);
        for(int i:v) e.push_back(i);
        vector<int> ans(32,0);
        for(int i=0;i<32;i++){
            if(e[i] == 1 && sb>0){
                ans[i] = 1;
                sb--;
            }
        } 
        if(sb > 0){
            for(int i=31;i>=0;i--){
                if(sb > 0 && ans[i]==0){
                    ans[i] = 1;
                    sb--;
                }
            }
        }
        int ret =0;
        for(int i=0;i<32;i++){
            int p = 31-i;
            if(ans[i]) ret += (int)(pow(2,p));
        }
        return ret;
    }
};
