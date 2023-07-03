#include <header.h>

int count_file_lines(char *filename)
{
	char buff[MAX] = {0};
	int len = 0,
	    count = 0;
	char *fname = NULL;

	len = strlen(filename)+1;
	fname = malloc(len * sizeof(char));
	//prevent garbage values
	memset(fname,'\0',len);

	//copy the file to a temp file
	if(fname)
	{
		strcpy(fname, filename);
	}

	FILE *fp = fopen(fname, "r");
	if(fp == NULL)
	{
		fprintf(stderr, "file cannot be open");
		return FAILURE;
	}
	//travers till end of the file
	while(!feof(fp))
	{
		while(fgets(buff, MAX, fp) != NULL)
		{
			count++;
		}
	}
	//free the file
	if(fp)
	{
		fclose(fp);
		fp = NULL;
	}
	//free the memory
	if(fname)
	{
		free(fname);
		fname = NULL;
	}

	return count;
}

//to read file line
char **read_file(char *ffname)
{
	int line_count = 0,
	    len = 0,
	    i = 0;
	char buff[MAX] = {0};
	char **lines = NULL;
	
	FILE *fp = fopen( ffname, "r");
	//check whether the file is empty
	if(fp == NULL)
	{
		fprintf(stderr, "File cannot be open");
		exit(FAILURE);
	}

	line_count = count_file_lines(ffname);
	lines = malloc(line_count * sizeof(char *));
	//traver till end of the file
	while(!feof(fp))
	{
		while(fgets(buff, MAX, fp) != NULL)
		{
			len = strlen(buff);

			//to trim the new line 
			if(buff[len - 1] == '\n')
			{
				buff[len - 1] = '\0';
			}

			lines[i] = malloc(len+1 * sizeof(char));

			//copy the lines separately
			if(lines[i])
			{
				strcpy(lines[i], buff);
			}
			i++;
		}
	}
	
	//print the lines
	for(i = 0; i < line_count; i++)
	{
		printf("%s\n",lines[i]);
	}

	return lines;
}

//to add suffix
char *file_process(char **file_line, char *suffix, int line_count)
{
	int len = 0,
	    len2 = 0,
	    len3 = 0,
	    count = 0,
	    i = 0;
	char *str = NULL;
	char *final_str = NULL;

	//to open a file with write option
	FILE *fp = fopen("out.txt", "w");
	//error handling
	if(fp == NULL)
	{
		fprintf(stderr, "File cannot be open");
		exit(FAILURE);
	}

	len2 =strlen(suffix)+2;
	for(i = 0; i < line_count; i++)
	{
		len = strlen(file_line[i])+1;

		//allocate memory to store the text
		str = malloc(len * sizeof(char));

		if(str)
		{
			strcpy(str, file_line[i]);
//			fprintf(fp, "%s\n", str);
		}
	
		char *token = strtok(str, DELIM);
		while(token != NULL)
		{
			count++;
			token = strtok(NULL, DELIM);
		}

		if(count >= 3 && strstr(file_line[i], "new"))
		{
			fprintf(fp, "%s\n", file_line[i]);

			//to find the question mark which will be at the end of a text
			char *token1 = strtok(file_line[i], "?");
			len3 = strlen(token1);

			//allocate memory for the final string along with sizeof suffix
			final_str = malloc(len3+len2 * sizeof(char));
			
			//to concat the given suffix in the final word
			if(final_str)
			{
				strcpy(final_str, token1);
				strcat(final_str, "_");
				strcat(final_str, suffix);
				strcat(final_str, "?");
			}
		}
	}
	
	//free memory
	if(str)
	{
		free(str);
		str = NULL;
	}

	if(fp)
	{
		fclose(fp);
		fp = NULL;
	}

	return final_str;
}


//to write the string to output file
void write_file(char *final_string)
{
	//to write a file
	FILE *fp = fopen("out.txt", "w");
	//error checking
	if(fp == NULL)
	{
		fprintf(stderr, "File cannot be open");
		exit(FAILURE);
	}

	//to write the string content to out.txt
	fprintf(fp, "%s", final_string);

	if(fp)
	{
		fclose(fp);
		fp = NULL;
	}
}



