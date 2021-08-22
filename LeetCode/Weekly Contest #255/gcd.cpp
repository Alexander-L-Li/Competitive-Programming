class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int a=1000; a>=0; a--){
            ans = a;
            if(nums[0] % a == 0 && nums[nums.size()-1] % a == 0){
                break;
            }
        }
        return ans;
    }
};
