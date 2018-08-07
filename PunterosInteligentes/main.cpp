#include "strc.h"
#include <memory>

int main(int argc, const char ** argv) {
	
	unique_actions();
	puts("");

	shared_actions();
	puts("");

	weak_actions();
	puts("");

	deleter_actions();

	return 0;
}