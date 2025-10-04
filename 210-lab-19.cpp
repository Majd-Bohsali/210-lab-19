// COMSC210 | Lab 19 | Majd Bohsali
// IDE used: Visual Studio Code
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime> 
using namespace std; 


const int NUM_RATINGS = 4; 
const int MIN_RATING = 1;
const int MAX_RATING = 5;

class Movie {
private: 
    struct Node {
        float rating; 
        Node *next;
    };
    string title;
    Node* head;
    string comments; 
public:
    Movie() {
        title = "";
        comments = ""; 
        head = nullptr; 
    }

    ~Movie() {
        Node* current = head;
        while (current) {
            head = current->next; 
            delete current;
            current = head;
        }
    }

    void setTitle(string t) { title = t; }
    void setComments(string c) {comments = c; }
    string getTitle() { return title; } 
    string getComments() { return comments; }
    void addReviewToHead(float rating) { 
        Node* newNode = new Node; 
        newNode->rating = rating; 
        newNode->next = head;
        head = newNode;
    }

    void printReviews() { 
        if (!head) {
        cout << "Empty list.\n";
        return;
        }
        Node* current = head;
        int reviewNum = 0; 
        float totalRatingScore = 0.0; 
        while (current) {
            cout << "    > Review #" << reviewNum++ << ": " << current->rating << endl; 
            totalRatingScore += current->rating; 
            current = current->next;
        }
        cout << "    > Average: " << totalRatingScore/reviewNum;
        cout << endl;
    }
};

int main() {
    srand(time(0));
    vector<Movie> movies;
    ifstream inputFile("input.txt");
    string title; 
    string comments;
    if(inputFile.is_open()) { 
        while (getline(inputFile, title)) {
            getline(inputFile, comments); 
            cout << title << " " << comments << endl; 
           // inputFile.ignore();
            Movie tempMovie; 
            tempMovie.setTitle(title);
            tempMovie.setComments(comments); 
            for(int i = 0; i < NUM_RATINGS; i++) {
                float rating = (rand() % ((MAX_RATING - MIN_RATING) * 10 + 1)) / 10.0;
                tempMovie.addReviewToHead(rating);
            }
            movies.push_back(tempMovie);
           
        }
        inputFile.close();
    }
    else { 
        cout << "File not found" << endl; 
    }

    for (int i = 0; i < movies.size(); i++) {
        movies.at(i).printReviews(); 
    }
    return 0; 
}

