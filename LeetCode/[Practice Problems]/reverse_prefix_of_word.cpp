class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = 0;
        for(int a=0; a<word.length(); a++){
            if(word[a] == ch){
                index = a;
                break;
            } 
        }
        for(int a=0; a<(index+1)/2; a++){
            swap(word[a], word[index-a]);
        }
        return word;
    }
};
