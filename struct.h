#ifndef STRUCT_H
#define STRUCT_H
#include <iostream>
#include <string.h>

using namespace std;

class Serie {
  //private: selber Effekt wie Kommentiert

  // Eigenschaften, Attribute, Klassenvariablen
  char name[20];
  char erscheinungsdatum[10];
  char genre[20];
  int folgenAnzahl;
  int aktuelleFolge;

public:
  Serie()
  {
    setzeSerie();
    zeigeSerie();
    setzeAktuelleFolge();
  }

  Serie( char name[20], char erscheinungsdatum[10], char genre[20], int folgenAnzahl)
  {
    aktuelleFolge = 0;
    strcpy(this->name, name );
    strcpy(this->genre, genre);
    strcpy(this->erscheinungsdatum, erscheinungsdatum);
    setzeFolgenAnzahl(folgenAnzahl);

    zeigeSerie();
    setzeAktuelleFolge();
  }
  // get-Methoden
  char gibName()
  {
    return *name;
  }

  char gibErscheinungsdatum()
  {
    return *erscheinungsdatum;
  }

  char gibGenre()
  {
    return *genre;
  }

  int gibFolgenAnzahl()
  {
    return folgenAnzahl;
  }


  // set-Methode
  void setzeSerie()
  {
    setzeNamen("Game of Thrones");
    setzeGenre("Fantasy");
    setzeErscheinungsdatum("23.3.2002");
    setzeFolgenAnzahl(50);
    setzeAktuelleFolge(0);
  }
  void setzeNamen ( char name[20])
  {
    strcpy(this->name,name);
  }

  void setzeErscheinungsdatum ( char erscheinungsdatum[10])
  {
    strcpy(this->erscheinungsdatum,erscheinungsdatum);
  }

  void setzeGenre ( char genre[20])
  {
    strcpy(this->genre, genre);
  }

  void setzeFolgenAnzahl( int folgenAnzahl )
  {
    if (folgenAnzahl >= 0) this->folgenAnzahl = folgenAnzahl;
  }

  void setzeAktuelleFolge(int folge)
  {
    this->aktuelleFolge = folge;
  }

  void setzeAktuelleFolge()
  {
    int folgenGucken;
    cout << "Wie viele Folgen soll ich schauen? ";

    do{
        cin >> folgenGucken;
      } while ( folgenAnzahl < aktuelleFolge+folgenGucken);
    aktuelleFolge += folgenGucken;

    cout << endl << "Jetzt bin ich schon bei Folge " << aktuelleFolge << endl << endl;
    system("PAUSE");
  }

  void zeigeSerie()
  {
    //system("cls");
    cout << "-------------------------------------------------" << endl;
    cout << "Mein Lieblingsgenre ist " << genre;
    cout << ", welches in der Serie " << name << " mehr als genug vorkommt."<< endl;
    cout << "Sie hat " << folgenAnzahl;
    cout << " Folgen und gerade bin ich bei Folge " << aktuelleFolge << endl;
    cout << "-------------------------------------------------" << endl;
  }

};

#endif // STRUCT_H
