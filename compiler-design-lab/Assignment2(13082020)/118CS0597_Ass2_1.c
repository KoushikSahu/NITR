#include<stdio.h>
#include<string.h>
#include<stdbool.h>

void fill(int dfa[][256],char s[]){
    int n = strlen(s);
    for(int i=0; i<256; i++)
        dfa[0][i] = 0;
    int X = 0;
    dfa[0][s[0]] = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<256;j++)
            dfa[i][j] = dfa[X][j];
        dfa[i][s[i]] = i+1;
        X = dfa[X][s[i]];
    }
}

void fillOther(int dfa[256][3]){
    
	for(int i=0; i<256; i++)
	{
		dfa[i][0] = 2;
		dfa[i][1] = 2;
		dfa[i][2] = 2;
	}
	for(int i='a'; i<='z'; i++)
	{
		dfa[i][0] = 1;
		dfa[i][1] = 1;
	}
	for(int i='A'; i<='Z'; i++)
	{
		dfa[i][0] = 1;
		dfa[i][1] = 1;
	}
	for(int i='0'; i<='9'; i++){
		dfa[i][0] = 2;
		dfa[i][1] = 1;
	}
	dfa['_'][0] = dfa['_'][1] = 1;
}

bool match(int dfa[][256], char s[], int k){
    int state = 0;
    int n = strlen(s);
    for(int i=0; i<n; i++){
        state = dfa[state][s[i]];
        printf("%d\n", state);
        if(state == k)
            return true;
    }
    return false;
}

bool matchOther(int dfa[][3],char s[]){
    int state = 0;
    for(int i=0; i<strlen(s); i++)
        state = dfa[s[i]][state];
    return state == 1;
}

int main(){
    int begin_dfa[5][256];
    int end_dfa[3][256];
    int else_dfa[4][256];
    int if_dfa[2][256];
    int identifier_dfa[256][3];
    fillOther(identifier_dfa);
    int constant_dfa[8][256];
    
    int gt[1][256];
    int gte[2][256];
    int eq[1][256];
    int ne[2][256];
    int lt[1][256];
    int lte[2][256];

    fill(constant_dfa, "constant");
    fill(begin_dfa, "begin");
    fill(end_dfa, "end");
    fill(else_dfa, "else");
    fill(if_dfa, "if");
    fill(gt, ">");
    fill(gte, ">=");
    fill(lt, "<=");
    fill(lte, ">=");
    fill(eq, "=");
    fill(ne, "<>");
    
}