#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

void fime()
{   printf("Welcome to Find-Me Game\n");
    int fimebool = 0;
    while(fimebool==0){
      
      char *fimeinput=(char *)malloc(sizeof(char)*255);
         while(1)
        {
        char * temp=(char *)malloc(sizeof(char)*255);
        printf("What is the maximum number for selection? ");  
        scanf("%s",temp);
        
        
        
         if(strcmp("quit",temp)==0)
         {
             printf("see you next time\n");
             fimebool=1;
             break;
         }else{ 
             int x=atoi(temp);
             if(x!=0){
              fimeinput=temp;
		fimebool=0;
              break;
            }else{
                printf("not a valid input\n");
            }
        }
        }
        if(fimebool==1){
            break;
        }
      printf("I chose 1 number between 1 to ");printf("%s",fimeinput);
      
      int bool;
      bool = 1;
      
      
      
      srand((unsigned) time(NULL));
      
      int max = atoi(fimeinput);
      int r = (rand() % max)+ 1;
      
      int nb=0;
      
      int guess;
      while(1)
      {   nb++;
          char *t=(char *)malloc(sizeof(char)*1);
          char *finalinput=(char *)malloc(sizeof(char)*255);
          printf("\nNow find me(e.g., 1):");
          scanf("%s",finalinput);
          scanf("%c",t);
          if(t[0]!='\n'){
              scanf("%*[^\n]%*c");
              guess=-1;
          }else{
          guess = atoi(finalinput);
          }
          if(strcmp("quit",finalinput)==0){
             fimebool=1;
             break;
          }else if(guess<1){
               printf("[ERROR] You must enter one number between 1 to ");
               printf("%s",fimeinput);
               nb--;
          }else if(guess>r){
              printf("[");printf("%d", nb);printf(" trial] Less than ");
              printf("%s",finalinput);
          }else if(guess<r){
              printf("[");printf("%d",nb);printf(" trial] Greater than ");
              printf("%s",finalinput);
          }else if (guess==r){
              printf("You got it in ");printf("%d",nb);
              printf(" trial(s)!");
              break;
          }
          
      }
      //break out of game but needs fixing too
        if(fimebool==1){
            printf("See you next time!\n");
            break;
        }
        
      while(1){
          printf("\nDo you want to play more(y/n)? ");
          scanf("%s",fimeinput);
          if(strcmp("quit",fimeinput)==0){
              printf("See you next time!");
              fimebool=1;
              break;
          }else if(strcmp("n",fimeinput)==0){
              fimebool=1;
              break;
          }else if(strcmp("y",fimeinput)==0){
              printf("\n");
              break;
          }else{
              printf("Invaild input");
          }
      }
      
    }
    printf("\n");
}


void nuba()
{
    printf("Welcome to Number-Baseball Game\n");
    int nubabool=0;
    while(nubabool==0){
        
        printf("I set 3 distinct number-balls between 1 to 9");
        srand((unsigned) time(NULL));
        int numberballs[3];
       for(int i=0;i<3;i++){//generates base set
           numberballs[i] = (rand() % 9)+ 1;
       }
       while(1){//checks for doubles and changes it
           if(numberballs[0]==numberballs[1]){
               numberballs[0] = (rand() % 9)+ 1;
           }else if(numberballs[0]==numberballs[2]){
               numberballs[1] = (rand() % 9)+ 1;
           }else if(numberballs[1]==numberballs[2]){
               numberballs[2] = (rand() % 9)+ 1;
           }else{
               break;
           }
       }
       
       
       int in;
       int trials=0;
       while(1){//main game segment
            int i;
            int num1=0,num2=0,num3=0;
           trials++;
           int tempstrikes=0;
           int tempballs=0;
           in++;
           printf("\nPitch your 3 number-balls(e.g., 123): ");
           char *input1=(char *)malloc(sizeof(char)*255);
           char *s1=(char *)malloc(sizeof(char)*1);
           
           scanf("%s",input1);
           scanf("%c",s1);
            num1=atoi(input1);
           if(strcmp("quit",input1)==0&&s1[0]=='\n'){
               printf("See you next time!\n");
               nubabool=1;
               break;
           }else if(num1>9 || num1==0 || num1<0 || s1[0]=='\n'){//checks 1 char
               tempstrikes=-1;tempballs=-1;
               if(s1[0]!='\n'){
                   scanf("%*[^\n]%*c"); 
                }
           }else{
               //checks 2nd char
               char *input2=(char *)malloc(sizeof(char)*255);
               char *s2=(char *)malloc(sizeof(char)*1);
               scanf("%s",input2);
               scanf("%c",s2);
               num2=atoi(input2);
               if(num2>9 || num2<0 || num2==0 || s2[0]=='\n'){
                tempstrikes=-1;tempballs=-1;
                if(s2[0]!='\n'){
                   scanf("%*[^\n]%*c"); 
                }
                
               }else{
                   //checks 3rd char
                    char *input3=(char *)malloc(sizeof(char)*255);
                    char *s3=(char *)malloc(sizeof(char)*1);
                    scanf("%s",input3);
                    scanf("%c",s3);
                    num3=atoi(input3);
                    if(num3>9 || num3<0 || num3==0 || s3[0]!='\n'){
                         tempstrikes=-1;
                         tempballs=-1;
                         if(s3[0]!='\n'){
                            scanf("%*[^\n]%*c"); 
                         }
                       
                    }else{
                        //start of matching
                        for(i=0;i<3;i++){
                           if(numberballs[i]==num1&&i==0){
                               tempstrikes++;
                           }else if(numberballs[i]==num1&&i!=0){
                               tempballs++;
                           }
                       }
                       for(i=0;i<3;i++){
                           if(numberballs[i]==num2&&i==1){
                               tempstrikes++;
                           }else if(numberballs[i]==num2&&i!=1){
                               tempballs++;
                           }
                       }
                       for(i=0;i<3;i++){
                           if(numberballs[i]==num3&&i==2){
                               tempstrikes++;
                           }else if(numberballs[i]==num3&&i!=2){
                               tempballs++;
                           }
                       }
                        //end of matching
                    }
               }
           }
           
           
          
           
           if(tempstrikes>0&&tempballs>0){//determines output
               printf("[");printf("%d",trials);printf("  inning]  ");
               printf("%d",tempstrikes); printf(" Strike "); 
               printf("%d",tempballs); printf(" Ball");
           }else if(tempstrikes==3){
                printf("[");printf("%d",trials);printf("  inning] 3 Strike! You win in ");
                printf("%d",tempstrikes);printf(" inning(s).");
                break;
           }else if(tempstrikes==0&&tempballs>0){
               printf("[");printf("%d",trials);printf("  inning]  ");
               printf("%d",tempballs); printf(" Ball");
           }else if(tempstrikes>0&&tempballs==0){
               printf("[");printf("%d",trials);printf("  inning]  ");
               printf("%d",tempstrikes); printf(" Strike"); 
           }else if(tempstrikes==0&&tempballs==0){
               printf("[");printf("%d",trials);printf("  inning]  Nothing");
           }else if(tempstrikes==-1&&tempballs==-1){
               printf("[Error] You must enter only 3 numbers between 1 to 9");
               trials--;
           }
       }
       
       if(nubabool==1){
           printf("\n");
           break;
       }
       
       char *last=(char *)malloc(sizeof(char)*255);
          printf("\nDo you want to play more(y/n)? ");
          scanf("%s",last);
          while(1){
          if(strcmp("y",last)==0){
              printf("\nComputer sets 3 distinct number-balls between 1 to 9.");
              break;
          }else if(strcmp("n",last)==0){
              nubabool=1;
              break;
          }else if(strcmp("quit",last)==0){
              printf("\nSee you next time!\n");
              nubabool=1;
              break;
          }else{
              printf("Invaild input\n");
          }
          }
       
    }
}

int main()
{
    int x = 1;
    printf("do you want to play fime, nuba or quit \n");
    while(x!=0)
    {
     char *input=(char *)malloc(sizeof(char)*225);
     char *dump=(char *)malloc(sizeof(char)*1);
     scanf("%s",input);
     scanf("%c",dump);
     if(strcmp("fime",input)==0&&dump[0]=='\n')
     {
         fime();
     }else if(strcmp("nuba",input)==0&&dump[0]=='\n')
     {
         nuba();
     }else if(strcmp("quit",input)==0&&dump[0]=='\n')
     {
         printf("Closing program");
         x=0;
     }else{printf("incorrect command\n");
         if(dump[0]!='\n'){
            scanf("%*[^\n]%*c");  
         }
     }
    }
    return 0;
}







