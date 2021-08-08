class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string str;
        for(int a=0; a<words.size(); a++){
            str += words[a];
            if(str == s){
            return true;
        }
        }

        return false;
    }
};
