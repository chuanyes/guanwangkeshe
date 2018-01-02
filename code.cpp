#include <iostream>
using namespace std;

double funcation(int n, int d, int b, int c, double a[])
{
	if (n == 2)
		return (a[d - 2] + a[b - 2]) / 2;
	else
		return (a[d - 2] + a[b - 2] + a[c - 2]) / 2;
}
int main(int argc, char const *argv[])
{
	int n;
	cout<<"请输入管段数："；
	cin>>n;
	double a[n] ;
	int kk=0;
	while(kk<n)
	{
		cin>>a[kk];
		++kk;
	}
	cout<<"============================="<<endl;
	int i = 0; double sum = 0;
	int d, b, c; int n;
	while (i<12)
	{
		cin>>n >> d >> b >> c;
		sum = sum + funcation(n, d, b, c, a);
		cout << funcation(n,d, b, c,a) << endl;
		++i;
	}
	cout << sum;
	system("pause");
	return 0;

}
