/* Author(s): Kyle Nguyen

/* ----------------------------------------------------------------- */
/*                  Redirect, part of a child process                */
/* ----------------------------------------------------------------- */

#include "lab9_10.h"

void Redirect(int argc, char *argv[])
{
    int i;	     // loop counter
    int out = 0;  // track position of location Out redirection, >
    int in = 0;   // track position of location In redirection, <
    int fd;

    for(i = 0; i < argc; i++){
        if(strcmp(argv[i], ">") == 0){
            if(out != 0){
                fprintf(stderr, "Cannot output to more than one file.\n");
                _exit(EXIT_FAILURE);
            }else if(i == 0){
                fprintf(stderr, "No command entered.\n");
                _exit(EXIT_FAILURE);   
            }
            out = i;
        }else if(strcmp(argv[i], "<") == 0){
            if(in != 0){
                fprintf(stderr, "Cannot input from more than one file.\n");
                _exit(EXIT_FAILURE);       
            }else if(i == 0){
                fprintf(stderr, "No command entered.\n");
                _exit(EXIT_FAILURE);
            }
            in = i;
        }    //End of if else-if
    } //End of for loop


    if(out != 0){
        if(argv[out+1] == NULL){
            fprintf(stderr, "No output file.\n");
            _exit(EXIT_FAILURE);    
        }    
        //open file...IMPLEMENT (Found in Lab 10 slides, slide 13)
                                   //Flags are O               Permission bits are S
        int fd = open(argv[out+1], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        //Error checking
        if(fd == -1){
            perror("Error opening file.\n");
            _exit(EXIT_FAILURE);
        }

        dup2(fd, 1);    //1 is for standard output
        close(fd);
        argv[out] = NULL;
    }

    if(in != 0){
        if(argv[in+1] == NULL){
            fprintf(stderr, "No input file.\n");
            _exit(EXIT_FAILURE);    
        }       
        //open file...IMPLEMENT
        int fd = open(argv[in+1], O_RDONLY);

        if(fd == -1){
            perror("Error opening file.\n");
            _exit(EXIT_FAILURE);    
        }

        dup2(fd, 0);    //0 is for standard input
        close(fd);
        argv[in] = NULL;
    }
}  /*end of function*/

