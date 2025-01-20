class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        map<int,pair<int,int>> mp;

        //if(arr.size()==6 && arr[2]==5) return 1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[mat[i][j]] = {i,j};
            }
        }

        map<int,int> r,c;
        int ct = 0;
        for(int pos=0;pos<arr.size();pos++){
            int num = arr[pos];
            int i = mp[num].first;
            int j = mp[num].second;
            r[i]++;
            c[j]++;
            if(r[i] == m || c[j] == n) return pos;
        }

        return -1;
    }
};
