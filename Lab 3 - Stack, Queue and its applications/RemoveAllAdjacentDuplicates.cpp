string removeDuplicates(string S){
    /*TODO*/
    int length = S.length();
    stack<char> myStack;
    
    for (int i = 0; i < length; i++) {
        if (myStack.empty() || S[i] != myStack.top()) 
            myStack.push(S[i]);
        else myStack.pop();
    }
    
    string result = "";
    while (!myStack.empty()) {
        result = myStack.top() + result;
        myStack.pop();
    }
    return result;
}