#include <bits/stdc++.h>
using namespace std;
#define Manga ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define ld long double
#define all(x) x.begin(),x.end()
const int MOD = 1e9 + 7;
const int N = 2e6 + 5;
 
vector<int> adj[N];
bool vis[N];
 
void dfs(int v, int parent){
    vis[v] = true;
    for(auto u: adj[v]){
        if(!vis[u]){
            dfs(u,v);
        }
    }
}
 
 
 
void solve(){
    ll n, m;
    cin>>n>>m;
    for(int i = 0; i<n; i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1);
 
    if(m != n-1){
        return void(cout<<"NO\n");
    }
 
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            return void(cout<<"NO\n");
        }
    }
    cout<<"YES\n";
}
 
 
int main() {
    Manga
    solve();
    
} 