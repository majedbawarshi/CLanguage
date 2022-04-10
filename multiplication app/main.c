#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("welcome to the multiplication game!\n");
    printf("levels:\n");
    printf("level 1: 1 * 1->10\n");
    printf("level 2: 2 * 1->10\n");
    printf("level 3: 3 * 1->10\n");
    printf("level 4: 4 * 1->10\n");
    printf("level 5: 5 * 1->10\n");
    printf("level 6: 6 * 1->10\n");
    printf("level 7: 7 * 1->10\n");
    printf("level 8: 8 * 1->10\n");
    printf("level 9: 9 * 1->10\n");
    printf("level 10: 10 * 1->10\n");
    printf("level -1: 1->10 * 1->10\n");
    printf("-------------------------------\n");
    printf("each level consist of 30 turn, and 100 turn for the level -1\n\n");
    numberValidation();
    return 0;
}
void numberValidation(){
    int x;
    printf("enter the level you want:");
    scanf("%d",&x);
    printf("\n");
    if(x==0||x>10||x<-1){
        printf("--------------------------------\n");
        printf("please enter a valid number!\a\n\n");
        numberValidation();
    }else{
        game(x);
    }
}
int Score(int correct,int score){
        if(correct>1){
                return(score=score+200);
            }
        else if(correct==0){
                return(score=score-500);
            }
        else{
                return(score=score+100);
            }
}
void game(int x){
    printf("---------------------------------------------------\n");
    printf("If you wanted to change the level please press 969!\n");
    printf("---------------------------------------------------\n\n");
    int r=1,y,num,score=0,correct=0;
    if (x==-1){
        num=100;
    }else{
        num=30;
    }
    while(r<=num){
        int i=rand()%1 + x;
        int j=rand()%10 + 1;
        int k;
        if (x==-1){
            i=rand()%10 + 1;
        }
        printf("%d * %d =",i,j);
        scanf("%d",&k);
        if(k==969){
            printf("you have pressed 969 you have to pick a new level!\n");
            numberValidation();
        }
        if(k != i*j){
            correct=0;
            score=Score(correct,score);
            printf("you'r answer is wrong!\n");
            printf("the correct answer is %d\nscore=%d, turn=%d\n",i*j,score,r);
            printf("--------------------------------\n");
        }else{
            correct++;
            score=Score(correct,score);
            printf("you'r answer is correct :) !\nscore=%d, turn=%d\n",score,r);
            printf("--------------------------------\n");
        }
        r++;
    }if(r>num){
        printf("\n");
        printf("enter the new level you want:");
        scanf("%d",&y);
        printf("\n");
        game(y);
    }

}
