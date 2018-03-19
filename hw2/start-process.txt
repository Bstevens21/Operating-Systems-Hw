#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("'shell' is running\n");
    pid_t child_pid;
    child_pid = fork();
    
    if (child_pid == 0) {
        int j = 0;
        printf("child started\n");
        for (int i=0; i < 200000000; i++){
            j = i + 3 - j;
        }
        execl("/usr/bin/firefox","firefox",NULL);
        chdir("/Desktop");
        printf("child ended\n");
    return 3;
    } else { 
        printf("parent waiting for child\n");
        int child_status;
        waitpid(child_pid, &child_status, 0);
        printf("child exited with status %d\n", (child_status/256));
    }
    return 0;
}
