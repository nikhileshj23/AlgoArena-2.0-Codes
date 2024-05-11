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

bool comp(pii a, pii b){
    return a.ff*b.ss>a.ss*b.ff;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    get(v)
    FOR(i,k){
        int d;
        cin>>d;
        int ans;
        deque<int> q;
        FOR(j,d){
            while(!q.empty()&&q.back()<v[j]) q.pop_back();
            q.push_back(v[j]);
        } 
        ans=q.front();
        // cout<<ans<<endl;
        for(int j=0;j<n-d;j++){
            if(!q.empty()&&q.front()==v[j]) q.pop_front();
            while(!q.empty()&&q.back()<v[j+d]) q.pop_back();
            q.push_back(v[j+d]);
            ans=min(ans,q.front());
            // cout<<q.front()<<endl;
        }
        cout<<ans<<endl;
    }

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
