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
    Node* addToHead(Node* hd, float rating) { 
    Node* newNode = new Node; 
    newNode->rating = rating; 
    newNode->next = hd; 
    return newNode;
}
};

int main() {
    vector<Movie> moveVector;

    return 0; 
}

