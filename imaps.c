#include <stdio.h>
#include <string.h>
#include "curl/curl.h"

int main(int argc, char* argv[])
{
    if (argc != 4) {
        printf("usage: ./imaps <username> <password> <emailnumber>\n");
        return 0;
    }
    char * username = argv[1];
    char * password = argv[2];
    char * count = argv[3];
//    printf("%s %s %s\n",username, password, count);
    char url[80] = "imaps://imap.gmail.com/INBOX/;UID=\0";
    strcat(url, count);
//    printf("%s\n",url);

    
    CURL * curl;
    CURLcode res = CURLE_OK;
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_USERNAME, username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password);

        curl_easy_setopt(curl, CURLOPT_URL, url); 
  //      curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            printf("error\n");
        }
        curl_easy_cleanup(curl);
    }
    return (int)res;
}
