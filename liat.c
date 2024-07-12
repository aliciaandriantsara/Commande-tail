#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void tail(FILE *pfile, char ligne[100], int l);
void arg(int argc, char *argv[]);


int main(int argc, char* argv[])
{
	arg(argc, argv);		
	return (0);
}

void arg(int argc, char *argv[])
{
	FILE *pfile=NULL;
	char ligne[100];
	int l=0;
	int i=0;
	int n=0;
	if(strcmp(argv[1], "-n") == 0)
	{
		l=atoi(argv[2]);
		pfile=fopen(argv[3], "r+");
		tail(pfile, ligne, l);
	}
	else if(strcmp(argv[1], "-v") == 0)
	{
		
		char lettre;
		printf("==> %s <==\n", argv[2]);

		pfile=fopen(argv[2], "r+");
		rewind(pfile);
		while((lettre=fgetc(pfile))!=EOF)
		{
			printf("%c",lettre);
		}
		
		
	}
	
	else if(strcmp(argv[1], "-c") == 0)
	{
		l=atoi(argv[2]);
		pfile=fopen(argv[3], "r+");
		if(pfile==NULL)
		{
			printf("Erreur d'ouverture du fichier\n");
		}
		else
		{
			while(fgetc(pfile) != EOF)
			{
				n++;
			}
			printf("%d", n);
			rewind(pfile);
			while(fgetc(pfile) != EOF)
			{
				i++;
				if(i>=(n-l))
				{
					
					printf("%s", fgets(ligne, 100, pfile));
				}
				
			}
		}
		fclose(pfile);
	}
	else if(strcmp(argv[1], "-z") == 0)
	{
		char lettre;
		pfile=fopen(argv[argc-1], "r+");
		rewind(pfile);
		while((lettre=fgetc(pfile))!=EOF)
		{
			printf("%c",lettre);
		}
		
	}
	else if(strcmp(argv[1], "-f") == 0)
	{
		l=10;
		pfile=fopen(argv[2], "r+");
		tail(pfile, ligne, l);
	}
	else if(strcmp(argv[1], "--pid") == 0)
	{
		l=10;
		pfile=fopen(argv[2], "r+");
		tail(pfile, ligne, l);
		exit(0);
	}
	else
	{
		l=10;
		pfile=fopen(argv[1], "r+");
		tail(pfile, ligne, l);
	}		
	fclose(pfile);	
	
}

void tail(FILE *pfile, char ligne[100], int l)
{
	int i=0;
	int j = 0 ;
	int n=0;
	char lettre;
	if(pfile==NULL)
	{
		printf("Erreur d'ouverture du fichier\n");
	}
	else
	{
		while(!feof(pfile))
		{
			fscanf(pfile, "%s", ligne);
			printf("%s\n", ligne);
			n++;
		}
		n=n-1;
		printf("%d", n);
		j=n-l ;
		printf("\n\n");
		rewind(pfile);
		while(!feof(pfile))
		{
			if(fgetc(pfile)=='\n')
			{
				i++;
				if(i>=j)
				{
					while((lettre=fgetc(pfile))!=EOF)
					{
						printf("%c",lettre);
					}
					//fscanf(pfile, "%s", ligne);
					//printf("%s\n", ligne);
				}
				
			}
			
			
		}
			
			
		fclose(pfile);
	}
}
