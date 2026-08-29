#pragma once

#include <iostream>
#include <string>
#include <queue>
#include <iomanip>

using namespace std;

class clsQueueLine
{
private:
    string _Prefix;
    int _AverageServeTime = 0;
    int _TotalTickets = 0;

    class clsTicket
    {
    private:
        int _AverageServeTime = 0;
        int _TicketNumber = 0;
        string _Prefix;
        string _TicketTime;

    public:
        clsTicket(const string &Prefix, int TicketNumber, int AverageServeTime)
        {
            _TicketNumber = TicketNumber;
            _TicketTime = _GetSystemDateTime();
            _Prefix = Prefix;
            _AverageServeTime = AverageServeTime;
        }

        string GetTicketTime() { return _TicketTime; }

        string FullNumber()
        {
            return _Prefix + to_string(_TicketNumber);
        }
    };

    queue<clsTicket> _QueueLine;

    clsTicket _ReadTicketInfo()
    {
        return {_Prefix, _TotalTickets, _AverageServeTime};
    }

    static string _GetSystemDateTime()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char buffer[30];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d | %H:%M:%S", ltm);
        return string(buffer);
    }

    void _PrintTicketsLine(queue<clsTicket> TempQueue, bool LeftToRight = false)
    {
        if (TempQueue.empty())
            return;

        clsTicket Ticket = TempQueue.front();
        TempQueue.pop();

        if (LeftToRight)
        {
            _PrintTicketsLine(TempQueue, LeftToRight);
            cout << Ticket.FullNumber() << (!TempQueue.empty() ? " --> " : "");
        }
        else
        {
            cout << Ticket.FullNumber() << (!TempQueue.empty() ? " <-- " : "");
            _PrintTicketsLine(TempQueue, LeftToRight);
        }
    }

public:
    clsQueueLine(const string &Prefix, int AverageServeTime)
    {
        if (AverageServeTime <= 0)
            AverageServeTime = 1;

        _Prefix = Prefix;
        _AverageServeTime = AverageServeTime;
    }

    void IssueTicket()
    {
        _TotalTickets++;
        _QueueLine.push(_ReadTicketInfo());
    }

    int WaitingClients()
    {
        return _QueueLine.size();
    }

    int ServedClients()
    {
        return _TotalTickets - WaitingClients();
    }

    bool ServeNextClient()
    {
        if (!_QueueLine.empty())
        {
            _QueueLine.pop();
            return true;
        }

        return false;
    }

    void PrintInfo()
    {
        cout << "\n\t\t====================================\n";
        cout << "\t\t             Queue Info             \n";
        cout << "\t\t====================================\n";
        cout << "\t\t  Prefix          : " << _Prefix << "\n";
        cout << "\t\t  Total Tickets   : " << _TotalTickets << "\n";
        cout << "\t\t  Served Clients  : " << ServedClients() << "\n";
        cout << "\t\t  Waiting Clients : " << WaitingClients() << "\n";
        cout << "\t\t====================================\n\n";
    }

    void PrintTicketsLineRTL()
    {
        cout << "\nTickets RTL: ";
        _PrintTicketsLine(_QueueLine, false);
        cout << "\n";
    }

    void PrintTicketsLineLTR()
    {
        cout << "Tickets LTR: ";
        _PrintTicketsLine(_QueueLine, true);
        cout << "\n\n";
    }

    void PrintTicket(clsTicket Ticket, int PositionInQueue)
    {
        int waitingBeforeThisTicket = PositionInQueue;
        int expectedTime = waitingBeforeThisTicket * _AverageServeTime;

        cout << "\t\t====================================\n";
        cout << "\t\t|" << setw(22) << Ticket.FullNumber() << setw(15) << "|\n";
        cout << "\t\t|" << setw(29) << Ticket.GetTicketTime() << setw(8) << "|\n";
        cout << "\t\t|  Waiting Clients = " << setw(2) << waitingBeforeThisTicket << setw(16) << "|\n";
        cout << "\t\t|  Serve Time In   = " << setw(2) << expectedTime << " Minutes" << setw(8) << "|\n";
        cout << "\t\t====================================\n\n";
    }

    void PrintAllTickets()
    {
        queue<clsTicket> Temp = _QueueLine;
        int position = 0;

        cout << "\t\t             -- Tickets --          \n\n";

        while (!Temp.empty())
        {
            PrintTicket(Temp.front(), position);
            Temp.pop();
            position++;
        }

        cout << endl;
    }
};