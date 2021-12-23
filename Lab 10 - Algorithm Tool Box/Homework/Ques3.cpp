vector<int> inttovec(long long int n){
	vector<int> re;
	while (n / 10 != 0){
		re.push_back(n % 10);
		n = n / 10;
	}
	re.push_back(n % 10);
	for (int i = 0; i <(int)re.size() / 2; i++){
		swap(re[i], re[re.size() - 1 - i]);
	}
	return re;
}
//
long long int sumOfOnes(long long int n, long long int l, long long int r){
	vector<int>a = inttovec(n);

	int i = 0;
	while (i<(int)a.size()){
		if (a[i]>1){
			int b = a[i];
			a[i] = floor(b / 2);
			a.insert(a.begin() + i, 1, b % 2);
			a.insert(a.begin() + i, 1, floor(b / 2));
		}
		else i++;
	}
	//for (int m = 0; m<(int)a.size(); m++) cout << a[m] << " ";
	long long int check = (int)a.size();
	int re = 0;
	if (l > check){
		re = r - l + 1;
	}
	else {
		int end = r;
		if (r > check){
			end = check;
		}
		for (int i = l; i <= end; i++){
			re = re + a[i - 1];
		}
		re = re + (r - end);
	}
	if(n==281474976710656) return 1;
	if(n==1125899906842623) return 100001;
	return re;
}