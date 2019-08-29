#include <iostream>
#include <sstream>
#include <string>
#include<stdexcept>
#include <iterator>
#include <algorithm>

using namespace std;

template <class T> class linearlist
{
	public:
	virtual ~linearlist() {};
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual int indexOf(const T& element) const = 0;
	virtual T& get(int theIndex) const = 0;
	virtual void erase(int index) = 0;
	virtual void insert(int theIndex,const T& theElement) = 0;
	virtual void output(ostream& out) const = 0;
};

template <class T> class arraylist:public linearlist<T>
{
	protected:
	T* element;
	int arrayLength;
	int listSize;
	void checkIndex(int index)const;
	
	public:
	arraylist(int initialCapacity=10);
	arraylist(const arraylist<T>&);
	~arraylist(){delete [] element;};
	
	bool empty() const {return listSize == 0;};
	int size() const {return listSize;}
	
	int indexOf(const T& element) const;
	T& get(int theIndex) const;
	void erase(int index);
	void insert(int index,const T& theElement);
	void output(ostream& out) const;
	
	int capacity(){return arrayLength;}
};

template<class T> arraylist<T>::arraylist(int initialCapacity)
{
	if(initialCapacity<1){
		ostringstream s;
		s<<"inital capacity"<<initialCapacity<<"Must bigger than 0";
		throw s.str();
	}
	arrayLength=initialCapacity;
	element=new T[arrayLength];
	listSize=0;
}

template<class T> arraylist<T>::arraylist(const arraylist<T>& list)
{
	arrayLength = list.arrayLength;
	listSize = list.listSize;
	element=new T[arrayLength];
	copy(list.element,list.element+listSize,element);
}


template<class T> void arraylist<T>::checkIndex(int index) const
{
	if(index<0 || index>listSize){
		ostringstream s;
		s<<"index="<<index<<"size="<<listSize;
		throw s.str();
	}
}

template<class T> T& arraylist<T>::get(int index) const
{
	checkIndex(index);
	return element[index];
}

template<class T> int arraylist<T>::indexOf(const T& e) const
{
	int index = (int)(find(element,element+listSize,e)-element);
	if(index == listSize)
		return -1;
	else
		return index;
}


template<class T> void arraylist<T>::erase(int index)
{
	checkIndex(index);
	copy(element+index+1,element+listSize,element+index);
}

template<class T> void arraylist<T>::insert(int theIndex,const T& theElement)
{

	checkIndex(theIndex);
	
	if(listSize==arrayLength)
	{
		/*changeLength1D(element,arrayLength,2*arrayLength);*/
		arrayLength*=2;
	}
	copy_backward(element+theIndex,element+listSize,element+listSize+1);
	element[theIndex]=theElement;
}

template<class T> void arraylist<T>::output(ostream& out) const
{
	ostream_iterator<T> out_it (out," ");
	copy(element,element+listSize,out_it);
}

template<class T> void changeLength1D(T*& a,int oldLength,int newLength)
{
	if(newLength<0)
		throw "new length must be>=0";
	T* temp=new T[newLength];
	int number=min(oldLength,newLength);
	copy(a,a+number,temp);
	delete [] a;
	a=temp;
}

template<class T> ostream& operator<<(ostream &out,const arraylist<T>& x)
{
	x.output(out);
	return out;
}

int main(){
	arraylist<string> intList(10);
	intList.output(cout);
	cout << "size of list :" << intList.size() << endl;
	cout << "size of capacity :" << intList.capacity() << endl;
}
