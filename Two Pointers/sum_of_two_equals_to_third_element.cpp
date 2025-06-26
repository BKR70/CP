#include <bits/stdc++.h>
using namespace std;

bool findTriplet(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 2; i < n; i++) {
        int left = 0, right = i - 1;
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == arr[i]) return true;
            else if (sum < arr[i]) left++;
            else right--;
        }
    }
    return false;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    if (findTriplet(arr))
        cout << "Existed." << endl;
    else
        cout << "Not existed." << endl;

    return 0;
}
