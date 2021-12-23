// You can implement some helping functions here

string SpecialString(int n, int k) {
	// TODO: return a string satisfying conditions.
	string result = "";
	for (int i = 0; i < n; i++) {
	    if (i % 3 == 0) result += 'a';
	    else if (i % 3 == 1) result += 'b';
	    else result += 'c';
	}
	return result;
}