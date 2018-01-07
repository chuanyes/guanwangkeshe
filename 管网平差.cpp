
#include<iostream>
#include<math.h>
using namespace std;

void opp(double &x, double &y);
void op(double &h1, double &h2, double qgd[], double si[]);
double hi[30]; double q1, q2; 

int main()
{
	double qgd[30] = { 0,0,0.0035492,
		0.0035491,
		0.00238345,
		0.0035492,
		0.00198223,
		//0.00060829,
		0.00083317,
		0.00041969



	};
	double si[30] = { 0,0,
		60554.8274,
		43906.53895,
		187988.2766,
		174253.7021,
		315725.3845,
		//969561.8688,
		3187797.682,
		5171967.074

	};
	double h1 = -7.009778926;
	double h2 = -2.211815449
		;

	while (abs(h1) > 0.01||abs(h2) > 0.01)
	{
		op(h1, h2, qgd, si);

	}

	system("pause");
}
void opp(double &q1, double &q2, double x, double y)
{
	q1 = -1 * 0.000051909026226*x + -1 * 0.000007240851872*y;
	q2 = -1 * 0.00000724085187*x + -1 * 0.000053856096*y;
}
void op(double &h1, double &h2, double qgd[], double si[])
{
	int i;
	


		cout << "input q1,q2:" << endl;
		opp(q1, q2, h1,h2);
		cout << q1 << "   " << q2 << endl;
		qgd[2] += q1; qgd[3] -= q2; qgd[4] += q1; qgd[5] = qgd[5] - q1 + q2;
		qgd[6] -= q2; qgd[7] -= q1; qgd[8] -= q2;
		i = 2;

		while (i < 9)
		{
			hi[i] = si[i] * pow(qgd[i], 1.852); ++i;

		}

		h1 = (hi[2] + hi[4] - hi[7] - hi[5]);
		h2 = (hi[5] - hi[6] - hi[3] - hi[8]);
		cout << h1 << ";" << h2 << endl;
		cout << "=============================================" << endl;
		i = 2;
		while (i < 9)
		{
			cout << qgd[i] << "        " << hi[i] << endl;
			i++;
		}
		cout << "===================================================" << endl;

	

}
