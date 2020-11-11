#include "types.h"
#include "user.h"

int main(int argc, char* argv[]) {
	int pid;
	int i,j,k;
	const int loop = 43000;
	set_tickets(10); // Default ticket count
	for(i = 0; i < 3; i++) {
		pid = fork();
		if (pid > 0) {
			continue;
		}
		else if (pid == 0) {
			set_tickets(30 - (10 * i));
			for (j = 0; j < loop; j++) {
				asm("nop");
				for (k = 0; k < loop; k++) {
					asm("nop");
				}
			}
			printf(1, "Child %d with tickets %d has finished with %d ticks\n",getpid(),30 - (10 * i), getprocessesinfo());  
			exit();
		}
		else {
			printf(2,"Error\n");
		}
	}
	if (pid > 0) {
		for (i = 0; i < 3; ++i) {
			wait();
		}
	}
	exit();
	return 0;
}

