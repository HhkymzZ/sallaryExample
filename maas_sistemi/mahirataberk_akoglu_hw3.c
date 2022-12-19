#include <stdio.h>
#include <stdlib.h>

struct employee{
	
	char name[20];
	int id;
	int salary;
	int total;
	int workhours;
	struct wh{
		int wd;
		int we;
	};	
	
};
int main(int argc, char *argv[]) {
	
	int size,i,s,fazladan;
	FILE *fp ;
	
	fp= fopen("salaries.txt","w");
	
	printf("Enter the count of the employee: ");
	scanf("%d",&size);
	struct employee arr[size];
	
	for(i=0;i<size;i++){
	
	printf("Enter The name of employee: ");
	scanf("%s",&arr[i].name);
	printf("Enter The ID of the employee: ");
	scanf("%d",&arr[i].id);
	printf("Enter The sallary of the employee: ");
	scanf("%d",&arr[i].salary);
	printf("Enter The weekly working of the employee: ");
	scanf("%d",&arr[i].workhours);
	
	if(arr[i].workhours == 40){
		arr[i].total=arr[i].salary;
	}
	if(arr[i].workhours>40){
		printf("Enter the weekly working day of the employee(1-WEEKDAY 2-WEEKEND):");
		scanf("%d",&s);
		if(s==1 && ((arr[i].workhours) - 40) < 6 ) {
			
			arr[i].total = arr[i].salary + ((arr[i].workhours) - 40)*35 ;
		}
		if(s==1 && ((arr[i].workhours) - 40) > 5 ) {
			
			arr[i].total = arr[i].salary + ((arr[i].workhours) - 40)*50;
		}
		if(s==2 && ((arr[i].workhours) - 40) < 6 ) {
			
			arr[i].total = arr[i].salary + ((arr[i].workhours) - 40)*50;
		}
		if(s==2 && ((arr[i].workhours) - 40) >5 ) {
			
			arr[i].total = arr[i].salary + ((arr[i].workhours) - 40)*80 ;
		}		
	}
	printf("Salary of %s is %d\n",arr[i].name,arr[i].total);
	printf("***************************\n");
	fprintf(fp, "Name: %s\n",arr[i].name );
	fprintf(fp, "Total Sallary: %d \n", arr[i].total);
}	
	return 0;
}



















