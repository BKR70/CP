#include<bits/stdc++.h>
#define INFI 1e9+10
using namespace std;

int vis[8][8];
int lev[8][8];
int getx(string s) {
    return s[0]-'a';
}
int gety(string s) {
    return s[1]-'1';
}
bool isvalid(int x,int y) {
    return x>=0 && y>=0 && x<8 && y<8;
}
vector<pair<int,int>> movements = {
    {-1,2},{1,2},{-1,-2},{1,-2},
    {-2,1},{2,1},{-2,-1},{2,-1}
};
int bfs(string src,string des) {
    int srcx = getx(src);
    int srcy = gety(src);
    int desx = getx(des);
    int desy = gety(des);
    queue<pair<int,int>> q;
    q.push({srcx,srcy});
    vis[srcx][srcy] = 1;
    lev[srcx][srcy] = 0;
    while(!q.empty()) {
        auto v = q.front();
        int x=v.first ,y=v.second;
        q.pop();
        for(auto mov:movements) {
            int childx = x+mov.first;
            int childy = y+mov.second;
            if(!isvalid(childx,childy))
                continue;
            if(!vis[childx][childy]) {
                q.push({childx,childy});
                lev[childx][childy] = lev[x][y]+1;
                vis[childx][childy] = 1;
            }
        }
        if(lev[desx][desy] != INFI) {
            break;
        }
    }
    return lev[desx][desy];
}
void reset() {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            vis[i][j] = 0; lev[i][j] = INFI;
        }
    }
}
int main() {
    int n; cin >> n;
    while(n--) {
        reset();
        string s1, s2; cin >> s1 >> s2;
        cout << bfs(s1,s2) << endl;
    }
    return 0;
}
