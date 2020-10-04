#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <utility>

class Scheduler
{
public:
    bool load_data(void);
    void print_schedule(void) const;
private:
    std::vector<std::pair<int, int>> lectures;
};

#endif // SCHEDULER_H
