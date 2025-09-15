// Last updated: 9/16/2025, 12:05:21 AM
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int ast : asteroids) {
            bool alive = true;

            while (!st.empty() && ast < 0 && st.top() > 0) {
                if (abs(ast) > st.top()) {
                    st.pop(); // top asteroid explodes, keep checking
                } else if (abs(ast) == st.top()) {
                    st.pop(); // both explode
                    alive = false;
                    break;
                } else {
                    alive = false; // current asteroid explodes
                    break;
                }
            }

            if (alive) st.push(ast);
        }

        // Convert stack to result vector
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};
