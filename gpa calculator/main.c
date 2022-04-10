#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input();
void semesterGpa();
void fullGpa();
void SaveGpaInput();
void notSavingGpaInput();
void notSavingGpa(int seNum,int seOp);
float GR(float igr,float igr2);
int main()
{
    system("COLOR A");
    printf("\t\t\t\t\t ______________________________________\n");
    printf("\t\t\t\t\t|                                      |\n");
    printf("\t\t\t\t\t|     Welcome to GPA calculator App!   |\n");
    printf("\t\t\t\t\t|    	Created by MAJED BAWARSHI      |\n");
    printf("\t\t\t\t\t|______________________________________|\n\n");
    printf("\t\t\t\t     Please Enter the information carefully below!\n\n\n");

    input();

    return 0;
}
void input(){
    int o;
    printf("Please choose one of the below:\n");
    printf("(1) Calculate a semester GPA.\n");
    printf("(2) Calculate cum GPA (general GPA for all semesters).\n");
    printf("-");
    scanf("%d",&o);
    if(o==1){
        printf("\ncalculating semester GPA..\n\n");
        semesterGpa();
    }
    else if(o==2){
        fullGpa();
    }else{
        printf("\nYou have entered invalid character!\a\nPlease enter a valid character\n\n");
        input();
    }
}
/*void semesterGpa(){
    int subNum,gCredet;
    printf("Enter your amount of subjects:");
    scanf("%d",&subNum);
    printf("Enter your total semester subject credit:");
    scanf("%d",&gCredet);
    printf("\n\n");
}*/
void semesterGpa(){

    int x,ECTS,subNum,gCredet;//x=variable for for loop ,ECTS =subject credit
    char gr[2];//result of the subject in letters e.g AA
    float wg=0.0,tWg=0.0,igr=0.0,igr2=0.0,gpa,tgr=0.0;//wg= ects*gr,twWg total wg,iGr int gr,tgr total gr

    printf("Enter your amount of subjects:");
    scanf("%d",&subNum);
    printf("Enter your total semester subject credit:");
    scanf("%d",&gCredet);
    printf("\n\n");

    for(x=0;x<subNum;x++){
        printf("Enter your %d subject result in letter:",x+1);
        scanf("%s",&gr);

        printf("Enter your %d subject ECTS:",x+1);
        scanf("%d",&ECTS);

        strupr(gr);
        igr=(int) gr[0];//casting
        igr2=(int) gr[1];//casting

        tgr=GR(igr,igr2);//returning the result of GR (grade) in number

        wg=ECTS * tgr;//Weighted Grade calculating

        tWg=tWg+wg;//the total weighted grade of the semester

    }
    gpa=tWg/gCredet;
    printf("your total GPA is :%.2f",gpa);
    //printf("gpa:%.2f\t tWg=%f\t gCredet=%d",gpa,tWg,gCredet);
}
void fullGpa(){
    char g;
    printf("\nDo you want to save the result on your computer?(c drive)\n If yes please press y if no press n\n-");
    scanf("%s",&g);
    if (g=='Y'||g=='y'){
        printf("\nThank you!\nYour data will be saved on C:\\ Program Files (x86) named as Your GPA ");//text to confirm to user the directory.
        printf("\nadd all information below carefully ! :)");
        SaveGpaInput();
    }
    else if(g=='N'||g=='n'){
        printf("\nThank you! add all information below carefully ! :)\n");
        notSavingGpaInput();
    }
    else{
        printf("You have entered invalid character!\a please try again:");
        fullGpa();
    }

}
void SaveGpaInput(){
    //seNum=semester number,seOp=semester option

            //make an execlusive function for this
            //you were thinking to add as same as n option in here but just add
            //an writing on an external file write commands.
}
void notSavingGpaInput(){
    int seNum,seOp;
    printf("\nEnter how many semester you want to know the total GPA of:");
    scanf("%d",&seNum);

    printf("\nPlease select one of the below:");
    printf("\n(1) Enter the general GPA of each semester (making sure if your GPA have been calculated correctly).");
    printf("\n(2) Enter the general GPA of each semester and add the last semester marks manually(by you).");
    printf("\n(3) Enter each subject of each semester manually (by you).\n-");
    scanf("%d",&seOp);

    notSavingGpa(seNum,seOp);
}
void notSavingGpa(int seNum,int seOp){
            int i,x,ECTS,subNum,gCredet,tECTS=0,gECTS=0;//x=variable for for loop ,ECTS =subject credit,gECTS=general credits
            char gr[2];//result of the subject in letters e.g AA
            float semGpa,tGpa=0.0,wg=0.0,tWg=0.0,igr=0.0,igr2=0.0,gpa,tgr=0.0,gWg=0.0;//semGpa=semester gpa,tGpa=total gpa,wg= ects*gr,twWg total wg,iGr int gr,tgr total gr,gwg=general wg

            if(seOp==1){
                //wrong equation fix it whenever you can.
                //for general gpa calculating without entering any of the subjects marks manually
                for (i=0;i<seNum;i++){
                    printf("Enter your %d semester GPA:",i+1);
                    scanf("%f",&semGpa);

                    if(semGpa>4||semGpa<0){
                        printf("\nYou have entered invalid GPA please try again!");
                        seOp=1;
                        notSavingGpa(seOp,seNum);
                    }
                    else{
                        tGpa=tGpa+semGpa;

                        if(i+1==seNum){
                            tGpa=tGpa/seNum;
                            printf("Your total semesters GPA is: %.2f",tGpa);
                        }
                    }
                }

            }
            else if(seOp==2){
                for (i=0;i<seNum;i++){
                    printf("Enter your %d semester GPA:",i+1);
                    scanf("%f",&semGpa);

                    if(semGpa>4||semGpa<0){
                        printf("\nYou have entered invalid GPA please try again!");
                        seOp=2;
                        notSavingGpa(seOp,seNum);
                    }
                    else{
                        tGpa=tGpa+semGpa;

                        if(i+1==seNum){
                            printf("Enter your last semester amount of subjects:");
                            scanf("%d",&subNum);
                            printf("Enter your total last semester subject credit:");
                            scanf("%d",&gCredet);
                            printf("\n\n");

                            for(x=0;x<subNum;x++){
                                printf("Enter your %d last semester subject result in letter:",x+1);
                                scanf("%s",&gr);

                                printf("Enter your %d semester subject ECTS:",x+1);
                                scanf("%d",&ECTS);

                                strupr(gr);
                                igr=(int) gr[0];//casting
                                igr2=(int) gr[1];//casting

                                tgr=GR(igr,igr2);//returning the result of GR (grade) in number

                                wg=ECTS * tgr;//Weighted Grade calculating

                                tWg=tWg+wg;//the total weighted grade of the semester

                            }
                            gpa=tWg/gCredet;
                            tGpa=tGpa+gpa;
                            printf("your total semesters GPA is: %f",tGpa);
                        }
                    }
                }
            }
            else if(seOp==3){
                    for(i=0;i<seNum;i++){
                            //the result will be wrong after calculating because the repeated sub is not aware
                            printf("\nEnter your %d semester amount of subjects:",i+1);
                            scanf("%d",&subNum);
                            printf("Enter your total %d semester subject credit:",i+1);
                            scanf("%d",&gCredet);
                            printf("\n\n");

                            for(x=0;x<subNum;x++){
                                printf("Enter your %d semester %d subject result in letter:",i+1,x+1);
                                scanf("%s",&gr);

                                printf("Enter your %d semester %d subject ECTS:",i+1,x+1);
                                scanf("%d",&ECTS);

                                strupr(gr);
                                igr=(int) gr[0];//casting
                                igr2=(int) gr[1];//casting

                                tgr=GR(igr,igr2);//returning the result of GR (grade) in number

                                tECTS=tECTS+ECTS;//calculating total credit which been taken so far

                                wg=ECTS * tgr;//Weighted Grade calculating

                                tWg=tWg+wg;//the total weighted grade of the semester

                            }

                            gECTS=gECTS+tECTS;//general ects of all the user semesters
                            gWg=gWg+tWg;//general wg for all the user semesters
                            gpa=gWg/gECTS;
                            printf("your total %d semester GPA is: %.2f",i+1,tGpa);
                    }
                    /*gpa=gWg/gECTS;
                    printf("your total semesters GPA is: %.2f",tGpa);*/
            }
            else{
                printf("\nyou have chosen invalid character!\a please try again");
                notSavingGpaInput();
            }


    }
float GR(float igr,float igr2){
    //fix this for the following ac,ad,af,bc,bd,bf,cf or opposite in the sending function
    float aGR=0.0,aGR2=0.0,taGr=0.0;

    if (igr == 65){aGR = 2.0;}
    else if (igr == 66){aGR = 1.5;}
    else if (igr == 67){aGR = 1.0;}
    else if (igr == 68){aGR = 0.5;}
    else if (igr == 70){aGR = 0.0;}

    if (igr2 == 65){aGR2 = 2.0;}
    else if (igr2 == 66){aGR2 = 1.5;}
    else if (igr2 == 67){aGR2 = 1.0;}
    else if (igr2 == 68){aGR2 = 0.5;}
    else if (igr2 == 70){aGR2 = 0.0;}

    taGr=aGR+aGR2;
    return taGr;
}
