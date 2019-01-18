/*Types*/
typedef enum { false, true } bool;

typedef enum  {a=1,b,c,d,e,f,g,h} fil;


typedef enum  {Black=0, White=1} col;


/*defines*/
#define BLACK_PIECE "\33[38;5;1m"
#define WHITE_PIECE "\33[38;5;2m"

#define COL1 "\33[38;5;4m"


#define WHITE_SQUARE "\33[48;5;15m"
#define BLACK_SQUARE "\33[48;5;0m"

#define ANSI_RESET  "\33[m"



/*globals*/
char board[65];
char colours[65];

char *gamePtr;
char *gameRevisedPtr;

int info[200][2];
int period[200];

/*-----------------------------------------------------------*/


struct move {
 int   m;
 char  text[50];    
};

struct move moves[200]; //Assume game has less than 200 moves



/*Function Prototypes*/
bool printhelp();
int  screenboard();
int  readPGN(char *filename);
int  writePGN(char *filename, int mc);
int  RF(int rank, int file);
int  RF1(int rank, int file); //2 wrongs make a right

int  psfunc(int Npages, char *filename, bool templatePS, bool white);
int  debugger();
int  morphy();


