//一楼送给永远漂亮的政和小姐姐
/* 
本段代码主要基于牛顿-拉夫森算法，对环状管网管段流量进行水利平差；
由于时间有限、本人水平有限，并未进行输入设置，导致这个小轮子非常局限（并不影响作者自己使用）；
由于未精通c++的矩阵实现，此处非常感谢@matlab提供的矩阵运算支持；
代码主要由三段函数组成：用于迭代的虚流量计算方程，用于进行闭合差运算的迭代方程，以及主（main）函数；
主函数作用为初始化hf1、hf2已经设置循环参数即闭合差（h）
代码编写及debug时间超过4小时；
中间bug报错简直逼疯我这个学环境工程的狗；
你说我一个学化工原理的怎么就写上c++代码了呢？/捂脸；
... ...
*/
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
		//录入各管段流量



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
