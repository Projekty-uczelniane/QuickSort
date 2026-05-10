# Analiza Złożoności Obliczeniowej Algorytmu QuickSort

## Czym jest ten projekt?
Ten projekt to program w języku C++, którego celem jest zbadanie wydajności algorytmu sortowania QuickSort dla rónych wariantów wyboru pivota. 
Program sprawdza, jak wybór wpływa na czas wykonania operacji oraz ich liczbę dla rónych danych.


###  Rodzaje wyboru pivota:
1. **QuickSort Right:** Pivotem jest zawsze skrajnie prawy element tablicy.
2. **QuickSort Random:** Pivot wybierany jest losowo.
3. **QuickSort Mediana:** Pivot to mediana z trzech elementów (lewego,środkowego i prawego)

## Jakie sś wnioski z analizy? (Oczekiwane awarie algorytmu)
Projekt ma charakter badawczy i celowo **nie zawiera** blokad przed przepełnieniem stosu.
Podczas testowania dużych tablic, program zgodnie z przewidywaniami ulegnie awarii w dwóch przypadkach:
* **QuickSort Right + Posortowana tablica**
* **Dowolny wariant + Ogromna liczba duplikatów**

## Co umie ten program?
* **Różnorodne zestawy danych:** Możesz przetestować algorytm na tablicach wygenerowanych losowo, posortowanych oraz takich, które zawierają dużą liczbę duplikatów.
* **Skalowalność i automatyzacja:** Program automatycznie przeprowadza testy dla tablic o rosnących rozmiarach od 10 000 do 250 000 elementów.
* **Precyzyjne pomiary czasu:** Program wykorzystuje bibliotekę`<chrono>` do dokładnego mierzenia czasu działania.
* **Zliczanie operacji:** Śledzenie w czasie rzeczywistym całkowitej liczby porównań oraz zamian wewnętrz tablicy (wykorzystanie wskaźników i referencji, kod
bez zmiennych globalnych).
* **Interaktywne, zagnieżdżone Menu:** Wygodne menu konsolowe, które pozwala na wielokrotne testowanie rónych wariantów bez konieczności uruchamiania programu
za każdym razem.
* **Automatyczny eksport danych:** Program zbiera wszystkich udane wyniki w pliku bazodanowym `.csv` (`dane1.csv`), który jest idealny np. do tworzenia wykresów
na podstawie testów.

## Jak to działa?
* **Język:** C++ (Standard C++11  lub nowsza)
* **Biblioteki:** *`<iostream>`,`<cstdlib>`,`<ctime>`- podstawowa logika, wejście/wyjście oraz losowanie danych
*  `<fstream>`- zapisywanie wyników testów do pliku bazodanowego `.csv`
*  `<chrono>`- precyzyjny pomiar czasu wykonania algorytmów
*  `<windows.h>`- funkcje opóniające działanie i czyszczące ekran
*  `<clocale>`- obsługa polskich znaków

## Jak uruchomić program?
1. Pobierz plik źródłowy projektu `QuickSort.cpp`.
2. Skompiluj kod w dowolnym środowisku IDE (np.Code::Blocks,Visual Studio)
