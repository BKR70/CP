#include<bits/stdc++.h>
using namespace std;

void prefix2Dsum(int arr[][5])
{
    int p2s[4][5];
    p2s[0][0] = arr[0][0];
    for(int i=1; i<5; i++)
        p2s[0][i] = p2s[0][i-1]+arr[0][i];

    for(int i=1; i<4; i++)
        p2s[i][0] = p2s[i-1][0]+arr[i][0];
    for(int i=1; i<4; i++){
        for(int j=1; j<5; j++){
            p2s[i][j] = p2s[i-1][j]+p2s[i][j-1]+arr[i][j]-p2s[i-1][j-1];
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<5; j++){
            cout<<p2s[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    int arr[4][5] = {{1,1,1,1,1},
                     {1,1,1,1,1},
                     {1,1,1,1,1},
                     {1,1,1,1,1}
                    };
    prefix2Dsum(arr);
    return 0;
}
