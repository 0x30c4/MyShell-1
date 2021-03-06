/* ------------------------------ Includes ------------------------------- */

#include "../include/tokens.h"

/* ------------------------ Function Definitions ------------------------ */

void tokenize(char * input, char *** tok, int * num_tok){
    int i;

    char ** tokens = (char **)malloc(sizeof(char *) * 1);
    tokens[0] = (char *)calloc(sizeof(char *), 1);
    int num_tokens = 0;

    char * temp = NULL;
    temp = strtok(input, " \n\t");
    tokens[num_tokens] = (char *)realloc(tokens[num_tokens], sizeof(char) * (strlen(temp) + 1));
    strcpy(tokens[num_tokens], temp);
    tokens[num_tokens][strlen(temp)] = '\0';

    num_tokens++;    
    tokens = (char **)realloc(tokens, sizeof(char *) * (num_tokens + 1));

	while((temp = strtok(NULL, " \n\t")) != NULL) {
        tokens[num_tokens] = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
        strcpy(tokens[num_tokens], temp);
        tokens[num_tokens][strlen(temp)] = '\0';
        num_tokens++;
        tokens = (char **)realloc(tokens, sizeof(char *) * (num_tokens + 1));
    }

    free(temp);
    
    *tok = (char **)malloc(sizeof(char *) * num_tokens);
    for(i = 0; i < num_tokens; i++){
	if(tokens[i][0]=='$'){
		char * temp_tok = (char *)malloc(sizeof(char)*1);
		int j;
		for(j = 0;j<strlen(tokens[1])-1;j++){
			temp_tok = (char *)realloc(temp_tok,sizeof(char)*j+1);
			temp_tok[j]=tokens[1][j+1];
		}
		temp_tok = (char *)realloc(temp_tok,sizeof(char)*j+1);
		temp_tok[j] = '\0';
		temp = getenv(temp_tok);
		if(temp == NULL){
			perror("getenv");
			return;
		}
		else{
			(*tok)[i] = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
			strcpy((*tok)[i], temp);
			(*tok)[i][strlen(tokens[i])] = '\0';
		}
	}
	else{	
		(*tok)[i] = (char *)malloc(sizeof(char) * (strlen(tokens[i]) + 1));
		strcpy((*tok)[i], tokens[i]);
		(*tok)[i][strlen(tokens[i])] = '\0';
	}
    }

    *(num_tok) = num_tokens;

    for(i = 0; i < num_tokens; i++){
        free(tokens[i]);
    }
    free(tokens);
    //free(temp);
    return ;
}

void print_tokens(char ** tokens, int num_tokens){
    int i = 0;
    for(i = 0; i < num_tokens; i++){
        printf("%s\t", tokens[i]);
    }
    printf("\n");
}
