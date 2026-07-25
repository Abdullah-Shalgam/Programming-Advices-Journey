#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };

enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner RoundWinner;
    string RoundWinnerName = "";
};

struct stGameResults
{
    short NumberOfRounds = 0;
    short Player1WonTimes = 0;
    short ComputerWonTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string GameWinnerName = "";
};

int HowManyRounds()
{
    int Num;
    do
    {
        cout << "How Many Rounds 1 to 10 ?\n";
        cin >> Num;
        cout << endl;
        if (Num >= 1 && Num <= 10)
            return Num;
        cout << "Invalid Input!\n";
    } while (true);
}

int RandomIntNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

string Tabs(int Count)
{
    string t = "";
    for (int j = 1; j <= Count; j++)
    {
        t += "\t";
    }
    return t;
}

enGameChoice ReadPlayer1Choice()
{
    short PlayerChoice = 0;
    do
    {
        cout << "Your Choice: [1]:Stone, [2]:Paper, [3]Scissors ?: ";
        cin >> PlayerChoice;
        if (PlayerChoice == 1 || PlayerChoice == 2 || PlayerChoice == 3) return (enGameChoice)PlayerChoice;
        cout << "Invalid Input!, Please try again.\n\n";
    } while (true);
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomIntNumber(1, 3);
}

string GetChoiceName(enGameChoice GameChoice)
{
    string ArrGameChoices[3] = { "Stone", "Paper", "Scissors" };
    return ArrGameChoices[GameChoice - 1];
}

string GetWinnerName(enWinner Winner)
{
    string ArrWinner[3] = { "Player1", "Computer", "Draw" };
    return ArrWinner[Winner - 1];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice) return enWinner::Draw;
    switch (RoundInfo.Player1Choice)
    {
    case enGameChoice::Stone:
        return (RoundInfo.ComputerChoice == enGameChoice::Paper) ? enWinner::Computer : enWinner::Player1;
    case enGameChoice::Paper:
        return (RoundInfo.ComputerChoice == enGameChoice::Scissors) ? enWinner::Computer : enWinner::Player1;
    case enGameChoice::Scissors:
        return (RoundInfo.ComputerChoice == enGameChoice::Stone) ? enWinner::Computer : enWinner::Player1;
    default:
        return enWinner::Draw;
    }
}

enWinner GetTheGameWinner(short PlayerWonTimes, short ComputerWonTimes)
{
    if (PlayerWonTimes == ComputerWonTimes) return enWinner::Draw;
    else if (PlayerWonTimes > ComputerWonTimes) return enWinner::Player1;
    else return enWinner::Computer;
}

void SetWinnerScreenColor(enWinner Winner)
{
    if (Winner == enWinner::Computer)
        system("color 4F");
    else if (Winner == enWinner::Player1)
        system("color 2F");
    else
        system("color 6F");
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
    cout << "\n__________________Round [" << RoundInfo.RoundNumber << "]__________________\n\n";
    cout << "Player1  Choice: " << GetChoiceName(RoundInfo.Player1Choice);
    cout << "\nComputer Choice: " << GetChoiceName(RoundInfo.ComputerChoice);
    cout << "\nRound Winner   : " << RoundInfo.RoundWinnerName;
    cout << "\n_____________________________________________\n\n";
}

stGameResults PlayTheGame(short NumberOfRounds)
{
    stRoundInfo RoundInfo;
    short Player1WonTimes = 0, ComputerWonTimes = 0, DrawTimes = 0;
    for (short GameRound = 1; GameRound <= NumberOfRounds; GameRound++)
    {
        cout << "Round [" << GameRound << "] begins:\n\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.RoundWinner = WhoWonTheRound(RoundInfo);
        RoundInfo.RoundWinnerName = GetWinnerName(RoundInfo.RoundWinner);
        SetWinnerScreenColor(RoundInfo.RoundWinner);
        if (RoundInfo.RoundWinner == enWinner::Computer)
            ComputerWonTimes++;
        else if (RoundInfo.RoundWinner == enWinner::Player1)
            Player1WonTimes++;
        else
            DrawTimes++;
        PrintRoundResults(RoundInfo);
    }
    enWinner FinalWinner = GetTheGameWinner(Player1WonTimes, ComputerWonTimes);
    return { NumberOfRounds, Player1WonTimes, ComputerWonTimes, DrawTimes, FinalWinner, GetWinnerName(FinalWinner) };
}

void ShowGameOverScreen()
{
    cout << Tabs(3) << "______________________________________________________________\n\n\n";
    cout << Tabs(5) << "   +++ G a m e  O v e r +++\n\n";
    cout << Tabs(3) << "______________________________________________________________\n\n\n";
}

void ShowGameResult(stGameResults GameResults)
{
    SetWinnerScreenColor(GameResults.GameWinner);
    cout << Tabs(3) << "________________________[Game Results]________________________\n";
    cout << Tabs(3) << "Game Rounds       : " << GameResults.NumberOfRounds << endl;
    cout << Tabs(3) << "Player1 won times : " << GameResults.Player1WonTimes << endl;
    cout << Tabs(3) << "Computer won times: " << GameResults.ComputerWonTimes << endl;
    cout << Tabs(3) << "Draw times        : " << GameResults.DrawTimes << endl;
    cout << Tabs(3) << "Final Winner      : " << GameResults.GameWinnerName << endl;
    cout << Tabs(3) << "______________________________________________________________\n\n";
}

void ResetTheScreen()
{
    system("color 0F");
    system("cls");
}

void StartTheGame()
{
    char AskPlayAgain = 'Y';
    do
    {
        ResetTheScreen();
        stGameResults GameResults = PlayTheGame(HowManyRounds());
        ShowGameOverScreen();
        ShowGameResult(GameResults);
        do
        {
            cout << Tabs(3) << "Do you want to play again? Y/N? ";
            cin >> AskPlayAgain;
            if (AskPlayAgain != 'y' && AskPlayAgain != 'Y' && AskPlayAgain != 'n' && AskPlayAgain != 'N')
                cout << Tabs(3) << "Invalid Input!, Please try again.\n\n";
        } while (AskPlayAgain != 'y' && AskPlayAgain != 'Y' && AskPlayAgain != 'n' && AskPlayAgain != 'N');
    } while (AskPlayAgain == 'Y' || AskPlayAgain == 'y');
    cout << "\n\nExecution completed successfully.";
}

int main()
{
    srand(time(0));
    StartTheGame();
    return 0;
}