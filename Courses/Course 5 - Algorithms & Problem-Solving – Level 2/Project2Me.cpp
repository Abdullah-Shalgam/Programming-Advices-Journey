#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum enQuestionsLevel {Easy = 1, Med = 2, Hard = 3, Mix = 4};

enum enOperationType {Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5};

struct stQuestionInformation
{
    short RandNum1 = 0;
    short RandNum2 = 0;
    enQuestionsLevel QuestionsLvl;
    enOperationType OpType;
    int UserAnswer = 0;
    int TheCorrectAnswer = 0;
    bool IsUserAnswerCorrect = true;
};

struct stFinalResults 
{
    bool IsPass = true;
    int NumberOfQuestions = 0;
    enQuestionsLevel QuestionsDifficulty;
    enOperationType OpType;
    int NumberOfRightAnswers = 0;
    int NumberOfWrongAnswers = 0;
};

int HowManyQuestions()
{
    int Num;
    do
    {
        cout << "How Many Questions do you want to answer ?: ";
        cin >> Num;
        cout << endl;
        if (Num >= 1)
            return Num;
        cout << "Invalid Input!\n";
    } while (true);
}

int RandomIntNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

enQuestionsLevel ReadQuestionLvl()
{
    short UserSelection = 0;
    do
    {
        cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ?: ";
        cin >> UserSelection;
        if (UserSelection == 1 || UserSelection == 2 || UserSelection == 3 || UserSelection == 4)
            return (enQuestionsLevel) UserSelection;
        cout << "Invalid Input!\n";
    } while (true);
}

enOperationType ReadOpType()
{
    short UserSelection = 0;
    do
    {
        cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ?: ";
        cin >> UserSelection;
        if (UserSelection == 1 || UserSelection == 2 || UserSelection == 3 || UserSelection == 4 || UserSelection == 5)
            return (enOperationType) UserSelection;
        cout << "Invalid Input!\n";
    } while (true);
}

int ReadQuestionAnswer()
{
    int Answer = 0;
    cin >> Answer;
    return Answer;
}

short GetRandomNumberBasedOnQuestionLvl(enQuestionsLevel QuestionsLvl, short RandNumFrom1To3)
{
    if (QuestionsLvl == enQuestionsLevel::Mix)
    {
        QuestionsLvl = (enQuestionsLevel) RandNumFrom1To3;
    }
    switch (QuestionsLvl)
    {
    case enQuestionsLevel::Easy: return RandomIntNumber(1, 10);
    case enQuestionsLevel::Med: return RandomIntNumber(11, 100);
    case enQuestionsLevel::Hard: return RandomIntNumber(101, 1000);
    default:
       return 1;
    }
}

enOperationType GetRandomOperationType(enOperationType OpType)
{
    if (OpType == enOperationType::MixOp)
        return (enOperationType) RandomIntNumber(1, 4);
    else
        return OpType;
}

int GetTheCorrectAnswer(stQuestionInformation QuestionInfo, enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add: return (QuestionInfo.RandNum1 + QuestionInfo.RandNum2);
    case enOperationType::Sub: return (QuestionInfo.RandNum1 - QuestionInfo.RandNum2);
    case enOperationType::Mul: return (QuestionInfo.RandNum1 * QuestionInfo.RandNum2);
    case enOperationType::Div: return (QuestionInfo.RandNum2 != 0) ? (QuestionInfo.RandNum1 / QuestionInfo.RandNum2) : 0;
    default: return 0;
    }   
}

string GetQuestionsLvlName(enQuestionsLevel QuestionsLevel)
{
    string ArrQuestinosLevelNames[4] = {"Easy", "Med", "Hard", "Mix"};
    return ArrQuestinosLevelNames[QuestionsLevel - 1];
}

string GetOpTypeSympol(enOperationType OpType)
{
    string ArrOperationTypeName[5] = {"+", "-", "*", "/", "Mix"};
    return ArrOperationTypeName[OpType - 1];
}

string GetIsPassText(bool IsPass)
{
    return (IsPass) ? "Pass :-)" : "Fail :-(";
}

bool IsCorrectAnswer(stQuestionInformation QuestionInfo)
{
    return (QuestionInfo.TheCorrectAnswer == QuestionInfo.UserAnswer);
}

void GenerateQuestion(stQuestionInformation &QuestionInfo, enOperationType &RandOpType)
{
    RandOpType = GetRandomOperationType(QuestionInfo.OpType);
    short RandNumFrom1To3 = RandomIntNumber(1, 3);
    QuestionInfo.RandNum1 = GetRandomNumberBasedOnQuestionLvl(QuestionInfo.QuestionsLvl, RandNumFrom1To3);
    QuestionInfo.RandNum2 = GetRandomNumberBasedOnQuestionLvl(QuestionInfo.QuestionsLvl, RandNumFrom1To3);
    QuestionInfo.TheCorrectAnswer = GetTheCorrectAnswer(QuestionInfo, RandOpType);
}

void AskAndCheckTheAnswer(stQuestionInformation &QuestionInfo)
{
    QuestionInfo.UserAnswer = ReadQuestionAnswer();
    QuestionInfo.IsUserAnswerCorrect = IsCorrectAnswer(QuestionInfo);
}

void SetAnswerScreenColor(bool IsCorrect)
{
    (IsCorrect) ? system("color 2F") : system("color 4F");
}

void ShowQuestion (stQuestionInformation QuestionInfo, enOperationType RandOpType, int QuestionNumber, int NumberOfQuestions)
{
    cout << "\nQuestion [" << QuestionNumber << "/" << NumberOfQuestions << "]\n\n";
    cout << QuestionInfo.RandNum1 << endl;
    cout << QuestionInfo.RandNum2 << " " << GetOpTypeSympol(RandOpType);;
    cout << "\n_________________\n";
}

void ShowAnswer(stQuestionInformation QuestionsInfo)
{
    SetAnswerScreenColor(QuestionsInfo.IsUserAnswerCorrect);

    if (QuestionsInfo.IsUserAnswerCorrect)
    {
        cout << "Right Answer :-)";
    }
    else
    {
        cout << "\a";
        cout << "Wrong Answer :-(\n";
        cout << "The right answer is: " << QuestionsInfo.TheCorrectAnswer;
    }
    cout << "\n\n\n";
}

stFinalResults PlayTheGame(int NumberOfQuestions)
{
    stQuestionInformation QuestionInfo;
    int NumberOfRightAnswers = 0 , NumberOfWrongAnswers = 0;
    bool IsPass = true;

    enOperationType RandOpType;

    QuestionInfo.QuestionsLvl = ReadQuestionLvl();
    QuestionInfo.OpType = ReadOpType();

    for (int QuestionNumber = 1; QuestionNumber <= NumberOfQuestions; QuestionNumber++)
    {
        GenerateQuestion(QuestionInfo, RandOpType);
        ShowQuestion(QuestionInfo, RandOpType, QuestionNumber, NumberOfQuestions);
        AskAndCheckTheAnswer(QuestionInfo);
        ShowAnswer(QuestionInfo);
        (QuestionInfo.IsUserAnswerCorrect) ? NumberOfRightAnswers++ : NumberOfWrongAnswers++;
    }
    IsPass = (NumberOfRightAnswers >= NumberOfWrongAnswers);
    return {IsPass, NumberOfQuestions, QuestionInfo.QuestionsLvl, QuestionInfo.OpType, NumberOfRightAnswers, NumberOfWrongAnswers};
}

void ResetTheScreen()
{
    system("color 0F");
    system("cls");
}

void ShowFinalResults(stFinalResults FinalResults)
{
    SetAnswerScreenColor(FinalResults.IsPass);

    cout << "_____________________________________\n\n";
    cout << " Final Results is " << GetIsPassText(FinalResults.IsPass);
    cout << "_____________________________________\n\n";

    cout << "Number of Questions : " << FinalResults.NumberOfQuestions;
    cout << "\nQuestions levle     : " << GetQuestionsLvlName(FinalResults.QuestionsDifficulty);
    cout << "\nOperation type      : " <<GetOpTypeSympol(FinalResults.OpType);
    cout << "\nNumber of Right Answers: " << FinalResults.NumberOfRightAnswers;
    cout << "\nNumber of Wrong Answers: " << FinalResults.NumberOfWrongAnswers;
    cout << "\n\n_____________________________________\n\n";
}

void StartTheGame()
{
    char AskPlayAgain = 'Y';
    do
    {
        ResetTheScreen();
        stFinalResults FinalResults = PlayTheGame(HowManyQuestions());
        ShowFinalResults(FinalResults);
        do
        {
            cout << "Do you want to play again? Y/N?: ";
            cin >> AskPlayAgain;
            if (AskPlayAgain != 'y' && AskPlayAgain != 'Y' && AskPlayAgain != 'n' && AskPlayAgain != 'N')
                cout << "Invalid Input!, Please try again.\n\n";
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