// Last updated: 9/16/2025, 12:03:15 AM
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip=0;
        while(a!=0 || b!=0 ||c!=0){
            if(c&1){
                if (((a & 1) == 0) && ((b & 1) == 0)) flip++; 
            } else{
                flip+= (a&1) +(b&1);
            } 
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return flip;
    }
};