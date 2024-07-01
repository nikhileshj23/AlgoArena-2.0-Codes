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
#define vb vector<bool>
#define vll vector<ll>
#define mpii map<int,int> 
#define mpll map<ll,ll> 
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define pll pair<ll,ll>
typedef long long int ll;
typedef unsigned long long ull;
const int MOD=1000000007;
const int MOD2=998244353;
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

ll power(ll a,ll b,int N){
    ll res=1;
    while(b>0){
        if(b%2==1) res=(res*a)%N;
        a=(a*a)%N;
        b>>=1;
    }
    return res;
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

// vector<int> child[250000];
// vector<int> dist(250000,0);
// vector<vector<int>> up(250000,vector<int>(18,0));
// vector<int> adj[250000];
// vector<bool> visited(250000,0);
// vector<int> parent(250000,0);
// const int l=18;

// void dfs(int u){
//     visited[u]=1;
//     for(auto& v:adj[u]){
//         if(!visited[v]){
//             parent[v]=u;
//             visited[v]=1;
//             up[v][0]=u;
//             for(int j=1;j<l;j++){
//                 up[v][j]=up[up[v][j-1]][j-1];
//             }
//             dist[v]=dist[u]+1;
//             dfs(v);
//             child[u].pb(v);
//         }
//     }
// }

// int get_lca(int& a,int& b){
//     if(dist[a]<dist[b]) swap(a,b);
    
//     int k=dist[a]-dist[b];
//     for(int j=l-1;j>=0;j--){
//         if((1<<j)&k) a=up[a][j];
//     }
//     if(a==b) return a;
//     for(int j=l-1;j>=0;j--){
//         if(up[a][j]!=up[b][j]){
//             a=up[a][j];
//             b=up[b][j];
//         }
//     }
//     return up[a][0];
// }

vector<ll> dp(2000005,1);
void func(){
    for(ll i=2;i<=2000002;i++){
        dp[i]=(i*dp[i-1])%MOD;
    }
}
void solve(){
  //if n is even, calculate (n/2)th catalan number
    func();
    ll n;
    cin>>n;
    if(n%2) cout<<0<<endl;
    else{
        ll p1,p2,p3;
        p1=dp[n];p2=dp[n/2];
        p2=power(p2,MOD-2,MOD);
        p1=((p1*p2)%MOD*p2)%MOD;
        p3=power(n/2+1,MOD-2,MOD);
        p1=(p1*p3)%MOD;
        cout<<p1<<endl;
    }
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
