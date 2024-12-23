#include<stdio.h>
#include<stdlib.h>
#include"string.h"

int main() 
{
    int MAX_TASKS=10;         // Define constants for array sizes
    int MAX_TASK_LENGTH=100;

    char tasks[MAX_TASKS][MAX_TASK_LENGTH];  // Task array and task counter
    int a,b,taskCount=0;
  
    while(1) 
	{
       
        printf("\nTodo List Menu:\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. View Tasks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&a);
        while(getchar()!='\n'); 

        switch(a) 
		{
            case 1:
                if (taskCount<MAX_TASKS) 
				{
                    // Add task logic
                    printf("Enter the task description: ");
                    fgets(tasks[taskCount], MAX_TASK_LENGTH, stdin);
                    tasks[taskCount][strcspn(tasks[taskCount], "\n")]='\0';  // Remove newline character
                    taskCount++;
                    printf("Task added successfully!\n");
                } 
				else 
				{
                    printf("Task list is full! Cannot add more tasks.\n");
                }
                break;

            case 2:
                if (taskCount>0) 
				{
                    // Remove task logic
                    printf("\nList of tasks:\n");
                    for (b=0;b<taskCount;b++) 
					{
                        printf("%d. %s\n",b+1,tasks[b]);
                    }

                    printf("Enter the task number to remove: ");
                    scanf("%d",&tn);
                    while(getchar()!='\n'); // Clear input buffer after scanf

                    if (tn>=1&& tn<=taskCount) 
					{
                        // Shift tasks to remove the selected task
                        for (b=tn-1;b<taskCount-1;b++) 
						{
                            strcpy(tasks[b],tasks[b+1]);
                        }
                        taskCount--;
                        printf("Task removed successfully!\n");
                    } 
					else 
					{
                        printf("Invalid task number.\n");
                    }
                } 
				else 
				{
                    printf("No tasks to remove.\n");
                }
                break;

            case 3:
                if (taskCount>0) 
				{
                    // View tasks logic
                    printf("\nList of tasks:\n");
                    for (b=0;b<taskCount;b++) 
					{
                        printf("%d. %s\n",b+1,tasks[b]);
                    }
                } 
				else 
				{
                    printf("No tasks available.\n");
                }
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}

