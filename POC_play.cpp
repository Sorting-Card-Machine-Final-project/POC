#include <iostream>
#include <unistd.h>
#include "POC_deck.h"
using namespace std;
#define DELAY_TIME 0

int main(){
    Deck deck;
    cout << "\n\n\nthe deck at the beggining \n\n\n";
    deck.Display();
    sleep(DELAY_TIME);

    for (int i = 0; i < 10; i++)
    {
        deck.shuffle();        
    }
    cout << "\n\n\nthe deck after shuffle \n\n\n";
    deck.Display();
    sleep(DELAY_TIME);

    deck.rearrange();
    cout << "\n\n\nthe deck at the end \n\n\n";
    deck.Display();

    return 0;
}