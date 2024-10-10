#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Library {
private:
    string tit;
    string theme;
    string actor;
    double r;
    int l;
    double sp;
    string f;
    string date;

public:
    Library(string t, string th, string act, double rat, int len, double speed, string file, string d)
    {
        tit = t;
        theme = th;
        actor = act;
        r = rat;
        l = len;
        sp = speed;
        f = file;
        date = d;
    }

    ~Library() {}

    void setTitle(string t) { tit = t; }
    void setTheme(string th) { theme = th; }
    void setActors(string act) { actor = act; }
    void setRating(double rat) { r = rat; }
    void setLength(int len) { l = len; }
    void setPlaybackSpeed(double speed) { sp = speed; }
    void setFileName(string file) { f = file; }
    void setDate(string d) { date = d; }

    string getTitle() const { return tit; }
    string getTheme() const { return theme; }
    string getActors() const { return actor; }
    double getRating() const { return r; }
    int getLength() const { return l; }
    double getPlaybackSpeed() const { return sp; }
    string getFileName() const { return f; }
    string getDate() const { return date; }

    void show() const {
        cout << "Заголовок: " << tit << "\nТема: " << theme << "\nАктори: " << actor
            << "\nОцінка: " << r << "\nДовжина: " << l << " хвилин"
            << "\nШвидкість відтворення: " << sp
            << "\nНазва файлу: " << f << "\nДата: " << date << endl;
    }
};

class Player {
private:
    vector<Library> library;

public:
    ~Player() {}

    void addMedia(Library& media) {
        library.push_back(media);
    }

    void searchByTitle(const string& title) const {
        for (const Library& media : library) {
            if (media.getTitle() == title) {
                media.show();
                return;
            }
        }
        cout << "Фільм з назвою " << title << " не знайдено." << endl;
    }

    void searchByTheme(const string& theme) const {
        for (const Library& media : library) {
            if (media.getTheme() == theme) {
                media.show();
            }
        }
    }

    void searchByActor(const string& actor) const {
        for (const Library& media : library) {
            if (media.getActors().find(actor) != string::npos) {
                media.show();
            }
        }
    }

    void showAllMedia() const {
        for (const Library& media : library) {
            media.show();
            cout << "------------------------" << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Ukrainian");
    Library movie1("Inception", "Sci-Fi", "Leonardo DiCaprio, Ellen Page", 8.8, 148, 1.0, "inception.mp4", "2010-07-16");
    Library movie2("The Matrix", "Action", "Keanu Reeves, Laurence Fishburne", 8.7, 136, 1.0, "matrix.mp4", "1999-03-31");
    Library movie3("Titanic", "Romance", "Leonardo DiCaprio, Kate Winslet", 7.8, 195, 1.0, "titanic.mp4", "1997-12-19");

    Player player;

    player.addMedia(movie1);
    player.addMedia(movie2);
    player.addMedia(movie3);

    cout << "Пошук за актором 'Leonardo DiCaprio':" << endl;
    player.searchByActor("Leonardo DiCaprio");

    cout << "\nПошук за назвою 'The Matrix':" << endl;
    player.searchByTitle("The Matrix");

    cout << "\nПошук за темою 'Romance':" << endl;
    player.searchByTheme("Romance");

    cout << "\nВсі фільми в бібліотеці:" << endl;
    player.showAllMedia();

    return 0;
}

