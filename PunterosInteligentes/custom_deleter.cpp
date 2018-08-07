//  custom_deleter.cpp

#include <cstdio>
#include <memory>
#include "strc.h"

// display object value from shared_ptr (with reference count)
void disp(const std::shared_ptr<strc> & o);

void deleter(const strc * o) {
	printf("deleter: ");
	if (o) printf("%s\n", o->value());
	else printf("[null]\n");
	fflush(stdout);
	delete o;
}

void deleter_actions() {
	puts("CUSTOM DELETER");
	puts("--------------");

	message("create shared_ptr");
	std::shared_ptr<strc> a(new strc("thing"), &deleter);
	disp(a);

	a.reset();
	disp(a);

	message("end of scope");
}
