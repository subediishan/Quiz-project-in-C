#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<ctype.h>


#define MAX_LENGTH 100

int score=0;
int got_highscore;
char uuid[MAX_LENGTH]; //intialized userid as global 

FILE *credentials;

//list of userdefined functions 

void signup(); //reads user id and password to create account
void call_questions1();
void call_questions2();
void call_questions3();
int  authenticate(char *,char *);
int gethighscore(char *id);
void initial_highscore(char *id);
void update_highscore();
int check_digits(int a); //checks no of digits in highscore in txt file





int main(){
    char response;
    int level,action,highscore;

    
   
    printf("\n\n\n-----------------------------welcome to the game------------------------------\n\n------------------------------------------------------------------------------ \n\n");
a:
printf("Login ---------------  1 \nsign up -------------  2\n");
scanf("%d",&action);

system("cls");
//checks whether the input credentials are valid or not 
if(action == 1){
    char inputUsername[MAX_LENGTH], inputPassword[MAX_LENGTH];

    // Get username and password input from the user
    printf("Enter username: ");
    scanf("%s", inputUsername);
    printf("Enter password: ");
    scanf("%s", inputPassword);

    // Authenticate the user
    if (authenticate(inputUsername, inputPassword)) {
        strcpy(uuid,inputUsername);
        system("cls");
        printf("Authentication successful. Welcome, %s!\n", uuid);
       

    } else {
        printf("Authentication failed. Incorrect username or password.\n");
goto a;   
 }

    
}
else if(action == 2){
signup();
goto a;
}
printf("Level : \n\n Hard ----------- input 1\n Medium --------- input 2\n Easy ------------input 3 \n\n");
    scanf("%d",&level);
    switch (level){
case 1:
call_questions3();

break;
case 2:
call_questions2();
break;
case 3:
call_questions1();
break;


    }



} 






//function for easy questions 

void call_questions1(){
int ans ,choice,z;
    char question[200];
    system("cls");
printf("\n\n\n\n----------------------round 1 ----------------------\n\n\n");
printf("which is the oldest national park of nepal \n 1.Chitwan national Park \n 2. langtang national park \n 3. Rara Natiional Park \n 4. Sagarmatha National park   ");
scanf("%d",&ans);
if(ans == 1)
score +=10;
system("cls");
printf("\n\n\nWho was the first king of Gopal Dynesty \n 1. Bhuktaman \n2. Yalambar \n3.Varsingh \n 4.Yakshya Gupta    ");
scanf("%d",&ans);
if(ans == 1)
score +=10;
system("cls");
printf("\n\n\n Which is the longest river in Nepal? \n 1. koshi \n 2. gandaki \n 3. karnali \n 4.Trishuli    ");
scanf("%d",&ans);
if(ans == 3)
score +=10;
system("cls");
printf("\n\n\n What is the capital city of France ? \n 1. Paris \n 2.Nice  \n 3. Abignon \n 4.Lyon    ");
scanf("%d",&ans);
if(ans == 4)
score +=10;
system("cls");
printf("\n\n\n  Tallest Peak of Nepal ? \n 1. k2 \n 2.Annapurna  \n 3.Dhaulagiri \n 4.Everest    ");
scanf("%d",&ans);
if(ans == 4)
score +=10;
system("cls");
printf("\n\n\n  Deficiency of which vitamin causes scurvy? \n 1. Vitamin A \n 2.Vitamin K  \n 3. Vitamin D \n 4.vitamin C   ");
scanf("%d",&ans);
if(ans ==4 )
score +=10;
system("cls");
printf("\n\n\n Who invented televison  ? \n 1.Marconi \n 2.JL Baird  \n 3.Thomas Alva Edison \n 4.Michale Farday   ");
scanf("%d",&ans);
if(ans == 2)
score +=10;
system("cls");
printf("Which is the country without snakes  ? \n 1.Iceland \n 2.France  \n 3.New zeland \n 4.Scotland   ");
scanf("%d",&ans);
if(ans == 1)
score +=10;

 printf("\n\n\ntotal score is  %d: ",score);
printf("\n\n\nDo you want to play round 2? (0/1): ");
    scanf("%d", &choice);
    if (choice == 1)
        call_questions2();
    else if (choice == 0) {
            update_highscore(); 
            printf("game finished press 0  ");
            scanf("%d",&z);
    }
}



// Define gethighscore and update_highscore functions if not already defined

// Declare call_questions3 function if not already defined

void call_questions2() {
    int choice,z;
    char ans[100];
    system("cls");
    printf("\n\n\n\n-----------------------ROUND 2 --------------------\n------------------------LETS PLAY --------------------------\n\n\n");
    printf("who was the first prime minister of Nepal?\n");
    scanf(" %[^\n]", ans); 
    if (strcmp(strupr(ans), "BP KOIRALA") == 0) { 
        
        score += 10;
    }
     printf("Which city is known as the city of temples ?\n");
    scanf(" %[^\n]", ans); 
    if (strcmp(strupr(ans), "KATHMANDU") == 0) { 
        
        score += 10;
    }
     printf("which is the lightest gas?\n");
    scanf(" %[^\n]", ans); 
    if (strcmp(strupr(ans), "HYDROGEN") == 0) { 
        
        score += 10;
    }
     printf("What is the national game of canada\n");
    scanf(" %[^\n]", ans); 
    if (strcmp(strupr(ans), "LACROSSE") == 0) {
        
        score += 10;
    }
     printf("Which organization was esblished after world war I?\n");
    scanf(" %[^\n]", ans); 
    if (strcmp(strupr(ans), "LEAGUE OF NATIONS") == 0) { 
        score += 10;
    }
     printf("Which mountain peak of nepal is also called ladies's peak?\n");
    scanf(" %[^\n]", ans); 
    if (strcmp(strupr(ans), "AMA DABLAM") == 0) {
        score += 10;
    }
       printf("which germs causes cholera?\n");
    scanf(" %[^\n]", ans); // Added a space before %[^\n] to consume the newline character
    if (strcmp(strupr(ans), "VIBRO CHOLERA") == 0) { 
        score += 10;
    }
       printf("Which veda is the oldest \n");
    scanf(" %[^\n]", ans); 
    if (strcmp(strupr(ans), "RIGVEDA") == 0) { 
        score += 10;
    }
       printf("Who was the last Rana prime minister \n");
    scanf(" %[^\n]", ans); 
    if (strcmp(strupr(ans), "MOHAN SUMSHER") == 0) { 
        
        score += 10;
    }


    printf("Your score: %d\n", score); // Print the score

    printf("Do you want to play round 3? (0/1): ");
    scanf("%d", &choice);
    if (choice == 1)
        call_questions3();
    else if (choice == 0) {
            update_highscore(); 
            printf("game finished press 0  ");
            scanf("%d",&z);
    }
}


//function for hard question / gambling round 

void call_questions3()

{
    system("cls");
    int ans,z;
    char answ[100];
      printf("-----------------ROUND 3 --------------------\n");
    printf("----------------Gambling Round ---------------\n----------Enter x If you want to pass the question -------\n\n\n\n\n ");
    printf("QUESTION : 0 \nHow many election areas are there in Kathmandu Distrit  \n\n\n");
    scanf(" %[^\n]",answ);
    if(strcmp(answ,"10")==0)
    score+=20;
    else if(ans!=1)
    score-=20;
    else if(strcmp(answ,"x")){
        printf("\n question passed");
    }
    system("cls");


    printf("QUESTION : 1 \n Who is awarded with Nobel Prize in Literature for year 2022?\n\n\n");
    scanf(" %[^\n]",answ);
    if(strcmp(strupr(answ),"ANNIE ERNAUX")==0)
    score+=20;
    
    else if(strcmp(answ,"x")){
        printf("\n question passed");
    }
    else
    score-=20;

    system("cls");
    printf("QUESTION : 2 \nWhat is the total population of Nepal according to primary report of census\n\n\n");
    scanf(" %[^\n]",answ);
    if(strcmp(strupr(answ),"29192480")==0)
    score+=20;
    
    else if(strcmp(answ,"x")){
        printf("\n question passed");
    }
    else
    score-=20;
    system("cls");
    
    printf("QUESTION : 3 \nWhich  is the bank to use Credit card for the first time in Nepal\n\n\n");
    scanf(" %[^\n]",answ);
    if(strcmp(strupr(answ),"HIMALAYAN BANK")==0)
    score+=20;
    
    else if(strcmp(answ,"x")){
        printf("\n question passed");
    }
    else
    score-=20;
system("cls");
    
    printf("QUESTION : 4 \nIn which district of Nepal kalapani is situated ?\n\n\n");
    scanf(" %[^\n]",answ);
    if(strcmp(strupr(answ),"DARCHULA")==0)
    score+=20;
    
    else if(strcmp(answ,"x")){
        printf("\n question passed");
    }
    else
    score-=20;
    
system("cls");
    printf("QUESTION : 5 \nWhat is the diagnosis test of typhoid called\n\n\n ?");
    scanf(" %[^\n]",answ);
    if(strcmp(strupr(answ),"WIDAL TEST")==0)
    score+=20;
    
    else if(strcmp(answ,"x")){
        printf("\n question passed");
    }
    else
    score-=20;

    


    printf("\n\n\n\nTHANK YOU FOR PLAYING  The total score is %d",score);
update_highscore();
printf("game finished press 0  ");
            scanf("%d",&z);

}




int authenticate(char *inputUsername, char *inputPassword) {
    FILE *filePointer;
    char username[MAX_LENGTH], password[MAX_LENGTH];
    int found = 0;

    
    filePointer = fopen("user_data.txt", "r");

    
    if (filePointer == NULL) {
        printf("File cannot be opened.\n");
        return 0;
    }

    // Read each line from the file and compare username and password
    while (fscanf(filePointer, "%s %s", username, password) != EOF) {
        if (strcmp(username, inputUsername) == 0 && strcmp(password, inputPassword) == 0) {
            found = 1;
            break;
        }
    }

    fclose(filePointer);

    return found;
}

//function to create an account
void signup(){
credentials =fopen("user_data.txt","a");
    char id[100],pasw[100];
printf("enter the user Id :\n ");
scanf("%s",id);
printf("enter the password ");
scanf("%s",&pasw);
fprintf(credentials,"%s %s\n",id,pasw);
fclose(credentials);
initial_highscore(id);

}

//writes highscore as 0 when the account is created
void initial_highscore(char *id) {
    FILE *file = fopen("highscore.txt", "a"); 
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Set initial highscore to 0 for the new user
    fprintf(file, "%s 00\n", id);
    fclose(file);

}
//reads highscore from the txt file
int gethighscore(char *id){
FILE *fp;
int sscore;//highscore as in txt file
char userid[100];
fp = fopen("highscore.txt","r");
while (fscanf(fp,"%s %d",&userid,&sscore)!=EOF)
{
if(strcmp(id,userid)==0){
    return sscore;
    fclose(fp);

}
}


}

//updates highscore if the secured score is greater than the highscore


void update_highscore(){
    FILE *fp;
int hs,hs_digits; //hs_digits is no of digits of highscore in text file

hs_digits=check_digits(uuid);
char uid[100],temp[100];
fp = fopen("highscore.txt","r+");

while(fscanf(fp,"%s %d",&uid,&hs)!=EOF){
    
if(strcmp(uuid,uid)==0){
    
    //snprintf(temp,sizeof(temp),"%d",score);
hs_digits = check_digits(gethighscore(uuid));
if(hs_digits==2)
  fseek(fp,-2,SEEK_CUR);  
  else if(hs_digits==3)
  fseek(fp,-3,SEEK_CUR); 
  else
  fseek(fp,-2,SEEK_CUR); 
fprintf(fp,"%d\n",score);
    fclose(fp);
    printf("NEW HIGH SCORE ! SCORE = %d\n\n",score);
   
    break;


}

}
}
//checks no of digits in a number
int check_digits(int a){
int r=0,s;
while(a>0){
r ++;
a = a/10;

}
return r;
}

    
