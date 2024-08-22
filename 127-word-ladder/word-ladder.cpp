class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> list(wordList.begin(), wordList.end());
        queue<pair<string, int>> q; //{string, steps}
        
        q.push({beginWord, 1});
        list.erase(beginWord);

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == endWord) {
                return steps;
            }

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (list.find(word) != list.end()) {
                        q.push({word, steps + 1});
                        list.erase(word);
                    }
                }

                word[i] = original;
            }
        }

        return 0;
    }
};