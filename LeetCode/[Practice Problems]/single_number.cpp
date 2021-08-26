class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        } else {
            sort(nums.begin(), nums.end());
            for(int a=0; a<nums.size()-1; a++){
                if(nums[a] == nums[a+1]){
                    a++;
                } else {
                    return nums[a];
                }
            }
        }
        return nums[nums.size()-1];
    }
};
