#include <string>
#include <iostream>

using namespace std;

struct Song {
    string title;
    string artist;
    int duration;
    string genre;

    Song(string p_title, string p_artist, int p_duration, string p_genre)
            : title(p_title), artist(p_artist), duration(p_duration), genre(p_genre) {}
};

struct Node {
    Song data;
    Node *next;

    Node(Song p_song) : data(p_song), next(nullptr) {}
};


class Playlist {
private:
    Node *head;

    Node *merge(Node *left, Node *right) {
        if (!left) return right;
        if (!right) return left;

        Node *result = nullptr;
        if (left->data.title <= right->data.title) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }

    static void split(Node *source, Node **front, Node **back) {
        Node *slow = source;
        Node *fast = source->next;

        while (fast) {
            fast = fast->next;
            if (fast) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *front = source;
        *back = slow->next;
        slow->next = nullptr;
    }

    void mergeSort(Node **node) {
        Node *head = *node;
        Node *left;
        Node *right;

        if (!head || !head->next) {
            return;
        }

        split(head, &left, &right);

        mergeSort(&left);
        mergeSort(&right);

        *node = merge(left, right);
    }

public:
    Playlist() : head(nullptr) {}

    void insert(Song song) {
        Node *newNode = new Node(song);
        if (!head) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void sort() {
        mergeSort(&head);
    }

    void display() {
        Node *temp = head;
        while (temp) {
            cout << "Title: " << temp->data.title << ", Artist: " << temp->data.artist
                 << ", Duration: " << temp->data.duration << "s, Genre: " << temp->data.genre << std::endl;
            temp = temp->next;
        }
    }
};