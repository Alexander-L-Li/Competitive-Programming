class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int a=0; a<nums.size()-1; a++){
            if(nums[a] == nums[a+1]){
                return true;
            }
        }
        return false;
    }
};
