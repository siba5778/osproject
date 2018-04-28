#include <iostream>
using namespace std;
struct Student{
	int id;
    int B_time;
    int CompletionTime ;
	int F_time;
	

};


void TotalTaskTime(Student s[]){
    for (int i=0;i<3;i++){
            if(s[i].F_time!=0)
                s[i].CompletionTime +=1;
    }

}

bool REMAIN(Student s[]){
    for (int i=0;i<3;i++){
        if(s[i].F_time!=0){
            return true;
        }
    }
    return false;
}
void SORT_DESC(Student s[]){
    for(int i=1;i<3;i++){
        for(int j=0;j<3-i;j++){
            if(s[j].F_time < s[j+1].F_time){
                Student temp = s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
            else if(s[j].F_time == s[j+1].F_time){
                if(s[j].id > s[j+1].id){
                    Student temp = s[j];
                    s[j]=s[j+1];
                    s[j+1]=temp;
                }
            }
        }
    }

}



int main(){
	Student s[3];

	
	for(int i=0;i<3;i++){
        printf("ENTER THE ID NUMBER OF THE STUDENT NUMBER %d \n",i+1);
        scanf("%d",&s[i].id);

		//cin>>s[i].id;
        printf("ENTER THE FOOD TAKEN TIME BY THE STUDENT %d \n",i+1);
        scanf("%d",&s[i].F_time);
		s[i].B_time = s[i].F_time;

	}
	SORT_DESC(s);

    printf("STUDENTS ENTERED THE QUEUE IN THE FOLLOWING WAY \n");
    while(REMAIN(s)){
        printf("%d \n ",s[0].id);
        TotalTaskTime(s);
        s[0].F_time--;
        SORT_DESC(s);
    }
    int sum = 0;
    int sum1 = 0;
    printf("STUDENT ID | TURN AROUND TIME | WAITING TIME\n");
    for(int i=0;i<3;i++){
        printf("%d :\t\t %d \t\t",s[i].id,s[i].CompletionTime);
        printf("%d \n",s[i].CompletionTime - s[i].B_time);
        sum += s[i].CompletionTime;
        sum1 += s[i].B_time;
    }
    printf("\n THE FINAL AVERAGE TURN AROUND TIME IS : %d",sum/3);
    printf("\n THE FINAL AVERAGE WAITING TIME IS     : %d",sum1/3);

}

