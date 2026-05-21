#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        string word = "";
    };

    void insert(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* curr, vector<string>& result) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        
        char c = board[i][j];
        if (c == '#' || !curr->children[c - 'a']) return;
        
        curr = curr->children[c - 'a'];
        if (!curr->word.empty()) {
            result.push_back(curr->word);
            curr->word = ""; 
        }

        board[i][j] = '#';
        dfs(board, i + 1, j, curr, result);
        dfs(board, i - 1, j, curr, result);
        dfs(board, i, j + 1, curr, result);
        dfs(board, i, j - 1, curr, result);
        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& w : words) {
            insert(root, w);
        }
        
        vector<string> result;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }
        
        return result;
    }
};