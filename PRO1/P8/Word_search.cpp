#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<char> Fila;
typedef vector< Fila > CharMatrix;
typedef vector< vector<bool> > BoolMatrix;

CharMatrix read_matrix(int r, int c)
{
    CharMatrix m(r, Fila(c));
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            cin >> m[i][j];
        }
    }
    return m;
}

BoolMatrix search_words(const CharMatrix& m, const vector<string>& words)
{
    int r = m.size();
    int c = m[0].size();
    int size = words.length();
    BoolMatrix w(r, Fila(c));
    for (int i = 0; i < size; ++i){
        int wsize = words[i].length();


        
        for (int j = 0; j < wsize; ++i){
            if(words[i][j] == )
        }
    }
    return w;
}

void write_matrix(const CharMatrix& w)
{
    int r = w.size();
    int c = w[0].size();
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            cout << w[i][j];
        }
    }
}

int main()
{
    int n, r, c;
    cin >> n >> r >> c;
    vector<string> words;
    for (int i = 0; i < n; ++i) cin >> words[i];
    CharMatrix M = read_matrix(r, c);
    inicializar a false
    BoolMatrix W = search_words(M, words);
    write_matrix(W);
}