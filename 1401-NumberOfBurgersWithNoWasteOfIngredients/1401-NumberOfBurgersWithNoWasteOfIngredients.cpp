// Last updated: 9/16/2025, 12:03:27 AM
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int numburgers=cheeseSlices;
        if(tomatoSlices%2==1) return {};

        int TwoSlice=(tomatoSlices/2);
        if(TwoSlice<numburgers) return {};
        int rem=TwoSlice-numburgers;
        if(rem>numburgers) return {};
        int jumbo=rem;
        int smol=numburgers-jumbo;

        return {jumbo,smol};
    }
};