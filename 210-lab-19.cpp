// COMSC210 | Lab 19 | Majd Bohsali
// IDE used: Visual Studio Code
#include <iostream>
#include <vector>
#include <string>
using namespace std; 

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
    vector<Movie> movies;

    Movie movie1; 
    movie1.setTitle("hell world");
    movie1.setComments("amazing");
    movie1.addReviewToHead(2.3);
    movie1.addReviewToHead(1.3);
    movie1.addReviewToHead(4.5);

    movie1.printReviews(); 
    return 0; 
}

