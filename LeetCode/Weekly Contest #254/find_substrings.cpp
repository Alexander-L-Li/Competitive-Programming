class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for(int a=0; a<patterns.size(); a++){
            if(string::npos != word.find(patterns[a])){
                ans++;
            }
        }
        return ans;
    }
};
