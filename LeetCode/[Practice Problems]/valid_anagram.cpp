class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26] = {0}, arr2[26] = {0};
        for(int a=0; a<s.length(); a++){
            arr[s[a] - 'a']++;
        }
        for(int a=0; a<t.length(); a++){
            arr2[t[a] - 'a']++;
        }
        for(int a=0; a<26; a++){
            if(arr[a] != arr2[a]){
                return false;
            }
        }
        return true;
    }
};
