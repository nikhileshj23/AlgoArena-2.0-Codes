#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define FOR(i,b) for(int i=0;i<b;i++)
#define FORwi(i,a,b) for(int i=a;i<b;i++)
#define get(v) FOR(i,(int)v.size()) cin>>v[i];
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define see(v) FOR(i,sz(v)) cout<<v[i]<<" "; cout<<endl;
#define gt(v) for(auto it=v.begin();it!=v.end();it++)
#define sz(v) v.size()
#define vi vector<int>
#define vll vector<ll>
#define mpii map<int,int> 
#define mpll map<ll,ll> 
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define pll pair<ll,ll>
typedef long long int ll;
typedef unsigned long long ull;
const int MOD=1000000007;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
 
int prime(long long int a){
    if(a==1) return 0;
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0) return 0;
    }
    return 1;
}
 
string base_rep(ll n, ll b){  //for representation in any base
    if(n==0) return "0";
    string res="";
    while(n>0){
        res+=char('0'+n%b);
        n=n/b;
    }
    reverse(all(res));
    return res;
}
const int N=150000;
vector<bool> visited(N+9,0);
vector<int> adj[N+9];

void dfs(int u,ll &vert,ll &edge){
    if(visited[u]) return;
    visited[u]=true;
    ++vert;
    edge+=adj[u].size();
    for(int s:adj[u]){
        if(!visited[s]) dfs(s,vert,edge);
    } 
}


void solve(){
    int n,m;
    cin>>n>>m;
    int sindx,sindy,eindx,eindy;
    vector<vector<char>> mat(n,vector<char>(m));
    FOR(i,n) FOR(j,m){
        cin>>mat[i][j];
        if(mat[i][j]=='A'){
            sindx=i;
            sindy=j;
        }else if(mat[i][j]=='B'){
            eindx=i;
            eindy=j;
        }
    }
    vector<vector<bool>> visited(n,vector<bool>(m,0));
    vector<vector<pair<int,char>>> dist(n,vector<pair<int,char>>(m,{INT_MAX,'>'}));
    dist[sindx][sindy].ff=0;
    queue<pair<int,int>> q;
    q.push({sindx,sindy});
    while(!q.empty()){
        int x=q.front().ff,y=q.front().ss;q.pop();
        if(x>0){
            if(!visited[x-1][y]&&(mat[x-1][y]=='.'||mat[x-1][y]=='B')){
                visited[x-1][y]=true;
                dist[x-1][y].ff=dist[x][y].ff+1;
                dist[x-1][y].ss='U';
                q.push({x-1,y});
            }
        }
        if(x+1<n&&(mat[x+1][y]=='.'||mat[x+1][y]=='B')){
            if(!visited[x+1][y]){
                visited[x+1][y]=true;
                dist[x+1][y].ff=dist[x][y].ff+1;
                dist[x+1][y].ss='D';
                q.push({x+1,y});
            }
            
        }
        if(y>0&&(mat[x][y-1]=='.'||mat[x][y-1]=='B')){
            if(!visited[x][y-1]){
                visited[x][y-1]=true;
                dist[x][y-1].ff=dist[x][y].ff+1;
                dist[x][y-1].ss='L';
                q.push({x,y-1});
            }
        }
        if(y+1<m&&(mat[x][y+1]=='.'||mat[x][y+1]=='B')){
            if(!visited[x][y+1]){
                visited[x][y+1]=true;
                dist[x][y+1].ff=dist[x][y].ff+1;
                dist[x][y+1].ss='R';
                q.push({x,y+1});
            }
        }
        
    }
    // FOR(i,n){
    //     FOR(j,m){
    //         cout<<"{"<<dist[i][j].ff<<","<<dist[i][j].ss<<"}"<<" ";
    //     }
    //     cout<<endl;
    // }
    int ans=dist[eindx][eindy].ff;
    if(ans==INT_MAX){
        no
        return;
    }
    yes
    cout<<ans<<endl;
    string res;
    while(true){
        if(eindx==sindx&&eindy==sindy) break;
        res.pb(dist[eindx][eindy].ss);
        if(dist[eindx][eindy].ss=='U') eindx++;
        else if(dist[eindx][eindy].ss=='D') eindx--;
        else if(dist[eindx][eindy].ss=='L') eindy++;
        else if(dist[eindx][eindy].ss=='R') eindy--;
    }
    reverse(all(res));
    cout<<res<<endl;
    
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
    
    // freopen("helpcross.in", "r", stdin);
	// freopen("helpcross.out", "w", stdout);
 
 
    solve();
    
    // int t;
    // cin>>t;
    // while(t--){
    //     solve();
    // }
}
