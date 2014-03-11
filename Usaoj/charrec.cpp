/*
    ID : jake1994
    PROG : charrec
    LANG : C++
*/
#include <stdio.h>
#include <string.h>
 
const char LETTER[] = " abcdefghijklmnopqrstuvwxyz";
 
int bit[1049000] = {0};
long a[27][20], b[1201];
int n;
 
char c[1201][3];
long f[1201], g[1201][3];
int prev[1201];
 
long i, j;
int k, l, p;
 
inline void scan(long &x) {
	for (x = 0, j = 0; j < 20; ++j) (x <<= 1) |= getchar() == '1';
	scanf("\n");
}
 
void print(const int x) {
	if (!x) return ;
	print(prev[x]);
	printf("%c", c[prev[x] + 1][x - prev[x] - 19]);
}
 
int main() {
	freopen("font.in", "rt", stdin);
	scanf("%*d\n");
	for (i = 0; i < 540; ++i) scan(a[i / 20][i % 20]);
 
	freopen("charrec.in", "rt", stdin);
	freopen("charrec.out", "wt", stdout);
	scanf("%d\n", &n);
	for (i = 1; i <= n; ++i) scan(b[i]);
 
	memset(g, 53, sizeof g);
	for (i = 1; i < 1048576; ++i) bit[i] = bit[i >> 1] + (i & 1);//算一个数字有多少位1 
	for (l = 1; l <= n; ++l) {
		if (l + 18 <= n)
			for (k = 0; k < 20; ++k) // 枚举比较时“删除”标准模板的哪一行
				for (i = 0; i < 27; ++i) {
					for (p = 0, j = 0; j < 20; ++j)
						if (j != k) p += bit[a[i][j] ^ b[l + j - (j > k)]];
					if (g[l][0] > p) g[l][0] = p, c[l][0] = LETTER[i];
				}
		if (l + 19 <= n)
			for (i = 0; i < 27; ++i) {
				for (p = 0, j = 0; j < 20; ++j) p += bit[a[i][j] ^ b[l + j]];
				if (g[l][1] > p) g[l][1] = p, c[l][1] = LETTER[i];
			}
		if (l + 20 <= n) 
			for (k = 0; k < 21; ++k) // 枚举比较时“删除”字符图案的哪一行
				for (i = 0; i < 27; ++i) {
					for (p = 0, j = 0; j < 21; ++j)
						if (j != k) p += bit[a[i][j - (j > k)] ^ b[l + j]];
					if (g[l][2] > p) g[l][2] = p, c[l][2] = LETTER[i];
				}
	}
 
	memset(f, 53, sizeof f), f[0] = 0;
	for (i = 19; i <= n; ++i) {
		f[i] = f[i - 19] + g[i - 18][0], prev[i] = i - 19;
		if (i >= 20 && f[i] > (j = f[i - 20] + g[i - 19][1])) f[i] = j, prev[i] = i - 20;
		if (i >= 21 && f[i] > (j = f[i - 21] + g[i - 20][2])) f[i] = j, prev[i] = i - 21;
	}
	print(n), printf("\n");
	return 0;
}
