// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <signal.h>

// void sighandler(int);

// int main(void)
// {
// 	int pid = getpid();
// 	printf("PID: %d\n", pid);
// 	signal(SIGINT, sighandler);

// 	int i = 0;
// 	while(!sleep(1) && printf("I: %d\n", i++)) 
// 		if (i == 4)
// 			kill(pid, SIGINT);

// }

// void sighandler(int signum) {

// 	printf("Caught signal %d, coming out...\n", signum);
// 	sleep(1);
// 	exit(1);
// }