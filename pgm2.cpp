#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registration() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    ofstream file("database.txt", ios::app); // Open file in append mode
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful!" << endl;
}

void login() {
    string username, password, user, pass;
    bool found = false;

    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ifstream file("database.txt");
    while (file >> user >> pass) {
        if (user == username && pass == password) {
            found = true;
            break;
        }
    }
    file.close();

    if (found) {
        cout << "Login successful! Welcome, " << username << "." << endl;
    } else {
        cout << "Login failed! Please check your credentials." << endl;
    }
}

int main() {
    int choice;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        registration();
    } else if (choice == 2) {
        login();
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
