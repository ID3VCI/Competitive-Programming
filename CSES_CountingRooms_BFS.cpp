#include <bits/stdc++.h>
using namespace std;
#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n"
#define int long long
const int MAXN = 200100;
const int MOD = 1000000007;

vector<int> dx={1,-1,0,0};
vector<int> dy={0,0,1,-1};

void solve() {
    int n,m;
    cin>>n>>m;
    char a;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a;
            grid[i][j] = (a=='.');
        }
    }
    vector<vector<int>> vis(n,vector<int>(m,0));

    int count=0;
    queue<pair<int,int>> q;
    pair<int,int> curr;
    int x,y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0 || vis[i][j]==1) continue;
            count++;
            q.push({i,j});
            vis[i][j]=1;
            while(!q.empty()){
                curr=q.front();
                x=curr.first;
                y=curr.second;
                for(int k=0;k<4;k++){
                    if(x+dx[k]>=0 && x+dx[k]<n && y+dy[k]>=0 && y+dy[k]<m && grid[x+dx[k]][y+dy[k]] && !vis[x+dx[k]][y+dy[k]]){
                        q.push({x+dx[k],y+dy[k]});
                        vis[x+dx[k]][y+dy[k]]=1;
                    }
                }
                q.pop();
            }
        }
    }
    cout<<count;
    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    //cin >> T;
    for(int I = 1; I <= T; I++) {
        solve();
    }
    return 0;
}