class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int a=0; a<nums.size(); a++){
            bool done = false;
            for(int b=0; b<nums.size(); b++){
                if(b != a && nums[a] + nums[b] == target){
                    ans.push_back(a); ans.push_back(b);
                    done = true;
                    break;
                }
            }
            if(done){
                break;
            }     
        }
        return ans;
    }
};
