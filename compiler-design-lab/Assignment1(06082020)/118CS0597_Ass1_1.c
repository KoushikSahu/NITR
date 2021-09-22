#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s[1000001];
    scanf("%s", s);
    // total states 4
    // state 0: even 0's even 1's
    // state 1: even 0's odd 1's
    // state 2: odd 0's odd 1's
    // state 3: odd 0's even 1's
    // Accepted state: 3
    // Rejected states: 0, 1, 2
    int dfa[4][2] = {{3, 1}, 
                    {2, 0},
                    {2, 3},
                    {0, 2}};
    int n = strlen(s);
    int state[n+1];
    state[0] = 0;
    for(int i=0; i<n; i++){
        state[i+1] = dfa[state[i]][s[i]-'0'];
    }
    printf("----------states----------\n");
    for(int i=0; i<=n; i++) printf("%d ", state[i]);
    printf("\n");
    printf("----------String is----------\n");
    if(state[n] == 3){
        printf("Accepted\n");
    }else{
        printf("Rejected\n");
    }
    return 0;
}