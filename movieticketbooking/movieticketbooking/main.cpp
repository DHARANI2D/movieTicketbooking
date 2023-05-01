#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Movie {
    string name;
    int duration;
    int rating;
    int num_tickets;
};

struct Theater {
    string name;
    string location;
    vector<Movie> movies;
};

vector<Theater> theaters;

void add_theater() {
    Theater theater;
    cout << "Enter theater name: ";
    getline(cin, theater.name);
    cout << "Enter theater location: ";
    getline(cin, theater.location);
    theaters.push_back(theater);
    cout << theater.name << " added successfully!" << endl;
}

void delete_theater() {
    string theater_name;
    cout << "Enter theater name: ";
    getline(cin, theater_name);
    for (int i = 0; i < theaters.size(); i++) {
        if (theaters[i].name == theater_name) {
            theaters.erase(theaters.begin() + i);
            cout << theater_name << " deleted successfully!" << endl;
            return;
        }
    }
    cout << theater_name << " not found." << endl;
}

void add_movie() {
    string theater_name, movie_name;
    int duration, rating;
    cout << "Enter theater name: ";
    getline(cin, theater_name);
    for (int i = 0; i < theaters.size(); i++) {
        if (theaters[i].name == theater_name) {
            cout << "Enter movie name: ";
            getline(cin, movie_name);
            cout << "Enter movie duration (in minutes): ";
            cin >> duration;
            cout << "Enter movie rating (out of 10): ";
            cin >> rating;
            theaters[i].movies.push_back({movie_name, duration, rating});
            cout << movie_name << " added to " << theater_name << " successfully!" << endl;
            return;
        }
    }
    cout << theater_name << " not found." << endl;
}

void display_theaters() {
    cout << "Theaters:" << endl;
    for (int i = 0; i < theaters.size(); i++) {
        cout << i+1 << ". " << theaters[i].name << " (" << theaters[i].location << ")" << endl;
    }
}

void book_ticket() {
    string theater_name, movie_name;
    int num_tickets;
    cout << "Enter theater name: ";
    getline(cin, theater_name);
    for (int i = 0; i < theaters.size(); i++) {
        if (theaters[i].name == theater_name) {
            cout << "Enter movie name: ";
            getline(cin, movie_name);
            for (int j = 0; j < theaters[i].movies.size(); j++) {
                if (theaters[i].movies[j].name == movie_name) {
                    cout << "Enter number of tickets to book: ";
                    cin >> num_tickets;
                    if (num_tickets > theaters[i].movies[j].num_tickets) {
                        cout << "Not enough tickets available." << endl;
                    } else {
                        theaters[i].movies[j].num_tickets -= num_tickets;
                        cout << num_tickets << " tickets booked for " << movie_name << " at " << theater_name << "." << endl;
                    }
                    return;
                }
            }
            cout << movie_name << " not found at " << theater_name << endl;
            return;
        }
    }
    cout << theater_name << " not found." << endl;
}

void display_movies() {
    string theater_name;
    cout << "Enter theater name: ";
    getline(cin, theater_name);
    for (int i = 0; i < theaters.size(); i++) {
        if (theaters[i].name == theater_name) {
            cout << "Movies at " << theater_name << ":" << endl;
            for (int j = 0; j < theaters[i].movies.size(); j++) {
                cout << j+1 << ". " << theaters[i].movies[j].name << " (" << theaters[i].movies[j].duration << " mins, " << theaters[i].movies[j].rating << "/10)" << endl;
            }
            return;
        }
    }
    cout << theater_name << " not found." << endl;
}

int main() {
    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Add theater" << endl;
        cout << "2. Delete theater" << endl;
        cout << "3. Add movie" << endl;
        cout << "4. Display theaters" << endl;
        cout << "5. Display movies" << endl;
        cout << "6. Book Tickets" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                add_theater();
                break;
            case 2:
                delete_theater();
                break;
            case 3:
                add_movie();
                break;
            case 4:
                display_theaters();
                break;
            case 5:
                display_movies();
                break;
            case 6:
                book_ticket();
                break;
            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
    return 0;
}
                
