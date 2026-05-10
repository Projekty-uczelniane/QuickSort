# Analiza Z�o�ono�ci Obliczeniowej Algorytmu QuickSort

## Czym jest ten projekt?
Ten projekt to program w j�zyku C++, kt�rego celem jest zbadanie wydajno�ci algorytmu sortowania QuickSort dla r�nych wariant�w wyboru pivota. Program sprawdza, jak wyb�r
wp�ywa na czas wykonania operacji oraz ich liczb� dla r�nych danych.


###  Rodzaje wyboru pivota:
1. **QuickSort Right:** Pivotem jest zawsze skrajnie prawy element tablicy.
2. **QuickSort Random:** Pivot wybierany jest w pe�ni losowo.
3. **QuickSort Mediana:** Pivot to mediana z trzech element�w (lewego,�rodkowego i prawego)

## Jakie s� wnioski z analizy?(Oczekiwane awarie algorytmu)
Projekt ma charakter badawczy i celowo **nie zawiera** sztucznych blokad przed przepe�nieniem stosu.
Podczas testowania du�ych tablic, program zgodnie z przewidywaniami ulegnie awarii w dw�ch przypadkach:
* **QuickSort Right + Posortowana tablica**
* **Dowolny wariant + Ogromna liczba duplikat�w**

## Co umie ten program?
* **R�norodne zestawy danych:** Mo�esz przetestowa� algorytm na tablicach wygenerowanych losowo, posortowanych oraz takich, kt�re zawieraj� du�� liczb� duplikat�w.
* **Skalowalno�� i automatyzacja:** Program automatycznie przeprowadza testy dla tablic o rosn�cych rozmiarach od 10 000 do 250 000 element�w.
* **Precyzyjne pomiary czasu:** Program wykorzystuje bibliotek�`<chrono>` do dok�adnego mierzenia czasu dzia�ania.
* **Zliczanie operacji:** �ledzenie w czasie rzeczywistym ca�kowitej liczby por�wna� oraz zamian wewn�trz tablicy (wykorzystanie wska�nik�w i referencji, kod bez zmiennych globalnych).
* **Interaktywne, zagnie�d�one Menu:** Wygodne menu konsolowe, kt�re pozwala na wielokrotne testowanie r�nych wariant�w bez konieczno�ci uruchamiania programu za ka�dym razem.
* **Automatyczny eksport danych:** Program zbiera wszystkich udane wyniki w pliku bazodanowym `.csv` (`dane1.csv`), kt�ry jest idealny np. do tworzenia wykres�w na podstawie test�w.

## Jak to dzia�a?
* **J�zyk:** C++ (Standard C++11  lub nowsza)
* **Biblioteki:** *`<iostream>`,`<cstdlib>`,`<ctime>`- podstawowa logika, wej�cie/wyj�cie oraz losowanie danych
*`<fstream>`- zapisywanie wynik�w test�w do pliku bazodanowego `.csv`
*`<chrono>`- precyzyjny pomiar czasu wykonania algorytm�w
*`<windows.h>`- funkcje op�niaj�ce dzia�anie i czyszcz�ce ekran
*`<clocale>`- obs�uga polskich znak�w

## Jak uruchomi� program?
1. Pobierz plik źródłowy projektu `QuickSort.cpp`.
2. Skompiluj kod w dowolnym �rodowisku IDE (np.Code::Blocks,Visual Studio)
