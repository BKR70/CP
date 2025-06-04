// Link : https://leetcode.com/problems/zero-array-transformation-i/description/?envType=daily-question&envId=2025-05-20
class Solution {
public:
    bool isZeroArray(vector<int>& v, vector<vector<int>>& q) {
        int n = v.size();
        vector<int> ar(n+1,0);
        for(int i=0; i<q.size(); i++) {
            int l = q[i][0], r = q[i][1];
            ar[l]++, ar[r+1]--;
        }
        for(int i=1; i<n; i++) {
            ar[i] = ar[i]+ar[i-1];
        }
        for(int i=0; i<n; i++) {
            if(ar[i] < v[i]) return false;
        }
        return true;
    }
};
