#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <cstdlib> // for system function

using namespace std;

// Function to print a border line
void printLine(char ch, int length) {
    for (int i = 0; i < length; ++i) {
        cout << ch;
    }
    cout << endl;
}

// Base class
class Crime {
protected:
    string name;
    string district;
    string area;
    string description;
    int numberOfPeople;

public:
    // Constructor
    Crime(const string& name, const string& district, const string& area, int numberOfPeople, const string& description)
        : name(name), district(district), area(area), numberOfPeople(numberOfPeople), description(description) {}

    // Virtual Destructor
    virtual ~Crime() {
        cout << "Crime data cleaned up." << endl;
    }

    // Pure virtual function for displaying crime details
    virtual void displayDetails() const = 0;

    // Getter for name
    string getName() const {
        return name;
    }
};

// Derived class for Snatching
class Snatching : public Crime {
private:
    string vehicleType;
    string vehicleNo;
    string snatchedItem;

public:
    // Constructor
    Snatching(const string& name, const string& district, const string& area, int numberOfPeople, const string& description,
              const string& vehicleType, const string& vehicleNo, const string& snatchedItem)
        : Crime(name, district, area, numberOfPeople, description),
          vehicleType(vehicleType), vehicleNo(vehicleNo), snatchedItem(snatchedItem) {}

    // Overridden function to display details
    void displayDetails() const override {
        printLine('=', 50);
        cout << "||" << setw(24) << "Snatching Report" << setw(25) << "||" << endl;
        printLine('=', 50);
        cout << "Name              : " << name << endl;
        cout << "District          : " << district << endl;
        cout << "Area              : " << area << endl;
        cout << "Number of People  : " << numberOfPeople << endl;
        cout << "Vehicle Type      : " << vehicleType << endl;
        cout << "Vehicle No        : " << vehicleNo << endl;
        cout << "Snatched Item     : " << snatchedItem << endl;
        cout << "Description       : " << description << endl;
        printLine('=', 50);
    }
};

// Derived class for Harassment
class Harassment : public Crime {
private:
    string vehicleType;
    string vehicleNo;
    bool physical;

public:
    // Constructor
    Harassment(const string& name, const string& district, const string& area, int numberOfPeople, const string& description,
               const string& vehicleType, const string& vehicleNo, bool physical)
        : Crime(name, district, area, numberOfPeople, description),
          vehicleType(vehicleType), vehicleNo(vehicleNo), physical(physical) {}

    // Overridden function to display details
    void displayDetails() const override {
        printLine('=', 50);
        cout << "||" << setw(24) << "Harassment Report" << setw(25) << "||" << endl;
        printLine('=', 50);
        cout << "Name              : " << name << endl;
        cout << "District          : " << district << endl;
        cout << "Area              : " << area << endl;
        cout << "Number of People  : " << numberOfPeople << endl;
        cout << "Vehicle Type      : " << vehicleType << endl;
        cout << "Vehicle No        : " << vehicleNo << endl;
        cout << "Type of Harassment: " << (physical ? "Physical" : "Verbal") << endl;
        cout << "Description       : " << description << endl;
        printLine('=', 50);
    }
};

// Derived class for Robbery
class Robbery : public Crime {
private:
    string vehicleType;
    string vehicleNo;
    string robbedItem;

public:
    // Constructor
    Robbery(const string& name, const string& district, const string& area, int numberOfPeople, const string& description,
            const string& vehicleType, const string& vehicleNo, const string& robbedItem)
        : Crime(name, district, area, numberOfPeople, description),
          vehicleType(vehicleType), vehicleNo(vehicleNo), robbedItem(robbedItem) {}

    // Overridden function to display details
    void displayDetails() const override {
        printLine('=', 50);
        cout << "||" << setw(24) << "Robbery Report" << setw(25) << "||" << endl;
        printLine('=', 50);
        cout << "Name              : " << name << endl;
        cout << "District          : " << district << endl;
        cout << "Area              : " << area << endl;
        cout << "Number of People  : " << numberOfPeople << endl;
        cout << "Vehicle Type      : " << vehicleType << endl;
        cout << "Vehicle No        : " << vehicleNo << endl;
        cout << "Robbed Item       : " << robbedItem << endl;
        cout << "Description       : " << description << endl;
        printLine('=', 50);
    }
};

// Function to get crime details
void getCrimeDetails(string& name, string& district, string& area, int& numberOfPeople, string& description) {
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your district: ";
    getline(cin, district);
    cout << "Enter your area: ";
    getline(cin, area);
    cout << "Enter the number of people involved: ";
    cin >> numberOfPeople;
    cin.ignore();  // To consume the newline character left by cin
    cout << "Enter description (max 1000 characters): ";
    getline(cin, description);
}

// Function to display taken details
void display(const string& name, const string& district, const string& area, int numberOfPeople, const string& description) {
    cout << "Entered Details:" << endl;
    cout << "Name              : " << name << endl;
    cout << "District          : " << district << endl;
    cout << "Area              : " << area << endl;
    cout << "Number of People  : " << numberOfPeople << endl;
    cout << "Description       : " << description << endl;
}

int main() {
    system("color 2");
    string name, district, area, description;
    int numberOfPeople;
    int choice;
    multimap<string, Crime*> crimeMap;
    
    do {
        printLine('*', 50);
        cout << "||" << setw(22) << "Crime Monitoring System" << setw(24) << "||" << endl;
        printLine('*', 50);
        cout << "1. Snatching\n2. Harassment\n3. Robbery\n4. Show Details\n5. Exit\n";
        cout << "Select crime type (1-5): ";
        cin >> choice;
        cin.ignore();  // To consume the newline character left by cin

        system("cls");
        if (choice == 1) {
            string vehicleType, vehicleNo, snatchedItem;
            getCrimeDetails(name, district, area, numberOfPeople, description);
            cout << "Enter vehicle type: ";
            getline(cin, vehicleType);
            cout << "Enter vehicle number: ";
            getline(cin, vehicleNo);
            cout << "Enter snatched item: ";
            getline(cin, snatchedItem);

            Crime* snatch = new Snatching(name, district, area, numberOfPeople, description, vehicleType, vehicleNo, snatchedItem);
            crimeMap.insert(make_pair(name, snatch));
            system("cls");
            snatch->displayDetails();
            
        } else if (choice == 2) {
            string vehicleType, vehicleNo;
            bool physical;
            getCrimeDetails(name, district, area, numberOfPeople, description);
            cout << "Enter vehicle type: ";
            getline(cin, vehicleType);
            cout << "Enter vehicle number: ";
            getline(cin, vehicleNo);
            cout << "Was the harassment physical? (1 for Yes, 0 for No): ";
            cin >> physical;

            Crime* harass = new Harassment(name, district, area, numberOfPeople, description, vehicleType, vehicleNo, physical);
            crimeMap.insert(make_pair(name, harass));
            system("cls");
            harass->displayDetails();
        } else if (choice == 3) {
            string vehicleType, vehicleNo, robbedItem;
            getCrimeDetails(name, district, area, numberOfPeople, description);
            cout << "Enter vehicle type: ";
            getline(cin, vehicleType);
            cout << "Enter vehicle number: ";
            getline(cin, vehicleNo);
            cout << "Enter robbed item: ";
            getline(cin, robbedItem);

            Crime* rob = new Robbery(name, district, area, numberOfPeople, description, vehicleType, vehicleNo, robbedItem);
            crimeMap.insert(make_pair(name, rob));
            system("cls");
            rob->displayDetails();
        } else if (choice == 4) {
            cout << "Enter the name to show details: ";
            getline(cin, name);
            auto range = crimeMap.equal_range(name);
            if (range.first != crimeMap.end()) {
                for (auto it = range.first; it != range.second; ++it) {
                    it->second->displayDetails();
                }
            } else {
                cout << "No details found for the name: " << name << endl;
            }
        } else if (choice == 5) {
            cout << "Program exited" << endl;
        } else {
            cout << "Invalid choice!" << endl;
        }
        
    } while (choice != 5);

    // Clean up dynamically allocated memory
    for (auto& pair : crimeMap) {
        delete pair.second;
    }

    return 0;
}
