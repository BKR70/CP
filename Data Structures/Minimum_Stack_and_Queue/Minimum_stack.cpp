#include<bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);  cin.tie(0);

    cout << "Enter \'1 val\' to add value to the stack." << endl;
    cout << "Enter 2 to remove the value from the stack." << endl;
    cout << "Enter 3 to get the min_value from the stack." << endl;
    cout << "Enter 4 to exit from the stack process." << endl;

    stack<pair<int,int>> st;

    while(1) {
        int type; cin >> type;
        if(type == 1) {
            int val; cin >> val;
            int Min = st.empty() ? val : min(val, st.top().second);
            st.push({val, Min});
        }
        else if(type == 2) {
            if(st.empty()) {
                cout << "Stack is empty !" << endl;
                continue;
            }
            cout << "Removed element is : " << st.top().first << endl;
            st.pop();
        }
        else if(type == 3) {
            if(st.empty()) {
                cout << "Stack is empty !" << endl;
                continue;
            }
            cout << "Min value is : ";
            cout << st.top().second << endl;
        }
        else if(type == 4) {
            return 0;
        }
    }
    return 0;
}
