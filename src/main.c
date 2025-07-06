#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MEM_SIZE 100
#define PERSON_SIZE 3


const char *user_error="cannot read user input";
const char *admin_error="enter vaid admin name";
const char *wrong_password="wrong password";
const char *file_error="error opening files";
char *file_name="record.txt";

int counter();

typedef int Age;
typedef struct{
	char *name;
	Age age;


}PERSON;
int main(int argc,char *argv[]){
	char *admin_mode="Sign in:\n1.Admin Mode\t2.Guest Mode\n";
	char *enter_name="enter name:";
	char *enter_number="enter number:";
	char *enter_command="enter:";
	char *enter_admin_mode="enter admin name:";
	char *enter_password="enter password:";
	char *enter_age="enter age";

	char *admin_password="Pass";
	int user_mode=0;
	int age=0;

	char *name=malloc(sizeof(char)*MEM_SIZE);
	char *admin_name=malloc(sizeof(char)*MEM_SIZE);
	char *user_input_password=malloc(sizeof(char)*MEM_SIZE);
	char *actual_admin_name=malloc(sizeof(char)*MEM_SIZE);
	char *user_third_input=malloc(sizeof(char)*MEM_SIZE);

//	char *registered_admin_name=malloc(sizeof(char)*MEM_SIZE);

	PERSON person[PERSON_SIZE];
	for(int i=0;i<PERSON_SIZE;i++){

		person[i].name=malloc(sizeof(char)*MEM_SIZE);
	}
	fputs(admin_mode,stdout);
	fputs(enter_command,stdout);
	scanf("%d",&user_mode);
	while(getchar()!='\n');
	switch(user_mode){
	case 1:
		fputs(enter_admin_mode,stdout);
		if(fgets(admin_name,MEM_SIZE,stdin)!=NULL){
			admin_name[strcspn(admin_name,"\n")]='\0';
			snprintf(actual_admin_name,MEM_SIZE-1,"%s",admin_name);
			actual_admin_name[strcspn(actual_admin_name,"\n")]='\0';
			fputs(enter_password,stdout);
			if(fgets(user_input_password,MEM_SIZE,stdin)!=NULL){

				user_input_password[strcspn(user_input_password,"\n")]='\0';
				if(strcmp(admin_password,user_input_password)==0){
					printf("welcomee");
				command:
					printf("Task to perform:\n1.enter name and age\n2.delete name\n");
					fputs(enter_command,stdout);
					int user_second_input=0;
					scanf("%d",&user_second_input);
					while(getchar()!='\n');
					if(user_second_input==1){
						int result=counter();
						fputs(enter_name,stdout);
						if(fgets(person[result].name,sizeof(person[result].name),stdin)){

							person[result].name[strcspn(person[result].name,"\n")]='\0';
							printf("%s",person[result].name);
							fputs(enter_age,stdout);
							scanf("%d",&age);
							while(getchar()!='\n');
							printf("Age:%d",age);
							putchar('\n');
							printf("do you want to save input to a file?:Y/N:");
							if(fgets(user_third_input,sizeof(user_third_input),stdin)!=NULL){

								user_third_input[strcspn(user_third_input,"\n")]='\0';
								//int j=0;
								for(int j=0;j<strlen(user_third_input);j++){
									user_third_input[j]=toupper(user_third_input[j]);

								}
								if(strcmp(user_third_input,"Y")==0){

									//file saving
									FILE *file=fopen(file_name,"a");
									if(file ==NULL){
										fprintf(stderr,"cannot open file");
										exit(1);
									}
									static int second_counter =0;
								
										if(second_counter < 1){

									fprintf(file,"Name\tAge\n");
									second_counter++;
									}
									for(int i=0;i<result;i++){

										fprintf(file,"%s\t%d\n",person[result].name,age);
									}
									putchar('\n');
									printf("adding new data to file");
									putchar('\n');
									// if(fclose(file)==EOF){
									// 	fprintf(stderr,"cannot close file");
									// }
									fclose(file);
									putchar('\n');
									printf("data appeneded successfully");
									putchar('\n');


								 char *fourth_user_input=malloc(sizeof(char)*100);
									printf("Enter another record?:");
									if(fgets(fourth_user_input,MEM_SIZE,stdin)!=NULL){
										fourth_user_input[strcspn(fourth_user_input,"\n")]='\0';

										for(int i =0;i<strlen(fourth_user_input);i++){

										fourth_user_input[i]=toupper(fourth_user_input[i]);
										}
										if(strcmp(fourth_user_input,"Y")==0){
											goto command;
										}
									}

								}
							}




						}
						else{
							fprintf(stderr, "%s\n",person[result].name );
						}


					}
				}
				else{
					fprintf(stderr, "%s\n",user_error );
					return 1;
				}
			}

		}
		else{
			fprintf(stderr,"%s\n",admin_error);
			putchar('\n');
			return 1;
		}

		break;
	case 2:
		printf("enter  guest mode");
		putchar('\n');
		break;
	default:
		exit(1);
	}
	//free(registered_admin_name);
	free(admin_name);
	free(name);
	for(int i=0;i<PERSON_SIZE;i++){
		free(person[i].name);
	}

	// fputs(enter_name,stdout);


	// if(fgets(name,sizeof(name),stdin)!=NULL){
	// 	printf("name:%s",name);
	// }
	// else{
	// 	perror(user_error);
	// }

	// fputs(enter_number,stdout);
	// scanf("%d",&age);
	// printf("age:%d",age);

	// printf("action\n:");
	// printf("1:Enter name and age\n2.search\n3.Delete");

	return 0;
}
int counter(){
	static int counter=0;
	counter++;
	return counter;
}
