#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Movie
{
public:
    string name;
    double rating;

    Movie(string n, double r) : name(n), rating(r) {}

    void Print() const
    {
        cout << name << ": " << rating << endl;
    }
};

int main()
{
    vector<Movie> movies;

    movies.push_back(Movie("titanic", 9.9));
    movies.push_back(Movie("gone with the wind", 9.6));
    movies.push_back(Movie("terminator", 9.7));

    // 영화 정보 출력
    for (const auto &movie : movies)
    {
        movie.Print();
    }

    return 0;
}
