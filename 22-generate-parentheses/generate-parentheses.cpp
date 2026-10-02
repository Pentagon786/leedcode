

class Solution {
public:

     vector <string> result;
    void backtrake(string curr, int open, int close, int n) {
        if(curr.length() == 2*n) {
            result.push_back(curr);
            return ;
        }

        if(open < n) {
            backtrake(curr+"(",open+1,close,n);
        }

        if(close < open) {
            backtrake(curr+")", open, close+1,n);
        }

    }

    
    vector<string> generateParenthesis(int n) {
        backtrake("",0,0,n);
         return result;
    }
};