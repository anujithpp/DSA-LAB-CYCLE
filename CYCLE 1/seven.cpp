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

    cout << "\nSorting Playlist by title:" << std::endl;
    playlist.sort("title");
    playlist.display();

    cout << "\nSorting Playlist by artist:" << std::endl;
    playlist.sort("artist");
    playlist.display();

    cout << "\nSorting Playlist by duration:" << std::endl;
    playlist.sort("duration");
    playlist.display();

    return 0;
}
