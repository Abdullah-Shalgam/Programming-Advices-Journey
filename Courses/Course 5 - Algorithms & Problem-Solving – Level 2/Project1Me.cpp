#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enStonePaperScissors {Stone = 1, Paper = 2, Scissors = 3};

struct stGameResults
{
    short NumberOfRounds = 0;
    short PlayerWonTimes = 0;
    short ComputerWonTimes = 0;
    short DrawTimes = 0;
    string FinalWinner = "";
};

int ReadNumberInRange(int From, int To, string Msg)
{
    int Num;
    do
    {
        cout << Msg;
        cin >> Num;
        if (Num >= From && Num <= To)
            return Num;
        cout << "Invalid Input!\n";
    } while(true);
}

int RandomIntNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

string ConvertTextToLowerCase(string Text)
{
    string Word = "";
    for (int i = 0; i <= Text.length() - 1; i++)
    {
        Word += tolower(Text[i]);
    }
    return Word;
}

enStonePaperScissors GetUserChoice()
{
    short UserChoice = 0;
    do
    {
        cout << "Your Choice: [1]:Stone, [2]:Paper, [3]Scissors ?: ";
        cin >> UserChoice;
        if (UserChoice == 1 || UserChoice == 2 || UserChoice == 3)
            return (enStonePaperScissors) UserChoice;
        cout << "Invalid Input!, Please try again.\n\n";
    } while(true);
}

enStonePaperScissors GetComputerChoice()
{
    return (enStonePaperScissors) RandomIntNumber(1, 3);
}

string GetEnumName(enStonePaperScissors enValue)
{
    switch (enValue)
    {
        case enStonePaperScissors::Stone: return "Stone";
        case enStonePaperScissors::Paper: return "Paper";
        case enStonePaperScissors::Scissors: return "Scissors";
        default: return "Unknown";
    }
}

string GetRoundResult(enStonePaperScissors PlayerChoice, enStonePaperScissors ComputerChoice)
{
    if (PlayerChoice == ComputerChoice)
        return "[No Winner]";
    if (PlayerChoice == enStonePaperScissors::Stone)
    {
        if (ComputerChoice == enStonePaperScissors::Paper) return "[Computer]";
    }
    else if (PlayerChoice == enStonePaperScissors::Paper)
    {
        if (ComputerChoice == enStonePaperScissors::Scissors) return "[Computer]";
    }
    else if (PlayerChoice == enStonePaperScissors::Scissors)
    {
        if (ComputerChoice == enStonePaperScissors::Stone) return "[Computer]";
    }
    return "[Player1]";
}

string GetTheFinalWinner(short PlayerWonTimes, short ComputerWonTimes)
{
    if (PlayerWonTimes == ComputerWonTimes) return "No Winner";
    else if (PlayerWonTimes > ComputerWonTimes) return "Player1";
    else return "Computer";
}

void PrintGameRounds(stGameResults &GameInfo)
{
    enStonePaperScissors PlayerChoice , ComputerChoice;
    string RoundResult;
    GameInfo.NumberOfRounds = ReadNumberInRange(1, 10, "How Many Rounds 1 to 10 ?\n");
    cout << endl;
    for (short i = 1; i <= GameInfo.NumberOfRounds; i++)
    {
        cout << "Round [" << i << "] begins:\n\n";
        PlayerChoice = GetUserChoice();
        ComputerChoice = GetComputerChoice();
        RoundResult = GetRoundResult(PlayerChoice, ComputerChoice);
        if (RoundResult == "[No Winner]")
        {
            GameInfo.DrawTimes++;
            system("color 6F");
        }
        else if (RoundResult == "[Player1]")
        {
            GameInfo.PlayerWonTimes++;
            system("color 2F");
        }
        else
        {
            GameInfo.ComputerWonTimes++;
            cout << "\a";
            system("color 4F");
        }
        cout << "\n__________________Round [" << i << "]__________________\n\n";
        cout << "Player1  Choice: " << GetEnumName(PlayerChoice);
        cout << "\nComputer Choice: " << GetEnumName(ComputerChoice);
        cout << "\nRound Winner   : " << RoundResult;
        cout << "\n_____________________________________________\n\n";
    }
}

void PrintGameOver()
{
    cout << "\t\t\t______________________________________________________________\n\n\n";
    cout << "\t\t\t\t\t   +++ G a m e  O v e r +++\n\n";
    cout << "\t\t\t______________________________________________________________\n\n";
}

void PrintGameResult(stGameResults GameResults)
{
    cout << "\n\t\t\t________________________[Game Results]________________________\n\n";
    cout << "\t\t\tGame Rounds\t  : " << GameResults.NumberOfRounds;
    cout << "\n\t\t\tPlayer1 won times : " << GameResults.PlayerWonTimes;
    cout << "\n\t\t\tComputer won times: " << GameResults.ComputerWonTimes;
    cout << "\n\t\t\tDraw times\t  : " << GameResults.DrawTimes;
    cout << "\n\t\t\tFinal Winner\t  : " << GameResults.FinalWinner;
    cout << "\n\t\t\t______________________________________________________________\n\n";
}

void StartTheGame()
{
    string AskPlayAgain = "";
    bool IsPlayAgain;
    do
    {
        stGameResults GameResults;
        PrintGameRounds(GameResults);
        GameResults.FinalWinner = GetTheFinalWinner(GameResults.PlayerWonTimes, GameResults.ComputerWonTimes);
        PrintGameOver();
        PrintGameResult(GameResults);
        do
        {
            cout << "\t\t\tDo you want to play again? Y/N? ";
            cin >> AskPlayAgain;
            AskPlayAgain = ConvertTextToLowerCase(AskPlayAgain);
            if (AskPlayAgain == "y")
            {
                IsPlayAgain = true;
                system("color 07");
                system("cls");
            }
            else if (AskPlayAgain == "n") IsPlayAgain = false;
            else cout << "\t\t\tInvalid Input!, Please try again.\n\n";
        } while (AskPlayAgain != "y" && AskPlayAgain != "n");
    } while (IsPlayAgain);
    cout << "\n\nExecution completed successfully.";
}

int main()
{
    srand(time(0));
    StartTheGame();
    return 0;
}