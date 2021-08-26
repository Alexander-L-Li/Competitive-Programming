class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans1 (1001);
        vector<int> ans2 (1001);
        vector<int> ans;
        fill(ans.begin(), ans.end(), 0);
        for(int a=0; a<nums1.size(); a++){
            ans1[nums1[a]]++;
        }
        for(int a=0; a<nums2.size(); a++){
            ans2[nums2[a]]++;
        }
        for(int a=0; a<1001; a++){
            int n = min(ans1[a], ans2[a]);
            while(n--){
                ans.push_back(a);
            }
        }   
        return ans;
    }
};
