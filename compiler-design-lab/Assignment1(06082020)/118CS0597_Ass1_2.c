#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

struct DFA{
    int state[31][31];
    int init_state;
    int num_states;
    bool final_states[31];
    int alphabet_size;
};

struct DFA build_dfa(int nfa[31][31],int init_state,bool final_states[],int alpha_size,int state_nums){
    struct DFA dfa;
    dfa.alphabet_size = alpha_size;
    memset(dfa.state,0,sizeof(dfa.state));
    int curr_state = (1<<init_state);
    
    dfa.init_state = curr_state;
    bool state_found[31];
    memset(state_found,0,sizeof(state_found));
    memset(dfa.final_states,0,sizeof(dfa.final_states));
    int i = 0;
    int final_states_rec = 0;
    for(i=0;i<state_nums;i++){
        if(final_states[i]){
            final_states_rec = (final_states_rec|(1<<i));
        }
    }
    i = 0;
    int j = 0;
    int waiting_states[31];
    waiting_states[j++] = curr_state;
    state_found[curr_state] = 1; 
    
    int cnt = 0;
    while(i<j){
        int curr_state = waiting_states[i++];
        int curr = curr_state;
        if((final_states_rec & curr_state) != 0){
            dfa.final_states[curr_state] = 1;
        }
        int mask = 0;
        int bit = 0;
        while(curr>0){
            if(curr&1){
                int k;
                for(k=0;k<alpha_size;k++){
                    if(nfa[bit][k] != -1){
                        
                        dfa.state[curr_state][k] = (dfa.state[curr_state][k]|(1<<nfa[bit][k]));
                        mask = (mask|(1<<nfa[bit][k]));
                        if((mask&final_states_rec) !=0)
                            dfa.final_states[mask] = true;
                    }
                }
            }
            bit++;
            curr>>=1;
        }

        if(mask == 0)
            break;
        if(!state_found[mask]){
            waiting_states[j++] = mask;
            state_found[mask] = true;
        }
    }
    dfa.num_states = cnt;
    return dfa;
}

bool isAccepted(struct DFA *dfa,char s[]){
    int  n = strlen(s);
    int state = dfa->init_state;
    for(int i=0;i<n;i++){
        if(state == 0)
            return false;
        state = dfa->state[state][s[i]-'0'];
        if(state == 0)
            return false;
    }
    return dfa->final_states[state];
}

int main(){
    int alphabet_size;
    printf("Enter number of alphabets: ");
    scanf("%d",&alphabet_size);
    int state_nums;
    printf("Enter number of states: ");
    scanf("%d",&state_nums);
    int state[31][31];
    for(int i=0;i<state_nums;i++){
        for(int j = 0;j<alphabet_size;j++)
            state[i][j] = -1;
    }
    printf("Enter number of final states : ");
    int num_f_states; 
    scanf("%d",&num_f_states);
    bool final_states[state_nums];
    memset(final_states,0,sizeof(final_states));
    int i;
    for(i=0;i<num_f_states;i++){
        int k;
        scanf("%d",&k);
        final_states[k] = 1;
    }
    int initial_state; //6
    printf("Enter the initial state for the NFA :");
    scanf("%d",&initial_state);
    int transitions; 
    printf("Enter number of transitions : ");
    scanf("%d",&transitions);
    printf("Enter transitions in the form <present_state> <alpahbet_seen> <next_state> :\n");
    while(transitions--){
        int current,alpha,next;
        scanf("%d%d%d",&current,&alpha,&next);
        state[current][alpha] = next;
    }
    struct DFA d = build_dfa(state,initial_state,final_states,alphabet_size,state_nums);
    struct DFA *dfa = &(d);
    char s[1000];
    while(true){
        printf("Enter String as a string of digits : ");
        scanf("%s",s);
        if(isAccepted(dfa,s))
            printf("Accepted\n");
        else
            printf("Rejected\n");
    }   
}