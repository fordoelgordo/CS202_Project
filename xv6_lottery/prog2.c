#include "types.h"
#include "stat.h"
#include "user.h"
#include "proc.h"
#include "param.h"
#include "mmu.h"

int main(int argc, char* argv[])
{
	// Set the number of tickets for the process
	struct processes_info p;
	set_tickets(400);
	int i,k;
	const int loop = 43000;
	for (i = 0; i < loop; ++i) {
		asm("nop");
		for (k = 0; k < loop; ++k) {
			asm("nop");
		}
	}
	// Scheduling statistics can be printed via procdump
	getprocessesinfo(&p);
	exit();

	return 0;
}
