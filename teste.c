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
// // }
// #include <stdio.h>
// #include "headers/server.h"
// int main ()
// {
// 	unsigned char set[] = {0b11000011, 0b10101001, '\0'};

// 	unsigned char e = 169;

// 	// é == 

// 	ft_printf("%s\n", set);
// 	ft_printf("%c\n", e);
// 	ft_printf("%c\n", 169);

// 	printf("LEN %d\n", ft_strlen("Hello e world"));
// 	printf("LEN %d\n", ft_strlen("Hello é world"));
// }
