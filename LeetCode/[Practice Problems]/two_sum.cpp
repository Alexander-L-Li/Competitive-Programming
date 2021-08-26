class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int p1 = 0; int p2 = nums.size()-1;
        vector<pair<int, int>> v;
        for(int a=0; a<nums.size(); a++){
            v.push_back(make_pair(nums[a], a));
        }
        vector<int> ans;
        sort(v.begin(), v.end());
        while(p1 < p2){
            if(v[p1].first + v[p2].first == target){
                ans.push_back(v[p1].second);
                ans.push_back(v[p2].second);
                break;
            } else if(v[p1].first + v[p2].first < target){
                p1++;
            } else {
                p2--;
            }
        }
        return ans;
    }
};
