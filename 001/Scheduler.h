#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <utility>

class Scheduler
{
public:
    bool init_from_input(void);
    void get_min_rooms(void) const;
private:
    std::vector<std::pair<int, int>> lectures;
};

#endif // SCHEDULER_H
