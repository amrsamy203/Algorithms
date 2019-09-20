//prime power in (n!) 
long long count_p_in_nfact(long long p, long long n) { // O(log n)
	long long res = 0;
	long long q = p;
	while (q <= n) {
		res += n / q;
		q *= p;
	}
	return res;
}
