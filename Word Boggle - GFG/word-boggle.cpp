//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool search(vector<vector<char> >& board, const string& word, int index, int x,
            int y) {

    // If position of the cell is out of boundary of board or
    // letter in current cell does not match letter of word
    if (x < 0 || x == board[0].size() || y < 0 || y == board.size() ||
        word[index] != board[y][x])
        return false;

    // Base case : each character of the word has been matched
    if (index == word.length() - 1) return true;

    // mark the current cell as visited
    char cur = board[y][x];
    board[y][x] = '#';
    bool found = search(board, word, index + 1, x + 1, y)        // bottom
                 || search(board, word, index + 1, x - 1, y)     // top
                 || search(board, word, index + 1, x, y + 1)     // right
                 || search(board, word, index + 1, x, y - 1)     // left
                 || search(board, word, index + 1, x + 1, y + 1) // bottom right
                 || search(board, word, index + 1, x - 1, y + 1) // top right
                 || search(board, word, index + 1, x + 1, y - 1) // bottom left
                 || search(board, word, index + 1, x - 1, y - 1); // top left

    // revert the current cell back to its original state
    board[y][x] = cur;
    return found;
}

bool exist(vector<vector<char> >& board, string word) {
    if (board.size() == 0) return false;

    // Consider every character cell and look for all words
    // starting with this character
    for (int i = 0; i < board[0].size(); i++)
        for (int j = 0; j < board.size(); j++)
            if (search(board, word, 0, i, j)) return true;

    return false;
}

vector<string> wordBoggle(vector<vector<char> >& board,
                      vector<string>& dictionary) {
    vector<string> result;

    // Iterate through every word in the dictionary
    for (int i = 0; i < dictionary.size(); ++i) {
        string word = dictionary[i];
        if (exist(board, word)) result.push_back(word);
    }
    return result;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends