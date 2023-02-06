#include <stdio.h>
#include <sys/fcntl.h>

int main(int argc, char *argv[]) {

    //Declare files
    FILE* copyFrom;
    FILE* copyTo;

    //  If argc != 3 reject
    if (argc != 3) {
        printf("Please enter the file you want to copy and the file where you want to copy it\n");
        return 0;
    }

    //  Make sure that the file exists
    int fileStatus = open(argv[1], O_RDONLY);
    if (fileStatus == -1) {
        printf("The specified file doesn't exist\n");
        return 0;
    }

    //  Open copyFrom in reader mode
    copyFrom = fopen(argv[1], "r");

    //  Open copyTo in write mode
    copyTo = fopen(argv[2], "w");

    // Copy from copyFrom to copyTo
    char ch = fgetc(copyFrom);
    while (ch != EOF){
        fprintf(copyTo, "%c", ch);
        ch = fgetc(copyFrom);
    }

    // close files
    fclose(copyFrom);
    fclose(copyTo);
}
