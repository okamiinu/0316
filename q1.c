#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
        int x = 111;
        printf("set x = %d, (pid:%d)\n", x, (int)getpid());
        int rc = fork();
        if (rc < 0) {
                fprintf(stderr, "fork Error!");
                exit(1);
        } 
	else if (rc == 0) {
                printf("child x = %d (pid:%d)\n", x, (int)getpid());
                x = 222;
                printf("child after changed x = %d (pid:%d)\n", x, (int)getpid());
        } 
	else {
                printf("parent x = %d (pid:%d)\n", x, (int)getpid());
                x = 333;
                printf("parent after changed x = %d (pid:%d)\n", x, (int)getpid());
        }
        return 0;
}

