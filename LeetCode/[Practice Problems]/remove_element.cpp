class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int a=0; a<nums.size(); a++){
            if(nums[a] == val){
                nums.erase(nums.begin() + a);
                a--;
            }
        }
        return nums.size();
    }
};
