/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/12/2015
Notes:
    We want to create the beginning of a little game we are calling Dice on a Yacht.  This game is played with 5 8-sided dice.  For this beginning, we need a function that, given an array of the 5 dice scores and a category indicator, will return the score that you would get for that category.  We also want a function that can iterate through all the categories and find the one with the highest potential score.
    Here is some pseudo code that we might use to call your program:
    enum Category {Ones, Twos, Threes, Fours, Fives, Sixes, Sevens, Eights, ThreeOfAKind, FourOfAKind, FullHouse, SmallStraight, LargeStraight, AllDifferent, Chance, AllSame};
    getScore(Twos, [1,2,3,2,2]);  // should return 6
    getSuggestion([1,1,1,1,1]);  // should return AllSame
    For the purposes of this exercise, we ask that you do the following scoring categories at a minimum:
    ? Any two of the following: Ones, Twos, Threes, Fours, Fives, Sixes, Sevens, Eights
    ? SmallStraight
    ? AllDifferent
    ? AllSame
    Here is how to score each of the categories:
    Ones, Twos, Threes, Fours, Fives, Sixes, Sevens, Eights: Sum of all dice that match the title of the category.  For example {4,4,4,4,5} scores 16 for fours.
    ThreeOfAKind: Sum of all dice as long as there are at least three dice that are the same, otherwise zero. For example {1,1,1,2,8} scores 13.
    FourOfAKind: Sum of all dice as long as there are at least four dice that are the same, otherwise zero. For example {1,1,1,1,8} scores 12.
    FullHouse: If there are three of one kind and two of another score 25, otherwise score zero. For example {1,1,1,8,8} scores 25.
    SmallStraight: If there are four dice in sequence score 30, otherwise zero. For example {1,2,3,4,7} scores 30.
    LargeStraight: If all five dice fall in sequence score 40, otherwise zero.  For example {3,4,5,6,7} scores 40.
    AllDifferent: If all five dice have unique values score 40, otherwise zero.  For example {1,2,4,6,8} scores 40.
    Chance: Sum of all dice. For example {1,2,1,8,8} scores 20.
    AllSame: If all five dice have the same value score 50, otherwise zero.  For example {1,1,1,1,1} scores 50.
Solution: 
*/

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Game
{
public:
    enum Category {
        Ones = 0, Twos, Threes, Fours, Fives, Sixes, Sevens, Eights, ThreeOfAKind, FourOfAKind, FullHouse, SmallStraight, LargeStraight, AllDifferent, Chance, AllSame
    };

    typedef map<int, int> MAP;

    Game() {}

    Game(vector<int> scores) : m_Scores(scores)
    {
        buildScoreMap();
    }

    int getScore(Category category, vector<int> scores)
    {
        if (scores != m_Scores)
        {
            m_Scores = scores;
            buildScoreMap();
        }

        return getScore(category);
    }

    int getScore(Category category)
    {
        MAP::iterator it;

        switch (category)
        {
        case Ones:
            break;
            case Twos:
                return (m_Scoremap.find(2) != m_Scoremap.end()) ? (m_Scoremap[2] * 2) : 0;

            case Threes:
                return (m_Scoremap.find(3) != m_Scoremap.end()) ? (m_Scoremap[3] * 3) : 0;

            case Fours:
                return (m_Scoremap.find(4) != m_Scoremap.end()) ? (m_Scoremap[4] * 4) : 0;

            case Fives:
                return (m_Scoremap.find(5) != m_Scoremap.end()) ? (m_Scoremap[5] * 5) : 0;

            case Sixes:
                return (m_Scoremap.find(6) != m_Scoremap.end()) ? (m_Scoremap[6] * 6) : 0;

            case Sevens:
                return (m_Scoremap.find(7) != m_Scoremap.end()) ? (m_Scoremap[7] * 7) : 0;

            case Eights:
                return (m_Scoremap.find(8) != m_Scoremap.end()) ? (m_Scoremap[8] * 8) : 0;

            case ThreeOfAKind:
                for (it = m_Scoremap.begin(); it != m_Scoremap.end(); it++)
                {
                    if (it->second == 3)
                    {
                        return m_Sum;
                    }
                }
                break;

            case FourOfAKind:
                for (it = m_Scoremap.begin(); it != m_Scoremap.end(); it++)
                {
                    if (it->second == 4)
                    {
                        return m_Sum;
                    }
                }
                break;

            case FullHouse:
                if (m_Scoremap.size() == 2)
                {
                    return (m_Scoremap.begin()->second == 3 || m_Scoremap.begin()->second == 2) ? 25 : 0;
                }
                break;

            case SmallStraight:
                if (m_Scoremap.size() >= 4)
                {
                    for (int i = 0; i < 2; i++)
                    {
                        bool sequence = true;
                        for (int j = i + 1; j < i + 4 && j < m_Scores.size(); j++)
                        {
                            if (m_Scores[j] != m_Scores[i] + j - i)
                            {
                                sequence = false;
                                break;
                            }
                        }
                        if (sequence)
                        {
                            return 30;
                        }
                    }

                    return 0;
                }
                break;

            case LargeStraight:
                if (m_Scoremap.size() == 5)
                {
                    for (int i = 1; i < m_Scores.size(); i++)
                    {
                        if (m_Scores[i] != m_Scores[0] + i)
                        {
                            return 0;
                        }
                    }

                    return 40;
                }
                break;

            case AllDifferent:
                return m_Scoremap.size() == 5 ? 40 : 0;

            case Chance:
                return m_Sum;

            case AllSame:
                return m_Scoremap.size() == 1 ? 50 : 0;

            default:
                return 0;
        }
        
        return 0;
    }

    Category getSuggestion(vector<int> scores)
    {
        if (scores != m_Scores)
        {
            m_Scores = scores;
            buildScoreMap();
        }

        return getSuggestion();
    }

    Category getSuggestion()
    {
        Category category;
        int max = 0;

        for (Category cat = Ones; cat <= AllSame; cat = static_cast<Category>(cat + 1))
        {
            int score = getScore(cat);
            if (score > max)
            {
                max = score;
                category = cat;
            }
        }

        return category;
    }

private:
    void buildScoreMap()
    {
        m_Sum = 0;
        sort(m_Scores.begin(), m_Scores.end());

        m_Scoremap.clear();

        for (int i = 0; i < m_Scores.size(); i++)
        {
            m_Sum += m_Scores[i];
            m_Scoremap[m_Scores[i]]++;
        }
    }

private:
    int m_Sum;
    vector<int> m_Scores;
    map<int, int> m_Scoremap;
};