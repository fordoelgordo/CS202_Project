#include "types.h"
#include "user.h"

int numProc(void);
int numCalls(void);
int numPages(void);

int main(int argc, char* argv[])
{
	printf(1, "***************************************\n");
	printf(1, "Test harness for lab 1 xv6 code changes\n");
	printf(1, "***************************************\n");
	// Run the test functions, each of which will call the system call info(int n) with paremeters 1, 2 and 3 respectively
	if (atoi(argv[1]) == 1) {
		printf(1, "Before we do any forking, check processes currently running\n");
		print_proc();
        	printf(1, "The current number of system proccesses is: %d\n", info(1));
		numProc();
	}
        else if (atoi(argv[1]) == 2) {	
		printf(1, "Testing the number of system calls a proc makes\n");
		numCalls();
	}
	else if (atoi(argv[1]) == 3) {
		printf(1, "Testing the number of memory pages in the proc\n");
		numPages();
	}
	else {
		printf(1, "Type lab1 1 to test process count, lab1 2 to test system calls made and lab1 3 to test number of memory pages\n");
	}
	exit();
	return 0;
}

int numProc(void) {
	int pid, pid2;
	
	// This function will spawn a few different processes, then call the system call to print the number of processes in the system
	printf(1, "Testing the number of processes there are in the system\n");
	printf(1, "Begin forking\n");
	pid = fork(); // First fork the process
	if (pid == 0) { 
		// In the child, fork again
		printf(1, "Forking again\n");
		pid2 = fork();
		if (pid2 == 0) {
			// In second child, begin tracking
			print_proc();
			printf(1, "In process with pid %d, there are %d proccesses in the system\n", getpid(), info(1));
		}
		else if (pid2 > 0) {
		 	// In parent, print counts
		 	wait();
			print_proc();
			printf(1, "In parent with pid %d, there are %d processes in the system\n", getpid(), info(1));
		}
		else {
			exit();
		}
	}
	else if (pid > 0) {
		// In original parent
		wait();
		print_proc();
		printf(1, "In parent with pid %d, there are %d processes in the system\n", getpid(), info(1));
	}
	else {
		exit();
	}

	return 0;
}
int numCalls(void) {
	int i;
	int cur = info(2);
	printf(1, "Current number of system calls made by proc: %d\n", cur);
	printf(1, "We'll call getpid() a few times, and expect the system call count to increase quite a bit, as calling printf requires lots of writes\n");
	for (i = 0; i < 4; ++i) {
		getpid(); // Call getpid which is a system call
	}
	printf(1, "Made the system calls, we now have %d system calls associated with the proc\n", info(2));

	return 0;
}
int numPages(void) {
	printf(1, "Current process is using %d pages\n", info(3));
	printf(1, "We'll grow the process by 5 pages using an added system call growproc\n");
	growproc(5);
	printf(1, "Process is now using %d pages\n", info(3));

	return 0;
}
