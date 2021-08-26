class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() < 1)      {
            return 0;
        }              
        int ans = haystack.find(needle);
        if(ans == haystack.size()){
            return -1;
        }
        return ans;
    }
};
