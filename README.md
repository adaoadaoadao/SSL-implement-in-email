Here is a mail message processing application.
Utilize SMTP and IMAPS protocols with SSL with libcurl.

Please make it at first.

make

Then there will be 2 executable file, smtps and imaps. smtps is for sending email and imaps is for fetching emails.

./imaps <username> <password> <operation> <operation-detail>
./smtps

For imaps command, there are two kinds of operations. 0 for fetching email with uid, operation-detail should be UID of expected mail. 1 for customizing operations, like examine folder, list folders etc. Operation-detail shoud be extected operation command.