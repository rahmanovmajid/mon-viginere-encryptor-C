/*==========================================================*\
|    Sunday 03.02.2020                                       |
|   Fahmin Guliyev                                           |
|   encryptor.c                                               |
\*==========================================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>


    char  alpha[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *code[26];
    char *vigenere[26][26];




char *getEmojibyLetter(char letter){
    int i;
    if (letter >= 'a' && letter <= 'z') letter -= 32;
    for (  i = 0 ; i < strlen(alpha) ; i++ ){
        if ( alpha[i] == letter ){
            return code[i];
        }
    }
}


char *getEmojibyString(char *str){
    char ans[50] = {'\0'};
    for ( int i = 0 ; str[i] != 0 ; i++ ){
        strcat(ans,getEmojibyLetter(str[i]));
    }
    char *ans2 = ans;
    return ans2;
}


int getAlphaNum(char letter){
    for ( int i = 0 ; i < strlen(alpha) ; i++ ){
        if ( letter == i+65 ){
            return i+1;
        }
    }
}

int main() {
    
    char inputText[50];
    char inputSecret[50];
    

    system("figlet -f slant Encryptor");
    printf("\n|*******************************************************|");
    printf("\n|**********WELCOME TO CUSTOM CIPHER ENCRYPTOR!**********|\n");
    printf("|*******************************************************|\n");
    printf("Please enter the word you want encrypted : \n\n");
    scanf("%s",inputText);
    // fgets(inputText,sizeof(inputText),stdin);
    puts("");
    printf("Your PLAINTEXT is successfully processed.\nNow, please provide a secret to get the CIPHER : \n\n");
    scanf("%s",inputSecret);
    // fgets(inputSecret,sizeof(inputSecret),stdin);
    puts("");
    code[0] = ":)"; //A
    code[1] = ":D"; //B
    code[2] = ":|"; //C
    code[3] = ":O"; //D
    code[4] = ":("; //E
    code[5] = ":'("; //F
    code[6] = ">_<"; //G
    code[7] = ":X"; //H
    code[8] = "<3"; //I
    code[9] = ":'D"; //J
    code[10] = ":P"; //K
    code[11] = ";)"; //L
    code[12] = ":3"; //M
    code[13] = ":*"; //N
    code[14] = "8)"; //O
    code[15] = "8|"; //P
    code[16] = "o.O"; //Q
    code[17] = "(^^^)"; //R
    code[18] = ":V"; //S
    code[19] = ":|]"; //T
    code[20] = "O:)"; //U
    code[21] = "^_^"; //V
    code[22] = "<(*)"; //W
    code[23] = "-_-"; //X
    code[24] = "3:)"; //Y
    code[25] = ">:O"; //Z


    char vigchar;
    for( int i = 0 ; i < 26 ; i++ ) {
        for( int j = 0; j < 26 ; j++ ) {
            vigchar = 'A' + (i + j) % 26;
            vigenere[i][j] = getEmojibyLetter(vigchar);
        }
    }      //creating my own viginere table corresponding to assigned emoji's.


    int diff = strlen(inputText)-strlen(inputSecret);
    if ( diff != 0 ){
        if ( diff < 0  ){
            inputSecret[strlen(inputText)] = '\0';
        }
        else{ 
        /*  for ( int w=strlen(inputSecret),e=0 ; w < strlen(inputText) ; w++,e++){
                inputSecret[w] = inputSecret[e];
            }   
       
            old code (didn't work properly) so i changed it to below version. */
            
            while ( strlen(inputSecret) < strlen(inputText) ){
                strcat(inputSecret,inputSecret);
            }
            if ( strlen(inputSecret) != strlen(inputText) ){
                inputSecret[strlen(inputText)] = '\0';
            }
        }
    }// shortening or extending the plaintext/secret to each other

    for ( int l = 0 ; l < strlen(inputText) ; l++ ){
        if ( inputText[l] >= 'a' && inputText[l] <= 'z'  )  inputText[l] -= 32;  
    }   // convert every letter of the inputText to uppercase

    for ( int l = 0 ; l < strlen(inputSecret) ; l++ ){
        if ( inputSecret[l] >= 'a' && inputSecret[l] <= 'z'  )  inputSecret[l] -= 32;  
    } // the same operation for inputSecret


    printf("NewText: ");
    puts(inputText);
    printf("NewSecret: ");
    puts(inputSecret);
    printf("\nNow CIPHERTEXT is generating...\n");
    puts("Consider that printed CIPHERTEXT will be consist of space's between each emoji letters.\n");
    


    int textNum = 0,secretNum = 0;
    char *cipher = (char*) malloc(sizeof(char));

    for ( int b = 0 ; b < strlen(inputText) ; b++ ){
        textNum = getAlphaNum(inputText[b]);
        secretNum = getAlphaNum(inputSecret[b]);
        strcat(cipher,vigenere[textNum-1][secretNum-1]); // -1 because array index
        strcat(cipher," "); // to include space's between each emoji as spaces between letter of each word
    }    

    puts(cipher);   
    // for ( int n = 0 ; n < strlen(inputText)-1 ; n++ ){
    //     printf("%c  ",inputText[n]);
    // }
    
    // printf("%c\n",inputText[strlen(inputText)-1]);


    return 0;

}
