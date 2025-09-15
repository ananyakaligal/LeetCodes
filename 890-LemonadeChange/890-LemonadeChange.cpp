// Last updated: 9/16/2025, 12:04:51 AM
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();

        int i=0;
        int five=0, ten=0;
        while(i<n){
            if(bills[i]==5){
                five++;
            }else if (bills[i]==10){
                ten++;
                if(five==0) return false;
                five--;
            }else { // bill == 20
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
            i++;
        }
        return true;
    }
};