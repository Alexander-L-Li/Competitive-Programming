class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        for(int a=0; a<s.size(); a++){
            if(s[a] != s[a+1] || s[a+1] != s[a+2] || s[a] != s[a+2]){
                ans.push_back(s[a]);
            }
        }
        return ans;
    }
};
