#include <iostream>

using std::cout;
using std::endl;
class X {
	int x;
public:
	X(int v=-1): x(v) { cout << this<<" init "<<v<<endl;};
	//X(int v=0): x(0) { cout << this<<" init0"<<endl;};
	~X() { cout << this<<"("<<x<<") destroy"<<endl;};
	X(const X& y) { cout <<this<<" copy from "<<&y<<" ("<<y.x<<")"<<endl; x=y.x;};
	X& operator=(const X& y) { cout <<this<<" assigning from "<<&y<<" ("<<y.x<<")"<<endl; x=y.x; return *this;};
};

X z(const int n=56) {
	X ret=n;
	return ret;
	//return n;
	//return X(X(X(X(X(X(ret))))));
}

X& leak(const int n=352) {
	X& ret=*new X(n);
	return ret;
}

#define TRACE(...) cout <<"\t"<<#__VA_ARGS__<<endl; __VA_ARGS__
int main() {
TRACE(X a,b,c=5;)
TRACE(b=10;)
TRACE(X d=z(60);)
TRACE(X f=d;)
TRACE(d=z(70);)
TRACE(b=c;)
TRACE(b=leak(100);)
TRACE(X e=leak(110);)
 cout <<"END"<<endl;
 return 0;
}
