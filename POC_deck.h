#ifndef POC_deck
#define POC_deck
#include <vector>
#include <queue>
using namespace std;

enum Suit{
    Clubs,
    Diamonds,
    Hearts,
    Spades
};

enum Value
{
	Ace,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Joker
};

struct Card{
    Suit suit;
    Value value;
}
;
class Deck{

    public:
        Deck();
        queue<Card> deck;
		static const int cartSize = 4;
		queue<Card> cart[cartSize] = { queue<Card>(), queue<Card>(), queue<Card>(), queue<Card>()};
		const int DefaultDeckSize = 52;
		queue<int> stackCount;

		void Display();

		void shuffle();
		void rearrange();
		void pushBackFromCart();

	private:
		void displayCard(Card card);

};











#endif // POC_deck