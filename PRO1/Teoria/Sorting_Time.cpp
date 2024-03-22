#include <iostream> 
#include <vector>
#include <algorithm> 
#include <sys/time.h> 
using namespace std; 


//pre: n > 0
//post: retorna un vector de tamanno n leido de la entrada
vector<int> lee_vector(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    return v;
}


//pre:---
//post: valores del vector escritos en output
void escribir_vector(const vector<int>& v) {
    int n = v.size();
    cout << v[0];
    for (int i = 1; i < n; ++i)
        if (i > 0 and i%25 == 0) cout << endl << v[i];
        else cout << ' ' << v[i];
    cout << endl;  
}


////////////////////////////////////////////////////////////////////////////
//////////////////////Mergesort////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////



// Pre: 0 <= iz <= mit <= de < v.size() i v[iz..mit] y v[mit+1..de], por separado, 
//      estan ordenados de menor a mayor
// Post: los valores de v[iz..de] son los iniciales, pero ordenados de menor a
//       a mayor y el resto de elementos de v no ha cambiado
void fusionar(vector<int>& v, int iz, int mit, int de) {
    vector<int> aux(de - iz + 1);
    int i = iz;      //indice para primer segmento
    int j = mit + 1; //indice para segundo segmento
    int k = 0;       //indice para aux
    while (i <= mit and j <= de) {
        if (v[i] <= v[j]) {
            aux[k] = v[i];
            ++i;
        }
        else {
            aux[k] = v[j];
            ++j;
        }
        ++k;
    }
    while (i <= mit) {
        aux[k] = v[i];
        ++k;
        ++i;
    }
    while (j <= de) {
        aux[k] = v[j];
        ++k;
        ++j;
    }
    //volcamos el resultado de la fusion en v[iz..de]
    int s = aux.size(); //s es de - iz + 1
    for (k = 0; k < s; ++k) v[iz + k] = aux[k];
}



// Pre: iz y de son posiciones validas de v 
// Post: los valores  de v[iz..de] son los  iniciales, pero ordenados de menor a mayor
void mergesort(vector<int>& v, int iz, int de) {
    if (iz < de) {
        int mit = (iz + de)/2;
        mergesort(v, iz, mit);
        //por hipotesis de induccion, v[iz..mit] tiene los valores originales ordenados
        mergesort(v, mit + 1, de);
        //por hipotesis de induccion, v[mit+1..de] tiene los valores originales ordenados
        fusionar(v, iz, mit, de);
    }
}



///////////////////////////////////////////////////////////////////////////
/////////////////////////////Insercion/////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// Pre:  ---
// Post: v contiene los valores iniciales y  esta ordenado de menor a mayor
void insert_sort(vector<int>& v) {
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        int x = v[i];
        int j = i;
        while (j > 0 and v[j - 1] > x) {
            v[j] = v[j - 1];
            --j;
        }
        v[j] = x;
    }
}
   
///////////////////////////////////////////////////////////////////////////
////////////////////Quicksort//////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////


//pre: e y d son indices validos de v y e < d y pivote es v[e]
//post: v[e..d] contiene los valores originales reordenados en dos partes
//v[e..mid] contiene los menores o iguales a pivote
//v[mid] es pivote
//v[mid + 1..d] los mayores
//y e <= mid <= d
void separa(vector<int>& v, int pivote, int e, int d, int& mid) {
    int ee = e;
    while (e < d) {
        while (e < d and v[e] <= pivote) ++e;
        while (e < d and v[d] > pivote) --d;
        if (e < d) swap(v[e], v[d]);
    }
    if (v[e] > pivote) mid = e - 1;
    else mid = e;  
    //mid es la  ultima posicion  con valor  <= que pivote
    swap(v[ee], v[mid]);
}
            


// Pre: 0<=e<=d<v.size()
// Post: els elements de v[e..d] son els inicials, pero ordenats creixentment
void quicksort(vector<int>& v, int e, int d) {
    if (e < d) {
        int mid;
        separa(v, v[e], e, d, mid);
        quicksort(v, e, mid - 1);
        quicksort(v, mid + 1, d);
    }
}



int main() {
   cout.setf(ios::fixed);
   cout.precision(10);
   int n;
   cin >> n;
   vector<int> v = lee_vector(n);
   vector<int> clon_v = v;
   //calculamos tiempo cuando ordenamos por insercion
   struct timeval start, stop;
   //escribir_vector(v);
   gettimeofday(&start, NULL);
   insert_sort(v);
   gettimeofday(&stop, NULL);
   double time_elapsed = stop.tv_sec - start.tv_sec;
   time_elapsed += (stop.tv_usec - start.tv_usec)*1e-6;
   cout << "Time elapsed insert_sort: " << time_elapsed;
   cout << " sec" << endl;
   //escribir_vector(v);
   //calculamos tiempo cuando ordenamos por fusion
   v = clon_v;
   //escribir_vector(v);
   gettimeofday(&start, NULL);
   mergesort(v, 0, n - 1);
   gettimeofday(&stop, NULL);
   time_elapsed = stop.tv_sec - start.tv_sec;
   time_elapsed += (stop.tv_usec - start.tv_usec)*1e-6;
   cout << "Time elapsed mergesort: " << time_elapsed;
   cout << " sec" << endl;
   //escribir_vector(v);
   //calculamos tiempo cuando ordenamos  con sort():
   v = clon_v;
   //escribir_vector(v);
   gettimeofday(&start, NULL);
   sort(v.begin(), v.end());
   gettimeofday(&stop, NULL);
   time_elapsed = stop.tv_sec - start.tv_sec;
   time_elapsed += (stop.tv_usec - start.tv_usec)*1e-6;
   cout << "Time elapsed sort(): " << time_elapsed;
   cout << " sec" << endl;
   //escribir_vector(v);   
   //calculamos tiempo cuando ordenamos  con quicksort():
   v = clon_v;
   gettimeofday(&start, NULL);
   quicksort(v, 0, n -1);
   gettimeofday(&stop, NULL);
   time_elapsed = stop.tv_sec - start.tv_sec;
   time_elapsed += (stop.tv_usec - start.tv_usec)*1e-6;
   cout << "Time elapsed quicksort(): " << time_elapsed;
   cout << " sec" << endl;
   //escribir_vector(v);
}
