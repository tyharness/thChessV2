/*
Ty Harness Chess Analysis Software version 2.

It's a rehash of v1 written years ago just a work in progress
get it working on a raspberry pi.  I've took more out than
Ive left in.

V2  - dropped my old non standard file format and use
pgn

Added colour to the text.

Please note the code at best is clunky use at own risk.





compiling with gcc:

make


mem leaks:
valgrind --tool=memcheck --leak-check=full -v ./thChessV2



To execute the software from CLI or terminal:

./thChessV2                       --- Help and options menu displayed on screen

or use the parameters

./thChessV2 3                     --- where 3 is the number of template pages based on white's point of view.
					you can add white as a 3rd parameter or black

./thChessV2 2  white              --- where 2 is the number of template pages based on white's point of view.
                         

./thChessV2 4  black              --- where 4 is the number of template pages based on blacks's point of view.


./thChessV2 <testfile>.pgn        --- to load in a saved game and export ps file automatically as <testfile>.ps





*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "thChessV2func.h"


/*-----------------------------------------------------------*/
int main(int argc, char **argv)
{

int Npages = 1;

  //intialise board 0 black 1 white
   strcpy(board,   "RNBQKBNRPPPPPPPP                                PPPPPPPPRNBQKBNR"); 
   strcpy(colours, "0000000000000000                                1111111111111111");

   

if (argc == 1) { 
   //hence there's only the 1 parameter the filename at 0 
   printhelp();  
  }else{ 
    if (argc > 1) {

    //check if string and validate file name

    if (atoi(argv[1]) != 0)
     { 
      //if user has supplied a number assume its' the number of pages in the template
      Npages = atoi(argv[1]);
       if(Npages > 20) Npages = 20;

       char *fn;
       
      //default to white=true
      bool white=true;
    
      //has the user provided 2 parameters where 2nd one is either white or black pov
      if (argc > 2){      
       if ( strcmp(argv[2],"black") == 0) white = false; 
      }    
         
       if ( white == true){
        fn = "WhiteTemplateV2.ps";
        }else{
          //playing black
         white=false;
         fn = "BlackTemplateV2.ps"; 
         strcpy(board,   "RNBKQBNRPPPPPPPP                                PPPPPPPPRNBKQBNR");     
         strcpy(colours, "1111111111111111                                0000000000000000");
        }
       
       psfunc(Npages,fn,true,white);
       printf("File %s has been created\n", fn);
      }else
      {
       printf("argv1 %s  %d\n",argv[1],access(argv[1], R_OK ));

      //The command line parameter is not a number therefor is it valid pgn file
      if(!access(argv[1], R_OK )){

        int r = readPGN(argv[1]);
            
        printf("File  %s Number of pages to be printed: %d\n", argv[1], r);

        char fn[50];memset( fn, 0, sizeof(fn) );
        
        char *filename = argv[1];
        

        for (int i =0;i<strlen(filename);i++){
         if ( *(filename+i)=='.' ) break;else
           fn[i] = *(filename+i);
            }

             strcat(fn,".ps");

             psfunc(r, fn, false, true);

             printf("\n%s has been created\n", fn);
    
       }else{
        printf("The File %s can not been found.............\n",argv[1]);
      }
     
   }
   
   
   
  }
     
  }


}




