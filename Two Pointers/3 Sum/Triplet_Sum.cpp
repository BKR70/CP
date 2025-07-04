#include<bits/stdc++.h>
using namespace std;

bool hasTripletSum(vector<int>& arr, int target) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++) {

        int l = i + 1, r = n - 1;
        int requiredSum = target - arr[i];
        while(l < r) {
            if(arr[l] + arr[r] == requiredSum)
                return true;
            if(arr[l] + arr[r] < requiredSum)
                l++;
            else if(arr[l] + arr[r] > requiredSum)
                r--;
        }
    }
    return false;
}

int main() {
    vector<int> arr = { 1, 4, 45, 6, 10, 8 };
    int target = 16;
    if(hasTripletSum(arr, target))      /// TC: O(n^2), SC: O(1)
        cout << "true";
    else
        cout << "false";
    return 0;
}
