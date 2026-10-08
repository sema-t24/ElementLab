#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <cjson/cJSON.h>

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

    antwortPtr->text[antwortPtr->laenge] = '\0';

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

        long statuscode = 0;
        CURLcode http = curl_easy_getinfo(anfrage, CURLINFO_RESPONSE_CODE, &statuscode);

        if (ergebnis != CURLE_OK)
        {
            printf("Fehler %s\n",
            curl_easy_strerror(ergebnis));
        }
        else
        {
            if (http != CURLE_OK)
            {
                printf("Fehler statuscode konnte nicht abgefragt werden!\n");
            }
            else
            {
                printf("%ld\n", statuscode);
                    if (statuscode != 200)
                    {
                    printf("Statuscode:%ld\n", statuscode);
                    }
                    else
                    {
                    cJSON *root = cJSON_Parse(antwort.text);

                    if (root == NULL)
                    {
                        printf("Fehler beim Lesen der JSON");
                    }
                    else
                    {
                        printf("JSON erfolgreich gelesen!\n");

                        cJSON *table = cJSON_GetObjectItem(root, "Table");

                        if (table == NULL)
                        {
                            printf("Fehler, table wurde nicht gefunden!\n");
                        }
                        else
                        {
                            cJSON *columns = cJSON_GetObjectItem(table, "Columns");
                            cJSON *row = cJSON_GetObjectItem(table, "Row");

                            if (columns == NULL || row == NULL)
                            {
                                printf("Fehler, columns oder row wurde nicht gefunden!\n");
                            }
                            else
                            {
                                printf("Columns und row wurde gefunden.\n");

                                cJSON *column = cJSON_GetObjectItem(columns, "Column");

                                if (column == NULL)
                                {
                                    printf("Fehler, column wurde nicht gefunden!.\n");
                                }
                                else
                                {
                                    printf("Column wurde gefunden.\n");

                                    cJSON *atomicNumber = cJSON_GetArrayItem(column, 0);

                                    if (atomicNumber == NULL)
                                    {
                                        printf("Fehler Atomic Number konnte nicht gelesen werden!\n");
                                    }
                                    else
                                    {
                                        const char *AtomicNumber = cJSON_GetStringValue(atomicNumber);

                                        if (AtomicNumber == NULL)
                                        {
                                            printf("NULL\n");
                                        }
                                        else
                                        {
                                            printf("%s\n", AtomicNumber);
                                        }
                                    }

                                }
                            }
                        }
                    }
                    cJSON_Delete(root);
                }
                    
                
            }

            
        }

    curl_easy_cleanup(anfrage);

    free(antwort.text);

    return 0;
}

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
