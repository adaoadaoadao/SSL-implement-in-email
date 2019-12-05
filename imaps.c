#include <stdio.h>
#include <string.h>
#include "curl/curl.h"

int main(int argc, char* argv[])
{
    if (argc != 5) {
        printf("usage: ./imaps <username> <password> <operation> <operation-detail>\n");
        // printf("usage: ./imaps <username> <password>\n");
        // operation 0 for get email with UID
        return 0;
    }
    char * username = argv[1];
    char * password = argv[2];
    char * operation = argv[3];
    char * detail = argv[4];
    char head[160] = "imaps://imap.gmail.com/INBOX";
    char url[80] = "imaps://imap.gmail.com/INBOX";
//    printf("%s %s %s\n",username, password, count);
    if (!strcmp(operation, "0")) {
        strcat(head, "/;UID=");
        strcat(head, detail);
        strcat(head, "/;SECTION=HEADER.FIELDS%20(FROM%20To%20DATE%20SUBJECT)\0");
        strcat(url, "/;UID=");
        strcat(url, detail);
        strcat(url, "/;SECTION=TEXT\0");
    } else {
        int i = 0;
        while (detail[i]) {
            if (detail[i] == '_') 
                detail[i] = ' ';
            i++;
        }
    }

    
    CURL * curl;
    CURLcode res = CURLE_OK;
    
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_USERNAME, username);
        curl_easy_setopt(curl, CURLOPT_PASSWORD, password);

        /* Set the SEARCH command specifying what we want to search for. Note that
	     * this can contain a message sequence set and a number of search criteria
	     * keywords including flags such as ANSWERED, DELETED, DRAFT, FLAGGED, NEW,
	     * RECENT and SEEN. For more information about the search criteria please
	     * see RFC-3501 section 6.4.4.   */ 

        curl_easy_setopt(curl, CURLOPT_URL, head); 

        if (strcmp(operation, "0")) {
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, detail);
        }
  //      curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        res = curl_easy_perform(curl);
        curl_easy_setopt(curl, CURLOPT_URL, url); 
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            printf("error\n");
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    return (int)res;
}
