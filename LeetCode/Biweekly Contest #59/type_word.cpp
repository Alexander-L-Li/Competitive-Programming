class Solution {
public:
    int minTimeToType(string word) {
        char curr = 'a'; int ans = 0;
        for(int a=0; a<word.length(); a++){
            int b = (123 - (int)word[a]) + ((int)curr - 97);
            int c = abs((int)word[a] - (int)curr);
            int d = (123 - (int)curr) + ((int)word[a] - 97);
            cout << b << " " << c << endl;
            ans += min(b, min(d, c)) + 1;
            curr = word[a];
        }
        return ans;
    }
};
