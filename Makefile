default:
	gcc imaps.c -o imaps -lcurl 
	gcc smtp-ssl.c -o smtps -lcurl 
