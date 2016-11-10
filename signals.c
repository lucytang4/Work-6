/*
◾Runs constantly inside a forever while loop.
◾Print out the process' PID inside the loop.
◾Use the sleep(1) function to have the program wait 1 second between inner loop iterations.
◾Catch the following signals
◾SIGINT
◾Before exiting, append a message to a file noting that the program exited due to SIGINT
◾To make your program quit, look up the exit function.
◾SIGUSR1
◾Print out the PID of the parent process.
◾Should not cause the program to exit.
*/

#include <stdio.h>
#include <stdlib.h>

#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

static void sighandler (int signo){
    if (signo == SIGINT){
        int a = open("file.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
        write(a, "Exited due to SIGINT\n", 21);
        close(a);
        exit(0);
    }
    else if (signo == SIGUSR1)
        printf("Parent Process' PID : %d\n", getppid());
}

int main(){
    signal(SIGINT,sighandler);
    while (1){
        printf("Process' PID : %d\n", getpid());
        sleep(1);
    }
    return 0;
}