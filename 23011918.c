
#include <stdlib.h>
#include <time.h>
#include <string.h>




/* run this program using the console pauser or add your own getch, system("pause") or input loop */


// Function to display the game board 
void displayBoard(int rows, int cols, char **board) {
	int i,j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c ", board[i][j]);
        }  
        printf("\n"); 
    }
}

// Function to initialize the game board
void initializeBoard(int rows, int cols, char **board) {
	int i,j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            board[i][j] = '.';
        }
    }
}

// Function to display the menu 
int displayMenu() {
    int choice;
    printf("\n========== TETRIS MENU ==========\n");
    printf("1. Start Game\n");
    printf("2. Customize Grid Size\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to customize the grid size
void customizeGridSize(int *rows, int *cols, char ***board) {
    // Free existing memory
    int i;
    for (i = 0; i < *rows; i++) {
        free((*board)[i]);
    }
    free(*board);

    printf("Enter the new number of rows: ");
    scanf("%d", rows);
    printf("Enter the new number of columns: ");
    scanf("%d", cols);

    // Allocate memory for the new game board
    *board = (char **)malloc(*rows * sizeof(char *));
    for (i = 0; i < *rows; i++) {
        (*board)[i] = (char *)malloc(*cols * sizeof(char));
    }
}

void displayPiece(int pieceSize, char piece[4][4]) {
	int i,j;
    for (i = 0; i < pieceSize; i++) {
        for (j = 0; j < pieceSize; j++) {
            printf("%c ", piece[i][j]);
        }
        printf("\n");
    }
}






//function for piece rotation 
int rotate(int x, int y, int r){
	switch(r % 4){
		case 0: return y*4+x;
		case 1: return 12+y-(x*4);
		case 2: return 15-(y*4)-x;
		case 3: return 3-y+(x*4);
	}
	return 0;
}




int main() {
	
	int i,j;
    // Random number generator
    srand(time(NULL));

    // grid size (determined by user)
    int rows, cols;

    // Initialize the game board
    char **board;
    
   char pieces[5][4][4] = { 
       {
	    {'a', '.', '.', '.'},
        {'a', 'a', '.', '.'},
        {'.', 'a', '.', '.'},
        {'.', '.', '.', '.'}
      },
    
    
      {
        {'a', '.', '.', '.'},
        {'.', '.', '.', '.'},
        {'.', '.', '.', '.'},
        {'.', '.', '.', '.'}
      },
    
    
    {
        {'a', '.', '.', '.'},
        {'a', '.', '.', '.'},
        {'a', '.', '.', '.'},
        {'.', '.', '.', '.'}
    },
    
    {
    	{'a', '.', '.', '.'},
        {'a', '.', '.', '.'},
        {'.', '.', '.', '.'},
        {'.', '.', '.', '.'}
	},
	
	{
    	{'a', '.', '.', '.'},
        {'a', '.', '.', '.'},
        {'a', 'a', '.', '.'},
        {'.', '.', '.', '.'}
	} 
    };   
	
	//displaying the pieces
	for (i = 0; i < 5; i++) {
        printf("%d\n", i + 1);
        displayPiece(4, pieces[i]);
    }
	
	
	
        
    int choice;
    int score = 0;
    int highestScore = 0;

    do {
        // Display the menu and get user choice
        choice = displayMenu();

        switch (choice) {
            case 1:
                // Start Game
                printf("Starting the game...\n");
                // Add game logic here
                displayBoard(rows, cols, board);
                printf
                 
                break;
            case 2:
                // Customize Grid Size
                customizeGridSize(&rows, &cols, &board);
                // Reinitialize the game board with the new size
                initializeBoard(rows, cols, board);
                printf("Grid size updated!\n");
                break;
            case 3:
                // Exit
                printf("Exiting the game. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

        // Display the current state of the game board
        if (choice == 2) {
            printf("Current Game Board:\n");
            displayBoard(rows, cols, board);
        }

    } while (choice != 3);

    // Free dynamically allocated memory
    for (i = 0; i < rows; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}