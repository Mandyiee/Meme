#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/wait.h>

void moveToUsed(char *image) {
    char srcFile[400];
    char dstFile[400];

    snprintf(srcFile, sizeof(srcFile), "/meme/images/%s",image);
    snprintf(dstFile, sizeof(dstFile), "/meme/used/images/%s",image);

    rename(srcFile, dstFile);
}

void clearTheNewLibrary () {
    char *dr = "/meme/new";
    char file[200];

    struct dirent *entry;

    DIR *ic = opendir(dr);

    if (ic == NULL)
    {
        fprintf(stderr, "This program has failed to open the directory.\n");
        exit(1);
    }
    
    while ((entry = readdir(ic)))
    {
        snprintf(file, sizeof(file), "%s/%s", dr, entry->d_name);
        remove(file);
        
    }
    
    printf("The new library has been cleared \n");

}
int main()
{
    clearTheNewLibrary();
    char command[400];
    int no = 1;
    int resp;
    char* imagePath = "/meme/images";
    char path[200];

    struct dirent *entry;
    DIR *ic = opendir(imagePath);

    if (ic == NULL)
    {
        fprintf(stderr, "This program has failed to open the directory.\n");
        exit(1);
    }

    while ((entry = readdir(ic)))
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        snprintf(path, sizeof(path), "/meme/images/%s", entry->d_name);
        printf("%s\n", path);

        snprintf(command, sizeof(command), 
            "ffmpeg -loop 1 -i %s -i audio/laff.mp3 -vf 'scale=trunc(iw/2)*2:trunc(ih/2)*2' -c:v libx264 -c:a copy -shortest new/video_%d.mp4", 
            path, no);

        resp = system(command);

        if (resp == -1)
        {
            fprintf(stderr, "Error: Unable to create video clip for %s.\n", path);
            return -1;
        }

        no += 1;
        moveToUsed(entry->d_name);
    }

    closedir(ic);

    return 0;
}
