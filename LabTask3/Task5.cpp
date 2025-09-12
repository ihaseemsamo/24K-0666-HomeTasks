#include <iostream>
#include <string>
using namespace std;

struct Node {
    string songName;
    Node* next;

    Node(string songName) {
        this->songName = songName;
        this->next = NULL;
    }
};

class CircularPlaylist {
private:
    Node* head;

public:
    CircularPlaylist() {
        head = NULL;
    }

    void addSongAtEnd(const string& songName) {
        Node* newSong = new Node(songName);
        if (head == NULL) {
            head = newSong;
            newSong->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newSong;
            newSong->next = head;
        }
    }

    void addSongAtBeginning(const string& songName) {
        Node* newSong = new Node(songName);
        if (head == NULL) {
            head = newSong;
            newSong->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newSong;
            newSong->next = head;
            head = newSong;
        }
    }

    void displayPlaylist() {
        if (head == NULL) {
            cout << "The playlist is empty!" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->songName << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to the first song)" << endl;
    }

    void removeSong(const string& songName) {
        if (head == NULL) {
            cout << "The playlist is empty!" << endl;
            return;
        }
        Node* temp = head;
        Node* prev = NULL;

        if (head->songName == songName) {
            if (head->next == head) {
                delete head;
                head = NULL;
            } else {
                prev = head;
                while (prev->next != head) {
                    prev = prev->next;
                }
                prev->next = head->next;
                delete head;
                head = prev->next;
            }
            return;
        }

        do {
            prev = temp;
            temp = temp->next;
            if (temp->songName == songName) {
                prev->next = temp->next;
                delete temp;
                return;
            }
        } while (temp != head);

        cout << "Song not found in the playlist!" << endl;
    }

    bool searchSong(const string& songName) {
        if (head == NULL) {
            return false;
        }
        Node* temp = head;
        do {
            if (temp->songName == songName) {
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    void playNextSong() {
        if (head == NULL) {
            cout << "The playlist is empty!" << endl;
            return;
        }
        cout << "Now playing: " << head->songName << endl;
        head = head->next;
    }

    ~CircularPlaylist() {
        if (head == NULL) return;
        Node* temp = head;
        do {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != head);
    }
};

int main() {
    CircularPlaylist playlist;

    playlist.addSongAtEnd("Song 1");
    playlist.addSongAtEnd("Song 2");
    playlist.addSongAtEnd("Song 3");
    playlist.addSongAtBeginning("Song 0");

    cout << "Displaying Playlist: " << endl;
    playlist.displayPlaylist();

    cout << "\nPlaying the next song..." << endl;
    playlist.playNextSong();

    cout << "\nDisplaying Playlist after removing Song 2: " << endl;
    playlist.removeSong("Song 2");
    playlist.displayPlaylist();

    cout << "\nSearching for Song 3 in the playlist: " << (playlist.searchSong("Song 3") ? "Found" : "Not Found") << endl;
    cout << "Searching for Song 5 in the playlist: " << (playlist.searchSong("Song 5") ? "Found" : "Not Found") << endl;

    return 0;
}
