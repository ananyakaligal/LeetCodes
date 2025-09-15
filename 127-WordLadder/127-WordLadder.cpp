// Last updated: 9/16/2025, 12:08:44 AM
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set <string> s(wordList.begin(),wordList.end());
        
        while(!q.empty()){
            auto [word,len]=q.front();
            q.pop();

            if(word==endWord) return len;

            for(int i=0;i<word.size();i++){
                char ch=word[i];
                for(char x='a';x<='z';x++){
                    word[i]=x;
                    if(s.find(word)!=s.end()){
                        q.push({word,len+1});
                        s.erase(word);
                    }
                }
                word[i]=ch;
            }
        }
        return 0;
    }
};