#include <bits/stdc++.h>
#define ft(i, a, b) for (int i = (int) a; i <= (int) b; i++)
#define fl(i, a, b) for (int i = (int) a; i >= (int) b; i--)
#define MAXN 100001
using namespace std;

struct mainData {
    string name;
    long long dmg;
    mainData() {}
    mainData(string _name, long long _dmg) {
        name = _name;
        dmg = _dmg;
    }
};

void maxHeapify(mainData a[], int i, int n) {
    int left = 2 * i, right = 2 * i + 1, largest;
    if (left <= n && a[left].dmg > a[i].dmg) largest = left;
    else largest = i;
    if (right <= n && a[right].dmg > a[largest].dmg) largest = right;
    if (largest != i) {
        swap(a[i].dmg, a[largest].dmg);
        swap(a[i].name, a[largest].name);
        maxHeapify(a, largest, n);
    }
}

void buildMaxHeapify(mainData a[], int n) {
    fl(i, n / 2, 1) maxHeapify(a, i, n);
}

void listAction(int *key) {
    ifstream read("./UI.txt");
    if (read.is_open() && *key != -2) {
        string line;
        cout << "------------------------------------------------------------------------\n";
        while (getline(read, line)) cout << line << '\n';
        read.close();
    }
    else
        if (*key != -2) {
            cout << "Loi mo file Danh sach thao tac." << '\n';
            *key = -2;
        }
}

void getInput(int *n, long long *d, int *k, mainData weapon[], int *key) {
    ifstream read("./MainInput.txt");
    long long Inp[3];
    if (read.is_open()) {
        string line;
        int i = 0;
        while (getline(read, line) && i < 3) {
            cout << line;
            cin >> Inp[i++];
        }
        read.close();
    }
    else {
        cout << "Loi thao tac nhap." << '\n';
        return;
    }
    cout << "Nhap danh sach vu khi: ";
    ft(j, 1, Inp[0]) {
        string name = "";
        cout << '\n' << "\t- Nhap ten vu khi " << j << ": ";
        while (getline(cin, name))
            if (name != "") break;
        long long dmg;
        bool tmp = false;
        do {
            if (!tmp) cout << "\t- Nhap sat thuong vu khi " << j << ": ";
            else cout << "\t- Nhap lai sat thuong vu khi " << j << " (sat thuong la so tu nhien): ";
            tmp = true;
            cin >> dmg;
        } while (dmg <= 0);
        weapon[j] = mainData(name, dmg);
    }
    *n = Inp[0];
    *d = Inp[1];
    *k = Inp[2];
}

void printPre(mainData a[], long long d, int k, long long start_d) {
    if (k == 1) cout << "------------------Cac thao tac nguoi choi da thuc hien------------------";
    cout << "\n*Luot danh thu " << k << ": " << '\n';
    cout << "\t- Su dung vu khi " << a[1].name << " voi sat thuong " << a[1].dmg << '\n';
    cout << "\t- BOSS: " << ((d > 0) ? d : 0) << "/" << start_d << '\n';
}

void printNext(mainData a[], int n) {
    cout << "\t- Danh sach vu khi sau khi tan cong: " << '\n';
    ft(i, 1, n) cout << "\t\t+ " << a[i].name << ": " << a[i].dmg << '\n';
}

void getKey(int *key) {
    int k;
    cout << "------------------------------------------------------------------------\nNhap lua chon thao tac: ";
    cin >> k;
    while (!(1 <= k && k <= 2)) {
        cout << "Nhap lai lua chon thao tac: ";
        cin >> k;
    }
    *key = k;
}

bool sameString(string a, string b) {
    if (a.length() != b.length()) return false;
    for (int i = 0; i < a.length(); i++)
        if (a[i] != b[i]) return false;
    return true;
}

struct mainData weapon[MAXN];
int n, k, key = 0;
long long d;

int main() {
    ios_base::sync_with_stdio(0);
    while (key == 0) {
        getInput(&n, &d, &k, weapon, &key);
        listAction(&key);
        if (key != -2) {
            getKey(&key);
            long long start_d = d;
            buildMaxHeapify(weapon, n);
            int res = 0;
            while (d > 0 && ++res <= k) {
                d -= weapon[1].dmg;
                if (weapon[1].dmg == 0) break;
                if (key == 2) printPre(weapon, d, res, start_d);
                if (weapon[1].dmg > 0) {
                    weapon[1].dmg /= 2;
                    maxHeapify(weapon, 1, n);
                }
                if (key == 2) printNext(weapon, n);
            }
            if (key == 1)
                if (res <= k && d <= 0) cout << "Ket qua: " << res << '\n';
                else cout << "Ket qua: -1\n";
            if (key == 2) {
                cout << "------------------------------------------------------------------------\n";
                if (res <= k && d <= 0) cout << "Ket qua chien dau: Chien thang.\n";
                else cout << "Ket qua chien dau: That bai.\n";
            }
        }
        if (key > 0) {
            cout << "------------------------------------------------------------------------\nGo C de tiep tuc danh BOSS lan khac: ";
            string line;
            cin >> line;
            if (sameString(line, "C") || sameString(line, "c")) {
                key = 0;
                for (int i = 1; i <= 2; i++) cout << "------------------------------------------------------------------------\n";
            }
        }
    }
    return 0;
}
