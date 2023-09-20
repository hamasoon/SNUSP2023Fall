#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

uint64_t processDir(const char* dn) {
    unsigned long long size = 0;
    struct dirent *e;
    struct stat s;
    char *fn;
    
    DIR *d = opendir(dn);
    if (d == NULL) return 0;

    while ((e = readdir(d)) != NULL) {
        if (strcmp(e->d_name, ".") && strcmp(e->d_name, "..")) {
            if (asprintf(&fn, "%s/%s", dn, e->d_name) == -1) continue;
            if (stat(fn, &s) == 0) {
                if (S_ISREG(s.st_mode)) size += s.st_size;
                if (S_ISDIR(s.st_mode)) size += processDir(fn);
            }
            free(fn);
        }
    }

    closedir(d);
    return size;
}

int main(int argc, char *argv[])
{
    const char CURDIR[] = ".";
    const char *dn = CURDIR;
    
    // use path provided on command line
    if (argc > 1) {
        dn = argv[1];
        DIR *d;
        if ((d = opendir(dn)) == NULL) {
            printf("'%s' is not a directory.\n", dn);
            return EXIT_FAILURE;
        } else {
            closedir (d);
        }
    }
    
    // recursively enumerate directory
    uint64_t size = processDir(dn);
    
    // print size
    printf("Total size of '%s': %llu bytes\n", dn, size);
    
    return EXIT_SUCCESS;
}
