// Last updated: 9/16/2025, 12:08:45 AM
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return {};

        unordered_map<string, vector<string>> parents; // word -> list of previous words
        unordered_map<string, int> levels;             // word -> level
        queue<string> q;

        q.push(beginWord);
        levels[beginWord] = 0;

        int level = 0;
        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();
            level++;
            unordered_set<string> visitedThisLevel;

            for (int i = 0; i < size; ++i) {
                string word = q.front(); q.pop();

                string original = word;
                for (int j = 0; j < word.size(); ++j) {
                    char ch = word[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == ch) continue;
                        word[j] = c;

                        if (wordSet.count(word)) {
                            if (!levels.count(word)) {
                                levels[word] = level;
                                q.push(word);
                                visitedThisLevel.insert(word);
                            }
                            if (levels[word] == level) {
                                parents[word].push_back(original);
                            }
                            if (word == endWord) found = true;
                        }
                    }
                    word[j] = ch;
                }
            }

            // optional: remove words visited in this level from wordSet
            for (auto& w : visitedThisLevel) wordSet.erase(w);
        }

        // Now do DFS from endWord to beginWord using `parents`
        vector<vector<string>> result;
        vector<string> path = {endWord};

        function<void(string)> dfs = [&](string word) {
            if (word == beginWord) {
                reverse(path.begin(), path.end());
                result.push_back(path);
                reverse(path.begin(), path.end());
                return;
            }
            for (string& p : parents[word]) {
                path.push_back(p);
                dfs(p);
                path.pop_back();
            }
        };

        if (found) dfs(endWord);
        return result;
    }
};
