#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    int fd[2],in,out,n;

    pipe(fd);

    switch(fork()){
        case -1:
            printf("\nFork Error !") ;
            exit(0);
        case 0:
            prinf("\nChild Process ");
            close(fd[0]);
            out=dup2(fd[1],STDOUT_FILENO);
            execlp("cat","cat","f1.txt",NULL);
            close(fd[1]);
            break;

        default :
            close(fd[0]);
            in=dup2(fd[0],STDIN_FILENO);
            execlp("head","head","-2",NULL);
            close(fd[0]);
    }
    close(in);
    close(out);
    return 0;
}