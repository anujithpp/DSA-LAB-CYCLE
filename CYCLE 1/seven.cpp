#include "Playlist.cpp"

int main() {
    Playlist playlist;

    playlist.insert(Song("Guzarish", "Javed Ali", 327, "Romantic"));
    playlist.insert(Song("Hey Manohara", "Gopi Sundar", 205, "Pop"));
    playlist.insert(Song("Mahanubhavulu", "Fejo", 192, "Rap"));
    playlist.insert(Song("Paradise", "Coldplay", 278, "Hip Hop"));
    playlist.insert(Song("Softcore", "The Neighbourhood", 206, "Hip Hop"));
    playlist.insert(Song("Shyamambaram", "Vineeth Sreenivasan", 298, "Melody"));

    cout << "Unsorted Playlist:" << std::endl;
    playlist.display();

    playlist.sort();

    cout << "\nSorted Playlist:" << std::endl;
    playlist.display();

    return 0;
}
