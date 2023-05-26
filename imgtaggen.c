/*
 * filename: imgtaggen.c
 * ---------------------
 * Generate a list of html tags
 * output can be piped into a file
 *
 * Author: Mason Armand
 * Date Created: May 25, 2023
 * Last Modified: May 25, 2023
 */
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

bool is_image(char* filename);


int main(int argc, char** argv)
{
        struct dirent* ent;
        DIR* dir;

        if (argc < 2) {
                printf("Usage: %s <directory>\n", argv[0]);
                return 0;
        }

        dir = opendir(argv[1]);
        if (dir == NULL) {
                fprintf(stderr, "Could not open current directory.\n");
                return 1;
        }

        while ((ent = readdir(dir)) != NULL) {
                if (is_image(ent->d_name))
                {
                        printf("<img src='%s'>\n", ent->d_name);
                }
        }

        closedir(dir);
        return 0;
}


bool is_image(char* filename)
{
        const char* image_ext[] = {
                ".jpg",
                ".jpeg",
                ".jfif",
                ".png",
                ".webp",
                ".gif",
                ".svg",
                ".avif",
                NULL
        };
        char* ext = strrchr(filename, '.');
        unsigned int i = 0;

        if (!ext)
                return false;

        while (image_ext[i] != NULL) {
                if (strcasecmp(ext, image_ext[i]) == 0) {
                        return true;
                }
                i++;
        }

        return false;
}
