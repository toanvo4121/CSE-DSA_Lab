int foldShift(long long key, int addressSize) { 
	long long tmp = key; 
	int A[100] = {}; 
	int n = 0;
	while (tmp != 0) { 
        A[n] = tmp % 10; 
        tmp = tmp / 10; 
        n++; 
	} 
	long long sum = 0; 
	while (n>0) { 
		long long s = 0; 
		for (int i = 0; i<addressSize; i++) { 
			if (n - i - 1 >= 0) { 
				s = s * 10 + A[n - i - 1]; 
			} 
		} 
		n -= addressSize; 
		sum += s; 
	} 
	long long t = 1; 
	for (int i = 0; i<addressSize; i++) t *= 10; 
	return sum % t; 
}


int rotation(long long key, int addressSize){ 
	long long tmp = key; 
	int A[100] = {};
	int n = 0; 
	while (tmp != 0){
		A[n] = tmp % 10; 
		tmp = tmp / 10; n++; 
	} 
	tmp = A[0]; 
	for (int i = 0; i<n - 1; i++) A[i] = A[i + 1]; 
	A[n - 1] = tmp; 
	long long sum = 0; 
	while (n>0){ 
		long long s = 0; 
    	for (int i = 0; i<addressSize; i++) { 
    		if (n - i - 1 >= 0) {
    		    s = s * 10 + A[n - i - 1]; 
    		} 
    	} 
    	n -= addressSize; sum += s;
	} 
	long long t = 1; 
	for (int i = 0; i<addressSize; i++) t *= 10; 
	return sum % t;
};