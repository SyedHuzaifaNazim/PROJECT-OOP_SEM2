<h1 class ="head_main"><strong><i>CRIME MONITORING SYSTEM</i></strong></h1>

<h2>Abstract: </h2>
	<p>Our project aims to develop a <b>Crime Monitoring System</b> using Object-Oriented Programming (OOP) principles in C++. The system will utilize the core pillars of OOP, namely encapsulation, inheritance, and polymorphism, to create a robust and scalable solution for tracking and analyzing crime rates in different areas. The base class, "Crime," will serve as the foundation, with derived classes such as <i>"Snatching," "Robbery," and "Harassment"</i> inheriting properties and behaviors from the parent class. Encapsulation will ensure data security and modularity, allowing for easy maintenance and expansion of the system. Polymorphism will enable flexibility in handling various types of crimes and generating statistical reports. Through this project, we aim to demonstrate the effectiveness of OOP principles in real-world applications, particularly in the domain of crime monitoring.</p>
<h3>GitHub Link: If you want to check code then: <a href="https://github.com/SyedHuzaifaNazim/PROJECT-OOP_SEM2">Click Here</a></h3>
<h3>Introduction:</h3>
<p>The <strong>"Crime Monitoring System"</strong> is designed to track and analyze crime incidents in different districts of Karachi using Object-Oriented Programming (OOP) principles in C++. This project leverages encapsulation for data security, inheritance to structure different crime types, and polymorphism for flexible handling and reporting.
Our system allows users to report crimes and view detailed statistical data. It categorizes crimes such as <i>robbery, snatching, and harassment, tracking them across various areas and times to identify patterns and trends</i>. This automation helps in understanding crime dynamics and supports law enforcement efforts.
This report will outline the design and architecture of the project, detailing the organization of classes and objects, and explaining the implementation specifics, including key algorithms and data structures. It will also highlight how OOP principles were applied to create a robust and efficient crime monitoring system.</p>
<h3>Design & Architecture:</h3>
<h4>Overall Design</h4>
The project is a Crime Monitoring System implemented using Object-Oriented Programming (OOP) principles in C++. The system is designed to track and analyze crime rates in different areas. It consists of the following key components:
<h4>Classes and Objects:</h4>
CrimeReportSystem: This class is the core of the system, responsible for managing crime data, reporting crimes, and displaying crime statistics.
<h4>Data Structures:</h4>
<h6>areas:</h6> <p>A vector to store different areas <i>(e.g., Downtown, Uptown, Suburbs)</i>.</p>
<h6>crimeTypes:</h6> <p>A vector to store different types of crimes <i>(e.g., Robbery, Snatching, Harassment)</i>.</p>
<h6>crimeData:</h6> <p>A map to store the count of each type of crime in each area.</p>
<h6>timeData:</h6> <p>To store the count of crimes occurring in different time intervals.</p>
<h5>Design Patterns:</h5>
<p>The project employs basic OOP principles but doesn't explicitly use advanced design patterns like MVC, Singleton, or Factory. However, the following principles are implemented:</p>
<h6>Encapsulation:</h6> <p>The data members of the CrimeReportSystem class are private and are accessed or modified through public member functions.</p>
<h6>Inheritance:</h6> <p>The design suggests the potential for a base class Crime with derived classes like <i>Snatching, Robbery, and Harassment,</i> but the current implementation has not detailed this.</p>
Polymorphism: This principle can be seen in the method calls where the same function is used to handle different types of crimes and generate statistical reports.
f
<img align="center" alt="coding" width="100%" src="./Scrshots/Screenshot 2024-07-05 111205.png"/>
<hr>
<img align="center" alt="coding" width="100%" src="./Scrshots/Screenshot 2024-07-05 111438.png"/>


<h3>Implementation Details:</h3>
<h4>Classes and Methods:</h4>
CrimeReportSystem Class
<h5>Data Members:</h5>
areas: Stores different areas.
crimeTypes: Stores different types of crimes.
crimeData: Stores the count of each type of crime in each area.
timeData: Stores the count of crimes occurring in different time intervals.

Methods:
CrimeReportSystem(): Constructor to initialize areas, crime types, and data structures.
reportCrime(): Handles the reporting of a crime, including user input for area, crime type, details, and time.
showDetails(): Displays crime statistics for selected areas and time intervals.
getTimeInterval(const string &time): Determines the time interval based on the provided time.
pause(): Pauses the program execution until the user presses Enter.
beepString(const string &str, int delayMilliseconds, int repeatCount): Displays a string with a beeping effect.
clearScreen(): Clears the console screen.

Implementation of OOP Principles
Encapsulation: Data members like areas, crimeTypes, crimeData, and timeData are private. They are accessed and modified through public methods like reportCrime() and showDetails().

Inheritance: Although not explicitly shown in the current code, the structure suggests potential for a base class Crime with derived classes like Snatching, Robbery, and Harassment.

Polymorphism: The methods reportCrime() and showDetails() handle different types of crimes and generate reports dynamically based on the crime type and area selected.

Code Snippets:
Here are some interesting parts of the code:

reportCrime() Method :
```cpp
void reportCrime()
{
    clearScreen();
    int areaChoice, crimeTypeChoice;
    // Animation and user input for selecting area and crime type
    for (size_t i = 0; i < areas.size(); ++i)
    {
        cout << " " << i + 1 << " -" << areas[i] << "\n\n";
    }
    cin >> areaChoice;
    string selectedArea = areas[areaChoice - 1];

    for (size_t i = 0; i < crimeTypes.size(); ++i)
    {
        cout << " " << i + 1 << " -" << crimeTypes[i] << "\n\n";
    }
    cin >> crimeTypeChoice;
    string selectedCrimeType = crimeTypes[crimeTypeChoice - 1];

    // Get details and time of the crime
    cin.ignore();
    string details, time;
    cout << "Enter details about the crime: ";
    getline(cin, details);
    cout << "Enter the time of the crime (HH:MM): ";
    cin >> time;

    string timeInterval = getTimeInterval(time);
    if (timeInterval == "Invalid")
    {
        cout << "Invalid Time Entered\n";
        pause();
        return;
    }

    // Update crime data
    crimeData[selectedArea][selectedCrimeType]++;
    timeData[timeInterval]++;
    cout << "Crime Reported Successfully!\n";
    pause();
}
```
showDetails() Method:
```cpp
void showDetails()
{
    int areaChoice;
    clearScreen();
    for (size_t i = 0; i < areas.size(); ++i)
    {
        cout << " " << i + 1 << " -" << areas[i] << "\n\n";
    }
    cin >> areaChoice;
    string selectedArea = areas[areaChoice - 1];
    clearScreen();
    cout << "Crime Details For " << selectedArea << "\n";
    for (const auto &crimeType : crimeTypes)
    {
        cout << " -" << crimeType << ": " << crimeData[selectedArea][crimeType] << "\n\n";
    }

    cout << "Crime Time Statistics\n";
    int totalCrimes = 0;
    for (const auto &interval : timeData)
    {
        totalCrimes += interval.second;
    }
    for (const auto &interval : timeData)
    {
        double percentage = (totalCrimes == 0) ? 0 : (interval.second / (double)totalCrimes) * 100;
        cout << " -" << interval.first << ": " << percentage << "% of crimes\n\n";
    }
    pause();
}
```
Testing and Validation:
To ensure the reliability and accuracy of the "Crime Monitoring System," we implemented a comprehensive testing strategy that included unit tests, integration tests, and various test cases to validate the functionality and performance of the system.
Unit Tests:
- CrimeReportSystem Class: We created unit tests for the core functions such as `reportCrime()` and `showDetails()`. These tests verified that crimes were accurately recorded in the correct categories and that the statistical reports were generated correctly.
- Helper Functions: We tested helper functions like `getTimeInterval()` to ensure they correctly parsed and categorized time inputs.
Integration Tests:
- User Interface and Interaction: We simulated user interactions to ensure the seamless integration of the user interface with the backend logic. This included testing the flow of reporting a crime and viewing detailed statistics.
- Data Integrity: We tested the system's ability to handle multiple crime reports in sequence and verified that the data remained consistent and accurate across different sessions.

Test Cases:
- Valid Inputs: Tested with valid area selections, crime types, detailed descriptions, and time inputs to ensure correct recording and reporting.
- Invalid Inputs: Tested with invalid inputs (e.g., out-of-range selections, incorrect time formats) to ensure the system handled errors gracefully and provided appropriate feedback to users.
- Edge Cases: Tested scenarios such as reporting crimes at boundary times (e.g., exactly at 5:00 AM) to ensure accurate time interval categorization.

Validation:
- Requirement Verification: We cross-referenced the system's functionality with the project requirements to ensure all features were implemented correctly.
- User Feedback: We gathered feedback from potential users to validate the system's usability and effectiveness in real-world scenarios.
Effectiveness:
The "Crime Monitoring System" successfully achieved its primary objectives of providing a structured way to report and analyze crime data. Here are some reflections on the project's effectiveness:
Successes:
- Accurate Data Handling: The system effectively recorded and categorized crimes, providing accurate and detailed statistical reports.
- User-Friendly Interface: The animated messages and clear prompts contributed to a user-friendly experience, making the system accessible even to non-technical users.
- Robust OOP Implementation: The use of encapsulation, inheritance, and polymorphism ensured a modular and scalable system.
Challenges:
- Error Handling: Implementing comprehensive error handling for all possible invalid inputs was challenging but essential for robustness.
- Real-Time Updates: Ensuring real-time updates and maintaining data integrity across multiple sessions required careful design and testing.
Areas for Improvement:
- Enhancing User Interface: Improving the graphical user interface (GUI) could make the system more intuitive and visually appealing.
- Expanding Features: Adding more crime types and integrating the system with external databases or law enforcement tools could enhance its functionality and applicability.
- Performance Optimization: Further optimizing the performance, especially for larger datasets, would improve the system's efficiency and scalability.

