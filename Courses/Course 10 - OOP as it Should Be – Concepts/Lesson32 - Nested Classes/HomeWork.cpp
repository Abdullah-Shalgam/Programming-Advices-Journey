#include <iostream>
#include <string>

using namespace std;

class clsPerson
{
private:
    string _FullName = "";

    // ==========================================
    // NESTED CLASS: clsAddress
    // ==========================================
    class clsAddress
    {
    private:
        string _AddressLine1 = "";
        string _AddressLine2 = "";
        string _City = "";
        string _Country = "";

    public:

        // Constructor
        clsAddress(const string& AddressLine1, 
                   const string& AddressLine2, 
                   const string& City, 
                   const string& Country)
            : _AddressLine1(AddressLine1), 
              _AddressLine2(AddressLine2), 
              _City(City), 
              _Country(Country)
        {
        }

        // Setters
        void SetAddressLine1(const string& AddressLine1) { _AddressLine1 = AddressLine1; }
        void SetAddressLine2(const string& AddressLine2) { _AddressLine2 = AddressLine2; }
        void SetCity(const string& City)                 { _City = City; }
        void SetCountry(const string& Country)           { _Country = Country; }

        // Getters
        string AddressLine1() const { return _AddressLine1; }
        string AddressLine2() const { return _AddressLine2; }
        string City() const         { return _City; }
        string Country() const      { return _Country; }

        void Print() const
        {
            cout << "\nAddress Details:\n";
            cout << "-----------------------------------\n";
            cout << "Line 1  : " << _AddressLine1 << endl;
            cout << "Line 2  : " << _AddressLine2 << endl;
            cout << "City    : " << _City << endl;
            cout << "Country : " << _Country << endl;
            cout << "-----------------------------------\n";
        }
    };

public:

    // Public Property / Object from Nested Class
    clsAddress Address;

    // Constructor for clsPerson
    clsPerson(const string& FullName, 
              const string& AddressLine1, 
              const string& AddressLine2, 
              const string& City, 
              const string& Country)
        : _FullName(FullName), 
          Address(AddressLine1, AddressLine2, City, Country)
    {
    }

    // Setters
    void SetFullName(const string& FullName) { _FullName = FullName; }

    // Getters
    string FullName() const { return _FullName; }
};

// ==========================================
// MAIN FUNCTION
// ==========================================
int main()
{
    clsPerson Person1("Mohammed Abu-Hadhoud", "Building 10", "Queen Rania Street", "Amman", "Jordan");
    
    cout << "Person Full Name: " << Person1.FullName() << endl;
    Person1.Address.Print();

    return 0;
}