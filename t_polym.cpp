#include <iostream>

using std::cout;
using std::endl;

struct A {
	void f() { cout << "A::f"<< endl; };
	virtual void vf() { cout << "A::vf"<< endl; };
};

struct B : public A {
	void f() { cout << "B::f"<< endl; };
	virtual void vf() { cout << "B::vf"<< endl; };
};

void tst_r(A& v) {
	cout << "by ref"<<endl;
	v.f();
	v.vf();
}

void tst_p(A *v) {
	cout << "by ptr"<<endl;
	v->f();
	v->vf();
}

void tst_v(A v) {
	cout << "by val"<<endl;
	v.f();
	v.vf();
}

int main() {
	B x;
	tst_r(x);
	tst_p(&x);
	tst_v(x);
	return 0;
}
