#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

void display_permissions(const char *filename) {
    struct stat file_stat;

    if (stat(filename, &file_stat) == -1) {
        perror("Error getting file status");
        exit(1);
    }

    printf("For user : ");
    if (file_stat.st_mode & S_IRUSR) {
        printf("read ");
    }
    if (file_stat.st_mode & S_IWUSR) {
        printf("write ");
    }
    if (file_stat.st_mode & S_IXUSR) {
        printf("execute ");
    }
    printf("\n");

    printf("For group : ");
    if (file_stat.st_mode & S_IRGRP) {
        printf("read ");
    }
    if (file_stat.st_mode & S_IWGRP) {
        printf("write ");
    }
    if (file_stat.st_mode & S_IXGRP) {
        printf("execute ");
    }
    printf("\n");

    printf("For others : ");
    if (file_stat.st_mode & S_IROTH) {
        printf("read ");
    }
    if (file_stat.st_mode & S_IWOTH) {
        printf("write ");
    }
    if (file_stat.st_mode & S_IXOTH) {
        printf("execute ");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    display_permissions(filename);

    return 0;
}
