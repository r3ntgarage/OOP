#include <iostream>
#include <string>

using namespace std;

class Email {
    private:
        string adresaodesilatele;
        string adresaprijemce;
    
    public:
        Email(string adresaodesilatele, string adresaprijemce);
        void vstupEmail();
        void vystupEmail();
        
    };

Email::Email(string adresaodesilatele, string adresaprijemce) {
    this->adresaodesilatele = adresaodesilatele;
    this->adresaprijemce = adresaprijemce;
}

void Email::vstupEmail() {
    cout << "Zadejte adresu odesilatele: \n";
    getline(cin, this->adresaodesilatele);
    cout << "Zadejte adresu prijemce: \n";
    getline(cin, this->adresaprijemce);
}

void Email::vystupEmail() {
    cout << "\n--------------------------\nAdresa odesilatele: \n" << this->adresaodesilatele;
    cout << "\nAdresa prijemce: \n" << this->adresaprijemce;
}

class Osoba {
    private:
        string jmenoprijmeni;
        string datumnarozeni;
    
    public:
        Osoba(string jmenoprijmeni, string datumnarozeni);
        void vstupOsoba();
        void vystupOsoba();
        
    };

Osoba::Osoba(string jmenoprijmeni, string datumnarozeni) {
    this->jmenoprijmeni = jmenoprijmeni;
    this->datumnarozeni = datumnarozeni;
}

void Osoba::vstupOsoba() {
    cout << "Zadejte jmeno a prijmeni: \n";
    getline(cin, this->jmenoprijmeni);
    cout << "Zadejte datum narozeni: \n";
    getline(cin, this->datumnarozeni);
}

void Osoba::vystupOsoba() {
    cout << "\n--------------------------\nJmeno a prijmeni osoby: \n" << this->jmenoprijmeni;
    cout << "\nDatum narozeni osoby: \n" << this->datumnarozeni;
}

class Dokument {
    private:
        string nazevdokumentu;
        string pocetstran;
    
    public:
        Dokument(string nazevdokumentu, string pocetstran);
        void vstupDokument();
        void vystupDokument();
        
    };

Dokument::Dokument(string nazevdokumentu, string pocetstran) {
    this->nazevdokumentu = nazevdokumentu;
    this->pocetstran = pocetstran;
}

void Dokument::vstupDokument() {
    cout << "Zadejte nazev dokumentu: \n";
    getline(cin, this->nazevdokumentu);
    cout << "Zadejte pocet stran: \n";
    getline(cin, this->pocetstran);
}

void Dokument::vystupDokument() {
    cout << "\n--------------------------\nNazev dokumentu: \n" << this->nazevdokumentu;
    cout << "\nPocet stran dokumentu: \n" << this->pocetstran;
}

int main() {

    Email odeslat("", "");
    odeslat.vstupEmail();

    Osoba clovek("", "");
    clovek.vstupOsoba();
    
    Dokument dokument("", "");
    dokument.vstupDokument();

    odeslat.vystupEmail();
    clovek.vystupOsoba();
    dokument.vystupDokument();

    return 0;
}