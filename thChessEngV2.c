#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include"thChessV2func.h"
#include"thChessEngV2.h"




int movePiece(struct movePiece mp){

//printf("xxxmove %d to %d\n", RF1(mp.fromRank-1,mp.fromFile-1),RF1(mp.toRank-1,mp.toFile-1));


//the from square beomes vacant
int f =  RF1(mp.fromRank-1,mp.fromFile-1);

struct man m  = getManfromID(b0.square[f]);
//printf("f %d [%d]\n",f,m.id);

int t =  RF1(mp.toRank-1,mp.toFile-1);
b0.square[f] = -1;



//is the to square occupied?
//yes remove piece from the game
 
//printf("t %d\n",t);
b0.square[ t ] = m.id;



return 0;
}


int LoadGame(char *filename){
printf("%s\n",filename);
return 0;
}


int SaveGame(char *filename){
//possible have a header struct
printf("%s\n",filename);
return 0;
}



struct man getManfromID(int id){

struct man m;

m.id = -1;
m.description = "Empty";
m.symbol = ' ';
m.colour = White;

if (id == -1) return m;

for (int i=0; i <32; i++){
 if (id == men[i].id) {
  m = men[i];
  break;
}

}


return m;

}


char * exportBoard(){

char *bs = (char *) malloc( 65 );
char *Ptrbs;

Ptrbs = bs;

for (int i=0; i<64; i++){

int id = b0.square[i];
   if (id != -1) {
     struct man m = getManfromID( id );
      //printf("%c", m.symbol); 
     *bs++ = m.symbol;
    }else *bs++ = ' ';
  
}

*bs++ = '\0';


return Ptrbs;


}


char * exportMenColourString(){

char *cs = (char *) malloc( 65 );
char *Ptrcs;

Ptrcs = cs;

for (int i=0; i<64; i++){

int id = b0.square[i];

   if (id != -1) {
     struct man m = getManfromID( id ); 
     if (m.colour == 1){
       *cs++ = '1';} else{*cs++ = '0'; }

     
    }else *cs++ = ' ';
  
}

*cs++ = '\0';

return Ptrcs;


}



int setupBoard(){


printf("Board Setup\n");


b0.id = 0;
b0.square[0] = men[0].id;
b0.square[1] = men[1].id;
b0.square[2] = men[2].id;
b0.square[3] = men[3].id;
b0.square[4] = men[4].id;
b0.square[5] = men[5].id;
b0.square[6] = men[6].id;
b0.square[7] = men[7].id;
b0.square[8] = men[8].id;
b0.square[9] = men[9].id;
b0.square[10] = men[10].id;
b0.square[11] = men[11].id;
b0.square[12] = men[12].id;
b0.square[13] = men[13].id;
b0.square[14] = men[14].id;
b0.square[15] = men[15].id;       

for (int i=16; i<48;i++){
 b0.square[i] = -1;
}

b0.square[48] = men[16].id;
b0.square[49] = men[17].id;
b0.square[50] = men[18].id;
b0.square[51] = men[19].id;
b0.square[52] = men[20].id;
b0.square[53] = men[21].id;
b0.square[54] = men[22].id;
b0.square[55] = men[23].id;
b0.square[56] = men[24].id;
b0.square[57] = men[25].id;
b0.square[58] = men[26].id;
b0.square[59] = men[27].id;
b0.square[60] = men[28].id;
b0.square[61] = men[29].id;
b0.square[62] = men[30].id;
b0.square[63] = men[31].id;




return 0;


}



//Load in Chessmen
int setupMen(){

men[0].id = 0;
men[0].description = "Queen's Rook";
men[0].symbol = 'R';
men[0].colour = Black;

men[1].id = 1;
men[1].description = "Queen's Knight";
men[1].symbol = 'N';
men[1].colour =  Black;

men[2].id = 2;
men[2].description = "Queen's Bishop";
men[2].symbol = 'B';
men[2].colour =  Black;

men[3].id = 3;
men[3].description = "Queen";
men[3].symbol = 'Q';
men[3].colour =  Black;

men[4].id = 4;
men[4].description = "King";
men[4].symbol = 'K';
men[4].colour =  Black;

men[5].id = 5;
men[5].description = "King's Bishop";
men[5].symbol = 'B';
men[5].colour =  Black;

men[6].id = 6;
men[6].description = "King's Knight";
men[6].symbol = 'N';
men[6].colour =  Black;

men[7].id = 7;
men[7].description = "King's Rook";
men[7].symbol = 'R';
men[7].colour =  Black;

men[8].id = 8;
men[8].description = "Pawn";
men[8].symbol = 'P';
men[8].colour =  Black;

men[9].id = 9;
men[9].description = "Pawn";
men[9].symbol = 'P';
men[9].colour =  Black;


men[10].id = 10;
men[10].description = "Pawn";
men[10].symbol = 'P';
men[10].colour =  Black;


men[11].id = 11;
men[11].description = "Pawn";
men[11].symbol = 'P';
men[11].colour =  Black;


men[12].id = 12;
men[12].description = "Pawn";
men[12].symbol = 'P';
men[12].colour =  Black;


men[13].id = 13;
men[13].description = "Pawn";
men[13].symbol = 'P';
men[13].colour =  Black;

men[14].id = 14;
men[14].description = "Pawn";
men[14].symbol = 'P';
men[14].colour =  Black;


men[15].id = 15;
men[15].description = "Pawn";
men[15].symbol = 'P';
men[15].colour =  Black;




men[16].id = 16;
men[16].description = "Pawn";
men[16].symbol = 'P';
men[16].colour = White;


men[17].id = 17;
men[17].description = "Pawn";
men[17].symbol = 'P';
men[17].colour = White;


men[18].id = 18;
men[18].description = "Pawn";
men[18].symbol = 'P';
men[18].colour = White;


men[19].id = 19;
men[19].description = "Pawn";
men[19].symbol = 'P';
men[19].colour = White;


men[20].id = 20;
men[20].description = "Pawn";
men[20].symbol = 'P';
men[20].colour = White;


men[21].id = 21;
men[21].description = "Pawn";
men[21].symbol = 'P';
men[21].colour = White;


men[22].id = 22;
men[22].description = "Pawn";
men[22].symbol = 'P';
men[22].colour = White;


men[23].id = 23;
men[23].description = "Pawn";
men[23].symbol = 'P';
men[23].colour = White;

men[24].id = 24;
men[24].description = "Queen's Rook";
men[24].symbol = 'R';
men[24].colour = White;

men[25].id = 25;
men[25].description = "Queen's Knight";
men[25].symbol = 'N';
men[25].colour = White;


men[26].id = 26;
men[26].description = "Queen's Bishop";
men[26].symbol = 'B';
men[26].colour = White;

men[27].id = 27;
men[27].description = "Queen";
men[27].symbol = 'Q';
men[27].colour = White;

men[28].id = 28;
men[28].description = "King";
men[28].symbol = 'K';
men[28].colour = White;

men[29].id = 29;
men[29].description = "King's Bishop";
men[29].symbol = 'B';
men[29].colour = White;

men[30].id = 30;
men[30].description = "King's Knight";
men[30].symbol = 'N';
men[30].colour = White;

men[31].id = 31;
men[31].description = "King's Rook";
men[31].symbol = 'R';
men[31].colour = White;






return 0;
}



/*
//check a pieces legal moves


*/
