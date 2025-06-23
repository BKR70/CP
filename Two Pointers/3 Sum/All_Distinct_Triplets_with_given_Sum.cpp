#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& arr, int target) {
    vector<vector<int>> res;
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        int j = i + 1, k = n - 1;
        while(j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if(sum == target) {
                vector<int> curr = {arr[i], arr[j], arr[k]};
                res.push_back(curr);
                j++;
                k--;
                while(j < n && arr[j] == arr[j - 1]) j++;
                while(k > j && arr[k] == arr[k + 1]) k--;
            }
            else if(sum < target) {
                j++;
            }
            else {
                k--;
            }
        }
    }
    return res;
}
int main() {
    vector<int> arr = {12, 3, 6, 1, 6, 9};
    int target = 24;
    vector<vector<int>> ans = threeSum(arr, target);                /// TC : O(n^2), SC : O(1)
    for(vector<int> triplet : ans) {
        cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << endl;
    }
    return 0;
}
