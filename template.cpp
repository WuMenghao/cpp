#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

/*
	C++ 模板
	模板是泛型编程的基础，泛型编程即以一种独立于任何特定类型的方式编写代码。

	模板是创建泛型类或函数的蓝图或公式。库容器，比如迭代器和算法，都是泛型编程的例子，它们都使用了模板的概念。

	每个容器都有一个单一的定义，比如 向量，我们可以定义许多不同类型的向量，比如 vector <int> 或 vector <string>。

	您可以使用模板来定义函数和类，接下来让我们一起来看看如何使用。
*/

template <class T> class Stack
{
	private:
		vector<T> elems;
	
	public:
		//入栈
		void push(T const&);
		//出栈
		void pop();
		//返回栈顶元素
		T top() const;
		//判空
		bool empty()
		{
			return elems.empty();
		}
};

template <class T> void Stack<T>::push (T const& elem)
{
	elems.push_back(elem);
}

template <class T> void Stack<T>::pop ()
{
	if(elems.empty()){
		throw out_of_range("Stack<>::pop(): empty stack");
	}
	elems.pop_back();
}

template <class T> T Stack<T>::top () const
{
	if(elems.empty()){
		throw out_of_range("Stack<>::top(): empty stack");
	}
	return elems.back();
}

int main()
{
	try{
			Stack<int> is;
			is.push(10);
			cout << "is.top() :" << is.top() << endl;
			
			Stack<string> ss;
			ss.push("hello");
			cout << "ss.top() :" << ss.top() << endl;
			ss.pop();
			ss.pop();
			
			return 0;
	}
	catch (exception const& ex)
	{
		cerr << "Exception: " << ex.what() <<endl; 
        return -1;
	}
}