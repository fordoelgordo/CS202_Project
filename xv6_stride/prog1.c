#include "types.h"
#include "user.h"

int main(int argc, char* argv[])
{
	set_tickets(30);
	int i,k;
	const int loop = 43000;
	for (i = 0; i < loop; ++i) {
		for (k = 0; k < loop; ++k) {
			asm("nop");
		}
		if (i % 5000 == 0) {
			printinfo();	
		}
	}
	exit();

	return 0;
}
