#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <cjson/cJSON.h>


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
                                    printf("Column could not be found.\n");
                                }
                                else
                                {
                                    cJSON *elementOutput = cJSON_CreateObject();
                                    cJSON *elementArray = cJSON_CreateArray();

                                    if (elementOutput == NULL || elementArray == NULL)
                                    {
                                        printf("Error output or array could not be created.\n");
                                    }
                                    else
                                    {
                                        cJSON_bool elements = cJSON_AddItemToObject(
                                            elementOutput, 
                                            "elements",
                                            elementArray
                                        );

                                        if (elements == 0)
                                        {
                                            printf("Error could not add array to object.\n");

                                            cJSON_Delete(elementArray);
                                            cJSON_Delete(elementOutput);
                                        }
                                        else
                                        {

                                            int rowSize = cJSON_GetArraySize(row);

                                            for (int i = 0; i < rowSize; i++)
                                            {
                                                cJSON *list = cJSON_CreateObject();

                                                if (list == NULL)
                                                {
                                                    printf("Error list could not be created.\n");
                                                }
                                                else
                                                {
                                                    printf("%d\n", i);

                                                    cJSON *elementRow = cJSON_GetArrayItem(row, i);

                                                    if (elementRow == NULL)
                                                    {
                                                        printf("Could not find row %d\n", i);
                                                    }
                                                    else 
                                                    {
                                                        cJSON *cell = cJSON_GetObjectItem(elementRow, "Cell");

                                                        if (cell == NULL)
                                                        {
                                                            printf("Cell could not be found\n");
                                                        }
                                                        else
                                                        {
                                                            int cellSize = cJSON_GetArraySize(cell);

                                                            for (int j = 0; j < cellSize; j++)
                                                            {
                                                                cJSON *columni = cJSON_GetArrayItem(column, j);

                                                                cJSON *celli = cJSON_GetArrayItem(cell, j);

                                                                if (columni == NULL || celli == NULL)
                                                                {
                                                                    printf("Property %d could not be found\n", j);
                                                                }
                                                                else
                                                                {
                                                                    const char *propertyName = cJSON_GetStringValue(columni);

                                                                    const char *value = cJSON_GetStringValue(celli);

                                                                    if (propertyName == NULL || value == NULL)
                                                                    {
                                                                        printf("NULL\n");
                                                                    }
                                                                    else
                                                                    {
                                                                        printf("%s: %s\n", propertyName, value);

                                                                        cJSON *elementProperties = cJSON_AddStringToObject(
                                                                            list,
                                                                            propertyName,
                                                                            value
                                                                        );

                                                                        if (elementProperties == NULL)
                                                                        {
                                                                            printf("Error properties could not besaved in the list.\n");
                                                                        }
                                                                        
                                                                    }
                                                                    
                                                                }
                                                                
                                                            }
                                                            cJSON_bool elementReady = cJSON_AddItemToArray(
                                                                                elementArray,
                                                                                list
                                                                            );

                                                                            if (elementReady == 0)
                                                                            {
                                                                                printf("Error list could not be saved in array.\n");

                                                                                cJSON_Delete(list);
                                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            char *elementsList = cJSON_Print(elementOutput);

                                            if (elementsList == NULL)
                                            {
                                                printf("Error could not convert JSON to text.\n");
                                            }
                                            else
                                            {
                                                FILE *elementsFile = fopen("elements.json", "w");

                                                if (elementsFile == NULL)
                                                {
                                                    printf("Error text file could not be created.\n");
                                                }
                                                else
                                                {
                                                    int crown = fputs(elementsList,  elementsFile);

                                                    if (crown == EOF)
                                                    {
                                                        printf("Error elements file could not be written.\n");
                                                    }

                                                    int result = fclose(elementsFile);

                                                    if (result == EOF)
                                                    {
                                                        printf("Error could not close elemnts file.\n");
                                                    }
                                                }

                                                cJSON_free(elementsList);
                                            }

                                            cJSON_Delete(elementOutput);
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
