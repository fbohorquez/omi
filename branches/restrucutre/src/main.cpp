#include "omi.h"

int main(int argc, char *argv[]) {
	interpreter::init(argc, argv)->run();
   _exit(0);
}
