#include <iostream>
#include "Scheduler.h"

//main function
int main()
{
    Scheduler scheduler;

    if ( ! scheduler.load_data() ){
        return 0;
    }

    scheduler.print_schedule();

    return 0;
}
