// DiceOnYacht.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "DiceOnYacht.h"

using namespace std;

string CategoryString[] = {
    "Ones", "Twos", "Threes", "Fours", "Fives", "Sixes", "Sevens", "Eights", "ThreeOfAKind", "FourOfAKind", "FullHouse", "SmallStraight", "LargeStraight", "AllDifferent", "Chance", "AllSame"
};

int main(int argc, char* argv[])
{
    Game game;
    Game::Category category;

    vector<int> test;
    int score;
    
    test = { 1, 2, 3, 2, 2 };
    score = game.getScore(Game::Twos, test);  // should return 6
    cout << "{ 1, 2, 3, 2, 2 } Category Twos Score 6 : " << score << "\r\n";
    category = game.getSuggestion(test);  // should return ThreeOfAKind
    cout << "{ 1, 2, 3, 2, 2 } Category Suggestion : " << CategoryString[(int)category].c_str() << "\r\n";

    test = { 4, 4, 4, 4, 5 }; // scores 16 for fours.
    score = game.getScore(Game::Fours, test);
    cout << "{ 4, 4, 4, 4, 5 } Category Four Score 16 : " << score << "\r\n";
    category = game.getSuggestion(test);  // should return FourOfAKind
    cout << "{ 4, 4, 4, 4, 5 } Category Suggestion : " << CategoryString[(int)category].c_str() << "\r\n";

    test = { 1, 1, 1, 2, 8 }; // scores 13.
    score = game.getScore(Game::ThreeOfAKind, test);
    cout << "{ 1, 1, 1, 2, 8 } Category ThreeOfAKind Score 13 : " << score << "\r\n";
    category = game.getSuggestion(test);  // should return ThreeOfAKind
    cout << "{ 1, 1, 1, 2, 8 } Category Suggestion : " << CategoryString[(int)category].c_str() << "\r\n";

    test = { 1, 1, 1, 1, 8 }; // scores 12.
    score = game.getScore(Game::FourOfAKind, test);
    cout << "{ 1, 1, 1, 1, 8 } Category FourOfAKind Score 12 : " << score << "\r\n";
    category = game.getSuggestion(test);  // should return FourOfAKind
    cout << "{ 1, 1, 1, 1, 8 } Category Suggestion : " << CategoryString[(int)category].c_str() << "\r\n";

    test = { 1, 1, 1, 8, 8 }; // scores 25.
    score = game.getScore(Game::FullHouse, test);
    cout << "{ 1, 1, 1, 8, 8 } Category FullHouse Score 25 : " << score << "\r\n";
    category = game.getSuggestion(test);  // should return FullHouse
    cout << "{ 1, 1, 1, 8, 8 } Category Suggestion : " << CategoryString[(int)category].c_str() << "\r\n";

    test = { 1, 2, 3, 4, 7 }; // scores 30.
    score = game.getScore(Game::SmallStraight, test);
    cout << "{ 1, 2, 3, 4, 7 } Category SmallStraight Score 30 : " << score << "\r\n";
    category = game.getSuggestion(test);  // should return AllDifferent
    cout << "{ 1, 2, 3, 4, 7 } Category Suggestion : " << CategoryString[(int)category].c_str() << "\r\n";

    test = { 3, 4, 5, 6, 7 }; // scores 40.
    score = game.getScore(Game::LargeStraight, test);
    cout << "{ 3, 4, 5, 6, 7 } Category LargeStraight Score 40 : " << score << "\r\n";
    category = game.getSuggestion(test);  // should return LargeStraight
    cout << "{ 3, 4, 5, 6, 7 } Category Suggestion : " << CategoryString[(int)category].c_str() << "\r\n";

    test = { 1, 2, 4, 6, 8 }; // scores 40.
    score = game.getScore(Game::AllDifferent, test);
    cout << "{ 1, 2, 4, 6, 8 } Category AllDifferent Score 40 : " << score << "\r\n";
    category = game.getSuggestion(test);  // should return AllDifferent
    cout << "{ 1, 2, 4, 6, 8 } Category Suggestion : " << CategoryString[(int)category].c_str() << "\r\n";

    test = { 1, 2, 1, 8, 8 }; // scores 20.
    score = game.getScore(Game::Chance, test);
    cout << "{ 1, 2, 1, 8, 8 } Category Chance Score 20 : " << score << "\r\n";
    category = game.getSuggestion(test);  // should return Chance
    cout << "{ 1, 2, 1, 8, 8 } Category Suggestion : " << CategoryString[(int)category].c_str() << "\r\n";

    test = { 1, 1, 1, 1, 1 };
    score = game.getScore(Game::AllSame, test);  // should return 50
    cout << "{ 1, 1, 1, 1, 1 } Category AllSame Score 50 : " << score << "\r\n";
    category = game.getSuggestion(test);  // should return AllSame
    cout << "{ 1, 1, 1, 1, 1 } Category Suggestion : " << CategoryString[(int)category].c_str() << "\r\n";

	return 0;
}

