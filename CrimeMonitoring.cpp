// #include <iostream>
// #include <string>
// #include <vector>
// #include <map>
// #include <iomanip>
// #include <mysql_driver.h>
// #include <mysql_connection.h>
// #include <cppconn/driver.h>
// #include <cppconn/exception.h>
// #include <cppconn/resultset.h>
// #include <cppconn/statement.h>
// #include <cppconn/prepared_statement.h>

// using namespace std;
// using namespace sql;

// void printLine(char ch, int length) {
//     for (int i = 0; i < length; ++i) {
//         cout << ch;
//     }
//     cout << endl;
// }

// class Crime {
// protected:
//     string name;
//     string district;
//     string area;
//     string description;
//     int numberOfPeople;

// public:
//     Crime(const string& name, const string& district, const string& area, int numberOfPeople, const string& description)
//         : name(name), district(district), area(area), numberOfPeople(numberOfPeople), description(description) {}

//     virtual ~Crime() {}

//     virtual void displayDetails() const = 0;

//     string getName() const {
//         return name;
//     }

//     virtual void saveToDatabase(PreparedStatement* pstmt) const = 0;
// };

// class Snatching : public Crime {
// private:
//     string vehicleType;
//     string vehicleNo;
//     string snatchedItem;

// public:
//     Snatching(const string& name, const string& district, const string& area, int numberOfPeople, const string& description,
//               const string& vehicleType, const string& vehicleNo, const string& snatchedItem)
//         : Crime(name, district, area, numberOfPeople, description),
//           vehicleType(vehicleType), vehicleNo(vehicleNo), snatchedItem(snatchedItem) {}

//     void displayDetails() const override {
//         printLine('=', 50);
//         cout << "||" << setw(24) << "Snatching Report" << setw(25) << "||" << endl;
//         printLine('=', 50);
//         cout << "Name              : " << name << endl;
//         cout << "District          : " << district << endl;
//         cout << "Area              : " << area << endl;
//         cout << "Number of People  : " << numberOfPeople << endl;
//         cout << "Vehicle Type      : " << vehicleType << endl;
//         cout << "Vehicle No        : " << vehicleNo << endl;
//         cout << "Snatched Item     : " << snatchedItem << endl;
//         cout << "Description       : " << description << endl;
//         printLine('=', 50);
//     }

//     void saveToDatabase(PreparedStatement* pstmt) const override {
//         pstmt->setString(1, name);
//         pstmt->setString(2, district);
//         pstmt->setString(3, area);
//         pstmt->setString(4, description);
//         pstmt->setInt(5, numberOfPeople);
//         pstmt->setString(6, "Snatching");
//         pstmt->setString(7, vehicleType);
//         pstmt->setString(8, vehicleNo);
//         pstmt->setString(9, snatchedItem);
//         pstmt->setNull(10, 0);
//         pstmt->setNull(11, 0);
//         pstmt->execute();
//     }
// };

// class Harassment : public Crime {
// private:
//     string vehicleType;
//     string vehicleNo;
//     bool physical;

// public:
//     Harassment(const string& name, const string& district, const string& area, int numberOfPeople, const string& description,
//                const string& vehicleType, const string& vehicleNo, bool physical)
//         : Crime(name, district, area, numberOfPeople, description),
//           vehicleType(vehicleType), vehicleNo(vehicleNo), physical(physical) {}

//     void displayDetails() const override {
//         printLine('=', 50);
//         cout << "||" << setw(24) << "Harassment Report" << setw(25) << "||" << endl;
//         printLine('=', 50);
//         cout << "Name              : " << name << endl;
//         cout << "District          : " << district << endl;
//         cout << "Area              : " << area << endl;
//         cout << "Number of People  : " << numberOfPeople << endl;
//         cout << "Vehicle Type      : " << vehicleType << endl;
//         cout << "Vehicle No        : " << vehicleNo << endl;
//         cout << "Type of Harassment: " << (physical ? "Physical" : "Verbal") << endl;
//         cout << "Description       : " << description << endl;
//         printLine('=', 50);
//     }

//     void saveToDatabase(PreparedStatement* pstmt) const override {
//         pstmt->setString(1, name);
//         pstmt->setString(2, district);
//         pstmt->setString(3, area);
//         pstmt->setString(4, description);
//         pstmt->setInt(5, numberOfPeople);
//         pstmt->setString(6, "Harassment");
//         pstmt->setString(7, vehicleType);
//         pstmt->setString(8, vehicleNo);
//         pstmt->setNull(9, 0);
//         pstmt->setNull(10, 0);
//         pstmt->setBoolean(11, physical);
//         pstmt->execute();
//     }
// };

// class Robbery : public Crime {
// private:
//     string vehicleType;
//     string vehicleNo;
//     string robbedItem;

// public:
//     Robbery(const string& name, const string& district, const string& area, int numberOfPeople, const string& description,
//             const string& vehicleType, const string& vehicleNo, const string& robbedItem)
//         : Crime(name, district, area, numberOfPeople, description),
//           vehicleType(vehicleType), vehicleNo(vehicleNo), robbedItem(robbedItem) {}

//     void displayDetails() const override {
//         printLine('=', 50);
//         cout << "||" << setw(24) << "Robbery Report" << setw(25) << "||" << endl;
//         printLine('=', 50);
//         cout << "Name              : " << name << endl;
//         cout << "District          : " << district << endl;
//         cout << "Area              : " << area << endl;
//         cout << "Number of People  : " << numberOfPeople << endl;
//         cout << "Vehicle Type      : " << vehicleType << endl;
//         cout << "Vehicle No        : " << vehicleNo << endl;
//         cout << "Robbed Item       : " << robbedItem << endl;
//         cout << "Description       : " << description << endl;
//         printLine('=', 50);
//     }

//     void saveToDatabase(PreparedStatement* pstmt) const override {
//         pstmt->setString(1, name);
//         pstmt->setString(2, district);
//         pstmt->setString(3, area);
//         pstmt->setString(4, description);
//         pstmt->setInt(5, numberOfPeople);
//         pstmt->setString(6, "Robbery");
//         pstmt->setString(7, vehicleType);
//         pstmt->setString(8, vehicleNo);
//         pstmt->setNull(9, 0);
//         pstmt->setString(10, robbedItem);
//         pstmt->setNull(11, 0);
//         pstmt->execute();
//     }
// };

// void getCrimeDetails(string& name, string& district, string& area, int& numberOfPeople, string& description) {
//     cout << "Enter your name: ";
//     getline(cin, name);
//     cout << "Enter your district: ";
//     getline(cin, district);
//     cout << "Enter your area: ";
//     getline(cin, area);
//     cout << "Enter the number of people involved: ";
//     cin >> numberOfPeople;
//     cin.ignore();
//     cout << "Enter description (max 1000 characters): ";
//     getline(cin, description);
// }

// void display(const string& name, const string& district, const string& area, int numberOfPeople, const string& description) {
//     cout << "Entered Details:" << endl;
//     cout << "Name              : " << name << endl;
//     cout << "District          : " << district << endl;
//     cout << "Area              : " << area << endl;
//     cout << "Number of People  : " << numberOfPeople << endl;
//     cout << "Description       : " << description << endl;
// }

// int main() {
//     system("color 2");
//     string name, district, area, description;
//     int numberOfPeople;
//     int choice;

//     try {
//         sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
//         unique_ptr<Connection> con(driver->connect("tcp://127.0.0.1:3306", "root", "your_password"));
//         unique_ptr<Statement> stmt(con->createStatement());
//         stmt->execute("USE crime_db");

//         unique_ptr<PreparedStatement> pstmt(con->prepareStatement("INSERT INTO crimes (name, district, area, description, number_of_people, type, vehicle_type, vehicle_no, snatched_item, robbed_item, physical) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"));

//         do {
//             printLine('*', 50);
//             cout << "||" << setw(22) << "Crime Monitoring System" << setw(24) << "||" << endl;
//             printLine('*', 50);
//             cout << "1. Snatching\n2. Harassment\n3. Robbery\n4. Show Details\n5. Exit\n";
//             cout << "Select crime type (1-5): ";
//             cin >> choice;
//             cin.ignore();

//             system("cls");
//             if (choice == 1) {
//                 string vehicleType, vehicleNo, snatchedItem;
//                 getCrimeDetails(name, district, area, numberOfPeople, description);
//                 cout << "Enter vehicle type: ";
//                 getline(cin, vehicleType);
//                 cout << "Enter vehicle number: ";
//                 getline(cin, vehicleNo);
//                 cout << "Enter snatched item: ";
//                 getline(cin, snatchedItem);

//                 Crime* snatch = new Snatching(name, district, area, numberOfPeople, description, vehicleType, vehicleNo, snatchedItem);
//                 snatch->saveToDatabase(pstmt.get());
//                 system("cls");
//                 snatch->displayDetails();
//                 delete snatch;

//             } else if (choice == 2) {
//                 string vehicleType, vehicleNo;
//                 bool physical;
//                 getCrimeDetails(name, district, area, numberOfPeople, description);
//                 cout << "Enter vehicle type: ";
//                 getline(cin, vehicleType);
//                 cout << "Enter vehicle number: ";
//                 getline(cin, vehicleNo);
//                 cout << "Was the harassment physical? (1 for Yes, 0 for No): ";
//                 cin >> physical;

//                 Crime* harass = new Harassment(name, district, area, numberOfPeople, description, vehicleType, vehicleNo, physical);
//                 harass->saveToDatabase(pstmt.get());
//                 system("cls");
//                 harass->displayDetails();
//                 delete harass;
//             } else if (choice == 3) {
//                 string vehicleType, vehicleNo, robbedItem;
//                 getCrimeDetails(name, district, area, numberOfPeople, description);
//                 cout << "Enter vehicle type: ";
//                 getline(cin, vehicleType);
//                 cout << "Enter vehicle number: ";
//                 getline(cin, vehicleNo);
//                 cout << "Enter robbed item: ";
//                 getline(cin, robbedItem);

//                 Crime* rob = new Robbery(name, district, area, numberOfPeople, description, vehicleType, vehicleNo, robbedItem);
//                 rob->saveToDatabase(pstmt.get());
//                 system("cls");
//                 rob->displayDetails();
//                 delete rob;
//             } else if (choice == 4) {
//                 cout << "Enter the name to show details: ";
//                 getline(cin, name);
//                 unique_ptr<PreparedStatement> select_stmt(con->prepareStatement("SELECT * FROM crimes WHERE name = ?"));
//                 select_stmt->setString(1, name);
//                 unique_ptr<ResultSet> res(select_stmt->executeQuery());
//                 while (res->next()) {
//                     printLine('=', 50);
//                     cout << "||" << setw(24) << res->getString("type") << " Report" << setw(24) << "||" << endl;
//                     printLine('=', 50);
//                     cout << "Name              : " << res->getString("name") << endl;
//                     cout << "District          : " << res->getString("district") << endl;
//                     cout << "Area              : " << res->getString("area") << endl;
//                     cout << "Number of People  : " << res->getInt("number_of_people") << endl;
//                     cout << "Description       : " << res->getString("description") << endl;
//                     cout << "Vehicle Type      : " << res->getString("vehicle_type") << endl;
//                     cout << "Vehicle No        : " << res->getString("vehicle_no") << endl;
//                     cout << "Snatched Item     : " << res->getString("snatched_item") << endl;
//                     cout << "Robbed Item       : " << res->getString("robbed_item") << endl;
//                     cout << "Type of Harassment: " << (res->getBoolean("physical") ? "Physical" : "Verbal") << endl;
//                     printLine('=', 50);
//                 }
//             } else if (choice == 5) {
//                 cout << "Program exited" << endl;
//             } else {
//                 cout << "Invalid choice!" << endl;
//             }

//         } while (choice != 5);

//     } catch (SQLException& e) {
//         cout << "SQLException: " << e.what() << endl;
//     }

//     return 0;
// }



#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;
using namespace sql;

void printLine(char ch, int length) {
    for (int i = 0; i < length; ++i) {
        cout << ch;
    }
    cout << endl;
}

class Crime {
protected:
    string name;
    string district;
    string area;
    string description;
    int numberOfPeople;

public:
    Crime(const string& name, const string& district, const string& area, int numberOfPeople, const string& description)
        : name(name), district(district), area(area), numberOfPeople(numberOfPeople), description(description) {}

    virtual ~Crime() {}

    virtual void displayDetails() const = 0;

    string getName() const {
        return name;
    }

    virtual void saveToDatabase(PreparedStatement* pstmt) const = 0;
};

class Snatching : public Crime {
private:
    string vehicleType;
    string vehicleNo;
    string snatchedItem;

public:
    Snatching(const string& name, const string& district, const string& area, int numberOfPeople, const string& description,
              const string& vehicleType, const string& vehicleNo, const string& snatchedItem)
        : Crime(name, district, area, numberOfPeople, description),
          vehicleType(vehicleType), vehicleNo(vehicleNo), snatchedItem(snatchedItem) {}

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

    void saveToDatabase(PreparedStatement* pstmt) const override {
        pstmt->setString(1, name);
        pstmt->setString(2, district);
        pstmt->setString(3, area);
        pstmt->setString(4, description);
        pstmt->setInt(5, numberOfPeople);
        pstmt->setString(6, "Snatching");
        pstmt->setString(7, vehicleType);
        pstmt->setString(8, vehicleNo);
        pstmt->setString(9, snatchedItem);
        pstmt->setNull(10, 0); // robbed_item
        pstmt->setNull(11, 0); // physical
        pstmt->execute();
    }
};

class Harassment : public Crime {
private:
    string vehicleType;
    string vehicleNo;
    bool physical;

public:
    Harassment(const string& name, const string& district, const string& area, int numberOfPeople, const string& description,
               const string& vehicleType, const string& vehicleNo, bool physical)
        : Crime(name, district, area, numberOfPeople, description),
          vehicleType(vehicleType), vehicleNo(vehicleNo), physical(physical) {}

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

    void saveToDatabase(PreparedStatement* pstmt) const override {
        pstmt->setString(1, name);
        pstmt->setString(2, district);
        pstmt->setString(3, area);
        pstmt->setString(4, description);
        pstmt->setInt(5, numberOfPeople);
        pstmt->setString(6, "Harassment");
        pstmt->setString(7, vehicleType);
        pstmt->setString(8, vehicleNo);
        pstmt->setNull(9, 0); // snatched_item
        pstmt->setNull(10, 0); // robbed_item
        pstmt->setBoolean(11, physical);
        pstmt->execute();
    }
};

class Robbery : public Crime {
private:
    string vehicleType;
    string vehicleNo;
    string robbedItem;

public:
    Robbery(const string& name, const string& district, const string& area, int numberOfPeople, const string& description,
            const string& vehicleType, const string& vehicleNo, const string& robbedItem)
        : Crime(name, district, area, numberOfPeople, description),
          vehicleType(vehicleType), vehicleNo(vehicleNo), robbedItem(robbedItem) {}

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

    void saveToDatabase(PreparedStatement* pstmt) const override {
        pstmt->setString(1, name);
        pstmt->setString(2, district);
        pstmt->setString(3, area);
        pstmt->setString(4, description);
        pstmt->setInt(5, numberOfPeople);
        pstmt->setString(6, "Robbery");
        pstmt->setString(7, vehicleType);
        pstmt->setString(8, vehicleNo);
        pstmt->setNull(9, 0); // snatched_item
        pstmt->setString(10, robbedItem);
        pstmt->setNull(11, 0); // physical
        pstmt->execute();
    }
};

void getCrimeDetails(string& name, string& district, string& area, int& numberOfPeople, string& description) {
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your district: ";
    getline(cin, district);
    cout << "Enter your area: ";
    getline(cin, area);
    cout << "Enter the number of people involved: ";
    cin >> numberOfPeople;
    cin.ignore();
    cout << "Enter description (max 1000 characters): ";
    getline(cin, description);
}

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

    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        unique_ptr<Connection> con(driver->connect("tcp://127.0.0.1:3306", "root", "your_password"));
        unique_ptr<Statement> stmt(con->createStatement());
        stmt->execute("USE crime_db");

        unique_ptr<PreparedStatement> pstmt(con->prepareStatement("INSERT INTO crimes (name, district, area, description, number_of_people, type, vehicle_type, vehicle_no, snatched_item, robbed_item, physical) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"));

        cout << "Crime Monitoring System" << endl;
        cout << "1. Snatching" << endl;
        cout << "2. Harassment" << endl;
        cout << "3. Robbery" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        getCrimeDetails(name, district, area, numberOfPeople, description);
        display(name, district, area, numberOfPeople, description);

        if (choice == 1) {
            string vehicleType, vehicleNo, snatchedItem;
            cout << "Enter vehicle type: ";
            getline(cin, vehicleType);
            cout << "Enter vehicle number: ";
            getline(cin, vehicleNo);
            cout << "Enter snatched item: ";
            getline(cin, snatchedItem);

            Snatching snatching(name, district, area, numberOfPeople, description, vehicleType, vehicleNo, snatchedItem);
            snatching.saveToDatabase(pstmt.get());
            snatching.displayDetails();
        } else if (choice == 2) {
            string vehicleType, vehicleNo;
            bool physical;
            cout << "Enter vehicle type: ";
            getline(cin, vehicleType);
            cout << "Enter vehicle number: ";
            getline(cin, vehicleNo);
            cout << "Was it physical harassment? (1 for Yes, 0 for No): ";
            cin >> physical;
            cin.ignore();

            Harassment harassment(name, district, area, numberOfPeople, description, vehicleType, vehicleNo, physical);
            harassment.saveToDatabase(pstmt.get());
            harassment.displayDetails();
        } else if (choice == 3) {
            string vehicleType, vehicleNo, robbedItem;
            cout << "Enter vehicle type: ";
            getline(cin, vehicleType);
            cout << "Enter vehicle number: ";
            getline(cin, vehicleNo);
            cout << "Enter robbed item: ";
            getline(cin, robbedItem);

            Robbery robbery(name, district, area, numberOfPeople, description, vehicleType, vehicleNo, robbedItem);
            robbery.saveToDatabase(pstmt.get());
            robbery.displayDetails();
        } else {
            cout << "Invalid choice!" << endl;
        }
    } catch (SQLException& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
