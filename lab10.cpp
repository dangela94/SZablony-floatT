// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// linie znajdujace sie pod komentarzem: "to nie moze sie skompilowac"
// musza generowac blad kompilacji

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Lab10. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Pliku lab10.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). Powinien działać dla dowolnej
// liczby przekształceń.

// Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
// ani żadnych innych materiałów (w tym własnych wcześniej
// przygotowanych plików)

// Kody źródłowe muszą znajdować się w katalogu ~/oop/lab_LABNR. Prawa
// do tego katalogu muszą być równe 700 (tylko dostęp dla
// właściciela).

// Skonczone zadanie nalezy wyslac uruchamiajac skrypt 
// /home/dokt/dog/WyslijZadanie.sh
// bedac w katalogu zawierajacym rozwiazanie czyli ~/oop/lab_10

#include"lab10.h"
#include<iostream>

int main ()
{
  using namespace std;
  
  Float_t<METER> distance (10);
  Float_t<SECOND> time (5);
  Float_t<METER> distance2 (20);
  cout<<"distance: "<<distance.Get()<<" distance2: "<<distance2.Get()<<" time: "<<time.Get()<<endl;
  Float_t<METER-SECOND> speed = distance/time;
  cout<<"speed : "<<speed.Get()<<endl;
  speed = (distance + distance2)/time;
  cout<<"speed2 : "<<speed.Get()<<endl;
  Float_t<METER-SECOND-SECOND> acceleration = distance/time/time;
  cout<<"acceleration : "<<acceleration.Get()<<endl;
  Float_t<METER-SECOND-SECOND> acceleration2 = (distance + distance2)/time/time;
  Float_t<METER-SECOND-SECOND> accSum = acceleration+acceleration2;
  cout<<"accSum : "<<accSum.Get()<<endl;

  Array_t summary (20);
  summary.Add(&distance);
  summary.Add(&time);
  summary.Add(&distance2);
  summary.Add(&speed);
  summary.Add(&acceleration);
  summary.Add(&acceleration2);
  summary.Add(&accSum);
  cout<<"----- SUMMARY -----\n";
  summary.PrintAll();
  
  // // to nie moze sie skompilowac
  //  distance + time;
  //  speed + distance;
  //  speed = distance*time;
  //  accSum = acceleration*acceleration2;
  //  acceleration+speed;
}

/*
distance: 10 distance2: 20 time: 5
speed : 2
speed2 : 6
acceleration : 0.4
accSum : 1.6
----- SUMMARY -----
10
5
20
6
0.4
1.2
1.6
*/
