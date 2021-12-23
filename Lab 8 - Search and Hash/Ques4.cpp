long int midSquare(long int seed)
{
    int square=seed*seed;
    return (square/100)%10000;
}
long int moduloDivision(long int seed, long int mod)
{
    return seed%mod;
}
long int digitExtraction(long int seed,int* extractDigits,int size)
{
    int add=0;
	int e=0;
    int t_seed=seed;
    int s_size=0;
    while(t_seed>0){
        t_seed/=10;
        s_size++;
    }
    for(int i=0; i<size; i++){
		int modi= pow(10, s_size - extractDigits[i]);
        e= ((seed%modi)-(seed%(modi/10)))/(modi/10);
		e*=pow(10, size-i-1);
		add+=e;
    }
	return add;
}