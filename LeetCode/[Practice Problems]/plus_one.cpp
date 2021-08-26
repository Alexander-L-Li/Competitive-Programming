class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1]++;
        for(int a=digits.size()-1; a>=0; a--){
            if(digits[a] == 10 && a != 0){
                digits[a-1]++;
                digits.erase(digits.begin() + a);
                digits.push_back(0);
            } else if(digits[a] == 10 && a == 0){
                digits.erase(digits.begin() + a);
                digits.push_back(0); digits.push_back(0);
                digits[0] = 1;
            }
        }
        return digits;
    }
};
