class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> v, v2;
        for(int a=0; a<s.length(); a++){
            if((int)s[a] >= 65 && (int)s[a] <= 90){
                v.push_back(tolower(s[a]));
            } else if((int)s[a] >= 48 && (int)s[a] <= 57){
                v.push_back(s[a]);
            } else if((int)s[a] >= 97 && (int)s[a] <= 122){
                v.push_back(s[a]);
            }
        }
        for(int a=v.size()-1; a>=0; a--){
            v2.push_back(v[a]);
        }
        for(int a=0; a<v.size(); a++){
            if(v2[a] != v[a]){
                return false;
            }
        }
        
        return true;
    }
};
