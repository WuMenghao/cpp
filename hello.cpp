#include <iostream>
#include <ctime>

using namespace std;

// 声明变量 全局变量
extern int count;

// 常量定义
#define LENGTH 10
#define WIDTH 5
#define NEWLINE '\n'

// 定义宏(全局函数)
#define MIN(a,b) ((a<b) ? a : b)

const char NAME[10] = "WuMenghao";
const int AGE = 25;
const string  SAY_HELLO = "Hello!";

int main()
{
	/*基本数据类型*/
	cout << "Hello world \n";
	cout << 1+2 << endl;
	cout << "Size of char : " << sizeof(char) << endl;
	cout << "Size of int : " << sizeof(int) << endl;
	cout << "Size of short int : " << sizeof(short int) << endl;
	cout << "Size of long int : " << sizeof(long int) << endl;
	cout << "Size of float : " << sizeof(float) << endl;
	cout << "Size of double : " << sizeof(double) << endl;
	cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
	cout << "Size of unsigned int : " << sizeof(unsigned int) << endl;
	
	/*枚举*/
	enum color {red , green ,blue} color;
	color = red;
	cout << "value of enum color :" << color << endl;
	
	/*变量定义与初始化 局部变量*/
	int count = 1 , all = 2 , size = 3;
	char ch = 'A';
	float salary = 1000.05;
	double quality = 500000.05;
	bool isGreate = true;
	cout << "int count = " << count << endl;
	cout << "int all = " << all << endl;
	cout << "int size = " << size << endl;
	cout << "char ch = " << ch << endl;
	cout << "float salary = " << salary << endl;
	cout << "double quality = " << quality << endl;
	cout << "bool isGreate = " << isGreate << endl;
	
	/*常量*/
	cout << "LENGTH :" << LENGTH << endl;
	cout << "WIDTH :" << WIDTH << endl;
	cout << "NEWLINE :" << NEWLINE << endl;
	cout << "NAME :" << NAME << endl;
	cout << "AGE :" << AGE << endl;
	cout << "SAY_HELLO :" << SAY_HELLO << endl;
	
	/*while循环*/
	int  i = 0;
	while( i <= 10 ){
		cout << "the value of i :" << i << endl;
		i ++;
	}
	
	/*for循环*/
	for( int i1 = 0; i1<= 10; i1++ ){
		cout << "the value of i1 :" << i1 << endl;
	}
	
	/*指针*/
	int obj = 20;
	int *objPoint = &obj;
	
	cout << "value of &obj :" << &obj << endl;
	cout << "value of *objPoint :" << objPoint << endl;
	cout << "value of obj :" << obj << endl;
	
	/*指针变量数值*/
	int ten[10] = {0,1,2,3,4,5,6,7,8,9};
	for( int i = 0; i <= 10; i++ ){
		int *p = &ten[i];
		if( i == 10 ){
			//修改指针对应内存区域的值
			*p = 20;
		}
		cout << "point value of ten[" << i << "] :" << &ten[i] << endl;
		cout << "value of i :" << i << endl;
		cout << "*p:" << *p << endl;
	}
	
	/*引用*/
	int x;
	int y;
	int& n = x;
	int& m = y;
	n = 1;
	m = 2;
	cout << "value of x :" << x << endl;
	cout << "value of y :" << y << endl;
	cout << "value of n :" << n << endl;
	cout << "value of m :" << m << endl;
	cout << "value of &x :" << &x << endl;
	cout << "value of &y :" << &y << endl;
	cout << "value of &n :" << &n << endl;
	cout << "value of &m :" << &m << endl;
	
	/*时间*/
	time_t now = time(0);
	char* now_str = ctime(&now);
	tm *now_tm = gmtime(&now);
	char* now_str1 = asctime(now_tm);
	cout << "value of now :" << now << endl;
	cout << "value of now_str :" << now_str << endl;
	cout << "value of *now_tm :" << now_tm << endl;
	cout << "value of now_str1 :" << now_str1 << endl;
	
	/*使用宏
		系统宏
		_LINE__	这会在程序编译时包含当前行号。
		__FILE__	这会在程序编译时包含当前文件名。
		__DATE__	这会包含一个形式为 month/day/year 的字符串，它表示把源文件转换为目标代码的日期。
		__TIME__	这会包含一个形式为 hour:minute:second 的字符串，它表示程序被编译的时间。
	*/
	int a , b;
	a = 100;
	b = 30;
	cout << "The minimum is :" << MIN(a,b) << endl;
	cout << "Value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;
	
   return 0;
}