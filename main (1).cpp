#include <iostream>
using namespace std;

class Postac {
protected:
    string imie;
    int zdrowie;

public:
    Postac(string _imie, int _zdrowie) : imie(_imie), zdrowie(_zdrowie) {}
    virtual void zaatakuj(Postac& p) = 0;
    virtual void przyjmijObrazenia(int obrazenia) = 0;
    virtual void info() = 0;
    int punktyZdrowia() {
        return zdrowie;
    }
};

class Mag : public Postac {
public:
    Mag(string _imie, int _zdrowie) : Postac(_imie, _zdrowie) {}

    void zaatakuj(Postac& p) override {
        cout << imie << " rzuca Fireball!" << endl;
        p.przyjmijObrazenia(40);
    }

    void przyjmijObrazenia(int obrazenia) override {
        zdrowie -= obrazenia;
        cout << imie << " otrzymuje " << obrazenia << " obrażeń." << endl;
        if (zdrowie <= 0) {
            cout << imie << " zostaje pokonany." << endl;
        }
    }

    void info() override {
        cout << "Mag: " << imie << ", Zdrowie: " << zdrowie << endl;
    }
};

class Rycerz : public Postac {
public:
    Rycerz(string _imie, int _zdrowie) : Postac(_imie, _zdrowie) {}

    void zaatakuj(Postac& p) override {
        cout << imie << " atakuje mieczem!" << endl;
        p.przyjmijObrazenia(30); 
    }

    void przyjmijObrazenia(int obrazenia) override {
        int rzeczywisteObrazenia = obrazenia - 10;
        if (rzeczywisteObrazenia < 0) rzeczywisteObrazenia = 0;
        zdrowie -= rzeczywisteObrazenia;
        cout << imie << " otrzymuje " << rzeczywisteObrazenia << " obrażeń." << endl;
        if (zdrowie <= 0) {
            cout << imie << " zostaje pokonany." << endl;
        }
    }

    void info() override {
        cout << "Rycerz: " << imie << ", Zdrowie: " << zdrowie << endl;
    }
};

class Lucznik : public Postac {
public:
    Lucznik(string _imie, int _zdrowie) : Postac(_imie, _zdrowie) {}

    void zaatakuj(Postac& p) override {
        cout << imie << " strzela z łuku!" << endl;
        p.przyjmijObrazenia(35); 
    }

    void przyjmijObrazenia(int obrazenia) override {
        zdrowie -= obrazenia;
        cout << imie << " otrzymuje " << obrazenia << " obrażeń." << endl;
        if (zdrowie <= 0) {
            cout << imie << " zostaje pokonany." << endl;
        }
    }

    void info() override {
        cout << "Łucznik: " << imie << ", Zdrowie: " << zdrowie << endl;
    }
};

int main() {
    Mag* mag = new Mag("Gandalf", 100);   
    Rycerz* rycerz = new Rycerz("Lancelot", 150); 

    mag->info();
    rycerz->info();

    mag->zaatakuj(*rycerz);  
    rycerz->info();

    rycerz->zaatakuj(*mag);  
    mag->info();

    delete mag;
    delete rycerz;

    return 0;
}
