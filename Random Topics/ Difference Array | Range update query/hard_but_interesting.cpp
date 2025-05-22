// Link : https://leetcode.com/problems/zero-array-transformation-iii/description/?envType=daily-question&envId=2025-05-22

class Solution {
public:
    int maxRemoval(vector<int>& v, vector<vector<int>>& q) {
        int used = 0;
        sort(q.begin(),q.end());

        priority_queue<int> still_available;
        priority_queue<int, vector<int>, greater<int>> already_assigned;

        for(int i=0, t=0; i<v.size(); i++) {
            while(t<q.size() && q[t][0]<=i) {
                still_available.push(q[t++][1]);
            }
            while(!already_assigned.empty() && already_assigned.top()<i) {
                already_assigned.pop();
            }
            while(already_assigned.size()<v[i] && !still_available.empty() && still_available.top()>=i) {
                used++;
                already_assigned.push(still_available.top());
                still_available.pop();
            }
            if(already_assigned.size() < v[i]) {
                return -1;
            }
        }
        return q.size()-used;
    }
};
