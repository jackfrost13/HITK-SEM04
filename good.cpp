#include <iostream>
using namespace std;
class D;
int c=0,c1=0;
class Swap
{
	public :
	int p,q;
	Swap(int a=0,int b=0):p(a),q(b)
	{
		cout<<"hello : "<<++c<<endl;
	}
	void show()
	{
		cout<<p<<" "<<q<<endl;
	}
	void calculate(int a=9)
	{
		cout<<a<<endl;;
	}
	void fun(Swap obj)
	{
		cout<<(obj.p+p);
		cout<<(obj.q+q)<<endl;
	}
	~Swap()
	{
		cout<<"bye : "<<--c<<endl;
	}
	friend Swap addpq(Swap p,Swap q);
};
Swap addpq(Swap q)
{
	Swap c;
	c.p=this->p+q.p;
	c.q=this->q+q.q;
	return c;
}
class D : public Swap
{
	int c;
	public :
	D()
	{
		cout<<"hello 1 : "<<++c1<<endl;
		this->c=9;
	}
	void fun(D obj){
		cout<<"SUM  : "<<c<<endl;
	}
	~D()
	{
		cout<<"bye 1 :"<<--c1<<endl;
	}
};
int main()
{
	int i;
	char *ptr[25]={"books\n","fdfdfd\n","dfdfdfv\n","dwffff\n"};
	for(i=0;i<4;i++)
		cout
		<<"bye"
		<<ptr[i]
		<<"hello";
	Swap e,f;
	e.p=f.p=10;
	f.q=e.q=10;
	Swap d =addpq(e,f);
	d.show();
}
/*
	template <typename X>
	void swapbyvalue(X a,X b)
	{
		a=a^b;
		b=a^b;
		a=a^b;i
	}
	template <typename X>
	void swapbyreference(X &a,X &b)
	{
		a=a^b;
		b=a^b;
		a=a^b;
	}
	template <typename X>
	void swapbypointer(X *a,X *b)
	{
		*a=*a^*b;
		*b=*a^*b;
		*a=*a^*b;
	}
*/