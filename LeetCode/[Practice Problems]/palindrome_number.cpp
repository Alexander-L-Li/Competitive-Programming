class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> v;
        if(x<0){return false;}
        while(x % 10 != x){
            v.push_back(x%10);
            x /= 10;
        }
        v.push_back(x);

        for(int a=0; a<v.size()/2; a++){
            if(v[a]!=v[v.size()-1-a]){
                return false;
            } 
        }
        return true;
    }
};
