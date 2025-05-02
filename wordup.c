//Projrect 10
//Alexis Bierman 
//wordup.c 


	#include<stdio.h>
	#define GUESS 6
	#define WORD_LENGTH 5
	
	void drawBorder();
	void Hint(char Guesses[GUESS][WORD_LENGTH+1],char FileWord[WORD_LENGTH+1], char Hints[GUESS][WORD_LENGTH+1], int guessIndex, char Arrows[GUESS][WORD_LENGTH+1], char used[WORD_LENGTH+1]);
	char CapitalizeLetters( char U);
	char LowercaseLetters( char L);
	void ConvertLower( char input[WORD_LENGTH+1]);
	int DubsorNot(char Guesses[GUESS][WORD_LENGTH+1], char FileWord[WORD_LENGTH+1], int guessIndex);
	
	int main(){
	
	int YAY=0;
	
	char FileWord[WORD_LENGTH+1], Guesses[GUESS][WORD_LENGTH+1], Hints[GUESS][WORD_LENGTH+1], Arrows[GUESS][WORD_LENGTH+1], input[WORD_LENGTH+1], used[WORD_LENGTH+1];
	int guessIndex, i;
	FILE* mysteryWord;
	
	mysteryWord = fopen("mystery.txt", "r");
		if(mysteryWord == NULL)
		{
			printf("There was an error reading you file:(");   
		 return 1;
		 }
	fscanf(mysteryWord, "%5s", FileWord);
	fclose(mysteryWord);
	ConvertLower(FileWord);
	
	
		for(int i= 0; i< GUESS; i++)
		{
		int guessLength =0;
		if(i == GUESS-1)
		{
	printf("FINAL GUESS : ");
	}else 
	{
	printf("GUESS %d! Enter your guess: ",i+1);}
	
	scanf("%s", Guesses[i]);
	ConvertLower(Guesses[i]);	
		for( int j= 0; Guesses[i][j] != '\0' ; j++)
		{		
	guessLength++;
	}
		
		if(guessLength != WORD_LENGTH)
		{
	printf("Your guess must be 5 letters long.\nPlease try again: ");	
	scanf("%s", Guesses[i]);
	ConvertLower(Guesses[i]);

	}
	
	drawBorder();
	if (DubsorNot(Guesses, FileWord, i) == 1)
	{
	break;}
	
	Hint(Guesses, FileWord, Hints, i, Arrows, used);
	for(int j = 0; j<GUESS; j++)
	{
	printf("%s\n", Hints[j]);
	printf("%s\n", Arrows[j]);
	}}
	if (YAY ==0)
	{
	printf("You lost! Better luck next time\n");
	}
	
	return 0;
	
	}
	
	
	void drawBorder(){
		for(int i= 0; i<=32; i++)
		{
			printf("=");
			}printf("\n");
		}
	
	char CapitalizeLetters( char U){
		if (U >= 'a'&& U<= 'z') 
		{
			return U - ('a'-'A');
			}return U;
			}
	char LowercaseLetters( char L){
		if (L >= 'A' && L <= 'Z')
		{
			return L + ('a'-'A');
			}return L;
			}
	void ConvertLower(char input[WORD_LENGTH +1]){
		 for(int i =0; i<WORD_LENGTH; i++)
		 {
		 input[i]= LowercaseLetters(input[i]);
			 }
		 	 }
	
	void Hint(char Guesses[GUESS][WORD_LENGTH+1], char FileWord[WORD_LENGTH+1], char Hints[GUESS][WORD_LENGTH+1], int guessIndex, char Arrows[GUESS][WORD_LENGTH+1], char used[WORD_LENGTH+1]){	
			char usedIndex[WORD_LENGTH+1] = {0};
		for(int i = 0; i<WORD_LENGTH; i++)
		{
			Hints[guessIndex][i] = Guesses[guessIndex][i];
			Arrows[guessIndex][i] = ' ';
			}
		for( int i=0; i<WORD_LENGTH; i++) 
		{
		
		if(Guesses[guessIndex][i] == FileWord[i])
		 {
			Hints[guessIndex][i] = CapitalizeLetters(Guesses[guessIndex][i]);
			Arrows[guessIndex][i]= ' ';
			usedIndex[i] = 1;
		}else
			{
			 Hints[guessIndex][i] = LowercaseLetters(Guesses[guessIndex][i]);
	
			 	}}
			 
		for(int i = 0; i< WORD_LENGTH; i++)
		{
		if(Guesses[guessIndex][i] != FileWord[i])
		{
		for(int l=0; l< WORD_LENGTH; l++)
		{
		if(Guesses[guessIndex][i] == FileWord[l])
		{
			 	Arrows[guessIndex][i] = '^';
			 	usedIndex[l] = 1;
			 	}
			 	 }
			 	  }
			 	   }
			 	    }
			 	
			 	int DubsorNot(char Guesses[GUESS][WORD_LENGTH+1], char FileWord[WORD_LENGTH+1], int guessIndex){

	
		for(int i=0; i<WORD_LENGTH+1; i++){
		
		if(Guesses[guessIndex][i] != FileWord[i])
		{
		return 0;
		 }
		 	}	
	
	
		for (int i=0; i<17; i++)
		{
	printf(" ");
	}
		for(int i=0; i<WORD_LENGTH; i++)
		{
	Guesses[guessIndex][i] = CapitalizeLetters(Guesses[guessIndex][i]);
	printf("%c", Guesses[guessIndex][i]);
	}
		for (int i=0; i<17; i++)
		{
		
	printf(" ");
	}
	printf("\n        You won in %d guesses!     \n", guessIndex+1);
	printf("              GOATED!!!          \n");
		return 1;
		}
	
		
		
