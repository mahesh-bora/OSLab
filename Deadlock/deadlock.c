#include <stdio.h> 
#include <stdbool.h> 
#define MAX_PROCESS 10 
#define MAX_RESOURCE 10 
int available[MAX_RESOURCE]; 
int max_claim[MAX_PROCESS][MAX_RESOURCE]; 
int allocated[MAX_PROCESS][MAX_RESOURCE]; 
int need[MAX_PROCESS][MAX_RESOURCE]; 
bool finished[MAX_PROCESS]; 
int num_processes, num_resources; 
void initialize() 
{ 
int i, j; 
for (i = 0; i < num_processes; i++) 
finished[i] = false; 
for (i = 0; i < num_processes; i++) 
for (j = 0; j < num_resources; j++) 
need[i][j] = max_claim[i][j] - allocated[i][j]; 
} 
bool is_safe_state() 
{ 
int work[MAX_RESOURCE]; 
bool finish[MAX_PROCESS]; 
int i, j, count = 0; 
for (i = 0; i < num_resources; i++) 
work[i] = available[i]; 
for (i = 0; i < num_processes; i++) 
finish[i] = false;while (count < num_processes) 
{ 
bool found = false; 
for (i = 0; i < num_processes; i++) 
{ 
if (!finish[i]) 
{
bool can_finish = true; 
for (j = 0; j < num_resources; j++) { 
if (need[i][j] > work[j]) 
{ 
can_finish = false; 
break; 
} 
} 
if (can_finish) 
{ 
for (j = 0; j < num_resources; j++) work[j] += allocated[i][j]; 
finish[i] = true; 
found = true; 
count++; 
} 
} 
} 
if (!found) 
break; 
} 
return (count == num_processes); } 
bool resolve_deadlock() 
{ 
int i, j; 
bool deadlock = true; 
while (deadlock) 
{ 
deadlock = false; 
for (i = 0; i < num_processes; i++) { 
if (!finished[i]) 
{ 
bool can_finish = true; 
for (j = 0; j < num_resources; j++) {if (need[i][j] > available[j]) { 
can_finish = false; 
break; 
} 
} 
if (can_finish) 
{ 
for (j = 0; j < num_resources; j++) {
available[j] += allocated[i][j]; 
allocated[i][j] = 0; 
need[i][j] = 0; 
} 
finished[i] = true; 
deadlock = true; 
break; 
} 
} 
} 
} 
return deadlock; 
} 
int main() 
{ 
int i, j; 
printf("Enter the number of processes: "); scanf("%d", &num_processes); 
printf("Enter the number of resources: "); scanf("%d", &num_resources); 
printf("\nEnter the available resources:\n"); for (i = 0; i < num_resources; i++) 
scanf("%d", &available[i]); 
printf("\nEnter the request matrix:\n"); 
for (i = 0; i < num_processes; i++) 
for (j = 0; j < num_resources; j++) 
scanf("%d", &max_claim[i][j]); 
printf("\nEnter the allocated matrix:\n"); 
for (i = 0; i < num_processes; i++) 
for (j = 0; j < num_resources; j++) 
scanf("%d", &allocated[i][j]); 
initialize();if (is_safe_state()) 
{ 
printf("\nSystem is safe.\n"); 
printf("Safe sequence: "); 
for (i = 0; i < num_processes; i++) 
printf("%d ", i); 
printf("\n"); 
} 
else 
{ 
printf("\nDeadlock detected. Resolving deadlock...\n"); bool deadlock = resolve_deadlock(); 
if (deadlock) 
{ 
printf("Deadlock resolved.\n"); 
printf("Safe sequence: ");
for (i = 0; i < num_processes; i++) 
{ 
if (!finished[i]) 
printf("%d ", i); 
} 
printf("\n"); 
} 
else 
{ 
printf("Unable to resolve deadlock.\n"); 
printf("System is still unsafe.\n"); 
} 
} 
return 0; 
} 

