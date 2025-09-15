// Last updated: 9/16/2025, 12:01:25 AM
class Solution {
public:
    int convertTime(string current, string correct) {
        auto getMinutes = [](const string& time) {
            int hours = stoi(time.substr(0, 2));
            int minutes = stoi(time.substr(3, 2));
            return hours * 60 + minutes;
        };

        int curMins = getMinutes(current);
        int corMins = getMinutes(correct);
        int diff = corMins - curMins;

        vector<int> ops = {60, 15, 5, 1};
        int count = 0;
        for (int op : ops) {
            count += diff / op;
            diff %= op;
        }

        return count;
    }
};
