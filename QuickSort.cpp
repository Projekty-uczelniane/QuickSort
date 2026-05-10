#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono>
#include <clocale>
#include <windows.h>

using namespace std;
using namespace std::chrono;

int partition(int* tab,int l,int r,long long& swapy, long long& porownania)
{
    int pivot=tab[r];
    int tmp=(l-1);

    for(int i=l; i<=r-1; i++)
    {
        porownania++;

        if(tab[i]<=pivot)
        {
            tmp++;
            int tmp1=tab[tmp];
            tab[tmp]=tab[i];
            tab[i]=tmp1;
            swapy++;
        }
    }

    int tmp2=tab[tmp+1];
    tab[tmp+1]=tab[r];
    tab[r]=tmp2;
    swapy++;

    return (tmp+1);
}

int pivotRandom(int l,int r)
{
    int pivot=l+rand()%(r-l+1);
    return pivot;
}

int mediana(int*tab,int l,int r,int mid,long long& porownania)
{
    porownania+=2;

    if((tab[l]<tab[r] && tab[l]>tab[mid])||tab[l]>tab[r]&&tab[l]<tab[mid])
    {
        return l;
    }
    else if((tab[r]<tab[l] && tab[r]>tab[mid])||tab[r]>tab[l]&&tab[r]<tab[mid])
    {
        return r;
    }
    else
    {
        return mid;
    }
}

void QuickSortMediana(int* tab, int l,int r,long long& swapy, long long& porownania)
{
    if(l<r)
    {
        porownania++;
        int mid=l+(r-l)/2;
        int pivot = mediana(tab,l,r,mid,porownania);

        int tmp1=tab[pivot];
        tab[pivot]=tab[r];
        tab[r]=tmp1;
        swapy++;

        pivot=partition(tab,l,r,swapy,porownania);
        QuickSortMediana(tab,l,pivot-1,swapy,porownania);
        QuickSortMediana(tab,pivot+1,r,swapy,porownania);

    }
}

void QuickSortRandom(int* tab, int l,int r,long long& swapy, long long& porownania)
{
    if(l<r)
    {
        porownania++;
        int pivot=pivotRandom(l,r);

        int tmp1=tab[pivot];
        tab[pivot]=tab[r];
        tab[r]=tmp1;
        swapy++;

        pivot=partition(tab,l,r,swapy,porownania);
        QuickSortRandom(tab,l,pivot-1,swapy,porownania);
        QuickSortRandom(tab,pivot+1,r,swapy,porownania);
    }

}

void QuickSortRight(int* tab, int l,int r,long long& swapy, long long& porownania)
{
    if(l<r)
    {
        porownania++;
        int pivot=partition(tab,l,r,swapy,porownania);

        QuickSortRight(tab,l,pivot-1,swapy,porownania);
        QuickSortRight(tab,pivot+1,r,swapy,porownania);
    }
}

int main()
{
    setlocale(LC_CTYPE,"Polish");

    std::string Quicksort = "dane1.csv";
    std::ofstream Plik(Quicksort,std::ios::app);

    int wybor;
    int wybor1;

    srand(time(NULL));

    long long swapy = 0;
    long long porownania = 0;

    Plik<<"Rozmiar tablicy;Liczba porownan;Liczba zmian;Czas dzialania"<<std::endl;

    do
    {
        system("cls");
        cout<<"-------------------------------------------Wybór QuickSorta-------------------------------------------"<<endl;
        cout<<"1-QuickSortRight"<<endl;
        cout<<"2-QuickSortRandom"<<endl;
        cout<<"3-QuickSortMediana"<<endl;
        cout<<"0-Koniec programu"<<endl;
        cout<<"Wybór:"<<endl;

        while(!(cin>>wybor))
        {
            cout<<"Błędne dane.Spróbuj jeszcze raz";
            cin.clear();
            cin.ignore(1000,'\n');
        }

        if(wybor==0)
        {
            break;
        }

        if (wybor<1 || wybor>3)
        {
            cout<<"\nNieznana opcja.Spróbuj ponownie."<<endl;
            Sleep(1500);
            continue;
        }

        switch(wybor)
        {

        case 1:
        {
            Plik<<"Quicksort right"<<std::endl;
            break;
        }

        case 2:
        {
            Plik<<"Quicksort Random"<<std::endl;
            break;
        }

        case 3:
        {
            Plik<<"Quicksort Mediana"<<std::endl;
            break;
        }

        }
        do
        {
            system("cls");
            cout<<"-------------------------------------------Wybór wypełnienia tablicy-------------------------------------------"<<endl;
            cout<<"1-Losowa tablica"<<endl;
            cout<<"2-Posortowana tablica"<<endl;
            cout<<"3-Duża liczba duplikatów w tablicy"<<endl;
            cout<<"0-Zmiana rodzaju QuickSorta"<<endl;
            cout<<"Wybór:"<<endl;

            while(!(cin>>wybor1) || wybor1<0 || wybor1>3)
            {
                cout<<"Błędne dane.Spróbuj jeszcze raz";
                cin.clear();
                cin.ignore(1000,'\n');
            }

            if(wybor1==0)
            {
                break;
            }

            switch(wybor1)
            {
            case 1:
            {
                Plik<<"Losowa tablica"<<std::endl;
                break;
            }

            case 2:
            {
                Plik<<"Posortowana tablica"<<std::endl;
                break;
            }

            case 3:
            {
                Plik<<"Duża liczba duplikatów w tablicy"<<std::endl;
                break;
            }

            }

            for(int n=10000; n<=250000; n+=10000)
            {
                swapy=0;
                porownania=0;
                int*tab = new int[n];

                for(int i=0; i<n; i++)
                {
                    if(wybor1==1)
                    {
                        tab[i]=rand();
                    }
                    else if(wybor1==2)
                    {
                        tab[i]=i;
                    }
                    else if(wybor1==3)
                    {
                        tab[i]=rand()%6;
                    }
                }

                auto start = steady_clock::now();

                if(wybor==1)
                {
                    QuickSortRight(tab,0,n-1,swapy,porownania);
                }
                else if(wybor==2)
                {
                    QuickSortRandom(tab,0,n-1,swapy,porownania);
                }
                else if(wybor==3)
                {
                    QuickSortMediana(tab,0,n-1,swapy,porownania);
                }

                auto end =steady_clock::now();
                auto elapsed_us =duration_cast<microseconds>(end-start).count();
                double elapsed_ms = elapsed_us / 1000.0;
                Plik<<n<<";"<<porownania<<";"<<swapy<<";"<<elapsed_ms<<std::endl;
                delete[] tab;
            }

            cout<<"Testy zakończone. Wyniki można znaleźć w dane1.csv"<<endl;
            Sleep(2500);
        }
        while(wybor1!=0);
    }
    while(wybor!=0);

    Plik.close();

    cout<<"Koniec programu..."<<endl;


    return 0;
}
