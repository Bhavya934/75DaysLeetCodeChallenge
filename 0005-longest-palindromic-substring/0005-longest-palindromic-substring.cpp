class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1) return s;

        int start=0,maxLen=0;
        for(int i=0;i<s.length();i++){
            expand(s,i,i,start,maxLen);
                        expand(s,i,i+1,start,maxLen);

        }
        return s.substr(start,maxLen);

    }
    private:
            void expand(string&s, int left, int right,int& start,int& maxLen){
                while (left >= 0 && right < s.length() && s[left] == s[right]) {
            int currentLen = right - left + 1;
            if (currentLen > maxLen) {
                start = left;
                maxLen = currentLen;
            }
            left--;
            right++;
        }
    }
            
};