class Solution {
public:
    bool isValid(string s) {
        stack<char> sq;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='[' || s[i]=='{' || s[i]=='(')
            {
                sq.push(s[i]);
            }
            else
            {
                if(sq.empty())
                {
                    return false;
                }
                if(s[i]==']' && sq.top()=='[')
                {
                    sq.pop();
                }
                else if(s[i]=='}' && sq.top()=='{')
                {
                    sq.pop();
                }
                else if(sq.top()=='(' && s[i]==')')
                {
                    sq.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(sq.empty())
        {
            return true;
        }
        return false;
    }
};
