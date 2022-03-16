#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<string.h>
int main()
{
        int f = open("./5.2.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
        int rc = fork();
        if (rc < 0) {
                fprintf(stderr,"fork Error!");
                close(f);
                exit(1);
        }
    	else if (rc == 0) {
                char * s = "child wrote something here\n";
                write(f, s, strlen(s));
        }
    	else {
                char * s = "parent come here to check\n";
                write(f, s, strlen(s));
                wait(NULL);
                close(f);
        }
        return 0;
}

