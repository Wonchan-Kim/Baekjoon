#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Song {
public:
    int identifier;
    string genre;
    int play;

    Song(int identifier, string genre, int play) : identifier(identifier), genre(genre), play(play) {}
};

bool sortByPlayThenId(const Song& a, const Song& b) {
    if (a.play != b.play)
        return a.play > b.play;
    return a.identifier < b.identifier;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<Song> songs;

    // Step 1: Parse input arrays and populate custom data structure
    for (int i = 0; i < genres.size(); i++) {
        songs.emplace_back(i, genres[i], plays[i]);
    }

    // Step 2: Group songs by genre in a map
    map<string, vector<Song>> songMap;
    for (const auto& song : songs) {
        songMap[song.genre].push_back(song);
    }

    // Step 3: Sort songs within each genre based on play count and identifier
    for (auto& pair : songMap) {
        sort(pair.second.begin(), pair.second.end(), sortByPlayThenId);
    }

    // Step 4: Sort genres based on total play count of all songs in each genre
    vector<pair<string, int>> genrePlayCounts;
    for (const auto& pair : songMap) {
        int totalPlayCount = 0;
        for (const auto& song : pair.second) {
            totalPlayCount += song.play;
        }
        genrePlayCounts.emplace_back(pair.first, totalPlayCount);
    }
    sort(genrePlayCounts.begin(), genrePlayCounts.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    // Step 5: Select the top two songs from each genre and add their identifiers to the answer vector
    for (const auto& pair : genrePlayCounts) {
        const string& genre = pair.first;
        const vector<Song>& genreSongs = songMap[genre];
        int count = min(2, static_cast<int>(genreSongs.size()));
        for (int i = 0; i < count; i++) {
            answer.push_back(genreSongs[i].identifier);
        }
    }

    return answer;
}
