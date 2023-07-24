#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        return 1;
    }

    FILE *outfile = NULL;

    int image_count = 0;
    BYTE *buffer = malloc(BLOCK_SIZE);

    while(fread(buffer, 1, BLOCK_SIZE, infile) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            if (outfile != NULL)
            {
                fclose(outfile);
                outfile = NULL;
            }

            char filename[10];
            sprintf(filename, "%03d.jpg", image_count);
            outfile = fopen(filename, "w");
            image_count++;
        }

        if (outfile != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, outfile);
        }
    }

    fclose(infile);
    free(buffer);

    printf("%i", image_count);
}