#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Score {
    int home, guest;
};

struct Team {
    int number, points, scored, received;
};

typedef vector<Score> Row;
typedef vector<Row> Matrix;

void compute_result(Score score, vector<Team>& scoreboard, int i, int j){
    if (score.home > score.guest){
        scoreboard[i].points += 3;
    }
    else if (score.home < score.guest) scoreboard[j].points += 3;
    else {
        scoreboard[j].points +=1;
        scoreboard[i].points +=1;
    }
    scoreboard[i].scored += score.home;
    scoreboard[j].scored += score.guest;
    scoreboard[j].received += score.home;
    scoreboard[i].received += score.guest;
}

void read_matrix(Matrix& m, int n, vector<Team>& scoreboard){
    for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> m[i][j].home >> m[i][j].guest;
                if (i != j) compute_result(m[i][j], scoreboard, i, j);
            }
    }
}

bool cmp(const Team& Team1, const Team& Team2) {
    if (Team1.points != Team2.points) return Team1.points > Team2.points;
    int goals1 = Team1.scored - Team1.received;
    int goals2 = Team2.scored - Team2.received;
    if (goals1 != goals2) return goals1 > goals2;
    return Team1.number < Team2.number;
}

void init_teams(vector<Team>& scoreboard) {
    int size = scoreboard.size();
    for (int i = 0; i < size; ++i){
        scoreboard[i].points = scoreboard[i].scored = scoreboard[i].received = 0;
        scoreboard[i].number = i + 1;
    }
}

void print_result(const vector<Team>& scoreboard) {
    int size = scoreboard.size();
    for (int i = 0; i < size; ++i){
        cout << scoreboard[i].number << ' ' << scoreboard[i].points << ' ';
        cout << scoreboard[i].scored << ' ' << scoreboard[i].received << endl;
    }
}

int main ()
{
    int size;
    cin >> size;
    Matrix m(size, Row(size));
    vector<Team> scoreboard(size);
    init_teams(scoreboard);
    read_matrix(m, size, scoreboard);
    sort(scoreboard.begin(), scoreboard.end(), cmp);
    print_result(scoreboard);
}
