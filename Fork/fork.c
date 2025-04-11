#include <stdio.h>
#include <unistd.h>

int main(){
    pid_t pid = fork();
    if(pid < 0){
        printf("Error forming a fork")
        return 1;
    } else if(pid==0){
        printf("Child process %d", getpid())
    } else{
        printf("Parent process %d, child = %d", getpid(), pid)
    }

    return 0;
}