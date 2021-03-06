//  shared_ptr.cpp

#include <memory>
#include "strc.h"

// display object value from shared_ptr (with reference count)
void disp(const std::shared_ptr<strc> & o) {
	if (o) printf("%s (%ld)\n", o->value(), o.use_count());
	else puts("[null]");
	fflush(stdout);
}

void shared_actions() {
	puts("SHARED POINTERS");
	puts("---------------");

	message("create pointer with new");
	auto a = std::make_shared<strc>("new");
	disp(a);

	std::shared_ptr<strc> x(new strc("foo"));
	disp(x);

	auto x1 = a;
	auto x2 = a;
	auto x3 = a;
	auto x4 = a;
	disp(a);

	x1.reset();
	x2.reset();
	x3.reset();
	x4.reset();
	disp(a);

	message("reset a to one");
	a.reset(new strc("one"));
	disp(a);

	message("b = a");
	auto b = a;
	disp(a);
	disp(b);

	printf("a == b %s\n", a == b ? "true" : "false");
	printf("*a == *b %s\n", *a == *b ? "true" : "false");

	message("reset a to two");
	a.reset(new strc("two"));
	disp(a);
	disp(b);

	printf("a == b %s\n", a == b ? "true" : "false");
	printf("*a == *b %s\n", *a == *b ? "true" : "false");

	message("b.swap(a)");
	b.swap(a);
	disp(a);
	disp(b);

	message("std::swap");
	std::swap(*a, *b);
	disp(a);
	disp(b);

	message("end of scope");
}
