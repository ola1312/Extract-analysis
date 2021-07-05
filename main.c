#include <stdio.h>
#include <string.h>

int countletters(const char *napis)
{
  int letter_counter = 0;
  if (napis[0]<48 || napis [0]>57)
    for (int i=0; i<strlen(napis); i++)
      if((napis[i]>96 && napis[i]<123) || (napis[i]>64 && napis[i]<91))
        letter_counter++;
  return letter_counter;
}

int main(void)
{
  const int LENGTH = 50;
  char tekst[LENGTH];
  int ilosc_slow = 0, dlugosc = 0, liczba_now = 0, liczba_harry = 0, liczba_v = 0, ilosc_liter = 0;
  double srednia_dlugosc;

  while(!feof (stdin))
  {
    scanf("%s", tekst);

    ilosc_liter = countletters(tekst);

    if(ilosc_liter > 0)
    {
      ilosc_slow++;
      dlugosc = dlugosc + ilosc_liter;
      if (strchr (tekst, ' '))
        ilosc_slow++;
      
      if (strchr (tekst, 'v') || strchr(tekst, 'V'))
        liczba_v++;

      if (strstr (tekst, "Harry") || strstr(tekst, "HARRY"))
        liczba_harry++;

      if (strstr (tekst, "now") || strstr(tekst, "Now"))
        liczba_now++;
    }
  }

  printf("Całkowita liczba słów: %d\n", ilosc_slow);
  printf("Suma długości słów: %d\n", dlugosc);
  printf("Średnia długość słowa: %lf\n", srednia_dlugosc);
  printf("Liczba wystąpień słowa 'now': %d\n", liczba_now);
  printf("Liczba wystąpień słowa 'Harry': %d\n", liczba_harry);
  printf("Liczba słów zawierających literę 'v': %d", liczba_v);

  return 0;
}