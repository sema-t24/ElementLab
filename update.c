#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>

//Behälter zum Speichern der Daten
typedef struct
{
    char *text;
    size_t laenge;
} Antwort;

size_t bekommen(
    char *daten,
    size_t size,
    size_t nmemb,
    void *userdata
)
{
    size_t gesamt = size * nmemb;
    printf("Erhaltene Datenmenge: %zu\n", gesamt);

    Antwort *antwortPtr = (Antwort *) userdata;

    char *neuerText = realloc(
        antwortPtr->text,
        antwortPtr->laenge + gesamt + 1
    );

    if (neuerText == NULL)
    {
        printf("Fehler beim Reservieren des Speichers!\n");
        return 0;
    }
    memcpy(
        neuerText + antwortPtr->laenge,
        daten,
        gesamt
    );

    antwortPtr->text = neuerText;
    antwortPtr->laenge = antwortPtr->laenge + gesamt;

    antwortPtr->text[antwortPtr->laenge] = "\0";

    return gesamt;
}

int main(void)
{
    CURL *anfrage;

    Antwort antwort;
    antwort.text = NULL;
    antwort.laenge = 0;

    anfrage = curl_easy_init();

    if (anfrage == NULL)
    {
        printf("Fehler: Anfrage konnte nicht initialisiert werden.\n");
        return 1;
    }

    curl_easy_setopt(
        anfrage,
        CURLOPT_URL,
        "https://pubchem.ncbi.nlm.nih.gov/rest/pug/periodictable/json"
    );

    curl_easy_setopt(
        anfrage,
        CURLOPT_WRITEFUNCTION,
        bekommen
    );

    curl_easy_setopt(
        anfrage,
        CURLOPT_WRITEDATA,
        &antwort
    );

    CURLcode ergebnis;

    ergebnis = curl_easy_perform(anfrage);

        if (ergebnis != CURLE_OK)
        {
            printf("Fehler %s\n",
            curl_easy_strerror(ergebnis));
        }

    curl_easy_cleanup(anfrage);

    free(antwort.text);

    return 0;
}