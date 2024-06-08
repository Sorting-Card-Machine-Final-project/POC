#include <iostream>
#include <cstdlib>
#include <ctime>

enum Suit {
  Clubs,
  Diamonds,
  Hearts,
  Spades
};

class Card {
public:
  int number;
  Suit suit;
  Card* next_card;
  Card() {}

  Card(int number, Suit suit) : number(number), suit(suit), next_card(nullptr) {}

  // Additional methods for Card (e.g., print function) can be added here
  
};

void print_pack(Card* pack){
     // Print the cards in the first pack
    int count = 1;
    std::cout << "Cards in the first pack:" << std::endl;
    while (pack) {
    std::cout << count << ":    Number: " << pack->number << ", Suit: ";
    switch (pack->suit) {
      case Clubs:
        std::cout << "Clubs" << std::endl;
        break;
      case Diamonds:
        std::cout << "Diamonds" << std::endl;
        break;
      case Hearts:
        std::cout << "Hearts" << std::endl;
        break;
      case Spades:
        std::cout << "Spades" << std::endl;
        break;
    }
    pack = pack->next_card;
    count++;
  }
}

//Shuffle the pack
void shuffle_pack(Card* mainPack){
    Card* packs[5];
    Card* pack_current[5];
    Card* currentCard = mainPack;
    int randomNumber = rand() % 5;
    while(currentCard){
        randomNumber = rand() % 5;
        if (packs + randomNumber == nullptr){
            packs[randomNumber] = currentCard;
            pack_current[randomNumber] = packs[randomNumber];
    std::cout << mainPack->number << " and " << mainPack->suit << std::endl;
        } else{
            pack_current[randomNumber]->next_card = currentCard;
            pack_current[randomNumber] = pack_current[randomNumber]->next_card;
        }
        
        currentCard = currentCard->next_card;
    }

    currentCard = mainPack;
    for (int i = 0; i < 5; i++)
    {
        pack_current[i] = packs[i];
    }

    mainPack = packs[0];
    pack_current[0] = packs[0]->next_card;
    currentCard = mainPack;
    for (int i = 0; i < 5; i++)
    {
        while(pack_current[i]){
            currentCard->next_card = pack_current[i];
            currentCard = currentCard->next_card;
            pack_current[i] = pack_current[i]->next_card;
        }
    }
    

}

void build_first_card_arr(Card* arr, int size){
    
    int suitCount = 0;
    int numberCount = 1;
    for (int i = 0; i < size; i++) {
        arr[i].suit = static_cast<Suit>(suitCount);
        arr[i].number = numberCount;
        numberCount++;
        if (numberCount == 14) {
            numberCount = 1;
            suitCount++;
        }
    }
    
  }

Card* create_pack(Card* arr){
    Card* start = new Card(arr->number, arr->suit);
    Card* next = start;
    for(int i = 1; i < 52; i++){
        next->next_card = new Card((arr+i)->number, (arr+i)->suit);
        next = next->next_card;
    }
    return start;
}




void free_pack(Card* pack){
// Remember to delete dynamically allocated Packs to avoid memory leaks
    while (pack) {
        Card* nextCard = pack->next_card;
        delete pack;
        pack = nextCard;
    }
    std::cout << "done deleting" << std::endl;
  }

int main() {
    srand(time(0));

    // Create an array of 52 Cards
    Card cards[52];
    build_first_card_arr(cards, 52);
        
    // Create the Main Pack
    Card* MainPackStart = create_pack(cards);
    Card* mainCurrentCard = MainPackStart;

    print_pack(MainPackStart);
    std::cout << "after the shuffle" << std::endl;
    shuffle_pack(mainCurrentCard);
    print_pack(mainCurrentCard);


    free_pack(MainPackStart);
    
    return 0;
}
