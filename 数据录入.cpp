//一楼送给永远可爱的达芬奇小姐姐；
/*
本段代码主要实现管网系统课设的前端数据录入的自动化；
为后期平差运算节省时间；
然而，部分小伙伴疯狂报错我也没办法，大概这是他们没安装宇宙最强IDE的结果吧（其实，是该段代码对输入格式要求比较奇怪）；
因为并未掌握c++环境下的GUI编程，在涉及管网拓扑学的知识时，还需要手动配置；
第一次用github啊；
虽然我还不知道git是个什么鬼；
只是知道这里可以托（zhuang）管（bi）代码；
果然科学是第一生产力啦；
大神请无视；
... ...
*/
#include <iostream>
using namespace std;

double funcation(int n, int d, int b, int c, double a[])
{
	if (n == 2)
		return (a[d] + a[b]) / 2;
	else if (n == 3)
		return (a[d] + a[b] + a[c]) / 2;
	else
		return a[d] / 2;
}
int main(int argc, char const *argv[])
{
	
	cout << "请输入用户数(cap):";
	double yonghu;
	cin >> yonghu;
	cout << "请输入人均综合用水量(L/cap·d)：";
	double yongshui;
	cin >> yongshui;
	cout << "请输入绿化用水量(L/s)：";
	double lvhua;
	cin >> lvhua;
	double Qmax = ((yongshui*yonghu/86400)+lvhua)* 1.45;
	cout << "取小时变化系数 K=1.45" << endl
		<< "==========================================================================" << endl 
		<< "q=" << Qmax<< endl;


	cout << "请输入管段数："; int nc;
	cin >> nc;
	cout << "请依次输入管段长度："<<endl;
	double guanduan[30];
	int guanduan_ = 2; double guanduanzc = 0;
	while (guanduan_<= nc)
	{
		cin >> guanduan[guanduan_];
		guanduanzc +=guanduan[guanduan_] ;
		guanduan_++;

	}
	cout<<"管段总长为："<< guanduanzc <<endl;

	double biliuliang;
	biliuliang = Qmax / guanduanzc;
	cout << "比流量为：" << biliuliang << endl<<
		"==========================================================================="<<endl;
	double yanxian[30];
	int i; double temp = 0;
	for (i = 2; i <= nc; ++i)
	{
		yanxian[i] = biliuliang*guanduan[i];
		temp += yanxian[i];
		cout << "管段[" << i << "] = " << yanxian[i] << endl;
	}
	cout << temp << endl;
	cout << "============================================================================"<<endl;





	cout << "请输入节点数：";
	int jie;
	cin >> jie;
	
	
	cout << "===========================================================================" << endl 
		<< "输入与各节点想连管段数（一般节点相邻管道非2即3），  所以输出格式务必如下："   << endl<<endl
		<< "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"  << endl <<endl
		<< "         1		管段1		0		    0" <<endl
		<< "         2		管段1		管段2		0" <<endl
		<< "         3		管段1		管段2		管段3"<< endl <<endl
		<< "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"  << endl;
	 i = 2; double sum = 0;
	int d, b, c; int n;
	double jiedian[100];
	while (i<=jie)
	{
		cin >> n >> d >> b >> c;
		jiedian[i] = funcation(n, d, b, c, yanxian);
		sum = sum + funcation(n, d, b, c, yanxian);
		
		++i;
	}
	i = 2;
	while (i <= jie)
	{
		cout << "节点(" << i << ")流量=" << jiedian[i]<<endl;
		i++;
	}
	cout << sum<<endl;


	cout << "Copyright@kttor" << endl;
	system("pause");
	return 0;

}
