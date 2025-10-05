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
const int NUM_MOVIES = 4; 

class Movie {
private: 
    struct Node {
        float rating; 
        string comments;
        Node *next;
    };
    string title;
    Node* head;
public:
    Movie() {
        title = "";
        head = nullptr; 
    }

    Movie(string t, vector<string> allComments, vector<float> movieRankings) {
        title = t;
        head = nullptr;  
        for(int i = 0; i < movieRankings.size(); i++) {
            addReviewToHead(movieRankings.at(i), allComments.at(i));
        }
    }

    Movie(const Movie& other) { // since there is a linked list it needs a deep copy
        title = other.title;
        head = nullptr;
        Node* current = other.head;
        Node* tail = nullptr; 

        while(current) {
            Node* nextNode = new Node; 
            nextNode->rating = current->rating; 
            nextNode->comments = current->comments; 
            nextNode->next = nullptr;

            if(!head) {
                head = nextNode;
                tail = nextNode;
            }
            else {
                tail->next = nextNode;
                tail = nextNode; 
            }
            current = current->next;
        }
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
    string getTitle() { return title; }
    void addReviewToHead(float rating, string comments) { 
        Node* newNode = new Node; 
        newNode->rating = rating; 
        newNode->comments = comments; 
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
        cout << "Movie title: " << title << endl;
        while (current) {
            cout << "    > Review #" << ++reviewNum << ": " << current->rating << ": " << current->comments << endl; 
            totalRatingScore += current->rating; 
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    srand(time(0));
    vector<Movie> movies;
    ifstream inputFile("input.txt");
    string title; 
    string comments;
    int movieCount = 0;
    if(inputFile.is_open()) { 
        while (getline(inputFile, title)) {
            vector<float> allRatings; 
            vector<string> allComments; 
            for(int i = 0; i < NUM_RATINGS; i++) {
                float rating = (rand() % ((MAX_RATING - MIN_RATING) * 10 + 1)) / 10.0 + MIN_RATING;
                getline(inputFile, comments); 
                allRatings.push_back(rating);
                allComments.push_back(comments); 
            }
            movies.push_back(Movie(title, allComments, allRatings));
            movieCount++;
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