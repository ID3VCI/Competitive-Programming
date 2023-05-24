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
    int n,m,x,y,X,Y,s=0;
    cin>>n>>m;
    char a;
    pair<int,int> Start;
    queue<pair<int,int>> q;
    pair<int,int> curr,target;
    vector<pair<int,int>> exit;
    vector<char> answer;

    vector<vector<int>> grid(n,vector<int>(m,0));
    vector<vector<int>> vis(n,vector<int>(m,0)),vis1(n,vector<int>(m,0));
    vector<vector<int>> dis(n,vector<int>(m,-1)),dis1(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a;
            if(a=='#') continue;
            grid[i][j]=1;
            if(a=='M') {q.push({i,j});dis[i][j]=0;vis[i][j]=1;}
            else if(a=='A') Start={i,j};
            if(i==0 || j==0 || i==n-1 || j==m-1) exit.push_back({i,j});
        }
    }

    while(!q.empty()){
        curr=q.front();
        x=curr.first;
        y=curr.second;
        for(int k=0;k<4;k++){
            X=x+dx[k];
            Y=y+dy[k];
            if(X>-1 && X<n && Y>-1 && Y<m && grid[X][Y] && !vis[X][Y]){
                q.push({X,Y});
                vis[X][Y]=1;
                dis[X][Y]=dis[x][y]+1;
            }
        }
        q.pop();
    }

    q.push(Start);
    dis1[Start.first][Start.second]=0;
    vis1[Start.first][Start.second]=1;


    while(!q.empty()){
        curr=q.front();
        x=curr.first;
        y=curr.second;
        for(int k=0;k<4;k++){
            X=x+dx[k];
            Y=y+dy[k];
            if(X>-1 && X<n && Y>-1 && Y<m && grid[X][Y] && !vis1[X][Y] &&(dis[X][Y]==-1 || dis1[x][y]+1<dis[X][Y])){
                q.push({X,Y});
                vis1[X][Y]=1;
                dis1[X][Y]=dis1[x][y]+1;

                

            }
        }
        q.pop();
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++) cout<<dis1[i][j];
    //     cout<<endl;
    // }
    
    for(auto itr:exit){
        if(dis1[itr.first][itr.second]>=0){
            s=1;
            target=itr;
            break;
        }
    }

    if(s) cout<<"YES\n"<<dis1[target.first][target.second]<<endl;
    else {cout<<"NO\n";return;}

    vector<char> direction(4);
    direction={'U','D','L','R'};
    while(target!=Start){
        x=target.first;
        y=target.second;
        for(int k=0;k<4;k++){
            X=x+dx[k];
            Y=y+dy[k];
            if(X>-1 && X<n && Y>-1 && Y<m && dis1[X][Y]==dis1[x][y]-1){
                answer.push_back(direction[k]);
                target={X,Y};
                continue;
            }
        }
    }
    for (int i = answer.size() - 1; i >= 0; i--) cout << answer[i];


    return;
    
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