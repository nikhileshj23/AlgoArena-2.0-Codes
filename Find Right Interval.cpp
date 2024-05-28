class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int m=intervals.size();
        vector<pair<int,int>> v(m);
        for(int i=0;i<m;i++){
            v[i].first=intervals[i][0];
            v[i].second=i;
        }
        sort(v.begin(),v.end());
        vector<int> a(m);
        for(int i=0;i<m;i++){
            a[i]=v[i].first;
        }
        vector<int> res;
        
        for(int i=0;i<m;i++){
            int key=intervals[i][1];
            int x=lower_bound(a.begin(),a.end(),key)-a.begin();
            if(x==m) res.push_back(-1);
            else{
                res.push_back(v[x].second);
            }
        }
        return res;
    }
};
