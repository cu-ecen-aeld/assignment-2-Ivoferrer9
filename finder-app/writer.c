#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file> <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

  
    FILE *file = fopen(argv[1], "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Error opening file: %s", argv[1]);
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    
    fprintf(file, "%s", argv[2]);
    fclose(file);


    syslog(LOG_DEBUG, "Writing \"%s\" to %s", argv[2], argv[1]);

    return 0;
}
