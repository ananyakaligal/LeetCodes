// Last updated: 9/16/2025, 12:03:45 AM
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();

        if(n==1) return "";

        for(int i=0; i<n/2; i++){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                return palindrome;
            }
        }
        palindrome[n-1]='b';
        return palindrome;
    }
};