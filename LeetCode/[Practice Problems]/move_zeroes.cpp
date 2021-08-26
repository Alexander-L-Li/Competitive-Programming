class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(int a=0; a<nums.size(); a++){
            if(nums[a] == 0){
                count++;
                nums.erase(nums.begin() + a);
                a--;
            }
        }
        while(count--){
            nums.push_back(0);
        }
    }
};
