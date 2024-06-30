#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <windows.h>
#include <string>

using namespace std;

class CrimeReportSystem
{
private:
    vector<string> areas;
    vector<string> crimeTypes;
    map<string, map<string, int>> crimeData;
    map<string, int> timeData;

public:
    CrimeReportSystem()
    {
        // Initialize areas
        areas = {"Downtown", "Uptown", "Suburbs"};

        // Initialize crime types
        crimeTypes = {"Robbery", "Snatching", "Harassment"};

        // Initialize crime data with 0 counts
        for (const auto &area : areas)
        {
            for (const auto &crimeType : crimeTypes)
            {
                crimeData[area][crimeType] = 0;
            }
        }

        // Initialize time data with 0 counts
        timeData["12am-5am"] = 0;
        timeData["5am-12pm"] = 0;
        timeData["12pm-5pm"] = 0;
        timeData["5pm-12am"] = 0;
    }

    //_________X_________X__________X__________

    // function for report crime (start)
    void reportCrime()
    {
        clearScreen();

        int areaChoice, crimeTypeChoice;

        // Select area

        // only for Animation
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        string message = "\n       ----(((( Select the District where the crime happened to you ))))----";
        // Define the delay in milliseconds
        int delay = 10;
        // Animate the message word by word
        for (size_t i = 0; i < message.size(); ++i)
        {
            cout << message[i] << flush;
            this_thread::sleep_for(chrono::milliseconds(delay));
        }
        cout << endl
             << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        // animation complete

        for (size_t i = 0; i < areas.size(); ++i)
        {
            cout << " " << i + 1 << " -" << areas[i] << "\n\n";
        }

        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "Enter your choice: ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cin >> areaChoice;
        cout << "\n\n";
        if (areaChoice < 1 || areaChoice > areas.size())
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            string message = "\a                ----XXXXXX  Invalid District Choice XXXXXX-----";
            int delay = 150;     // 500 milliseconds delay
            int repeatCount = 7; // Number of times to repeat the on-off cycle
            beepString(message, delay, repeatCount);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            pause();
            return;
        }

        string selectedArea = areas[areaChoice - 1];

        // Select crime type

        // only for Animation
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        string message2 = "\n                        ----(((( Select Crime Type ))))----";
        // Define the delay in milliseconds
        int delay2 = 10;
        // Animate the message word by word
        for (size_t i = 0; i < message2.size(); ++i)
        {
            cout << message2[i] << flush;
            this_thread::sleep_for(chrono::milliseconds(delay2));
        }
        cout << endl
             << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        // animation complete

        for (size_t i = 0; i < crimeTypes.size(); ++i)
        {
            cout << " " << i + 1 << " -" << crimeTypes[i] << "\n\n";
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "Enter your choice: ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cin >> crimeTypeChoice;

        if (crimeTypeChoice < 1 || crimeTypeChoice > crimeTypes.size())
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            string message = "\a                ----XXXXXX  Invalid Crime Type Choice XXXXXX-----";
            int delay = 150;     // 500 milliseconds delay
            int repeatCount = 7; // Number of times to repeat the on-off cycle
            beepString(message, delay, repeatCount);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            pause();
            return;
        }
        string selectedCrimeType = crimeTypes[crimeTypeChoice - 1];

        // Get details about the crime
        cin.ignore(); // to ignore the newline character left in the buffer
        string details;
        clearScreen();

        // only for Animation
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\n\n";
        string message3 = " -(( Enter details about the crime (e.g., number of persons, vehicle used ))-";
        // Define the delay in milliseconds
        int delay3 = 10;
        // Animate the message word by word
        for (size_t i = 0; i < message3.size(); ++i)
        {
            cout << message3[i] << flush;
            this_thread::sleep_for(chrono::milliseconds(delay3));
        }
        cout << endl
             << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        // animation complete
        cout << "\nDETAIL: ";
        getline(cin, details);

        // Get the time of the crime

        clearScreen();
        string time;
        // only for Animation
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        // cout<<"\n\n";
        string message4 = "Enter the time of the crime (HH:MM in 24-hour format, e.g., 14:30)";
        // Define the delay in milliseconds
        int delay4 = 10;
        // Animate the message word by word
        for (size_t i = 0; i < message4.size(); ++i)
        {
            cout << message4[i] << flush;
            this_thread::sleep_for(chrono::milliseconds(delay4));
        }
        cout << endl
             << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        // animation complete
        cout << "Time: ";
        cin >> time;
        string timeInterval = getTimeInterval(time);
        if (timeInterval == "Invalid")
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "\n\n";
            string message = "\a                ----XXXXXX  Invalid Time Enterd XXXXXX-----";
            int delay = 150;     // 500 milliseconds delay
            int repeatCount = 7; // Number of times to repeat the on-off cycle
            beepString(message, delay, repeatCount);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            pause();
            return;
        }

        // Increase crime count
        crimeData[selectedArea][selectedCrimeType]++;
        timeData[timeInterval]++;
        clearScreen();
        // only for Animation
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\n\n\n\n\n\n\n\n\n\n";
        string message5 = "               -----((((( Crime Reported Successfully! )))))-----\n\n\n\n\n";
        // Define the delay in milliseconds
        int delay5 = 10;
        // Animate the message word by word
        for (size_t i = 0; i < message5.size(); ++i)
        {
            cout << message5[i] << flush;
            this_thread::sleep_for(chrono::milliseconds(delay5));
        }
        cout << endl
             << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        // animation complete

        // only for audio-----------------------------
        //  Specify the path to your audio file
        const char *audioFilePath = "C:\\Thanks.mp3"; // Ensure this is the correct path and file extension

        // Construct the PowerShell command to use Windows Media Player COM object
        std::string command = "powershell -c \"";
        command += "$wmplayer = New-Object -ComObject WMPlayer.OCX.7; ";
        command += "$wmplayer.URL = '";
        command += audioFilePath;
        command += "'; ";
        command += "$wmplayer.controls.play(); ";
        command += "Start-Sleep -Seconds 6;\"";

        // Execute the PowerShell command to play the audio file
        int result = std::system(command.c_str());

        // Check if the command was executed successfully
        if (result != 0)
        {
            std::cerr << "Error executing PowerShell command." << std::endl;
            // return 1;
        }
        // only for audio-----------------------------

        pause();
    }
    // function for report (End)

    //______________X______________X__________X_____________X______________X__________X_____________X______________X__________X_____________X______________X_______

    // function for show Details(start)
    void showDetails()
    {
        int areaChoice;

        // Select area to show details
        clearScreen();
        // only for Animation
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\n\n";
        string message = "            -----(((((( Select District To View Details )))))-----\n";
        // Define the delay in milliseconds
        int delay = 10;
        // Animate the message word by word
        for (size_t i = 0; i < message.size(); ++i)
        {
            cout << message[i] << flush;
            this_thread::sleep_for(chrono::milliseconds(delay));
        }
        cout << endl
             << endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        // animation complete

        for (size_t i = 0; i < areas.size(); ++i)
        {
            cout << " " << i + 1 << " -" << areas[i] << "\n\n";
        }

        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "Enter choice: ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cin >> areaChoice;

        if (areaChoice < 1 || areaChoice > areas.size())
        {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            string message = "\a                ----XXXXXX  Invalid District Choice XXXXXX-----";
            int delay = 150;     // 500 milliseconds delay
            int repeatCount = 7; // Number of times to repeat the on-off cycle
            beepString(message, delay, repeatCount);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            pause();
            return;
        }
        string selectedArea = areas[areaChoice - 1];
        clearScreen();
        // Display crime details for the selected area
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\n\n                    -----((((( Crime Details For " << selectedArea << ")))))-----\n\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        for (const auto &crimeType : crimeTypes)
        {
            cout << " -" << crimeType << ": " << crimeData[selectedArea][crimeType] << "\n\n";
        }

        // Display time statisticS
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\n\n                     -----((((( Crime Time Statistics ))))-----\n\n\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        int totalCrimes = 0;
        for (const auto &interval : timeData)
        {
            totalCrimes += interval.second;
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        for (const auto &interval : timeData)
        {
            double percentage = (totalCrimes == 0) ? 0 : (interval.second / (double)totalCrimes) * 100;
            cout << " -" << interval.first << ": " << percentage << "% of crimes\n\n";
        }
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        pause();
    }
    // function for show Details(End)

private:
    string getTimeInterval(const string &time)
    {
        int hour, minute;
        if (sscanf(time.c_str(), "%d:%d", &hour, &minute) != 2 || hour < 0 || hour >= 24 || minute < 0 || minute >= 60)
        {
            return "Invalid";
        }
        if (hour >= 0 && hour < 5)
        {
            return "12am-5am";
        }
        else if (hour >= 5 && hour < 12)
        {
            return "5am-12pm";
        }
        else if (hour >= 12 && hour < 17)
        {
            return "12pm-5pm";
        }
        else
        {
            return "5pm-12am";
        }
    }

    void pause()
    {
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        clearScreen();
    }

    void beepString(const string &str, int delayMilliseconds, int repeatCount)
    {
        for (int i = 0; i < repeatCount; ++i)
        {
            // Display the string
            cout << str << flush;
            this_thread::sleep_for(chrono::milliseconds(delayMilliseconds));

            // Clear the string by overwriting with spaces
            cout << "\r" << string(str.length(), ' ') << flush;
            this_thread::sleep_for(chrono::milliseconds(delayMilliseconds));

            // Move the cursor back to the start
            cout << "\r";
        }
        clearScreen();
        // Ensure the cursor is in the correct place after the loop
        cout << endl;
    }

    void clearScreen()
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }
};

// Global Function to animate a single word
void animateWord(const string &word, int delay)
{
    for (char ch : word)
    {
        cout << ch << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}

int main()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CrimeReportSystem system;
    int choice;

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    string message = "\n            ----(((( Welcome to crime monitoring system Karachi ))))----";

    // Define the delay in milliseconds
    int delay = 20;

    // Animate the message word by word
    for (size_t i = 0; i < message.size(); ++i)
    {
        cout << message[i] << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);

    string message2 = "\n________________________________________________________________________________";

    // Define the delay in milliseconds
    int delay2 = 20;

    // Animate the message word by word
    for (size_t i = 0; i < message2.size(); ++i)
    {
        cout << message2[i] << flush;
        this_thread::sleep_for(chrono::milliseconds(delay2));
    }

    cout << endl
         << endl;

    // only for audio-----------------------------
    //  Specify the path to your audio file
    const char *audioFilePath = "C:\\welcome.mp3"; // Ensure this is the correct path and file extension

    // Construct the PowerShell command to use Windows Media Player COM object
    std::string command = "powershell -c \"";
    command += "$wmplayer = New-Object -ComObject WMPlayer.OCX.7; ";
    command += "$wmplayer.URL = '";
    command += audioFilePath;
    command += "'; ";
    command += "$wmplayer.controls.play(); ";
    command += "Start-Sleep -Seconds 3;\"";

    // Execute the PowerShell command to play the audio file
    int result = std::system(command.c_str());

    // Check if the command was executed successfully
    if (result != 0)
    {
        std::cerr << "Error executing PowerShell command." << std::endl;
        return 1;
    }
    // only for audio-----------------------------

    while (true)
    {

        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "\n\nDo you want to report a crime or show details?\n\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << " -Press "
                "1"
                " to Report a crime\n";
        cout << " -Press "
                "2"
                " to view details\n";
        cout << " -Press "
                "3"
                " to Exit\n\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "\nplease Enter your choice: ";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cin >> choice;

        switch (choice)
        {
        case 1:
            system.reportCrime();
            break;
        case 2:
            system.showDetails();
            break;
        case 3:
            cout << "Exiting the program. Goodbye!\n";
            return 0;
        default:
            cerr << "Invalid choice\n";
            // system.pause();
        }
    }

    return 0;
}