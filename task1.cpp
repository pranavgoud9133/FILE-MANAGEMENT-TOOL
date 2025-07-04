// FileOperations.cpp
// A C++ program to Read, Write, and Append data to text files

#include <iostream>
#include <fstream>
using namespace std;

// Function to write to file (overwrites existing content)
void writeFile(const string& filename) {
    ofstream file(filename); // Default is overwrite mode
    if (file.is_open()) {
        string data;
        cout << "Enter text to write (end with a dot on a new line):" << endl;
        while (getline(cin >> ws, data) && data != ".") {
            file << data << endl;
        }
        file.close();
        cout << "Data written successfully." << endl;
    } else {
        cout << "Error opening file for writing." << endl;
    }
}

// Function to append to file
void appendFile(const string& filename) {
    ofstream file(filename, ios::app); // Append mode
    if (file.is_open()) {
        string data;
        cout << "Enter text to append (end with a dot on a new line):" << endl;
        while (getline(cin >> ws, data) && data != ".") {
            file << data << endl;
        }
        file.close();
        cout << "Data appended successfully." << endl;
    } else {
        cout << "Error opening file for appending." << endl;
    }
}

// Function to read file
void readFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        cout << "\n--- File Contents ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Error opening file for reading." << endl;
    }
}

// Main function with menu
int main() {
    string filename = "mydata.txt";
    int choice;

    do {
        cout << "\n=== File Handling Menu ===\n";
        cout << "1. Write to File (Overwrite)\n";
        cout << "2. Append to File\n";
        cout << "3. Read from File\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                writeFile(filename);
                break;
            case 2:
                appendFile(filename);
                break;
            case 3:
                readFile(filename);
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
