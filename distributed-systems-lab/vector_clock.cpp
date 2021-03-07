#include <bits/stdc++.h>
using namespace std;

int p, e, src, dest;
char evt_type;

int main(){
    cout<<"Enter the number of processes: ";
    cin>>p;
    vector<int>* ts = new vector<int>[p];
    for(int i=0; i<p; i++) ts[i] = vector<int> (p, 0);
    cout<<"Enter the number of events: ";
    cin>>e;
    for(int j=0; j<e; j++){
        cout<<"Enter the event type[e(event), s(send), r(receive)]: ";
        cin>>evt_type;
        assert(evt_type=='e' || evt_type=='s' || evt_type=='r');
        switch(evt_type){
            case 'e':
                cout<<"Enter the process id: ";
                cin>>src;
                src--;
                ts[src][src]++;
                cout<<"******************\n";
                cout<<"Timestamp of the event: [";
                for(int i: ts[src]) cout<<i<<", ";
                cout<<"]\n";
                cout<<"******************\n";
                break;
            case 's':
                cout<<"Enter the source and destination process id: ";
                cin>>src>>dest;
                src--, dest--;
                ts[src][src]++;
                cout<<"******************\n";
                cout<<"Timestamp of the event: [";
                for(int i: ts[src]) cout<<i<<", ";
                cout<<"]\n";
                cout<<"******************\n";
                break;
            case 'r':
                cout<<"Enter the destination and source process id: ";
                cin>>dest>>src;
                dest--, src--;
                ts[dest][dest]++;
                for(int i=0; i<p; i++) ts[dest][i] = max(ts[dest][i], ts[src][i]);
                cout<<"******************\n";
                cout<<"Timestamp of the event: [";
                for(int i: ts[dest]) cout<<i<<", ";
                cout<<"]\n";
                cout<<"******************\n";
                break;
        }
    }
    return 0;
}

