class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};
        for(int a=0; a<s.length(); a++){
            arr[s[a]-'a']++;
        }
        for(int a=0; a<s.length(); a++){
            if(arr[s[a]-'a'] == 1){
                return a;
            }
        }
        return -1;
    }
};
