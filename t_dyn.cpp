#include <iostream>

using std::cout;
using std::endl;
class X {
	int x;
public:
	X(int v): x(v) { cout << this<<" init "<<v<<endl;};
	X(): x(0) { cout << this<<" init0"<<endl;};
	~X() { cout << this<<"("<<x<<") destroy"<<endl;};
	X(const X& y) { cout <<this<<" copy from "<<&y<<" ("<<y.x<<")"<<endl; x=y.x;};
	X& operator=(const X& y) { cout <<this<<" assigning from "<<&y<<" ("<<y.x<<")"<<endl; x=y.x;};
};

X z(const int n=56) {
	X ret=n;
	return ret;
}

X& leak(const int n=352) {
	X& ret=*new X(n);
	return ret;
}

#define P(x) cout <<#x<<endl; x;
int main() {
P(X a;);
P(X b;);
P(X c=5;);
P(b=10;);
P(X d=z(60););
P(X f=d;);
P(d=z(70););
P(b=c;);
P(b=leak(100););
P(X e=leak(110););
 cout <<"END"<<endl;
 return 0;
}
