/*globals*/



struct movePiece {
 	fil fromFile;
 	int fromRank;
 	fil toFile;
 	int toRank;
};



struct man {	
	int id;
        char *description;
        char symbol;
	int colour;               
	};

struct man men[32];


struct board {
       int id;
       int square[64];
       } b0;


//function Prototypes
int setupMen();
int setupBoard();
struct man getManfromID(int id);
char * exportBoard();
char * exportMenColourString();
int LoadGame(char *filename);
int SaveGame(char *filename);
int movePiece(struct movePiece mp);

// legal moves
// calculation








