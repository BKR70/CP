#include<bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);  cin.tie(0);

    cout << "Enter \'1 val\' to add value to the queue." << endl;
    cout << "Enter 2 to remove the value from the queue." << endl;
    cout << "Enter 3 to get the min_value from the queue." << endl;
    cout << "Enter 4 to exit from the queue process." << endl;

    stack<pair<int,int>> st1, st2;

    while(1) {
        int type; cin >> type;
        if(type == 1) {
            int val; cin >> val;
            int Min = st1.empty() ? val : min(val, st1.top().second);
            st1.push({val, Min});
        }
        else if(type == 2) {
            if(st1.empty() and st2.empty()) {
                cout << "Queue is empty !" << endl;
                continue;
            }
            if(st2.empty()) {
                while(!st1.empty()) {
                    int val = st1.top().first;
                    st1.pop();
                    int Min = st2.empty() ? val : min(val, st2.top().second);
                    st2.push({val, Min});
                }
            }
            cout << "Removed element is : " << st2.top().first << endl;
            st2.pop();
        }
        else if(type == 3) {
            if(st1.empty() and st2.empty()) {
                cout << "Queue is empty !" << endl;
                continue;
            }
            if(st1.empty() or st2.empty()) {
                cout << "Min value is : ";
                cout << (st2.empty() ? st1.top().second : st2.top().second) << endl;
            }
            else {
                cout << "Min value is : ";
                cout << min(st1.top().second, st2.top().second )<< endl;
            }
        }
        else if(type == 4) {
            return 0;
        }
    }
    return 0;
}
