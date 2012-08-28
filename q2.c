# include <stdio.h>
# include <stdio.h>
int main()
{
	char hour[100], month[100], day[100], minute[200], date[200], category[100], message[1000];
	int add=1,i;
	FILE *fp;
	printf("Note: '*' for all values, ',' as seperator between value, O to stop when asked for more\nEg. day = * or day = 1,3,5\n");

	while(1)
	{
		printf("Enter mintute (write some mintues earlier to get email early) : ");
		scanf("%s",minute);
		printf("Enter hour : ");
		scanf("%s",hour);
		printf("Enter date : ");
		scanf("%s",date);
		printf("Enter month : ");
		scanf("%s",month);
		printf("Enter day : ");
		scanf("%s",day);
		printf("Category (break by space/enter) : ");
		scanf("%s",category);
		message[0] = getchar();
		printf("Message (break by enter) : ");
	i=0;
	while(1)
	{
		message[i] = getchar();
		if(message[i]=='\n') break;
		i++;
	}
	message[i]='\0';

	fp = fopen("open.txt","a");
	fprintf(fp, "%s %s %s %s %s /bin/bash ~/mail.sh\n", minute, hour, date, month, day);
	fclose(fp);

	fp = fopen("msg.txt","a");
	fprintf(fp, "%s \n %s", category, message);
	fclose(fp);

	fp = fopen("log.txt", "a");
	fprintf(fp, "Time : %s %s %s %s %s \n", minute, hour, date, month, day);
	fprintf(fp, "Mail : Subject : %s \n Message: %s \n\n", category, message);
	fclose(fp);

	printf("More ? : ");
	scanf("%d",&add);
	if(!add) break;

	printf("\n");
	}

return 0;
}

