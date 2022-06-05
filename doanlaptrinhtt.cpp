#include <stdio.h>
#include <conio.h>

void nhap(double a[100][100], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			printf("Nhap a[%d][%d]: ", i + 1, j + 1);
			scanf("%lf", &a[i][j]);
		}
}
void xuat(double a[100][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\n");
		for (int j = 0; j < 2 * n; j++)
			printf("  %4.1lf", a[i][j]);
	}
}
void doidong(double a[100][100], int n, int p, int q)
{
	double k;
	for (int i = 0; i < 2 * n; i++)
	{
		k = a[p][i];
		a[p][i] = a[q][i];
		a[q][i] = k;
	}
}
void donvi(double a[100][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n; j < 2 * n; j++)
			a[i][i + n] = 1;
	}
}
double det(double a[100][100], int n)
{
	double d = 1;
	for (int i = 0; i < n; i++)
		d *= a[i][i];
	return d;
}

int main()
{
	double a[100][100], b[100][100], d;
	int n, i, j;
	printf("Nhap cap cua ma tran vuong: ");
	scanf("%d", &n);
	nhap(a, n);
	//Tao ma tran don vi
	donvi(a, n);
	printf("\n=======================================");
	printf("\n MA TRAN MO RONG (A/I)\n");
	xuat(a, n);
	printf("\n=======================================");
	printf("\n");
	//Ham giai phuong trinh
	//Dung phep BDSC dua A ve ma tran cheo
	for (i = 0; i < n; i++)
	{
		if (!a[i][i])
		{
			for (j = i + 1; j < n; j++)
			{
				if (a[j][i])
				{
					doidong(a, n, i, j);
					break;
				}
			}
			if (j == n)
			{
				printf("\n KHONG CO MA TRAN NGHICH DAO.");
				printf("\n=======================================");
				return 0;
			}
		}
		for (j = i + 1; j < n; j++)
		{
			double m = -a[j][i] / a[i][i];
			for (int k = i; k < 2 * n; k++)
				a[j][k] = a[j][k] + a[i][k] * m;
		}
	}
	printf("PHEP BIEN DOI SO CAP\n");
	xuat(a, n);
	printf("\n");
	//Tinh dinh thuc cua ma tran
	d = det(a, n);
	if (d != 0)
	{
		for (i = 0; i < n; i++)
		{
			double c = a[i][i];
			for (j = i; j < 2 * n; j++)
				a[i][j] = a[i][j] / c;
		}
		xuat(a, n);
		printf("\n");

		for (i = 0; i < n; i++)
		{
			for (int k = i + 1; k < n; k++)
			{
				double c = a[i][k];
				for (j = k; j <= 2 * n; j++)
					a[i][j] = a[i][j] - a[k][j] * c;
			}
		}
		xuat(a, n);
		for (i = 0; i < n; i++)
			for (j = n; j < 2 * n; j++)
				b[i][j - n] = a[i][j];
		//In ra ma tran nghich dao.---------------------------------------------------
		printf("\n=======================================");
		printf("\n MA TRAN NGHICH DAO CUA A:\n\n");
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
				printf("%5.1f", b[i][j]);
			printf("\n");
		}
	}
	else
		printf("\n KHONG CO MA TRAN NGHICH DAO.");
	printf("\n=======================================");
}
