#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <malloc.h>
#include <errno.h>
#include <stdint-gcc.h>


void print_file(FILE *fp);
bool search_in_file(FILE *fp, char *str);

void check_process_file(){
    const char* fileName = "C:\\Users\\fang2\\PE-1.txt";
    char str[] = "I want to learn PE format!";

    if (access(fileName, F_OK) != 0){
        FILE *fp = fopen(fileName, "w+");
        fprintf(fp, "%s\n", str);
        fclose(fp);
    }else{
        FILE *fp = fopen(fileName, "r");
        char *target = "I want to learn PE format!";
        if (search_in_file(fp, target) == false){
            fclose(fp);
            FILE *file_for_write = fopen(fileName, "a+");
            fprintf(file_for_write, "%s\n", target);
            fclose(file_for_write);
        }else{
            FILE *file_to_print = fopen(fileName, "r");
            print_file(file_to_print);
            fclose(file_to_print);
        }
    }
}

bool search_in_file(FILE *f, char *str){
    if(!f){
        printf("Error: %d (%s)\n", errno, strerror(errno));
    }
    int size = 1024, pos;
    int c;
    char *buffer = (char *)malloc(size);

    if(f) {
        do { // read all lines in file
            pos = 0;
            do{ // read one line
                c = fgetc(f);
                if(c != EOF && c!='\n') buffer[pos++] = (char)c;
                if(pos >= size - 1) { // increase buffer length - leave room for 0
                    size *=2;
                    buffer = (char*)realloc(buffer, size);
                }
            }while(c != EOF && c != '\n');
            buffer[pos] = 0;
            // line is now in buffer
            if(strcmp(buffer, str) == 0){
                return true;
            }
        } while(c != EOF);
        fclose(f);
    }
    free(buffer);
    return false;
}

void print_file(FILE *f){
    if(!f){
        printf("Error: %d (%s)\n", errno, strerror(errno));
    }
    int size = 1024, pos;
    int c;
    char *buffer = (char *)malloc(size);

    if(f) {
        do { // read all lines in file
            pos = 0;
            do{ // read one line
                c = fgetc(f);
                if(c != EOF ) buffer[pos++] = (char)c;
                if(pos >= size - 1) { // increase buffer length - leave room for 0
                    size *=2;
                    buffer = (char*)realloc(buffer, size);
                }
            }while(c != EOF && c != '\n');
            buffer[pos] = 0;
            // line is now in buffer
            printf("%s", buffer);
        } while(c != EOF);
        fclose(f);
    }
    free(buffer);
}


int main(){
    check_process_file();
    return 0;
}