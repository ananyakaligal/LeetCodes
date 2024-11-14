class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());

        int i=0, j=tokens.size()-1;
        int maxCount=0;
        int score=0;

        while(i<=j){

            if(tokens[i]<=power){
                power-=tokens[i];
                score++;
                i++;
            }
            else if(score>0){
                power+=tokens[j];
                j--;
                score--;
            }
            else break;

            maxCount=max(score, maxCount);
        }
        return maxCount;
    }
};