#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Song {
public:
    int identifier;
    int plays;

    Song(int identifier, int plays) : identifier(identifier), plays(plays) {}
};

bool sortByPlaysDesc(const Song& a, const Song& b) {
    return a.plays > b.plays;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<Song> songs;
    for (size_t i = 0; i < genres.size(); ++i) {
        songs.emplace_back(Song(i, plays[i]));
    }

    map<string, vector<Song>> myMap;
    for (size_t i = 0; i < genres.size(); ++i) {
        myMap[genres[i]].emplace_back(songs[i]);
    }
//맵은 정렬 함수 사용 불가,.,,
    
    vector<pair<int, string>> genrePlayCount;
    for (const auto& pair : myMap) {
        int totalPlayCount = 0;
        const vector<Song>& songs = pair.second;
        for (const Song& song : songs) {
            totalPlayCount += song.plays;
        }
        genrePlayCount.emplace_back(totalPlayCount, pair.first);
    }
    //1번 조건

    sort(genrePlayCount.rbegin(), genrePlayCount.rend());

    for (const auto& pair : genrePlayCount) {
        const string& genre = pair.second;
        vector<Song>& songs = myMap[genre];
        sort(songs.begin(), songs.end(), sortByPlaysDesc);
        for (size_t i = 0; i < songs.size() && i < 2; ++i) {
            answer.emplace_back(songs[i].identifier);
        }
    }

    return answer;
}
