#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define FOR(i,b) for(ll i=0;i<b;i++)
#define FORwi(i,a,b) for(int i=a;i<b;i++)
#define Get(v,n) FOR(i,n) cin>>v[i];
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

ll get(){
    ll x;
    cin>>x;
    return x;
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
    int n=get(),m=get(),k=get();

    vi a(n);
    FOR(i,n) cin>>a[i];

    vi b(m);
    FOR(i,m) cin>>b[i];

    sort(all(a));sort(all(b));

    int ans=0;
    int ca=0,cb=0;

    while(cb<m){
        if(b[cb]<=a[ca]+k&&a[ca]-k<=b[cb]){
            ans++;
            // cout<<ca<<" "<<a[ca]<<" "<<cb<<" "<<b[cb]<<endl;
            ca++;
            cb++;
            if(ca>=n) break;
        }else if(b[cb]<a[ca]-k){
            cb++;
        }else{
            if(ca==n-1) break;
            else ca++;
        }

        
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
    // int t;
    // cin>>t;
    // while(t--){
    //     solve();
    // }  
    
    solve();
}