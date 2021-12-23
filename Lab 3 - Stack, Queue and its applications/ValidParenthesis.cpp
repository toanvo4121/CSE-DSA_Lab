bool isValidParentheses (string s){
    /*TODO*/
    int length = s.length();
    if (s.length() == 0) return true;
    stack<char> myStack;
    char top;
    
    for (int i = 0; i < length; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            myStack.push(s[i]);
            continue;
        }
        
        else if (myStack.empty()) return false;
        else {
            switch (s[i]) {
            case ')':
                top = myStack.top();
                myStack.pop();
                if (top == '[' || top == '{') return false;
                break;
                
            case ']':
                top = myStack.top();
                myStack.pop();
                if (top == '(' || top == '{') return false;
                break;
            
            
            case '}':
                top = myStack.top();
                myStack.pop();
                if (top == '[' || top == '(') return false;
                break;
            }
        }
    }
    return myStack.empty();
}