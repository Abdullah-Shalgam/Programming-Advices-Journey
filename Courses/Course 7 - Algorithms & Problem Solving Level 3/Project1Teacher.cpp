#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <conio.h>
#include "InputValidateLib.h"

using namespace std;

const string ClientsFileName = "Clients.txt";

void ShowMainMenu();
void ShowTransactionsMenu();
void GoBackToMainMenu();
void GoBackToTransactionsMenu();

enum enMainMenuOptions { 
    eListClients = 1, eAddNewClient = 2, eDeleteClient = 3, 
    eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenu = 6, eExit = 7 
};

enum enTransactionsMenuOptions { 
    eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, eShowMainMenu = 4 
};

struct stClient
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string PhoneNumber = "";
    double AccountBalance = 0;
    bool MarkForDelete = false;
};

string GetValidPIN()
{
    string pin;
    while (true)
    {
        cout << "Enter PinCode?: ";
        cin >> pin;

        if (pin.length() != 4)
        {
            cout << "\nError: PIN must be exactly 4 digits.\n\n";
            continue;
        }

        bool isAllDigits = true;
        for (char c : pin)
        {
            if (!isdigit(c))
            {
                isAllDigits = false;
                break;
            }
        }

        if (isAllDigits) return pin;
        else cout << "\nError: PIN must contain numbers only (no letters or signs).\n\n";
    }
}

void ResetTheScreen()
{
    system("color 0F");
    system("cls");
}

string Tabs(short Num)
{
    string Result = "";
    for (short i = 1; i <= Num; i++) Result += "\t";
    return Result;
}

vector<string> SplitString(string S1, string Delim = "#//#")
{
    vector<string> vString;
    short pos = 0;
    string sWord;
    while ((pos = S1.find(Delim)) != string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "") vString.push_back(sWord);
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "") vString.push_back(S1);
    return vString;
}

stClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
    stClient Client;
    vector<string> vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.PhoneNumber = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;
}

string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
{
    ostringstream ss;
    ss << fixed << setprecision(6) << Client.AccountBalance;
    
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.PhoneNumber + Seperator;
    stClientRecord += ss.str();

    return stClientRecord;
}

bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            stClient Client = ConvertLineToRecord(Line);
            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }
        }
        MyFile.close();
    }
    return false;
}

vector<stClient> LoadClientsDataFromFile(string FileName)
{
    vector<stClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line))
        {
            if (Line != "")
                vClients.push_back(ConvertLineToRecord(Line));
        }
        MyFile.close();
    }
    return vClients;
}

void SaveClientsDataToFile(string FileName, vector<stClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    if (MyFile.is_open())
    {
        for (stClient C : vClients)
        {
            if (!C.MarkForDelete)
            {
                MyFile << ConvertRecordToLine(C) << endl;
            }
        }
        MyFile.close();
    }
}

bool FindClientByAccountNumber(string AccountNumber, vector<stClient> &vClients, stClient &Client)
{
    for (stClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

short FindClientIndexByAccountNumber(string AccountNumber, const vector<stClient> &vClients)
{
    for (short i = 0; i < vClients.size(); i++)
    {
        if (vClients[i].AccountNumber == AccountNumber) return i;
    }
    return -1;
}

void PrintClientRecordLine(stClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.PhoneNumber;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintClientCard(stClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccount Number: " << Client.AccountNumber;
    cout << "\nPin Code      : " << Client.PinCode;
    cout << "\nName          : " << Client.Name;
    cout << "\nPhone         : " << Client.PhoneNumber;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "-----------------------------------\n";
}

void ShowAllClientsScreen()
{
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_____________________________________________________________________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Account Number" << "| " << left << setw(10) << "Pin Code" << "| " << left << setw(40) << "Client Name" << "| " << left << setw(12) << "Phone" << "| " << left << setw(12) << "Balance";
    cout << "\n_____________________________________________________________________________________________________\n" << endl;

    if (vClients.size() == 0) cout << "\t\t\t\tNo Clients Available In the System!";
    else
    {
        for (stClient Client : vClients)
        {
            PrintClientRecordLine(Client);
            cout << endl;
        }
    }
    cout << "\n_____________________________________________________________________________________________________\n" << endl;
}

stClient ReadNewClient()
{
    stClient Client;
    Client.AccountNumber = InputValidateLib::ReadText("Enter Account Number? ");
    while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
    {
        cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
        Client.AccountNumber = InputValidateLib::ReadText("Enter Account Number? ");
    }
    Client.PinCode = GetValidPIN();
    Client.Name = InputValidateLib::ReadText("Enter Name? ");
    Client.PhoneNumber = InputValidateLib::ReadText("Enter Phone? ");
    Client.AccountBalance = InputValidateLib::ReadDblPositiveNumber("Enter AccountBalance? ");
    return Client;
}

void ShowAddNewClientsScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n-----------------------------------\n";
    
    char AddMore = 'Y';
    do {
        cout << "Adding New Client:\n\n";
        stClient Client = ReadNewClient();
        
        fstream MyFile;
        MyFile.open(ClientsFileName, ios::out | ios::app);
        if (MyFile.is_open())
        {
            MyFile << ConvertRecordToLine(Client) << endl;
            MyFile.close();
        }
        
        AddMore = InputValidateLib::getYesNoAnswer("\nClient Added Successfully, do you want to add more clients? (y/n): ");
    } while (toupper(AddMore) == 'Y');
}

void ShowDeleteClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-----------------------------------\n";

    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = InputValidateLib::ReadText("Please enter AccountNumber? ");
    stClient Client;

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        char Answer = InputValidateLib::getYesNoAnswer("\n\nAre you sure you want delete this client? (y/n): ");
        if (Answer == 'y')
        {
            for (stClient &C : vClients)
            {
                if (C.AccountNumber == AccountNumber) { C.MarkForDelete = true; break; }
            }
            SaveClientsDataToFile(ClientsFileName, vClients);
            cout << "\n\nClient Deleted Successfully.";
        }
    }
    else cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
}

void ShowUpdateClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Client Info Screen";
    cout << "\n-----------------------------------\n";

    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = InputValidateLib::ReadText("Please enter AccountNumber? ");
    stClient Client;

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        char Answer = InputValidateLib::getYesNoAnswer("\n\nAre you sure you want update this client? (y/n): ");
        if (Answer == 'y')
        {
            for (stClient &C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C.PinCode = InputValidateLib::ReadText("Enter PinCode? ");
                    C.Name = InputValidateLib::ReadText("Enter Name? ");
                    C.PhoneNumber = InputValidateLib::ReadText("Enter Phone? ");
                    C.AccountBalance = InputValidateLib::ReadDblPositiveNumber("Enter AccountBalance? ");
                    break;
                }
            }
            SaveClientsDataToFile(ClientsFileName, vClients);
            cout << "\n\nClient Updated Successfully.";
        }
    }
    else cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
}

void ShowFindClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tFind Client Screen";
    cout << "\n-----------------------------------\n";

    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = InputValidateLib::ReadText("Please enter AccountNumber? ");
    stClient Client;

    if (FindClientByAccountNumber(AccountNumber, vClients, Client)) PrintClientCard(Client);
    else cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
}

void ShowDepositScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-----------------------------------\n";

    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = InputValidateLib::ReadText("Please enter AccountNumber? ");
    short ClientIndex = FindClientIndexByAccountNumber(AccountNumber, vClients);

    while (ClientIndex == -1)
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = InputValidateLib::ReadText("Please enter AccountNumber? ");
        ClientIndex = FindClientIndexByAccountNumber(AccountNumber, vClients);
    }

    PrintClientCard(vClients[ClientIndex]);
    double Amount = InputValidateLib::ReadDblPositiveNumber("\nPlease enter deposit amount? ");

    char Answer = InputValidateLib::getYesNoAnswer("\n\nAre you sure you want perform this transaction? (y/n): ");
    if (Answer == 'y')
    {
        vClients[ClientIndex].AccountBalance += Amount;
        SaveClientsDataToFile(ClientsFileName, vClients);
        cout << "\n\nDone Successfully. New balance is: " << vClients[ClientIndex].AccountBalance;
    }
}

void ShowWithDrawScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n-----------------------------------\n";

    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = InputValidateLib::ReadText("Please enter AccountNumber? ");
    short ClientIndex = FindClientIndexByAccountNumber(AccountNumber, vClients);

    while (ClientIndex == -1)
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = InputValidateLib::ReadText("Please enter AccountNumber? ");
        ClientIndex = FindClientIndexByAccountNumber(AccountNumber, vClients);
    }

    PrintClientCard(vClients[ClientIndex]);
    double Amount = InputValidateLib::ReadDblPositiveNumber("\nPlease enter withdraw amount? ");

    while (Amount > vClients[ClientIndex].AccountBalance)
    {
        cout << "\nAmount Exceeds the balance, you can withdraw up to : " << vClients[ClientIndex].AccountBalance << endl;
        Amount = InputValidateLib::ReadDblPositiveNumber("Please enter another amount? ");
    }

    char Answer = InputValidateLib::getYesNoAnswer("\n\nAre you sure you want perform this transaction? (y/n): ");
    if (Answer == 'y')
    {
        vClients[ClientIndex].AccountBalance -= Amount;
        SaveClientsDataToFile(ClientsFileName, vClients);
        cout << "\n\nDone Successfully. New balance is: " << vClients[ClientIndex].AccountBalance;
    }
}

void ShowTotalBalances()
{
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n___________________________________________________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Account Number" << "| " << left << setw(40) << "Client Name" << "| " << left << setw(12) << "Balance";
    cout << "\n___________________________________________________________________________________\n" << endl;
    
    double TotalBalances = 0;
    if (vClients.size() == 0) cout << "\t\t\t\tNo Clients Available In the System!";
    else
    {
        for (stClient Client : vClients)
        {
            cout << "| " << setw(15) << left << Client.AccountNumber;
            cout << "| " << setw(40) << left << Client.Name;
            cout << "| " << setw(12) << left << Client.AccountBalance << endl;
            TotalBalances += Client.AccountBalance;
        }
    }
    cout << "\n___________________________________________________________________________________\n" << endl;
    printf("%sTotal Balances = %.3f", Tabs(3).c_str(), TotalBalances);
}

void ShowEndScreen()
{
    cout << "\n-----------------------------------\n";
    cout << Tabs(1) << "Program Ends :-)" << Tabs(1);
    cout << "\n-----------------------------------\n";
    exit(0);
}

void GoBackToMainMenu()
{
    cout << "\n\nPress any key to go back to Main Menu...";
    _getch();
    ShowMainMenu();
}

void GoBackToTransactionsMenu()
{
    cout << "\n\nPress any key to go back to Transactions Menu...";
    _getch();
    ShowTransactionsMenu();
}

void PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionMenuOption)
{
    switch (TransactionMenuOption)
    {
    case enTransactionsMenuOptions::eDeposit:
        ResetTheScreen();
        ShowDepositScreen();
        GoBackToTransactionsMenu();
        break;
    case enTransactionsMenuOptions::eWithdraw:
        ResetTheScreen();
        ShowWithDrawScreen();
        GoBackToTransactionsMenu();
        break;
    case enTransactionsMenuOptions::eShowTotalBalance:
        ResetTheScreen();
        ShowTotalBalances();
        GoBackToTransactionsMenu();
        break;
    case enTransactionsMenuOptions::eShowMainMenu:
        ShowMainMenu();
        break;
    }
}

void ShowTransactionsMenu()
{
    ResetTheScreen();
    cout << "===========================================\n";
    cout << Tabs(1) << "Transactions Menu Screen" << Tabs(1) << "\n";
    cout << "===========================================\n";
    cout << Tabs(1) << "[1] Deposit.\n";
    cout << Tabs(1) << "[2] Withdraw.\n";
    cout << Tabs(1) << "[3] Total Balances.\n";
    cout << Tabs(1) << "[4] Main Menu.\n";
    cout << "===========================================\n";
    
    short Choice = InputValidateLib::ReadIntNumberInRange(1, 4, "Choose what do you want to do? [1 to 4]: ");
    PerformTransactionsMenuOption((enTransactionsMenuOptions)Choice);
}

void PerformMainMenuOption(enMainMenuOptions MainMenuOption)
{
    switch (MainMenuOption)
    {
    case enMainMenuOptions::eListClients:
        ResetTheScreen();
        ShowAllClientsScreen();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eAddNewClient:
        ResetTheScreen();
        ShowAddNewClientsScreen();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eDeleteClient:
        ResetTheScreen();
        ShowDeleteClientScreen();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eUpdateClient:
        ResetTheScreen();
        ShowUpdateClientScreen();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eFindClient:
        ResetTheScreen();
        ShowFindClientScreen();
        GoBackToMainMenu();
        break;
    case enMainMenuOptions::eShowTransactionsMenu:
        ShowTransactionsMenu();
        break;
    case enMainMenuOptions::eExit:
        ResetTheScreen();
        ShowEndScreen();
        break;
    }
}

void ShowMainMenu()
{
    ResetTheScreen();
    cout << "===========================================\n";
    cout << Tabs(2) << "Main Menu Screen" << Tabs(2) << "\n";
    cout << "===========================================\n";
    cout << Tabs(1) << "[1] Show Client List.\n";
    cout << Tabs(1) << "[2] Add New Client.\n";
    cout << Tabs(1) << "[3] Delete Client.\n";
    cout << Tabs(1) << "[4] Update Client Info.\n";
    cout << Tabs(1) << "[5] Find Client.\n";
    cout << Tabs(1) << "[6] Transactions.\n";
    cout << Tabs(1) << "[7] Exit.\n";
    cout << "===========================================\n";
    
    short Choice = InputValidateLib::ReadIntNumberInRange(1, 7, "Choose what do you want to do? [1 to 7]: ");
    PerformMainMenuOption((enMainMenuOptions)Choice);
}

int main()
{
    ShowMainMenu();
    return 0;
}