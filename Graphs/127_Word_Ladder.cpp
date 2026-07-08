/*
LeetCode 127

Problem:
Word Ladder

Topic:
Graph, Breadth-First Search (BFS)

Approach:
Treat each word as a node in an implicit graph.

Starting from beginWord, generate all possible words by
changing one character at a time. If a generated word
exists in the dictionary and has not been visited, add it
to the BFS queue.

Since BFS explores level by level, the first time we reach
endWord gives the shortest transformation sequence.

Time Complexity: O(N × L × 26)
Space Complexity: O(N)

where:
N = number of words
L = length of each word
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> words(wordList.begin(), wordList.end());

        if (!words.count(endWord))
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {

            auto [word, level] = q.front();
            q.pop();

            if (word == endWord)
                return level;

            for (int i = 0; i < word.size(); i++) {

                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    word[i] = ch;

                    if (words.count(word) && !visited.count(word)) {
                        visited.insert(word);
                        q.push({word, level + 1});
                    }
                }

                word[i] = original;
            }
        }

        return 0;
    }
};
