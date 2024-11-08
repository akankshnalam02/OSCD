#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main() {
    int shm_id = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    char *shm_ptr;
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    if (fork() == 0) {
        // Writer process
        shm_ptr = (char *)shmat(shm_id, NULL, 0);
        if (shm_ptr == (char *)(-1)) {
            perror("shmat");
            exit(1);
        }
        strncpy(shm_ptr, "Hello from the writer process!", 1024);
        printf("Writer: Wrote to shared memory: %s\n", shm_ptr);
        shmdt(shm_ptr);
        exit(0);
    }
    else {
        // Reader process
        wait(NULL);
        shm_ptr = (char *)shmat(shm_id, NULL, 0);
        if (shm_ptr == (char *)(-1)) {
            perror("shmat");
            exit(1);
        }
        printf("Reader: Read from shared memory: %s\n", shm_ptr);
        shmdt(shm_ptr);
        shmctl(shm_id, IPC_RMID, NULL);
    }

    return 0;
}

