#include<list>
#include<math.h>

long long helpFunc(list<int> listNumber, long long sum) {
	if (listNumber.empty()) return sum;
	sum = sum * 10 + listNumber.back();
	listNumber.pop_back();
	return helpFunc(listNumber, sum);
}

long long largestNumber(list<int> listNumber) {
	listNumber.sort();
	int sum = 0;
	return helpFunc(listNumber, sum);
}