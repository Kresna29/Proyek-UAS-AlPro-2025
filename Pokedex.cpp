#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Struct
struct Pokemon
{
    int id;
    string nama;
    string tipe1;
    string tipe2;
    bool shiny;
    int power;
};

const int MAX = 100;
Pokemon dataPokemon[MAX];
int jumlah = 0;

string tipeList[18] = 
{
    "Normal","Fire","Water","Grass","Electric","Ice","Fighting",
    "Poison","Ground","Flying","Psychic","Bug","Rock","Ghost",
    "Dragon","Dark","Steel","Fairy"
};

// Deklarasi Fungsi
bool isValidType(string tipe);
string toLowerCase(string teks);
void tambahPokemon();
void tampilkanPokemon();
void sortByPower();
void cariPokemon();
void filterByType();
void simpanFile();
void loadFile();
void menu();

// Main Program
int main()
{
    menu();
    return 0;
}

// Definisi Fungsi
string toLowerCase(string teks)
{
    for(int i = 0; i < teks.length(); i++)
    {
        if(teks[i] >= 'A' && teks[i] <= 'Z')
        {
            teks[i] = teks[i] + 32;
        }
    }
    return teks;
}

bool isValidType(string tipe)
{
    for(int i = 0; i < 18; i++)
    {
        if(tipe == tipeList[i])
        {
            return true;
        }
    }
    return false;
}

void tambahPokemon()
{
    if(jumlah >= MAX)
    {
        cout << "Data penuh!" << endl;
        return;
    }

    Pokemon p;
    char pilihan;

    cout << "ID Pokemon (0-9999): ";
    cin >> p.id;

    if(p.id < 0 || p.id > 9999)
    {
        cout << "ID tidak valid!" << endl;
        return;
    }

    cin.ignore();
    cout << "Nama Pokemon: ";
    getline(cin, p.nama);

    do
    {
        cout << "Tipe Utama: ";
        getline(cin, p.tipe1);
    }
    while(!isValidType(p.tipe1));

    cout << "Apakah dual type? (y/n): ";
    cin >> pilihan;
    cin.ignore();

    if(pilihan == 'y' || pilihan == 'Y')
    {
        do
        {
            cout << "Tipe Kedua: ";
            getline(cin, p.tipe2);
        }
        while(!isValidType(p.tipe2));
    }
    else
    {
        p.tipe2 = "-";
    }

    cout << "Apakah shiny? (y/n): ";
    cin >> pilihan;
    p.shiny = (pilihan == 'y' || pilihan == 'Y');

    cout << "Power: ";
    cin >> p.power;

    dataPokemon[jumlah] = p;
    jumlah++;

    cout << "Pokemon berhasil ditambahkan!" << endl;
}

void tampilkanPokemon()
{
    if(jumlah == 0)
    {
        cout << "Belum ada data Pokemon!" << endl;
        return;
    }

    for(int i = 0; i < jumlah; i++)
    {
        cout << "ID    : " << setw(4) << setfill('0') << dataPokemon[i].id << endl;
        cout << "Nama  : " << dataPokemon[i].nama << endl;
        cout << "Tipe  : " << dataPokemon[i].tipe1;
        if(dataPokemon[i].tipe2 != "-")
        {
            cout << " / " << dataPokemon[i].tipe2;
        }
        cout << endl;
        cout << "Status: " << (dataPokemon[i].shiny ? "Shiny" : "Normal") << endl;
        cout << "Power : " << dataPokemon[i].power << endl;
        cout << "----------------------" << endl;
    }
}

void sortByPower()
{
    if(jumlah == 0)
    {
        cout << "Belum ada data Pokemon!" << endl;
        return;
    }

    for(int i = 0; i < jumlah - 1; i++)
    {
        int minIdx = i;
        for(int j = i + 1; j < jumlah; j++)
        {
            if(dataPokemon[j].power < dataPokemon[minIdx].power)
            {
                minIdx = j;
            }
        }
        Pokemon temp = dataPokemon[i];
        dataPokemon[i] = dataPokemon[minIdx];
        dataPokemon[minIdx] = temp;
    }

    cout << "Data berhasil diurutkan berdasarkan power!" << endl;
}

void cariPokemon()
{
    if(jumlah == 0)
    {
        cout << "Belum ada data Pokemon!" << endl;
        return;
    }

    string namaCari;
    cin.ignore();
    cout << "Masukkan nama Pokemon: ";
    getline(cin, namaCari);

    string key = toLowerCase(namaCari);
    bool ditemukan = false;

    for(int i = 0; i < jumlah; i++)
    {
        if(toLowerCase(dataPokemon[i].nama) == key)
        {
            cout << "----------------------" << endl;
            cout << "ID    : " << setw(4) << setfill('0') << dataPokemon[i].id << endl;
            cout << "Nama  : " << dataPokemon[i].nama << endl;
            cout << "Tipe  : " << dataPokemon[i].tipe1;
            if(dataPokemon[i].tipe2 != "-")
            {
                cout << " / " << dataPokemon[i].tipe2;
            }
            cout << endl;
            cout << "Status: " << (dataPokemon[i].shiny ? "Shiny" : "Normal") << endl;
            cout << "Power : " << dataPokemon[i].power << endl;
            ditemukan = true;
        }
    }

    if(!ditemukan)
    {
        cout << "Pokemon tidak ditemukan!" << endl;
    }
}

void filterByType()
{
    if(jumlah == 0)
    {
        cout << "Belum ada data Pokemon!" << endl;
        return;
    }

    string input, tipe1, tipe2;
    bool dual = false;

    cin.ignore();
    cout << "Masukkan tipe (contoh: Fire atau Grass,Poison): ";
    getline(cin, input);

    int pos = input.find(',');
    if(pos != string::npos)
    {
        dual = true;
        tipe1 = input.substr(0, pos);
        tipe2 = input.substr(pos + 1);
    }
    else
    {
        tipe1 = input;
    }

    bool ada = false;
    for(int i = 0; i < jumlah; i++)
    {
        if(!dual)
        {
            if(dataPokemon[i].tipe1 == tipe1 || dataPokemon[i].tipe2 == tipe1)
            {
                cout << dataPokemon[i].nama << " (" << dataPokemon[i].power << ")" << endl;
                ada = true;
            }
        }
        else
        {
            if((dataPokemon[i].tipe1 == tipe1 && dataPokemon[i].tipe2 == tipe2) ||
               (dataPokemon[i].tipe1 == tipe2 && dataPokemon[i].tipe2 == tipe1))
            {
                cout << dataPokemon[i].nama << " (" << dataPokemon[i].power << ")" << endl;
                ada = true;
            }
        }
    }

    if(!ada)
    {
        cout << "Tidak ada Pokemon dengan tipe tersebut!" << endl;
    }
}

void simpanFile()
{
    ofstream file("pokemon.txt");
    for(int i = 0; i < jumlah; i++)
    {
        file << dataPokemon[i].id << "|"
             << dataPokemon[i].nama << "|"
             << dataPokemon[i].tipe1 << "|"
             << dataPokemon[i].tipe2 << "|"
             << dataPokemon[i].shiny << "|"
             << dataPokemon[i].power << endl;
    }
    file.close();
    cout << "Data berhasil disimpan ke file!" << endl;
}

void loadFile()
{
    ifstream file("pokemon.txt");
    jumlah = 0;

    while(file >> dataPokemon[jumlah].id)
    {
        file.ignore();
        getline(file, dataPokemon[jumlah].nama, '|');
        getline(file, dataPokemon[jumlah].tipe1, '|');
        getline(file, dataPokemon[jumlah].tipe2, '|');
        file >> dataPokemon[jumlah].shiny;
        file.ignore();
        file >> dataPokemon[jumlah].power;
        jumlah++;
    }
    file.close();
    cout << "Data berhasil dimuat dari file!" << endl;
}

void menu()
{
    int pilihan;
    do
    {
        cout << "\n===== POKEDEX CLI =====" << endl;
        cout << "1. Tambah Pokemon" << endl;
        cout << "2. Tampilkan Semua Pokemon" << endl;
        cout << "3. Urutkan Berdasarkan Power" << endl;
        cout << "4. Cari Pokemon" << endl;
        cout << "5. Filter Berdasarkan Tipe" << endl;
        cout << "6. Simpan ke File" << endl;
        cout << "7. Load dari File" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch(pilihan)
        {
            case 1: tambahPokemon(); break;
            case 2: tampilkanPokemon(); break;
            case 3: sortByPower(); break;
            case 4: cariPokemon(); break;
            case 5: filterByType(); break;
            case 6: simpanFile(); break;
            case 7: loadFile(); break;
        }
    }
    while(pilihan != 0);
}
