#include "types.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"
#include "user.h"

int main(void) {
	struct processes_info inf;
	getprocessesinfo(&inf);
	printf(1, "%d running processes\n", inf.num_processes);
	printf(1, "PID\tTICKETS\tTICKS\n");
	
	int i;
	for (i = 0; i < inf.num_processes; ++i) {
		printf(1, "%d\t%d\t%d\t", inf.pids[i], inf.tickets[i], inf.ticks[i]);
	}
	exit();

	return 0;
}
