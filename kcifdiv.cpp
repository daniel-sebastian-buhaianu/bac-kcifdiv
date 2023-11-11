#include <fstream>
#include <iostream>
using namespace std;
ofstream fout("bac.txt");
int zeceLaPuterea(int);
int cmmdc(int, int);
long long cmmmc(int, int);
int main()
{
	int n, m, k, x, cmin, cmax, i;
	long long mc;
	cin >> n >> m >> k;
	mc = cmmmc(n, m);
	x = zeceLaPuterea(k-1);
	cmin = (x % mc == 0) ? x/mc : x/mc + 1;
	cmax = (zeceLaPuterea(k)-1)/mc;
	for (i = cmin; i <= cmax; i++)
		fout << mc*i << '\n';
	fout.close();
	return 0;
}
int zeceLaPuterea(int p)
{
	if (p == 0) return 1;
	return 10 * zeceLaPuterea(p-1);
}
int cmmdc(int a, int b)
{
	while (b)
	{
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}
long long cmmmc(int a, int b)
{
	return (long long)(a/cmmdc(a,b) * b);
}
