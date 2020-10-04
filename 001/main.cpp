#include <iostream>
#include "Scheduler.h"

//main function
int main()
{
    Scheduler scheduler;

    if ( ! scheduler.init_from_input() ){
        return 0;
    }

    scheduler.get_min_rooms();

    return 0;
}
