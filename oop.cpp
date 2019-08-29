#include <iostream>

using namespace std;

/*
	C++ 接口（抽象类）
	接口描述了类的行为和功能，而不需要完成类的特定实现。

	C++ 接口是使用抽象类来实现的，抽象类与数据抽象互不混淆，数据抽象是一个把实现细节与相关的数据分离开的概念。

	如果类中至少有一个函数被声明为纯虚函数，则这个类就是抽象类。纯虚函数是通过在声明中使用 "= 0" 来指定的，如下所示：
*/

class Box
{
	public:
		double getVolume(){
			return length*weight*height;
		};
		
		void setLength(double l){
			length = l;
		}
		
		void setWeight(double w){
			weight = w;
		}
		
		void setHeight(double h){
			height = h;
		}
		
		double getLength(){
			return length;
		}
		
		double getWeight(){
			return weight;
		}
		
		double getHeight(){
			return height;
		}
		
	private:
		double length;
		double weight;
		double height;
};

//基类
class Shape
{
	public:
		virtual int getArea() = 0;
		
		void setWidth(int w)
		{
			width = w;
		}
		
		void setHeight(int h)
		{
			height = h;
		}
	
	protected:
		int width;
		int height;
};

//派生类
class Rectangle : public Shape
{
	public:
		int getArea()
		{
			return width*height;
		}
};

class Triangle : public Shape
{
	public:
		int getArea()
		{
			return (width*height)/2;
		}
};


int main()
{
	Box box;
	box.setLength(10);
	box.setWeight(10);
	box.setHeight(10);
	
	cout << "Box length is :" << box.getLength() << endl;
	cout << "Box weight is :" << box.getWeight() << endl;
	cout << "Box height is :" << box.getHeight() << endl;
	cout << "Box volume is :" << box.getVolume() << endl;
	
	Rectangle rect;
	rect.setWidth(3);
	rect.setHeight(4);
	cout << "rect area is :" << rect.getArea() << endl;
	
	Triangle tri;
	tri.setWidth(3);
	tri.setHeight(4);
	cout << "tri area is :" << tri.getArea() << endl;
	
	//多态
	Shape *shape;
	shape = &rect;
	cout << "shape = &rect;" << endl;
	cout << "shape area is :" << shape->getArea() << endl;
	shape = &tri;
	cout << "shape = &tri;" << endl;
	cout << "shape area is :" << shape->getArea() << endl;
	
	
	return 0;
}

