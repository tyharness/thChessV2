#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include"thChessV2func.h"
#include"thChessEngV2.h"






int debugger(){

printf("\n\ndebug info\n");


screenboard();


printf("%d %d %d %d %d %d %d %d\n\n", a,b,c,d,e,f,g,h );


setupMen();
setupBoard();


for (int i=0; i<32;i++){
 printf("\nman: %d %s %d ", men[i].id, men[i].description, men[i].colour  );
}



printf("\n\n");

for (int j=0; j<8;j++){
 for (int i=0; i<8;i++){

  int id = b0.square[i+j*8];
   if (id != -1) {
    struct man m = getManfromID( id ); 
    printf("%d [%c]\t", id, m.symbol );
   } else printf("[ ]\t");
 }
 printf("\n"); 
}



 printf("\n\n%s\n", exportBoard() );
 printf("%s\n", exportMenColourString() );

 strcpy(board,   exportBoard() );     
 strcpy(colours, exportMenColourString() );

 screenboard();
 printf("\n");




for (int j=0; j<8;j++){
 for (int i=0; i<8;i++){
    
      printf("%d\t", i+j*8 );

 }
 
 printf("\n"); 
}








printf("move e2 [%d] to e4 [%d]\n", RF1(2-1,e-1),  RF1(4-1,e-1) );

struct man m = getManfromID(  b0.square[ RF1(2-1,e-1) ]   ); 
      printf("amove: %d [%c] %d %s\n", m.id, m.symbol, m.colour,m.description );

 m = getManfromID(  b0.square[ RF1(4-1,e-1) ]   ); 
      printf("ato: %d [%c] %d %s\n", m.id, m.symbol, m.colour,m.description );

//move a piece on the board
struct movePiece mp;
mp.fromFile = e; mp.fromRank = 2;
mp.toFile = e; mp.toRank = 4;
movePiece(mp);



printf("\n\n");

for (int j=0; j<8;j++){
 for (int i=0; i<8;i++){

  int id = b0.square[i+j*8];
   if (id != -1) {
    struct man m = getManfromID( id ); 
    printf("%d [%c]\t", id, m.symbol );
   } else printf("[ ]\t");
 }
 printf("\n"); 
}

printf("\n\n");

//update the global string for the screenboard
printf("\n\n%s\n", exportBoard() );
printf("%s\n", exportMenColourString() );
strcpy(board,   exportBoard() );     
strcpy(colours, exportMenColourString() );


screenboard();

printf("\n\nend debug\n");


exit(0);

return 0;
}


int morphy(){


//hard code in morphy game


setupMen();
setupBoard();


printf("Paul Morphy vs. Duke of Brunswick and Count Isouard 1858\n\n");
//screenboard();


//move a piece on the board
struct movePiece mp;

int morph[34][4];

morph[0][0] = e; morph[0][1] = 2; morph[0][2] = e; morph[0][3] = 4;//white
morph[1][0] = e; morph[1][1] = 7; morph[1][2] = e; morph[1][3] = 5;

morph[2][0] = g; morph[2][1] = 1; morph[2][2] = f; morph[2][3] = 3;
morph[3][0] = d; morph[3][1] = 7; morph[3][2] = d; morph[3][3] = 6;

morph[4][0] = d; morph[4][1] = 2; morph[4][2] = d; morph[4][3] = 4;
morph[5][0] = c; morph[5][1] = 8; morph[5][2] = g; morph[5][3] = 4;

morph[6][0] = d; morph[6][1] = 4; morph[6][2] = e; morph[6][3] = 5;
morph[7][0] = g; morph[7][1] = 4; morph[7][2] = f; morph[7][3] = 3;

morph[8][0] = d; morph[8][1] = 1; morph[8][2] = f; morph[8][3] = 3;
morph[9][0] = d; morph[9][1] = 6; morph[9][2] = e; morph[9][3] = 5;



//move 6

morph[10][0] = f; morph[10][1] = 1; morph[10][2] = c; morph[10][3] = 4;
morph[11][0] = g; morph[11][1] = 8; morph[11][2] = f; morph[11][3] = 6;

//move 7
morph[12][0] = f; morph[12][1] = 3; morph[12][2] = b; morph[12][3] = 3;
morph[13][0] = d; morph[13][1] = 8; morph[13][2] = e; morph[13][3] = 7;


//move 8
morph[14][0] = b; morph[14][1] = 1; morph[14][2] = c; morph[14][3] = 3;
morph[15][0] = c; morph[15][1] = 7; morph[15][2] = c; morph[15][3] = 6;

//move 9
morph[16][0] = c; morph[16][1] = 1; morph[16][2] = g; morph[16][3] = 5;
morph[17][0] = b; morph[17][1] = 7; morph[17][2] = b; morph[17][3] = 5;

//move 10
morph[18][0] = c; morph[18][1] = 3; morph[18][2] = b; morph[18][3] = 5;
morph[19][0] = c; morph[19][1] = 6; morph[19][2] = b; morph[19][3] = 5;

//move 11
morph[20][0] = c; morph[20][1] = 4; morph[20][2] = b; morph[20][3] = 5;
morph[21][0] = b; morph[21][1] = 8; morph[21][2] = d; morph[21][3] = 7;


//move 12
morph[22][0] = e; morph[22][1] = 1; morph[22][2] = c; morph[22][3] = 1;
morph[23][0] = a; morph[23][1] = 1; morph[23][2] = d; morph[23][3] = 1;


morph[24][0] = a; morph[24][1] = 8; morph[24][2] = d; morph[24][3] = 8;
//move 13
morph[25][0] = d; morph[25][1] = 1; morph[25][2] = d; morph[25][3] = 7;
morph[26][0] = d; morph[26][1] = 8; morph[26][2] = d; morph[26][3] = 7;
//move 14
morph[27][0] = h; morph[27][1] = 1; morph[27][2] = d; morph[27][3] = 1;
morph[28][0] = e; morph[28][1] = 7; morph[28][2] = e; morph[28][3] = 6;
//move 15
morph[29][0] = b; morph[29][1] = 5; morph[29][2] = d; morph[29][3] = 7;
morph[30][0] = f; morph[30][1] = 6; morph[30][2] = d; morph[30][3] = 7;
//move 15
morph[31][0] = b; morph[31][1] = 3; morph[31][2] = b; morph[31][3] = 8;
morph[32][0] = d; morph[32][1] = 7; morph[32][2] = b; morph[32][3] = 8;
//move 16
morph[33][0] = d; morph[33][1] = 1; morph[33][2] = d; morph[33][3] = 8;


moves[0].m = 1; strcpy(moves[0].text,"1. e4 ...");
moves[1].m = 1; strcpy(moves[1].text,"1. ... e5");
moves[2].m = 2; strcpy(moves[2].text,"2. Nf3 ...");
moves[3].m = 2; strcpy(moves[3].text,"2. ... d6");
moves[4].m = 2; strcpy(moves[4].text,"3. d4 ...");
moves[5].m = 2; strcpy(moves[5].text,"3. ... Bg4");
moves[6].m = 2; strcpy(moves[6].text,"4. dxe5 ...");
moves[7].m = 2; strcpy(moves[7].text,"4. ... Bxf3");
moves[8].m = 2; strcpy(moves[8].text,"5. Qxf3 ...");
moves[9].m = 2; strcpy(moves[9].text,"5. ... dxe5");
moves[10].m = 2; strcpy(moves[10].text,"6. Bc4 ...");
moves[11].m = 2; strcpy(moves[11].text,"6. ... Nf6");
moves[12].m = 2; strcpy(moves[12].text,"7. Qb3 ...");
moves[13].m = 2; strcpy(moves[13].text,"7. ... Qe7");
moves[14].m = 2; strcpy(moves[14].text,"8. Nc3 ...");
moves[15].m = 2; strcpy(moves[15].text,"8. ... c6");
moves[16].m = 2; strcpy(moves[16].text,"9. Bg5 ...");
moves[17].m = 2; strcpy(moves[17].text,"9. ... b5");
moves[18].m = 2; strcpy(moves[18].text,"10. Nxb5 ...");
moves[19].m = 2; strcpy(moves[19].text,"10. ... cxb5");
moves[20].m = 2; strcpy(moves[20].text,"11. Bxb5+ ...");
moves[21].m = 2; strcpy(moves[21].text,"11. ... Nbd7");
moves[22].m = 2; strcpy(moves[22].text,"12. O-O-O ...");
moves[23].m = 2; strcpy(moves[23].text,"12. O-O-O ...");

moves[24].m = 2; strcpy(moves[24].text,"12. ... Rd8");
moves[25].m = 2; strcpy(moves[25].text,"13. Rxd7 ...");
moves[26].m = 2; strcpy(moves[26].text,"13. ... Rxd7");
moves[27].m = 2; strcpy(moves[27].text,"14. Rd1 ...");
moves[28].m = 2; strcpy(moves[28].text,"14. ... Qe6");
moves[29].m = 2; strcpy(moves[29].text,"15. Bxd7+ ...");
moves[30].m = 2; strcpy(moves[30].text,"15. ... Nxd7");
moves[31].m = 2; strcpy(moves[31].text,"16. Qb8+ ...");
moves[32].m = 2; strcpy(moves[32].text,"16. ... Nxb8");
moves[33].m = 2; strcpy(moves[33].text,"17. Rd8 # 1-0");





int j = 0;
for (int i=0 ; i<34;i++){

mp.fromFile = morph[i][0]; mp.fromRank = morph[i][1];
mp.toFile = morph[i][2]; mp.toRank = morph[i][3];
movePiece(mp);


strcpy(board,   exportBoard() );     
strcpy(colours, exportMenColourString() );

system("clear");
printf(WHITE_SQUARE BLACK_PIECE "Ty Harness Chess-Puter" ANSI_RESET);
printf(BLACK_PIECE "\n\nDuke of Brunswick and Count Isouard\n" ANSI_RESET);
screenboard();
printf(WHITE_PIECE "Morphy, P.\n" ANSI_RESET);
printf("\nThe 1858 Infamous\nParis Opera House Game\n");

if (j<23){
 if (j%2==0){
  printf(WHITE_PIECE "\n%s\n" ANSI_RESET ,moves[j].text);}else
 { printf(BLACK_PIECE "\n%s\n" ANSI_RESET ,moves[j].text);
 }
}

if (j>=23){
if (j%2!=0){
printf(WHITE_PIECE "\n%s\n" ANSI_RESET ,moves[j].text);}else
{
printf(BLACK_PIECE "\n%s\n" ANSI_RESET ,moves[j].text);
}
}




sleep(1);

/*
//convert -delay 200 frame*xwd paul.gif
//turn off the menu bar from terminal


char buffer[30];
snprintf(buffer, sizeof(buffer), "xwd -out xwd/frame%04d.xwd", j);
system(buffer);
*/


j++;

}




return 0;
}




/* =====================================================================
Postscript file
*/
int psfunc(int Npages, char *filename, bool templatePS, bool white){

int tp = 0;

FILE * fp;

fp = fopen (filename, "w+");

fprintf(fp, "%%%%!PS\n\n");  
fprintf(fp, "%%%%Pages: %d\n", Npages); 




for (int page=0; page<Npages; page++){

fprintf(fp, "%%%%Page: %d %d\n", page+1, page+1); 
fprintf(fp, "/f {findfont exch scalefont setfont} bind def\n"); 
fprintf(fp, "/s {show} bind def\n"); 
fprintf(fp, "/ps {true charpath} bind def\n"); 
fprintf(fp, "/l {lineto} bind def\n"); 
fprintf(fp, "/m {newpath moveto} bind def\n"); 
fprintf(fp, "/sg {setgray} bind def\n");
fprintf(fp, "/sr {setrgbcolor} bind def\n");
fprintf(fp, "/a {stroke} bind def\n");
fprintf(fp, "/cp {closepath} bind def\n");
fprintf(fp, "/g {gsave} bind def\n");
fprintf(fp, "/h {grestore} bind def\n");
fprintf(fp, "/i {fill} bind def\n");



fprintf(fp, "matrix currentmatrix /originmat exch def\n");
fprintf(fp, "/umatrix {originmat matrix concatmatrix setmatrix} def\n");
fprintf(fp, "[28.3465 0 0 28.3465 10.5 100.0] umatrix\n");

fprintf(fp,"/Courier findfont 36 72 div scalefont setfont\n");
fprintf(fp,"0 0 0 setrgbcolor\n");


if (templatePS == false) {
  fprintf(fp,"2.0 22.0 moveto (%s) show\n", moves[0].text);
}else{
 fprintf(fp,"2.0 22.0 moveto (Ty Harness Postscript Chess Analysis Reporting Software) show\n");
}

//fprintf(fp,"0 setgray %% black\n");
//fprintf(fp,"0.5 9.8 moveto (Ty) show\n");
//fprintf(fp,"0.5 9.6 moveto (Harness) show\n");


fprintf(fp,"0.0001000 setlinewidth \n");




double x  = 2.75;
double y  = 0.0;
double dx = 0.5;
double dy = 0.5;



for (int h=0;h<2;h++){

x = 2.75 + h*6;
y = 0.0;


 for (int k=0;k<4;k++){

  int B=0;

   for (int j=0; j<8;j++){
    for (int i=0; i<8;i++){
       fprintf(fp,"%f %f m\n",x,y);
       fprintf(fp,"%f %f l\n",x-dx,y);
       fprintf(fp,"%f %f l\n",x-dx,y-dy);
       fprintf(fp,"%f %f l\n",x,y-dy);
       fprintf(fp,"cp\n");
       fprintf(fp,"g\n");

       if( (i%2==B) && (j%2==B) ){ 
        fprintf(fp,"0.67 1.00 0.67 sr\n");
       }else fprintf(fp,"1.00 1.00 1.00 sr\n");
        fprintf(fp,"i h a\n");
 

       x+=dx;

       }
       x = 2.75 + h*6;
       y += dy;
       if(B==0) B=1; else B=0;
     };

   y += 1.75;

}//end k

}

double oox = 0.1;
double ooy = 0.1;


x = 13.5;
y = -dy + 42*dy;




 for (int j=0; j<30;j++){
 fprintf(fp,"%f %f m\n", x,y);
 fprintf(fp,"%f %f l\n", x+10*dx,y);
 fprintf(fp,".5 sg\n");
 fprintf(fp,"a\n");
 
 if (templatePS == false) {

  fprintf(fp,"/Courier findfont 20 72 div scalefont setfont\n");

  int ni = 7; //number of info blocks

  //write out the info on the first page only
  if (page == 0){
    if ( j < 8+ni ) {
      if (moves[j + tp].m+1-ni < 1){
       fprintf(fp,"%f %f m (%s) s\n", x,   y+ooy,  moves[j + tp].text ); 
       }else{
       fprintf(fp,"%f %f m (%d %s) s\n", x,   y+ooy, moves[j + tp].m+1-ni ,  moves[j + tp].text );  
      } 
 
    }
  }else{
    //only write 8 moves per page  
    if ( j < 8 ) {
    fprintf(fp,"%f %f m (%d %s) s\n", x,   y+ooy, moves[j + tp + ni].m+1-ni ,  moves[j + tp + ni].text );  
    }
  
  }
 }
  

 y -= 1*dy;
}



/*
Board Reference on the printed sheet
0 4
1 5
2 6
3 7
*/

struct BoardRef{
 int board;
 int move;
 double ox,oy;
};


struct BoardRef B1;

B1.board = 0;
B1.move = 0;

if (B1.board <= 3){
B1.oy = (3 - B1.board)*(1.75 + 8*dy); 
B1.ox = 0; 
}else {
B1.oy = (3 - (B1.board-4))*(1.75 + 8*dy); 
B1.ox = 6.0;
}



x = 2.75 - dx;
y = -dy;


for (int h=0;h<2;h++){

y = -8*dy;

for (int k=0;k<4;k++){

  //print the rank and file letters

  fprintf(fp,"/Courier findfont 30 72 div scalefont setfont\n");
  fprintf(fp,"0.2 0.2 0.2 setrgbcolor\n");

  for (int j=0; j<8;j++){
   if (white == true){
    fprintf(fp,"%f %f m (%d) s\n", x-dx,   y+ooy+(7*dy),   j+1 );}
    else{
     fprintf(fp,"%f %f m (%d) s\n", x-dx,   y+ooy+(7*dy),  8-j );  
    }
  
   y += dy;
  }

  y -= 2*dy;
  

  
  
  
  if (white == true){
   char fil[] = "a b c d e f g h";
   fprintf(fp,"%f %f m (%s) s\n", x+oox,   y+ooy,   fil);}
  else{
   char fil1[] = "h g f e d c b a";
   fprintf(fp,"%f %f m (%s) s\n", x+oox,   y+ooy,   fil1);
  }


  y += 2.75;


}//end k

x = 8.35;

}//end h



x = 2.75 - dx;
y = -dy;


if ((templatePS == true) && (page==0)){
 
  fprintf(fp,"/Courier findfont 32 72 div scalefont setfont\n");


  for (int j=0; j<8;j++){
    for (int i=0; i<8;i++){

     if ( colours[RF(j,i)] != '0') { fprintf(fp,"1 0 0 setrgbcolor\n");}
           else{
           fprintf(fp,"0.4 0.4 0.4 setrgbcolor\n");
           }

     //print the men on the board
     fprintf(fp,"%f %f m (%c) s\n", x+oox+B1.ox,   y+ooy+B1.oy,   board[RF(j,i)]);

     

     x += dx;
     }
     x = 2.75 - dx;
     y += dy;
   }


 y = -dy;




} //end template



fprintf(fp,"showpage\n");

tp+=8;

}//end pages


fclose(fp);

return 0;


}



/*============================================================================
Given Rank and file return id/array position on the board note my rank and file
are 0..7

rank 7: 56,57,58,59,60,61,62,63
rank 6: 48,49,50,51,52,53,54,55
rank 5: 40
rank 4: 32
rank 3: 24
rank 2: 16
rank 1: 8, 9, 10,11,12,13,14,15
rank 0: 0, 1, 2 ,3 ,4 ,5 ,6 ,7
        a, b, c ,d ,e ,f ,g ,h  
*/

int RF(int rank, int file){
   int p = rank*8 + file;
  return  p;
}

/*
	a, b, c, d, e, f, g, h
rank 7: 0, 1, 2 ,3 ,4 ,5 ,6 ,7
rank 6: 8, 9, 10,11,12,13,14,15
rank 5: 16
rank 4: 24
rank 3: 32
rank 2: 40
rank 1: 48,49,50,51,52,53,54,55
rank 0: 56,57,58,59,60,61,62,63
*/

int RF1(int rank, int file){
   int p = (7-rank)*8 + file;
  return  p;
}


/*=================




===========================================================
Main menu screen and help page*/


bool printhelp(){


char strChoice[30];
char strPGNfile[30];
char strPages[10];
char strMove[10];

int choice = -1;

do{
 system("clear"); 

 printf(WHITE_SQUARE BLACK_PIECE "Welcome to the Ty Harness Postscript Chess Analysis Reporting Software V2\n\n" ANSI_RESET);

 printf("Command Line parameters.\n\n");
 printf("How to export a blank template file.\nThere are 8 boards and 42 ruled lines per page:\n\n./thChessV2 <number of pages> <playing colour>\n\ne.g. 2 pages playing  white    ./thChessV2 2 white\n");
 printf("or 3 pages playing black  ./thChessV2 3 black\n");
 printf("-----------------------------------------------------\n\n");
 printf("How to read in a .pgn file and export as postscript .ps report\n./thChessV2 test.pgn\n\n");
 printf("-----------------------------------------------------\n\n"); 
 printf("Menu driven options:\n\n");
 printf("-----------------------------------------------------\n\n");
 printf("Export a White POV template PS file. \n8 boards and 42 ruled lines per page.\n");
 printf("Enter w [return]\n");
 printf("-----------------------------------------------------\n\n");
 printf("Export a Black POV template PS file.\n");
 printf("Enter b [return]\n");
 printf("-----------------------------------------------------\n\n");
 printf("Load in a previously saved game (pgn format)\n");
 printf("Enter f [return]\n");
 printf("-----------------------------------------------------\n\n");
 printf("Input New Game (pgn format)\n");
 printf("Enter g [return]\n");
 printf("-----------------------------------------------------\n\n");
 printf("Press Ctrl c to quit at any time\n");
 printf("-----------------------------------------------------\n\n");

  
 fgets(strChoice,30,stdin);
 
 if (strcmp(strChoice,"w\n")  == 0)   choice = 0; 
 if (strcmp(strChoice,"b\n")  == 0)   choice = 3; 
 if (strcmp(strChoice,"f\n")  == 0)   choice = 1; 
 if (strcmp(strChoice,"g\n")  == 0)   choice = 2; 
 if (strcmp(strChoice,"debug\n")  == 0)   choice = 4; 
 if (strcmp(strChoice,"morphy\n")  == 0)   choice = 5; 
  
 
} while (choice == -1); 


 if (choice == 0) {
  printf("Enter Number of template pages and create PS file: ");
  fgets(strPages,10,stdin);
  psfunc(atoi(strPages),"WhiteTemplateV2.ps",true,true);
 }

 if (choice == 3) {
  printf("Enter Number of template pages and create PS file: ");
  fgets(strPages,10,stdin);
  strcpy(board,   "RNBKQBNRPPPPPPPP                                PPPPPPPPRNBKQBNR"); 
  strcpy(colours, "1111111111111111                                0000000000000000");
  psfunc(atoi(strPages),"BlackTemplateV2.ps",true,false);
 }





 if (choice == 1){  
  
   int q=1;

   printf("Enter a valid pgn file: "); 
   fgets(strPGNfile,30,stdin);

    int i;
    char fn[30];
    for(i=0;i<strlen(strPGNfile)-1;i++){
     fn[i] = strPGNfile[i];
    }
     fn[i] = '\0';

    if(!access(fn, R_OK )){
        printf("The File %s has been found\n",fn);
        q = readPGN(fn);

        printf("Do you wish to export PGN as a PS? (y/n to quit)\n");  

       char strExportPS[10];
       fgets(strExportPS,10,stdin);

       if (strcmp(strExportPS,"y\n")  == 0) {
         
        char fn1[30] ;memset( fn1, 0, sizeof(fn) );
        
         for (int i =0;i<strlen(fn);i++){
           if ( fn[i] == '.' ) break;else
           fn1[i] = fn[i];
           }
           strcat(fn1,".ps");
            
           psfunc(q, fn1, false, true);
           printf("\n%s has been created\n", fn1);
         } 





      }else{
        printf("The File %s can not been found......\n",fn);
      }
  
 
      
     
       
     

  
}



if (choice == 2){ 
  int mc=1;

 
  printf("Type end to exit game input mode.\n");
  

  //ask user for game information


  while(1){ 

  printf("Enter White move %d\n",mc);
  fgets(strMove,10,stdin);
  
  if(strcmp(strMove,"end\n") == 0)break;

  //validate and record move
   moves[mc-1].m =    mc;
   

  if (strcmp(moves[mc-1].text,"end\n") != 0 )
   { 
    strcpy(moves[mc-1].text,strMove);

    for(int i = 0; i < 30; i++){	  
         if( moves[mc-1].text[i] == '\n'){		
	     moves[mc-1].text[i] = ' ';
	     break;}
    }

    //screenboard();

    printf("Enter Black move %d\n",mc);
    fgets(strMove,10,stdin);
    if(strcmp(strMove,"end\n") == 0)break;
  
    strcat(moves[mc-1].text, strMove);

    //screenboard();

    mc++; 
    }
   
}
  
 



  printf("\nChoose a file name <xxxxxxx.pgn> to save the game.\n(.pgn is not appended automatically)\n");
  fgets(strChoice,30,stdin);

  if (strcmp(strChoice,"\n") != 0) 
  {

     for(int i = 0; i < 30; i++)
     {	  
         if( strChoice[i] == '\n')
             {		
	     strChoice[i] = '\0';
	     break;
             }
     }

     if (writePGN(strChoice,mc) == 0){
       printf("has been exported\n\n");
     }
  }

} 



if (choice == 4){
  debugger();
}

if (choice == 5){
  morphy();
}


return true;

}


/*-----------------------------------------------------------*/
int screenboard(){

/*Piece

0 -  Black Queen's Rook
1 -  Black Queen's Knight
2 -  Black Queen's Bishop
3 -  Black Queen
4 -  Black King
5 -  Black King's Bishop
6 -  Black King's Knight
7 -  Black King's Rook
8 -  Black Pawn
9 -  Black Pawn
10 - Black Pawn
11 - Black Pawn
12 - Black Pawn
13 - Black Pawn
14 - Black Pawn
15 - Black Pawn
*/


//j being rank and i being file


int B=0;    

   for (int j=0; j<8; j++){
     for (int i=0; i<8; i++){
        if( (i%2==B) && (j%2==B) ){ 
           
           if ( colours[RF(j,i)] != '0') {
              printf( WHITE_SQUARE WHITE_PIECE "%c" ANSI_RESET, board[RF(j,i)]);
               
}
           else{
               printf( WHITE_SQUARE BLACK_PIECE "%c" ANSI_RESET, board[RF(j,i)]);
              
           }
          

          }else{ 
         
          
         if ( colours[RF(j,i)] != '0') {
             printf(BLACK_SQUARE WHITE_PIECE "%c" ANSI_RESET,board[RF(j,i)]);
            // printf(BLACK_SQUARE WHITE_PIECE "%c" ANSI_RESET,b0.square[RF(i,j)]);
            }
            else{
             printf(BLACK_SQUARE BLACK_PIECE "%c" ANSI_RESET, board[RF(j,i)]);
             }
            


          }
          }
          printf("%d\n",8-j);

    if(B==0) B=1; else B=0;
  
   }

    printf("abcdefgh\n");
     
    return 0;

}







/*==============================================================================
Export PGN
==============================================================================*/

int writePGN(char *filename, int mc){

 FILE * fp;

 fp = fopen (filename, "w");

 //default info
 fprintf(fp, "[Event \"Test Game\"]\n[Site \"UK\"]\n[Date \"2018.12.25\"]\n");
 fprintf(fp, "[Round \"\"]\n[White \"ZX81(DRH)\"]\n[Black \"Ty Harness\"]\n[Result \"1-0\"]\n");
 

  for(int i=0; i<mc-1;i++){

   if (strcmp(moves[i].text, "end end\n")!=0){
    fprintf(fp, " %d. ", moves[i].m );
    fprintf(fp, "%s", moves[i].text ); //puts a newline but I prefer that
   }
  }

 fclose(fp);

return 0;
}



/*==============================================================================
Read in game into an array
==============================================================================*/
int readPGN(char *filename){


int i = 0;
int c;
int mi = 0;

//initialise data arrays
for (int j=0;j<200;j++){
info[j][0] = -1;
info[j][1] = -1;
period[j] = -1;
}


FILE *file;

file = fopen(filename,"r");

 fseek(file, 0, SEEK_END);
 long fsize = ftell(file); 
 printf("File size %ld\n\n",fsize);
 fseek(file, 0, SEEK_SET); 

 // Create an char pointer and set aside enough space to hold the chars
 // The typecast (char *) isn't required in C

  char *game = (char *) malloc(fsize + 1);
  fread(game, fsize, 1, file);
  fclose(file);

  
 
 /* Debug display in the CLI
  printf("game size length = %ld  %ld\n\n", sizeof(game), strlen(game));
  while (*game != '\0'){
  putchar(*game++);
 }
 */


//gamePtr = game; //might need this for freeing
//printf("File size %ld\n\n",fsize);


char *game1 = (char *) malloc( fsize + 1 );



gameRevisedPtr = game1;




//copy data but take out newline and excess white space

while ( (c = *game++) != '\0'){
 if ( (c != '\n') ){
  *game1++ = c;
  }

}

*game1++ = '.';
*game1++ = '\0';


/* Debug 
printf("game1 size and  length = %ld  %ld\n\n", sizeof(gameRevisedPtr) ,  strlen(gameRevisedPtr) );
while (*game1 != '\0'){
 putchar(*game1++);
}
*/


game1 = gameRevisedPtr;

    int p=0;
    int pi = 0;
    int open = 0; //keep track of am in inside a pair of [ ] brackets

  
   while ( (c = *game1++) != '\0'){

    if (c == '[') {
      info[i][0] = p;
      //putchar('{');
      open = 1;
    } else if (c == ']') {
      info[i][1] = p;
      i++;
      //putchar('}');
      open = 0;
    } else if (c == '.') {

       //It's possible to use periods in the info blocks[] e.g. date 12.31.18
       if( info[i-2][1] != -1){
        if (open != 1){       
           period[pi] = p; 
           pi++; 
          }
      }//check past the info part

    }
  
    putchar(c);
   
    p++;

    }


 printf("\n\n");



//strip data out between info [] blocks
mi = 0;

for (int j=0;j<200;j++){
  if (info[j][0] == -1)break;
  int p1 = info[j][0];
  int p2 = info[j][1];
  printf("info blocks: %d to %d ", p1, p2);

  char temp[30];
  memset( temp, 0, sizeof(temp) );
  int ti = 0;

  for (int i = p1;i<p2+1;i++){
    printf("%c", *(gameRevisedPtr+i)   );
    temp[ti] = *(gameRevisedPtr+i) ; ti++;
  }
   printf("\n");

   moves[mi].m = mi;  
   strcpy(moves[mi].text, temp);
   mi++;


}



//Strip out move data between periods
for (int j=0;j<200;j++){
 
  if (period[j+1] == -1)break;
  
    int p1 = period[j];
    int p2 = period[j+1];

    printf("Periods: %d to %d => %d. ", period[j], period[j+1], j+1);

    //p1+2 to remove .space   <p2 takes off end period
    int sc=0; //space count strip of final space and spurious number
    
    char temp[30];
    memset( temp, 0, sizeof(temp) );
    int ti = 0;


    for (int i = p1+2;i<p2;i++){
       if (*(gameRevisedPtr+i) == ' ') sc++;

       if (sc<2){
        printf("%c", *(gameRevisedPtr+i)   );
        temp[ti] = *(gameRevisedPtr+i) ; ti++;
       } 
   }
   printf("\n");


   
   moves[mi].m = mi;  
   strcpy(moves[mi].text, temp);
   mi++;

  

}



double fmi = (float)mi /8;
int q = (int) fmi; //number of pages


return q;

}

/*----------------------------------------------------------------------------*/



