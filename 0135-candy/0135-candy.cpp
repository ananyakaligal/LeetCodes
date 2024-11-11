class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) 
            return 0;

        int totalCandies = 1;        // Start with 1 candy for the first child
        int up = 0, down = 0;        // Tracks increasing and decreasing sequence lengths
        int peak = 0;                // Peak of an increasing sequence

        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                // Start of a new increasing sequence
                up++;
                peak = up;
                down = 0;
                totalCandies += up + 1;  // More candies than previous
            } 
            else if (ratings[i] < ratings[i - 1]) {
                // Start of a decreasing sequence
                up = 0;
                down++;
                totalCandies += down;    // Add to total candies for each decreasing child
                
                if (down > peak) {
                    totalCandies++;      // Adjust to make sure the first peak child has enough candies
                }
            }
            else {
                // Reset both up and down on plateau
                up = down = peak = 0;
                totalCandies += 1;       // One candy for same-rating child
            }
        }
        return totalCandies;
    }
};