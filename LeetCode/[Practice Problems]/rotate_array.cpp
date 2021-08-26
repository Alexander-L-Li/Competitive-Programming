class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>v;
        if(k > nums.size()){
            k = k % nums.size();
        }
        for(int a=nums.size()-k; a<nums.size(); a++){
            v.push_back(nums[a]);
        }
        for(int a=0; a<nums.size()-k; a++){
            v.push_back(nums[a]);
        }
        for(int a=0; a<nums.size(); a++){
            nums[a] = v[a];
        }
    }
};
