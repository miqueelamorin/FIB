#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Student {
    string name;
    int right;
    int wrong;
};


vector<int> read_right_answers(int m) {
    vector<int> M(m);
    for (int i = 0; i < m; ++i) cin >> M[i];
    return M;
}

vector<Student> get_info_test(const vector<int>& answer, int n) {
    vector<Student> s(n);
    int answsize = answer.size();
    for (int i = 0; i < n; ++i) {
        cin >> s[i].name;
        int student_answ;
        s[i].right = s[i].wrong = 0;
        for (int j = 0; j < answsize; ++j) {
            cin >> student_answ;
            if (student_answ == answer[j]) ++s[i].right;
            else if (student_answ != answer[j] and student_answ != 0) ++s[i].wrong;
        }
    }
    return s;
}

bool cmp(Student a, Student b) {
    int nota_a = (a.right*2) - a.wrong;
    int nota_b = (b.right*2) - b.wrong;

    if (nota_a != nota_b) return nota_a > nota_b;
    if (a.wrong != b.wrong) return a.wrong < b.wrong;
    return a.name < b.name;
}

void write_results(const vector<Student>& v) {
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        cout << v[i].name << ' ' << v[i].right << ' ' << v[i].wrong << endl;
    }
}

int main() {
    int m;
    cin >> m;
    vector<int> answer = read_right_answers(m);
    int n;
    cin >> n;
    vector<Student> v = get_info_test(answer, n);
    sort(v.begin(), v.end(), cmp);
    write_results(v);
}