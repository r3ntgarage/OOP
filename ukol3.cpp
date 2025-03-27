#include <iostream>
#include <vector>
using namespace std;

class KeyValue {
public:
    int key;
    string value;
    KeyValue(int k, string v) : key(k), value(v) {}
};

class KeyValues {
private:
    vector<KeyValue*> items;
public:
    void AddObject(int k, string v) {
        items.push_back(new KeyValue(k, v));
    }
    
    KeyValue* RemoveObject(int k) {
        for (vector<KeyValue*>::iterator it = items.begin(); it != items.end(); ++it) {
            if ((*it)->key == k) {
                KeyValue* removed = *it;
                items.erase(it);
                return removed;
            }
        }
        return nullptr;
    }
    ~KeyValues() {
        for (size_t i = 0; i < items.size(); i++) {
            delete items[i];
        }
    }
};

class Osoba {
public:
    string jmeno;
    string adresa;
    Osoba(string j, string a) : jmeno(j), adresa(a) {}
};

class PolozkaFaktury {
public:
    string nazev;
    double cena;
    PolozkaFaktury(string n, double c) : nazev(n), cena(c) {}
};

class Faktura {
private:
    int cislo;
    Osoba* osoba;
    vector<PolozkaFaktury*> polozky;
public:
    Faktura(int c, Osoba* o) : cislo(c), osoba(o) {}
    
    void PridatPolozku(string nazev, double cena) {
        polozky.push_back(new PolozkaFaktury(nazev, cena));
    }
    
    double CelkovaCena() {
        double suma = 0;
        for (size_t i = 0; i < polozky.size(); i++) {
            suma += polozky[i]->cena;
        }
        return suma;
    }
    
    void VytiskniFakturu() {
        cout << "\n----------------------------------------\n";
        cout << "Zakaznik: " << osoba->jmeno << "\n";
        cout << "Adresa: " << osoba->adresa << "\n";
        cout << "----------------------------------------\n";
        cout << "Polozky faktury:\n";
        for (size_t i = 0; i < polozky.size(); i++) {
            cout << i + 1 << ". " << polozky[i]->nazev << " - " << polozky[i]->cena << " Kc\n";
        }
        cout << "----------------------------------------\n";
        cout << "Celkem k uhrade: " << CelkovaCena() << " Kc\n";
        cout << "----------------------------------------\n";
    }
    
    ~Faktura() {
        for (size_t i = 0; i < polozky.size(); i++) {
            delete polozky[i];
        }
        delete osoba;
    }
};

int main() {
    KeyValues kv;
    int key;
    string value;
    cout << "Zadejte klic a hodnotu: ";
    cin >> key >> value;
    kv.AddObject(key, value);
    
    cout << "Zadejte klic pro odstraneni: ";
    cin >> key;
    KeyValue* removed = kv.RemoveObject(key);
    if (removed) {
        cout << "Odebrán: " << removed->key << " - " << removed->value << endl;
        delete removed;
    }
    
    string jmeno, adresa;
    cout << "Zadejte jmeno a adresu osoby: ";
    cin.ignore();
    getline(cin, jmeno);
    getline(cin, adresa);
    Osoba* osoba = new Osoba(jmeno, adresa);
    
    Faktura faktura(1001, osoba);
    int pocetPolozek;
    cout << "Zadejte pocet polozek faktury: ";
    cin >> pocetPolozek;
    
    for (int i = 0; i < pocetPolozek; i++) {
        string nazev;
        double cena;
        cout << "Zadejte nazev polozky a cenu: ";
        cin.ignore();
        getline(cin, nazev);
        cin >> cena;
        faktura.PridatPolozku(nazev, cena);
    }
    
    faktura.VytiskniFakturu();
    
    return 0;
}
