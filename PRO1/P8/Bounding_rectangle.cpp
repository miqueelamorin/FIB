#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> Row;
typedef vector<Row> Rectangle;

void minimal_dimensions(char c, const Rectangle& r, int& rows, int& cols)
{
    int nrows = r.size();
    int ncols = r[0].size();
    int rowmin, colmin, rowmax, colmax;
    rowmin = nrows; 
    colmin = ncols; 
    rowmax = colmax = - 1;
    
    bool found = false;
    int i = 0;
    int j = 0;
    while (not found and i < nrows) {
        while (not found and j < ncols) {
            if (r[i][j] == c) {
                rowmin = rowmax = i;
                colmin = colmax = j;
                found = true;
            }
            ++j;
        }
        ++i;
    }
    found = false;
    i = nrows - 1;
    j = 0;
    while (not found and i > rowmin) {
        while (not found and j < ncols) {
            if (r[i][j] == c) {
                rowmax = i;
                if (j > colmax) colmax = j;
                else if (j < colmin) colmin = j; 
                found = true;
            }
            ++j;
        }
        --i;
    }
    found = false;
    i = rowmin;
    while (not found and i <= rowmax) {
        j = ncols - 1;
        while (not found and j > colmax) {
            if (r[i][j] == c) {
                colmax = j;
                found = true;
            }
            --j;
        }
        ++i;
    }
    found = false;
    i = rowmin;
    j = 0;
    while (not found and i <= rowmax) {
        while (not found and j < colmin) {
            if (r[i][j] == c) {
                colmin = j;
                found = true;
            }
            ++j;
        }
        ++i;
    }
    if (rowmax > -1) {
    rows = rowmax - rowmin + 1;
    cols = colmax - colmin + 1;
    }
    else
    {
    rows = 0;
    cols = 0;
    }
}

int main()
{ 
    int n, m;
    while (cin >> n >> m) {
    Rectangle r(n, vector<char>(m));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j) cin >> r[i][j];
    }
        
    int t;
    cin >> t;
    while (t--) {
        char c;
        cin >> c;
        int rows, cols;
        minimal_dimensions(c, r, rows, cols);
        cout << rows << " " << cols << endl;
    }
  }
}
