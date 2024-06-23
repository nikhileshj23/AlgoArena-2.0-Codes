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


void solve(){
    int n,m;
    cin>>n>>m;
    int xa,ya;
    vector<vector<char>> grid(n,vector<char>(m));
    FOR(i,n) FOR(j,m){
        cin>>grid[i][j];
        if(grid[i][j]=='A'){
            xa=i;
            ya=j;
        }
    }
    if(xa==0||xa==n-1||ya==0||ya==m-1){
        yes
        cout<<0<<endl;
        return;
    }
    vector<vector<int>> dist1(n,vector<int>(m,INT_MAX));
    vector<vector<pair<int,char>>> dist2(n,vector<pair<int,char>>(m,{INT_MAX,'S'}));
    vector<vector<bool>> visited(n,vector<bool>(m,0));
    queue<pair<int,int>> q;
    FOR(i,n) FOR(j,m){
        if(grid[i][j]=='M'){
            q.push({i,j});
            dist1[i][j]=0;
            visited[i][j]=1;
        }
    }
    while(!q.empty()){
        int x=q.front().ff,y=q.front().ss;q.pop();
        if(x>0&&!visited[x-1][y]&&grid[x-1][y]!='#'){
            dist1[x-1][y]=dist1[x][y]+1;
            visited[x-1][y]=1;
            q.push({x-1,y});
        }
        if(x+1<n&&!visited[x+1][y]&&grid[x+1][y]!='#'){
            dist1[x+1][y]=dist1[x][y]+1;
            visited[x+1][y]=1;
            q.push({x+1,y});
        }
        if(y>0&&!visited[x][y-1]&&grid[x][y-1]!='#'){
            dist1[x][y-1]=dist1[x][y]+1;
            visited[x][y-1]=1;
            q.push({x,y-1});
        }
        if(y+1<m&&!visited[x][y+1]&&grid[x][y+1]!='#'){
            dist1[x][y+1]=dist1[x][y]+1;
            visited[x][y+1]=1;
            q.push({x,y+1});
        }
    }
    FOR(i,n) FOR(j,m) visited[i][j]=false;
    visited[xa][ya]=1;
    q.push({xa,ya});
    dist2[xa][ya].ff=0; dist2[xa][ya].ss='S';
    while(!q.empty()){
        int x=q.front().ff,y=q.front().ss;q.pop();
        if(x>0&&!visited[x-1][y]&&grid[x-1][y]!='#'){
            dist2[x-1][y].ff=dist2[x][y].ff+1;
            dist2[x-1][y].ss='U';
            visited[x-1][y]=1;
            q.push({x-1,y});
        }
        if(x+1<n&&!visited[x+1][y]&&grid[x+1][y]!='#'){
            dist2[x+1][y].ff=dist2[x][y].ff+1;
            dist2[x+1][y].ss='D';
            visited[x+1][y]=1;
            q.push({x+1,y});
        }
        if(y>0&&!visited[x][y-1]&&grid[x][y-1]!='#'){
            dist2[x][y-1].ff=dist2[x][y].ff+1;
            dist2[x][y-1].ss='L';
            visited[x][y-1]=1;
            q.push({x,y-1});
        }
        if(y+1<m&&!visited[x][y+1]&&grid[x][y+1]!='#'){
            dist2[x][y+1].ff=dist2[x][y].ff+1;
            visited[x][y+1]=1;
            dist2[x][y+1].ss='R';
            q.push({x,y+1});
        }
    }
    int destx=-1,desty=-1,dest=-1;
    // FOR(i,n){
    //     FOR(j,m){
    //         cout<<"{"<<dist2[i][j].ff<<","<<dist2[i][j].ss<<"}"<<" ";
    //     }
    //     cout<<endl;
    // }
    FOR(i,n){
        FOR(j,m){
            if((i==0||i==n-1||j==0||j==m-1)&&grid[i][j]=='.'&&dist2[i][j].ff<dist1[i][j]){
                destx=i;desty=j;
                dest=dist2[i][j].ff;
                break;
            }
        }
    }
    if(dest==-1){
        no
        return;
    }
    yes
    cout<<dest<<endl;
    string res="";
    while(true){
        res.pb(dist2[destx][desty].ss);
        if(dist2[destx][desty].ss=='R') desty--;
        else if(dist2[destx][desty].ss=='L') desty++;
        else if(dist2[destx][desty].ss=='U') destx++;
        else if(dist2[destx][desty].ss=='D')destx--;
        if(destx==xa&&desty==ya) break;
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
