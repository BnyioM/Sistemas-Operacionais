
#include <stdio.h>
#include <stdlib.h>
#include "FreeRTOS.h"		/* RTOS firmware */
#include "task.h"			/* Task */
#include "timers.h"

#define CH3_TASKMANAGEMENT

/* --------------------------------------------- */
#ifdef CH3_TASKMANAGEMENT
void vTask1(void*);
void vTask2(void*);
void vTask3(void*);
void vTask4(void*);

#endif

void vApplicationIdleHook(void);

int main ( void )
{
#ifdef CH3_TASKMANAGEMENT
	xTaskCreate( vTask1, "Task 1", 1000, NULL, 1, NULL );
	xTaskCreate( vTask2, "Task 2", 1000, NULL, 1, NULL );
	xTaskCreate( vTask3, "Task 3", 1000, NULL, 1, NULL );
	xTaskCreate( vTask4, "Task 4", 1000, NULL, 1, NULL );
#endif

	vTaskStartScheduler();
	return 0;
}

void vAssertCalled( unsigned long ulLine, const char * const pcFileName )
{
 	taskENTER_CRITICAL();
	{
        printf("[ASSERT] %s:%lu\n", pcFileName, ulLine);
        fflush(stdout);
	}
	taskEXIT_CRITICAL();
	exit(-1);
}


#ifdef CH3_TASKMANAGEMENT
void vTask1(void* parameter)
{
    while(1){
        printf("Task 1\n");
        vTaskDelay(pdMS_TO_TICKS(250));
    }
}
void vTask2(void* parameter)
{
    while(1){
        printf("Task 2\n");
        vTaskDelay(pdMS_TO_TICKS(250));
    }
}
void vTask3(void* parameter)
{
    while(1){
        printf("Task 3\n");
        vTaskDelay(pdMS_TO_TICKS(250));
    }
}
void vTask4(void* parameter)
{
    while(1){
        printf("Task 4\n");
        vTaskDelay(pdMS_TO_TICKS(250));
    }
}

#endif
/* CH3_TASKMANAGEMENT ends */


void vApplicationIdleHook(void)
{
    printf("Idle\r\n");
    vTaskDelay(pdMS_TO_TICKS(250));
}
