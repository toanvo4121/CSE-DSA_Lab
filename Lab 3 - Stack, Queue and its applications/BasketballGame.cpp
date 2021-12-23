int baseballScore(string ops){
    /*TODO*/
    int length = ops.length();
    std::stack<int> scores;
    int top;
    
    for (int i = 0; i < length; i++) {
        if (ops[i] >= 48 && ops[i] <= 57) {
            top = (int)(ops[i] - 48);
            scores.push(top);
            continue;
        }
        else if (ops[i] == 'C') {
            if (!scores.empty()) scores.pop();
            else continue;
        }
        else if (ops[i] == 'D') {
            if (!scores.empty()) {
                top = scores.top() * 2;
                scores.push(top);
            }
            else continue;
        }
        else if (ops[i] == '+') {
            if (scores.size() >= 2 ) {
                top = scores.top();
                scores.pop();
                int newTop = scores.top() + top;
                scores.push(top);
                scores.push(newTop);
            }
            else continue;
        }
    }
    if (scores.empty()) return 0;
    else {
        int result = 0;
        while (!scores.empty()) {
            top = scores.top();
            result += top;
            scores.pop();
        }
        return result;
    }
}