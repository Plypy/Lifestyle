/*
ID: jake1994
LANG: C++
TASK: dualpal
*/

#include <stdio.h>
 
int Check(int x, int base)
{
	static const char code[] = "0123456789";
	static char buff[20];
	char *p = buff, *q = buff;
	for (; *q++ = code[x%base], x /= base; );
	for (; p < --q; ++p)
		if (*p != *q)
			return 0;
	return 1;
}
 
int main()
{
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);
	int m, n;
	scanf("%d%d", &n, &m);
	for (; ++m, n; )
	{
		int cnt = 0;
		for (int base = 2; base <= 10; ++base)
			cnt += Check(m, base);
		if (cnt >= 2)
		{
			--n;
			printf("%d\n", m);
		}
	}
}
