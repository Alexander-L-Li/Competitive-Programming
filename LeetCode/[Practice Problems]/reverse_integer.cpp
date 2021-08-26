class Solution {
public:
    int reverse(int x) {
        string s = to_string(abs(x));
        int p1 = 0, p2 = s.length()-1;
        while(p1 < p2){
            swap(s[p1], s[p2]);
            p1++; p2--;
        }
        long long ans = 0;
        if(x < 0){
            ans = stoll(s) * -1;
        } else {
            ans = stoll(s);
        }
        if(ans > pow(2, 31) || ans < pow(2, 31) * -1){
            ans = 0;
        }
        return ans;
    }
};
