#include <iostream>
#include "Scheduler.h"

//main function
int main()
{
    Scheduler scheduler;

    if ( ! scheduler.init_from_input() ){
        return 0;
    }

    std::cout << "Minimal number of rooms required for entered lectures: " << scheduler.get_min_rooms() << std::endl;

    return 0;
}
