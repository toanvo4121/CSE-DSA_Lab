int minWaitingTime(int n, int arrvalTime[], int completeTime[]) {
    // YOUR CODE HERE
    int sumWait = 0;
    int preTime = 0;
    
    while (n != 0) {
        int index = 0;
        bool isWaiting = false;
        for (int i = 0; i < n; ++i) {
            if (arrvalTime[i] <= preTime) {
                if (isWaiting == false) {
                    index = i;
                    isWaiting = true;
                }
                else {
                    if (completeTime[i] < completeTime[index]) {
                        index = i;
                    }
                }
            }
        }
        if (isWaiting == true) {
            preTime = preTime + completeTime[index];
            sumWait = sumWait + preTime - arrvalTime[index];
            swap(completeTime[index], completeTime[n - 1]);
            swap(arrvalTime[index], arrvalTime[n - 1]);
            n--;
        }
        else {
            preTime = arrvalTime[0];
            for (int i = 1; i < n; i++) {
                if (arrvalTime[i] < preTime) {
                    preTime = arrvalTime[i];
                }
            }
        }
    }
    return sumWait;
}