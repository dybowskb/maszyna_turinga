#include <iostream>

using namespace std;

string t;
int q = 0;
int qi = 0;
char w;

string generujTasme(int m, int n) {
    t = '1';
    for (int i = 0; i < m; i++)
        t = '0' + t;
    for (int i = 0; i < n; i++)
        t += '0';
    return t;
}

int obliczRoznice(int m, int n) {
    int r = 0;
    if (m >= n)
        r = m - n;
    return r;
}

void P() {
    qi++;
    if (qi + 1 >= t.length())
        t += 'B';

    w = t[qi + 1];
    t[qi] = 'q';
}

void L() {
    swap(t[qi], t[qi - 1]);
    qi--;

    w = t[qi + 1];
}

bool przejscia(int qt, char wt) {
    switch (qt) {
    case 0:
        if (wt == '0') {
            q = 1;
            t[qi] = 'B';
            P();
            return 1;
        }
        else if (wt == '1') {
            q = 5;
            t[qi] = 'B';
            P();
            return 1;
        }
        else
            return 0;

        break;

    case 1:
        if (wt == '0') {
            q = 1;
            t[qi] = '0';
            P();
            return 1;
        }
        else if (wt == '1') {
            q = 2;
            t[qi] = '1';
            P();
            return 1;
        }
        else
            return 0;
        break;

    case 2:
        if (wt == '0') {
            q = 3;
            t[qi + 1] = '1';
            L();
            return 1;
        }
        else if (wt == '1') {
            q = 2;
            t[qi] = '1';
            P();
            return 1;
        }
        else {
            q = 4;
            t[qi + 1] = 'B';
            L();
            return 1;
        }
        break;

    case 3:
        if (wt == '0') {
            q = 3;
            t[qi + 1] = '0';
            L();
            return 1;
        }
        else if (wt == '1') {
            q = 3;
            t[qi + 1] = '1';
            L();
            return 1;
        }
        else {
            q = 0;
            t[qi] = 'B';
            P();
            return 1;
        }
        break;

    case 4:
        if (wt == '0') {
            q = 4;
            t[qi + 1] = '0';
            L();
            return 1;
        }
        else if (wt == '1') {
            q = 4;
            t[qi + 1] = 'B';
            L();
            return 1;
        }
        else {
            q = 6;
            t[qi] = '0';
            P();
            return 1;
        }
        break;

    case 5:
        if (wt == '0') {
            q = 5;
            t[qi] = 'B';
            P();
            return 1;
        }
        else if (wt == '1') {
            q = 5;
            t[qi] = 'B';
            P();
            return 1;
        }
        else {
            q = 6;
            t[qi] = 'B';
            P();
            return 1;
        }
        break;

    case 6:
        return 0;
        break;
    }

    return 0;
}

void wypisz(string t) {
    string wy = "";
    int i = t.length() - 1;
    while (t[i] == 'B')
        i--;
    for (int j = 0; j <= i; j++) {
        if (t[j] == 'q') {
            wy += "[";
            wy += t[j];
            wy += (q + '0');
            wy += "]";
        }
        else
            wy += t[j];
    }
    cout << wy;
}

int main()
{
    cout << "\t\tEmulator maszyny Turinga\t" << endl;
    cout << " Obliczajacy roznice wlasciwa: m-n dla m >= n, 0 dla m < n" << endl << endl;
    cout << "\t\t\tPostac MT" << endl;
    cout << " M=({q0, q1, q2, q3, q4, q5, q6}, {0,1}, {0,1,B}, delta, q0, B, 0)" << endl << endl;
    cout << " Tabela przejsc: " << endl;
    cout << " ------------------------------------------" << endl;
    cout << " | delta |     0    |     1    |     B    |" << endl;
    cout << " ------------------------------------------" << endl;
    cout << " |   q0  | (q1,B,P) | (q5,B,P) |     -    |" << endl;
    cout << " |   q1  | (q1,0,P) | (q2,1,P) |     -    |" << endl;
    cout << " |   q2  | (q3,1,L) | (q2,1,P) | (q4,B,L) |" << endl;
    cout << " |   q3  | (q3,0,L) | (q3,1,L) | (q0,B,P) |" << endl;
    cout << " |   q4  | (q4,0,L) | (q4,B,L) | (q6,0,P) |" << endl;
    cout << " |   q5  | (q5,B,P) | (q5,B,P) | (q6,B,P) |" << endl;
    cout << " |   q6  |     -    |     -    |     -    |" << endl;
    cout << " ------------------------------------------" << endl;

    int m, n;
    cout << "podaj m: ";
    cin >> m;
    cout << "podaj n: ";
    cin >> n;

    cout << "\n Wygenerowana tasma wejsciowa: " << generujTasme(m, n) << endl;

    t = 'q' + t;
    w = t[1];

    int stan;
    int isFirst = 1;

    cout << "\n Ciag opisow chwilowych MT:" << endl;
    do {
        if (isFirst)
            isFirst = 0;
        else
            cout << " |- ";
        wypisz(t);
        stan = przejscia(q, w);
    } while (stan);

    cout << "\n\n Roznica wlasciwa wynosi: " << obliczRoznice(m, n) << endl;

    return 0;
}