class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double,int>mp;
        vector<double>vc;
        for(auto x: rectangles)
        {
            int first = x[0];
            int second = x[1];
            double ratio = (double)first/second;
            vc.push_back(ratio);
            mp[ratio]++;
        }
        long long count = 0;
      
        for(auto x:mp)
        {
            long long cnt = x.second;
            long long  value = (cnt*(cnt-1))/2;
            count += value;
        }
        return count;
        
    }
};
