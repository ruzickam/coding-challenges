#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <utility>

class Scheduler
{
public:
    bool init_from_input(void);
    int get_min_rooms(void);
private:
    std::vector<std::pair<int, int>> lectures;
};

#endif // SCHEDULER_H
