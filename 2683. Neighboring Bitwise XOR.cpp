class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int a = 0;
        for(int i:derived) a ^= i;
        return !a;
    }
};
