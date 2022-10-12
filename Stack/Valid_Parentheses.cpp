class Solution {
public:
    bool isValid(string s) {
        stack<char>st; //taking stack for keep tracking the order of the brackets..
        for(int i=0;i<s.length();++i) //iterate over each and every elements
        {
            if(s[i]=='{'||s[i]=='('||s[i]=='[') st.push(s[i]); //if current element of the string will be opening bracket then we will just simply push it into the stack
            else  //if control comes to else part, it means that current element is a closing bracket, so check two conditions  current element matches with top of the stack and the stack must not be empty...
            {
                if(st.empty()||(st.top()=='('&&s[i]!=')')||(st.top()=='{'&&s[i]!='}')||(st.top()=='['&&s[i]!=']')) return false;
                st.pop(); //if control reaches to that line, it means we have got the right pair of brackets, so just pop it.
            }
        }
        return st.empty(); //at last, it may possible that we left something into the stack unpair so return checking stack is empty or not..
    }
};
