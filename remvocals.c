#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    char header[44];
    short leftRight[2];
    short combined[2];

    if ( argc != 3) {
        perror("wrong number of args");
        exit(EXIT_FAILURE);
    }
    
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        perror("input incorrect");
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        perror("input incorrect");
        exit(EXIT_FAILURE);
    }
    
    /*write the header */
    fread(header, 1, 44, input);
    fwrite(header, 1, 44, output);
    
    
    while (fread(leftRight, sizeof(short), 2, input) == 2) {
        combined[0] = (leftRight[0]-leftRight[1])/2;
        combined[1] = combined[0];
        fwrite(combined, sizeof(short), 2, output);
    }
    
    
    fclose(input);
    fclose(output);
    return 0;
}
