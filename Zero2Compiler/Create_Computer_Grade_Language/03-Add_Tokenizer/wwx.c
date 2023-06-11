#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define token type
typedef enum {
    TK_RESERVED, //reserved for operator token type
    TK_NUM,      //integer token type
    TK_EOF,      //end of line token type
}TokenKind;

typedef struct Token Token;

//Define token 
struct Token{
    TokenKind kind; //token's type
    Token *next;    //next token
    int val;        //integer when kind is TK_NUM
    char *str;      //tag text string
};

//Processing token
Token *token;

//Function to handle error
//Take the same arguments as printf
void error(char *fmt, ...){
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    exit(1);
}

bool consume(char op){
    if(token->kind != TK_RESERVED || token->str[0] != op)return false; //if next token is not expected operator return false
    token = token->next; //if next token is expected token, go next token
    return true;  //return true if next token is expected token
}

void expect(char op){
    if(token->kind != TK_RESERVED || token->str[0] != op)error("Not '%c'", op);//if next token is not expected operator warning error
    token = token->next;//if next token is expected operator, go next token
}

int expect_number(){
    if(token->kind != TK_NUM)error("Not integer");//if next token is not integer print Not integer
    int val = token->val; 
    token= token->next; 
    return val; //if next token is integer then go next token and return the integer
}

//Function to indicate is end of line
bool at_eof(){
    return token->kind == TK_EOF; //return true if end of line 
}

//Build a new token and link to current token
Token *new_token(TokenKind kind, Token *cur, char *str){
    Token *tok = calloc(1, sizeof(Token));
    tok->kind = kind;
    tok->str = str;
    cur->next = tok;
    return tok;
}

//tokenize text string p and return linked list token
Token *tokenize(char *p){
    Token head;
    head.next = NULL;
    Token *cur = &head;

    while(*p){
        if (isspace(*p)){p++;continue;}//Skip space

        if(*p=='+' || *p=='-'){
            cur = new_token(TK_RESERVED, cur, p++);
            continue;
        }//if is + or - create new_token with TK_RESERVED type 

        if(isdigit(*p)){
            cur = new_token(TK_NUM, cur, p); //create new_token with TK_NUM type
            cur->val = strtol(p, &p, 10); //set current token val 
            continue;
        }

        error("Tokenize error"); //If unexpected character detected then tokenize error

    }

    new_token(TK_EOF,cur,p); //Create new_token with TK_EOF type
    return head.next; //Return linked list token
    
}

int main(int argc, char **argv){
    if(argc != 2){error("Wrong number of arguments");return 1;}

    token = tokenize(argv[1]); //tokenize 

    printf(".intel_syntax noprefix\n");
    printf(".global main\n");
    printf("main:\n");
    printf("    mov rax, %d\n",expect_number());//the first mov instruction and make sure the first token is number

    //if not end of line then keep read next token
    while(!at_eof()){
        if(consume('+')){
            printf("    add rax, %d\n",expect_number());
            continue;
        } 

        expect('-');
        printf("    sub rax, %d\n", expect_number());
    }
    printf("    ret\n");
    return 0;
}