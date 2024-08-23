#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        exit(1);
    }

    int n = atoi(argv[1]);
    int ancestor_pid = getancestor(n);

    if (ancestor_pid == -1) {
        printf("-1\n");
    } else {
        printf("The PID of the ancestor %d is %d\n", n, ancestor_pid);
    }

    exit(0);
}
