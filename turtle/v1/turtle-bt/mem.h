#include <MemoryUsage.h>



void print_mem_state() 
{
    Serial.println("State of the memory:");
    Serial.println();
    
    MEMORY_PRINT_START
    MEMORY_PRINT_HEAPSTART
    MEMORY_PRINT_HEAPEND
    MEMORY_PRINT_STACKSTART
    MEMORY_PRINT_END
    MEMORY_PRINT_HEAPSIZE

    Serial.println();
   
    FREERAM_PRINT;
}
