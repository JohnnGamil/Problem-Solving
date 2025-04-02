#include <bits/stdc++.h>
using namespace std;
#define Manga ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define ld long double
#define all(x) x.begin(),x.end()
const int MOD = 1e9 + 7;
const int N = 2e6 + 5;

char di[] = {'D','L','U','R'};
int dx[] = {1, 0, -1, 0, -1};
int dy[] = {0, -1, 0, 1, -1}; 



vector<vector<char>>grid;
vector<vector<bool>>vis;
ll n,m;
 
bool valid(int nx, int ny){
    return ( nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.');
}

void dfs(int x, int y){
    vis[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(valid(nx, ny) &&!vis[nx][ny]){
            dfs(nx, ny);

        }
    }
}


void solve(){
    cin>>n>>m;
    grid = vector<vector<char>> (n, vector<char> (m));
    vis = vector<vector<bool>> (n, vector<bool> (m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    int components = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(grid[i][j] == '.' && !vis[i][j]){
            dfs(i,j); components++;
           }
        }
    }
    cout<<components;

}


int main() {
    Manga
    solve();
    
}