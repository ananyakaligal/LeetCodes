// Last updated: 9/16/2025, 12:01:51 AM
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int i = 0;
        int ans = 0;
        int countT = 0;
        int countF = 0;

        for(int j=0; j<n; j++){
            if(answerKey[j] == 'T')
                countT++;
            else    countF++;

            while(countT > k && countF > k){
                if(answerKey[i] == 'T')
                    countT--;
                else
                    countF--;
                i++;
            }

            ans = max(ans, j-i+1);
        }

        return ans;
    }
};