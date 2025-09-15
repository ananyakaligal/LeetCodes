// Last updated: 9/16/2025, 12:06:36 AM
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string,int>> q;
        q.push({startGene,0});
        unordered_set <string> s(bank.begin(),bank.end());
        if (!s.count(endGene)) return -1;
        vector<char> choices = {'A', 'C', 'G', 'T'};
        
        while(!q.empty()){
            auto [word,len]=q.front();
            q.pop();

            if(word==endGene) return len;

            for(int i=0;i<word.size();i++){
                char ch=word[i];
                for(int x=0;x<4;x++){
                    word[i]=choices[x];
                    if(s.find(word)!=s.end()){
                        q.push({word,len+1});
                        s.erase(word);
                    }
                }
                word[i]=ch;
            }
        }
        return -1;
    }
};