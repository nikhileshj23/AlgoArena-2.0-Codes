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
 
bool prime(long long int a){
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

void multiply(int n,vector<vector<ll>>& a,vector<vector<ll>>& b){
    ll mul[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mul[i][j]=0;
            for(int k=0;k<n;k++){
                mul[i][j]=(mul[i][j]+(a[i][k]*b[k][j])%MOD)%MOD;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=mul[i][j];
        }
    }
}


void query(int a,int b,int c,int d){
    cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    cout.flush();
}

void solve(){ 
    int n;
    cin>>n;
    vi v(n);
    int sum=0;
    map<int,bool> mp;
    FOR(i,n){
        cin>>v[i];
        sum+=v[i];
        mp[sum]=1;
    }
    vi divisors;
    vi ans;
    for(int i=1;i*i<=sum;i++){
        if(sum%i==0){
            divisors.pb(i);
            if(i!=sum/i) divisors.pb(sum/i);
        }
    }
    sort(all(divisors));
    vb checked(divisors.size(),0);
    for(int i=0;i<divisors.size();i++){
        if(!checked[i]){
            bool can=1;
            for(int j=divisors[i];j<=sum;j+=divisors[i]){
                if(!mp[j]){
                    can=0;
                    break;
                }
            }
            if(can){
                ans.pb(divisors[i]);
                for(int j=i+1;j<divisors.size();j++){
                    if(divisors[j]%divisors[i]==0&&checked[j]==0){
                        checked[j]=1;
                        ans.pb(divisors[j]);
                    }
                }
            }
        }
    }
    sort(all(ans));
    see(ans);    
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
    
    // freopen("helpcross.in", "r", stdin);
    // freopen("helpcross.out", "w", stdout);
    
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
