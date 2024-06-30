//============================================================================
// Name        : ProjecTwo.cpp
// Author      : Mubeen Ahmed Khan
// Version     : 1.0
// Copyright   : Copyright © 2023 SNHU COCE
// Description : ABCU Advising Assistance Program
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Structure to represent a course
struct Course {
    string courseNumber;             // Course number (e.g., "CS101")
    string name;                     // Course name (e.g., "Introduction to Computer Science")
    vector<string> prerequisites;    // List of course numbers that are prerequisites
};

// Hash Table class to store courses
class HashTable {
private:
    vector<vector<Course>> table;    // The hash table to store courses, implemented as a vector of vectors
    int size;                        // Size of the hash table

    // Hash function to convert a string key into an index for the hash table
    int hash(string key) {
        int sum = 0;
        for (char ch : key) {
            sum += static_cast<int>(ch);   // Sum ASCII values of characters
        }
        return sum % size;                 // Modulus operator to get index within table size
    }

public:
    // Constructor to initialize the hash table with a specified size
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size);    // Resize the table to the specified size
    }

    // Method to insert a course into the hash table
    void insert(Course course) {
        int index = hash(course.courseNumber);  // Calculate the index using the hash function
        table[index].push_back(course);         // Insert the course into the appropriate bucket
    }

    // Method to find a course in the hash table by course number
    Course* find(string courseNumber) {
        int index = hash(courseNumber);         // Calculate the index using the hash function
        for (auto& course : table[index]) {     // Search through the bucket
            if (course.courseNumber == courseNumber) {
                return &course;                 // Return the course if found
            }
        }
        return nullptr;                         // Return nullptr if the course is not found
    }

    // Method to get all courses in the hash table
    vector<Course> getAllCourses() {
        vector<Course> allCourses;              // Vector to store all courses
        for (const auto& bucket : table) {
            for (const auto& course : bucket) {
                allCourses.push_back(course);   // Add each course to the vector
            }
        }
        return allCourses;                      // Return the vector containing all courses
    }
};

// Function to read and parse the course list file
vector<string> readFile(string filename) {
    vector<string> lines;           // Vector to store lines from the file
    ifstream file(filename);        // Open the file
    if (!file) {
        cout << "Error: Unable to open file." << endl;
        return lines;               // Return empty vector if file cannot be opened
    }
    string line;
    while (getline(file, line)) {
        lines.push_back(line);      // Read each line and add to the vector
    }
    file.close();                   // Close the file
    return lines;                   // Return the vector containing all lines
}

// Function to parse course data from lines
HashTable parseCourses(vector<string> lines, int tableSize) {
    HashTable hashTable(tableSize);       // Initialize hash table
    unordered_map<string, string> courseNumbers;   // Map to store course numbers and names
    for (string line : lines) {
        stringstream ss(line);            // Create a string stream for the line
        string courseNumber, name, prerequisite;
        vector<string> tokens;
        while (getline(ss, prerequisite, ',')) {
            tokens.push_back(prerequisite);  // Split line by commas and add to tokens vector
        }
        if (tokens.size() < 2) {
            cout << "Error: Invalid format in line: " << line << endl;
            exit(1);                      // Exit if line format is invalid
        }
        courseNumber = tokens[0];         // First token is course number
        name = tokens[1];                 // Second token is course name
        vector<string> prerequisites;     // Vector to store prerequisites
        for (size_t i = 2; i < tokens.size(); ++i) {
            if (!tokens[i].empty()) {
                prerequisites.push_back(tokens[i]);  // Add remaining tokens as prerequisites
            }
        }
        Course course = { courseNumber, name, prerequisites };
        hashTable.insert(course);         // Insert course into hash table
        courseNumbers[courseNumber] = name;
    }

    // Check for missing prerequisites
    for (const auto& bucket : hashTable.getAllCourses()) {
        for (const auto& prereq : bucket.prerequisites) {
            if (courseNumbers.find(prereq) == courseNumbers.end()) {
                cout << "Error: Prerequisite " << prereq << " for course " << bucket.courseNumber << " does not exist." << endl;
                exit(1);                  // Exit if prerequisite does not exist
            }
        }
    }

    return hashTable;                     // Return the populated hash table
}

// Function to print course information
void printCourseInfo(Course* course) {
    cout << "Course Number: " << course->courseNumber << endl;
    cout << "Course Name: " << course->name << endl;
    if (!course->prerequisites.empty()) {
        cout << "Prerequisites: ";
        for (size_t i = 0; i < course->prerequisites.size(); ++i) {
            cout << course->prerequisites[i];
            if (i < course->prerequisites.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    else {
        cout << "Prerequisites: None" << endl;
    }
}

// Function to search for a course and print its information
void searchCourse(HashTable& courses, string courseNumber) {
    Course* course = courses.find(courseNumber);  // Find course in hash table
    if (course) {
        printCourseInfo(course);                  // Print course information if found
    }
    else {
        cout << "Course " << courseNumber << " not found." << endl;  // Print error if not found
    }
}

// Function to print sorted courses
void printSortedCourses(HashTable& courses) {
    vector<Course> allCourses = courses.getAllCourses();  // Get all courses from hash table
    sort(allCourses.begin(), allCourses.end(), [](Course a, Course b) {
        return a.courseNumber < b.courseNumber;  // Sort courses by course number
    });
    for (Course course : allCourses) {
        cout << course.courseNumber << ", " << course.name << endl;  // Print each course
    }
}

// Function to display the menu and handle user input
void displayMenu(HashTable& courses, int tableSize) {
    bool exit = false;   // Flag to indicate when to exit the menu
    while (!exit) {
        cout << "1. Load file data into data structure" << endl;
        cout << "2. Print alphanumerically ordered list of all courses" << endl;
        cout << "3. Print course title and prerequisites" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;  // Read user choice

        switch (choice) {
        case 1: {  // Option 1: Load file data
            string filename;
            cout << "Enter the file name: ";
            cin >> filename;
            vector<string> lines = readFile(filename);  // Read file
            if (!lines.empty()) {
                courses = parseCourses(lines, tableSize);  // Parse courses and load into hash table
                cout << "Courses loaded successfully." << endl;
            }
            break;
        }
        case 2:  // Option 2: Print sorted courses
            printSortedCourses(courses);
            break;
        case 3: {  // Option 3: Print course information
            string courseNumber;
            cout << "Enter course number: ";
            cin >> courseNumber;
            searchCourse(courses, courseNumber);  // Search and print course information
            break;
        }
        case 9:  // Option 9: Exit
            exit = true;  // Set exit flag to true
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;  // Handle invalid input
        }
    }
}

// Main function
int main() {
    int tableSize = 100;       // Define the size of the hash table
    HashTable courses(tableSize);  // Create a hash table for courses
    displayMenu(courses, tableSize);  // Display the menu for user interaction
    return 0;  // Return 0 to indicate successful execution
}
