#include "POC_deck.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <queue>
#include <cstdlib>
#include <ctime>


int getDivide(int num){
    switch (num)
	{
        case Ace: 
        case Two: 
        case Three: 
            return 0;
            break;
        case Four: 
        case Five: 
        case Six: 
            return 1;
            break;
        case Seven: 
        case Eight: 
        case Nine: 
            return 2; 
            break;
        case Ten: 
        case Jack: 
        case Queen: 
        case King:
        default:
            return 3; 
            break;
    } 
}

int getLastDevide(int num){
    switch (num)
	{
        case Ace: 
        case Four: 
        case Seven: 
        case Ten: 
            return 0;
            break;
        case Two: 
        case Five: 
        case Eight: 
        case Jack: 
            return 1;
            break;
        case Three: 
        case Six: 
        case Nine: 
        case Queen: 
            return 2; 
            break;
        case King:
        default:
            return 3; 
            break;
    }
}

Deck::Deck(){
    for (int i = 0; i < DefaultDeckSize; i++)
    {
        Card newc;
        newc.suit = static_cast<Suit>(i%4);
        newc.value = static_cast<Value>(i/4);
        deck.push(newc);
    }
    stackCount.push(DefaultDeckSize);
}

void Deck::Display(){
    for (int i = 0; i < DefaultDeckSize; i++)
    {
        displayCard(deck.front());
        deck.push(deck.front());
        deck.pop();
    }
    
}

void Deck::displayCard(Card card){

    switch (card.value)
	{
        case Ace: std::cout << "Ace of ";
            break;
        case Two: std::cout << "2 of ";
            break;
        case Three: std::cout << "3 of ";
            break;
        case Four: std::cout << "4 of ";
            break;
        case Five: std::cout << "5 of ";
            break;
        case Six: std::cout << "6 of ";
            break;
        case Seven: std::cout << "7 of ";
            break;
        case Eight: std::cout << "8 of ";
            break;
        case Nine: std::cout << "9 of ";
            break;
        case Ten: std::cout << "10 of ";
            break;
        case Jack: std::cout << "Jack of ";
            break;
        case Queen: std::cout << "Queen of ";
            break;
        case King: std::cout << "King of ";
            break;
    }
    switch (card.suit)
    {
        case Clubs: std::cout << "Clubs" << std::endl;
            break;
        case Diamonds: std::cout << "Diamonds" << std::endl;
            break;
        case Hearts: std::cout << "Hearts" << std::endl;
            break;
        case Spades: std::cout << "Spades" << std::endl;
            break;
    }
}

void Deck::shuffle(){
    srand(time(0));
    for (int i = 0; i < DefaultDeckSize; i++)
    {
        int indexOne = rand() % 4;
        cart[indexOne].push(deck.front());
        deck.pop();

    }
    // cout << "Pushback from shuffle()" << endl; // Delete
    pushBackFromCart();
    while(!stackCount.empty()){
        stackCount.pop();
    }
    stackCount.push(DefaultDeckSize);
}

void Deck::rearrange(){
    int count = 0;
    for (int arrangeCount = 0; arrangeCount < 3; arrangeCount++)
    {
        switch (arrangeCount)
        {
        case 0:
            while (!deck.empty())
            {
                cart[deck.front().suit].push(deck.front());
                deck.pop();
            }
            stackCount.pop();
            // cout << "Pushback from rearrange[0]()" << endl; // Delete
            pushBackFromCart();
            cout << "\nThe pack after first sort\n" << endl; // Delete
            Display(); // Delete
            break;    

        case 1:
            count = 0;
            cout << "The next number of card to work with is " << stackCount.front() << endl; // Delete
            for(int i = 0; i < DefaultDeckSize; i++)
            {
                cart[getDivide(deck.front().value)].push(deck.front());
                // cout << "pushing "; // Delete
                // displayCard(deck.front()); // Delete
                // cout << "to " << getDivide(deck.front().value) << endl; // Delete
                deck.pop();
                count ++;
                if (count >= stackCount.front()){
                    // cout << "pushing back" << endl; // Delete
                    pushBackFromCart();
                    count = 0;
                    stackCount.pop();
                    // cout << "The next number of card to work with is " << stackCount.front() << endl; // Delete
                }
            }
            cout << "\n\n\nsecond arrange \n\n\n"; // Delete
            Display(); // Delete
            break;    
        case 2:
            count = 0;
            for(int i = 0; i < DefaultDeckSize; i++)
            {
                cout << "The next number of card to work with is " << stackCount.front() << endl; // Delete
                cart[getLastDevide(deck.front().value)].push(deck.front());
                // cout << "pushing "; // Delete
                // displayCard(deck.front()); // Delete
                // cout << "to " << getLastDevide(deck.front().value) << endl; // Delete
                deck.pop();
                count ++;
                if (count >= stackCount.front()){
                    // cout << "Pushback from rearrange[2]()" << endl; // Delete
                    pushBackFromCart();
                    count = 0;
                    stackCount.pop();
                }
            }
            pushBackFromCart();
            cout << "\n\n\nthird arrange \n\n\n";// Delete
            Display(); // Delete
            break; 
        default:
            break;
        }
    }
    
    
}

void Deck::pushBackFromCart(){
    int count = 0;
    for (int i = 0; i < cartSize; i++)
    {
        while(!cart[i].empty()){
            deck.push(cart[i].front());
            cart[i].pop();
            count ++;
        }
        // cout << "The number that entering the stackCounter from cart[" << i << "] is:" << count << endl; // Delete
        stackCount.push(count);
        count = 0;
    } 
}