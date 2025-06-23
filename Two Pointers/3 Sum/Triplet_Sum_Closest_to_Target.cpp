#include<bits/stdc++.h>
using namespace std;

int closest3Sum(vector<int> &arr, int target) {
    int n = arr.size();
  	sort(arr.begin(), arr.end());
    int res = 0;
    int minDiff = INT_MAX;

    for (int i = 0; i < n - 2; i++) {
      	int l = i + 1, r = n - 1;
        while (l < r) {
            int currSum = arr[i] + arr[l] + arr[r];
            if (abs(currSum - target) < minDiff) {
                minDiff = abs(currSum - target);
                res = currSum;
            }
            else if(abs(currSum - target) == minDiff) {
            	res = max(res, currSum);
            }

            if (currSum > target)
                r--;
            else
                l++;
        }
    }
    return res;
}

int main() {
    vector<int> arr = {-1, 2, 2, 4};
    int target = 4;
    cout << closest3Sum(arr, target) << endl;       /// TC: O(n^2), SC: O(1)
    return 0;
}
