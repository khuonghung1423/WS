#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <stdbool.h>

void input(char s[]){
	printf("\nInput a string: ");
	fflush(stdin);
	gets(s);
}
void cutWord(char s[]){
	int count=0;
	char p[100]; strcpy(p,s);
	printf("*************************************************");
	printf("\nThe original string: ");
	puts(s);
	printf("\nNumber of words in the string: %d, they are: \n",countWord(s));
	char *token;
	token=strtok(p," \t");
	while(token!=NULL){
		puts(token);
		token=strtok(NULL," \t");
		count++;
	}
	printf("*************************************************");
}
void beautyCharacter(char s[]){
	char p[100]; strcpy(p,s);
    printf("*************************************************");
	printf("\nThe original string: ");
	puts(s);
	printf("The proper form: ");
	for(int i=0; i<=strlen(p); i++){
		if(p[i]==32&&p[i+1]!=32){
			if(p[i+1]>='a'&&p[i+1]<='z') p[i+1]-=32;
		}
		if(p[0]>='a'&&p[0]<='z') p[0]-=32;
	}
	puts(p);
	printf("*************************************************");
}

int countWord(char s[]){
	int word=0;
	for(int i=0; i<strlen(s); i++)
		if(s[i]!=32&&(s[i+1]==32||s[i+1]==NULL))	word++;
	return word;
}


void deleteSpace(char s[]){
	char p[100]; strcpy(p,s);
	printf("*************************************************");
	printf("\nThe original string: ");
	puts(s);
	printf("The cleaned form: ");
	for(int i=0; i<strlen(p); i++){
		if(p[i]==32&&p[i+1]==32){
			for(int j=i; j<strlen(p); j++)
				p[j]=p[j+1];
			i--;	
			p[strlen(p)]=NULL;
		}
	}
	if(p[0]==32){
		for(int i=0; i<strlen(p); i++)
			p[i]=p[i+1];
		s[strlen(p)]=NULL;
	}
	if(s[strlen(p)]==32)
		s[strlen(p)]=NULL;
	puts(p);
	printf("*************************************************");
}
void checkName(char s[]){
	printf("*************************************************\n");
	bool check=true;
	for(int i=0; i<strlen(s); i++){
		if(isalpha(s[i])==0&&s[i]!=32){
			check=false;
			break;
		}	
	}
	if(check==true)	printf("%s is a valid name\n",s);
	else printf("%s is not a valid name\n",s);
	printf("*************************************************\n");
}
int main(){
	char s[100];char next;
	system("cls");
	int selection;
	while(-1){
		printf("\nChoose one of the following options:\n");
		printf("1. Input a string\n");
		printf("2. Split a string into words\n");
		printf("3. Convert a string into proper form\n");
		printf("4. Remove redundant spaces\n");
		printf("5. Check valid name\n");
		printf("0. Exit\n");
		printf("Your selection (0->6): ");
		scanf("%d", &selection);
		switch(selection){
			case 1: input(s); break;
			case 2: cutWord(s); break;
			case 3: beautyCharacter(s); break;
			case 4: deleteSpace(s); break;
			case 5: checkName(s);break;
			case 0: return 0;
		}

   }
}
