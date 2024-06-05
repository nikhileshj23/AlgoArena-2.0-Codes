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
#define get(v) FOR(i,v.size()) cin>>v[i];
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
 
void solve(){
    int n;
    cin>>n;
    vi a(n),b(n);
    FOR(i,n) cin>>a[i]>>b[i];
    vector<int> dp((1<<n),0);
    dp[0]=0,dp[1]=0;
    for(int k=2;k<((1<<n));k++){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(((k&(1<<i)))&&(k&(1<<j))&&(j!=i)){
                    if(a[n-i-1]==a[n-j-1]||b[n-i-1]==b[n-j-1]){
                        if(dp[(k^(1<<i))^(1<<j)]==0) dp[k]=1;
                    }
                }
            }
        }
    }
    // see(dp)
    if(dp[(1<<(n))-1]) cout<<"Takahashi"<<endl;
    else cout<<"Aoki"<<endl;
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
