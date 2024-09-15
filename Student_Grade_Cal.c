#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

typedef struct{
    char name[max],n1[max];
    char subjects[max][max];
    float scores[max];
    int num_subjects;
}stud;

void choose_subject(stud *stud,int i){
    int ch;
	system("cls");
    printf("\n1.Mathematics\n2.Chemistry\n3.Physics\n4.Biology\n5.English\n6.Bengali\n7.Others.\n");
    printf("Choose subject %d: ",i+1);
	scanf("%d",&ch);
    switch(ch){
        case 1:	
            strcpy(stud->subjects[i],"Mathematics");
            break;
        case 2:	
            strcpy(stud->subjects[i],"Chemistry");
            break;
        case 3:	
            strcpy(stud->subjects[i],"Physics");
            break;
        case 4:	
            strcpy(stud->subjects[i],"Biology");
            break;
        case 5:	
            strcpy(stud->subjects[i],"English");
            break;
        case 6:	
            strcpy(stud->subjects[i],"Bengali");
            break;
        case 7:
            printf("\nEnter your Subject:");
            scanf("%s",stud->subjects[i]);
            break;
    }
}	


void add_score(stud* stud,char* subject,float score){
	int i;
    for (i=0;i<stud->num_subjects;i++) {
        if (strcmp(stud->subjects[i],subject)==0){
            stud->scores[i]=score;
            return;
        }
    }
    strcpy(stud->subjects[stud->num_subjects], subject);
    stud->scores[stud->num_subjects]=score;
    stud->num_subjects++;
}

float calculate_average(stud* stud) {
    float sum=0,avg=0;
    int i;
    for(i=0;i<stud->num_subjects;i++){
        sum+=stud->scores[i];
    }
    avg=sum/stud->num_subjects;
    if(avg>=90.0)
    	printf("\nGrade is: O");
    else if(80<=avg<90)
    	printf("\nGrade is: E");
    else if(70<=avg<80)
		printf("\nGrade is: A"); 
    else if(60<=avg<70)
		printf("\nGrade is: B"); 
	else if(40<=avg<60)
		printf("\nGrade is: C"); 
	else
		printf("\nGrade is: Fail"); 
	return avg;
}

int get_highest_score_index(stud* stud){
    int max_index=0,i;
    for(i=0;i<stud->num_subjects;i++){
        if(stud->scores[i]>stud->scores[max_index]){
            max_index=i;
        }
    }
    return max_index;
}

int get_lowest_score_index(stud* stud) {
    int min_index=0,i;
    for(i=0;i<stud->num_subjects;i++) {
        if(stud->scores[i]<stud->scores[min_index]) {
            min_index=i;
        }
    }
    return min_index;
}

void display_performance(stud* stud){
    int max_index=get_highest_score_index(stud);
    int min_index=get_lowest_score_index(stud);
    printf("Student: %s %s\n",strupr(stud->name),strupr(stud->n1));
    printf("\nAverage Score: %.2f\n",calculate_average(stud));
    printf("Highest Score --> %s : %.2f\n",stud->subjects[max_index],stud->scores[max_index]);
    printf("Lowest Score --> %s : %.2f\n",stud->subjects[min_index],stud->scores[min_index]);
    printf("\n");
}

int main() {
    stud studs[max];
    int num_studs = 0;
    while (1) {
        printf("1. Add Student.\n");
        printf("2. Display student Performance.\n");
        printf("3. Exit.\n");
        printf("\n\nEnter Your Choice:");
        int choice,i;
        scanf("%d", &choice);
        system("cls");
        switch(choice){
         case 1:
            printf("Enter Student Name: ");
            scanf("%s %s",studs[num_studs].name,studs[num_studs].n1);
            printf("\nEnter Number of Subjects: ");
            scanf("%d",&studs[num_studs].num_subjects);
            for (i=0;i<studs[num_studs].num_subjects;i++){
                choose_subject(&studs[num_studs],i);
                printf("Enter score for %s: ",studs[num_studs].subjects[i]);
                scanf("%f",&studs[num_studs].scores[i]);
            }
            num_studs++;
            break;
        case 2:
            for(i=0;i<num_studs;i++){
                display_performance(&studs[i]);
            }
            break; 
		case 3:
        	printf("\nThank You.!!");
    		exit(0);
        default:
            printf("Invalid Choice.\nPlease try again.\n");
        
    }
}
return 0;
}
