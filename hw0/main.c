#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit lim;
    if(getrlimit(RLIMIT_STACK, &lim)==-1){
        printf("ERR!");
    }
    printf("stack size: %ld\n",lim.rlim_cur);
    getrlimit(RLIMIT_NPROC, &lim);
    printf("process limit: %ld\n",lim.rlim_cur);
    getrlimit(RLIMIT_NOFILE, &lim);
    printf("max file descriptors: %ld\n", lim.rlim_cur);
    return 0;
}
