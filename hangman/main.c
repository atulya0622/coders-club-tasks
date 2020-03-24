#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


void hangman(int z)
{
    switch(z)
    {
case 0:
        printf("\n  --------\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("       -----\n");
        break;
case 1:
        printf("\n  --------\n");
        printf("  |      |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("       -----\n");
        break;
case 2:
        printf("\n  --------\n");
        printf("  |      |\n");
        printf("-----    |\n");
        printf("|. .|    |\n");
        printf("-----    |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("       -----\n");
        break;
case 3:
        printf("\n  --------\n");
        printf("  |      |\n");
        printf("-----    |\n");
        printf("|. .|    |\n");
        printf("-----    |\n");
        printf("  |      |\n");
        printf("  |      |\n");
        printf("  |      |\n");
        printf("  |      |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("       -----\n");
        break;
case 4:
        printf("\n  --------\n");
        printf("  |      |\n");
        printf("-----    |\n");
        printf("|. .|    |\n");
        printf("-----    |\n");
        printf("  |      |\n");
        printf(" /|      |\n");
        printf("/ |      |\n");
        printf("  |      |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("       -----\n");
        break;
case 5:
        printf("\n  --------\n");
        printf("  |      |\n");
        printf("-----    |\n");
        printf("|. .|    |\n");
        printf("-----    |\n");
        printf("  |      |\n");
        printf(" /|\     |\n");
        printf("/ | \    |\n");
        printf("  |      |\n");
        printf("         |\n");
        printf("         |\n");
        printf("         |\n");
        printf("       -----\n");
        break;
case 6:
        printf("\n  --------\n");
        printf("  |      |\n");
        printf("-----    |\n");
        printf("|. .|    |\n");
        printf("-----    |\n");
        printf("  |      |\n");
        printf(" /|\     |\n");
        printf("/ | \    |\n");
        printf("  |      |\n");
        printf(" /       |\n");
        printf("/        |\n");
        printf("         |\n");
        printf("       -----\n");
        break;
case 7:
        printf("\n  --------\n");
        printf("  |      |\n");
        printf("-----    |\n");
        printf("|. .|    |\n");
        printf("-----    |\n");
        printf("  |      |\n");
        printf(" /|\     |\n");
        printf("/ | \    |\n");
        printf("  |      |\n");
        printf(" / \     |\n");
        printf("/   \    |\n");
        printf("         |\n");
        printf("       -----\n");
        break;
    }
}
/*char * update_guess(char* str1,char* str,char ch)
{
    int i;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]==ch)
        {
            str1[i]=ch;
        }
        else
            str1[i]='_';
    }
    return str1;
}*/
int is_correct(char* str1,char* str)
{
    int i,count=0;
    for(i=0;i<strlen(str);i++)
    {
  if(str1[i]==str[i])
    count++;
    }
    if(count==strlen(str))
        return 1;
  else
    return 0;
}

int main()
{
    char *movie[3]={"ANNABELLE","AVENGERS","SPIDERMAN"};
    int x,len,i,j,z=0,turn=0,flag=0;
    char *wrong[15];

    char ch,ch1;
    printf("Welcome to the HANGMAN game\n");
    printf("Guess the name of the movie\n");
    printf("\n");
    srand(time(0));
    x=rand()%3;

    len=strlen(movie[x]);

    char *film;
    char *film1=(char*)malloc(len*sizeof(char));

    film=(char*)malloc(len*sizeof(char));
    strcpy(film,movie[x]);
    printf("Movie: ");
    for(i=0;i<len;i++)
    {
        film1[i]='_';
        printf("%c ",film1[i]);
    }
    printf("\n\n");
    hangman(z);


    do{


    printf("Enter your guess\n");
    scanf(" %c",&ch);
    ch=toupper(ch);
    printf("\n");
    turn++;
    int flag=0;
    for(i=0;i<len;i++)
    {
        if(ch==film[i])
        {
            printf("Your guess is correct\n");
            flag=1;
        break;
        }
    }
    if(flag==1)
    {
        //film1=update_guess(film1,film,ch);
        for(j=0;j<len;j++)
        {
            if(ch==film[j])
                film1[j]=ch;
        }
        for(j=0;j<len;j++)
            printf("%c ",film1[j]);
        printf("\n");
        hangman(z);
    }
    else{
        printf("Your guess is wrong\n");
        for(j=0;j<len;j++)
            printf("%c ",film1[j]);
        wrong[z]=ch;
        z++;
        printf("Wrong guesses: ");
        for(j=0;j<z;j++)
        {
            printf("%c",wrong[j]);
            printf(" ");
        }
            printf("\n");
            hangman(z);

    }

    if(is_correct(film1,film)==1)
    {
        printf("You Won!!\n");
    return 0;
    }
    printf("Do You want to continue?(y/n)\n");
    scanf(" %c",&ch1);
    if(ch1=='y'||ch1=='Y')
        system("cls");
    else
        exit(0);


    }while(z!=7);

    return 0;
}


