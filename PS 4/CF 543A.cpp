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
const int MOD1=1000000007;
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
ll dp[2][505][505];
void solve(){
    int n,m,b,x;
    cin>>n>>m>>b>>x;
    const int mod=x;
    vi a(n);get(a);
    dp[0][0][0]=1;
    for(int it=1;it<=n;it++){
        int i=it&1;
        for(int j=0;j<=m;j++){
            for(int k=0;k<=b;k++){
                dp[i][j][k]=dp[i^1][j][k];
                if(j>0&&k>=a[it-1]) dp[i][j][k]+=dp[i][j-1][k-a[it-1]];
                dp[i][j][k]%=mod;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=b;i++){
        ans+=dp[n&1][m][i];
        ans%=mod;
    }
    cout<<ans<<endl;
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
