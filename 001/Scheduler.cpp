#include <iostream>
#include <algorithm>
#include "Scheduler.h"

bool Scheduler::init_from_input(void)
{
    // input num of lectures
    std::cout << "Enter number of lectures: " << std::endl;
    auto number_of_lectures {0};
    if( ! (std::cin >> number_of_lectures) ){
        std::cout << "Invalid number!" << std::endl;
        return false;
    }
    if( number_of_lectures < 0 ){
        std::cout << "Number of lectures cannot be negative!" << std::endl;
        return false;
    }
    std::cout << "Entered number of lectures: " << number_of_lectures << std::endl;
    lectures.reserve(number_of_lectures);

    // input start and end of lessons
    for(auto i {0}; i < number_of_lectures; ++i){
        std::cout << "Enter start & end time in minutes for the lecture #" << (i + 1) << " (Example: 0 200):" << std::endl;
        auto start {0}, end {0};
        if ( ! (std::cin >> start >> end) ){
            std::cout << "Invalid input!" << std::endl;
            return false;
        }
        if ( start >= end ){
            std::cout << "Start is later or at the same time as the end!" << std::endl;
            return false;
        }
        lectures.emplace_back( start, end );
    }

    // sort lectures vector for finding lecture overlaps
    std::sort( lectures.begin(), lectures.end() );

    return true;
}

// -----------------------------------------------------------------------------------

void Scheduler::get_min_rooms(void) const
{
    std::vector<std::vector<std::pair<int,int>>> building; // building<room<lecture>>
    if ( lectures.size() > 0 ){
        building.emplace_back(); // add one room
        building[0].push_back( { lectures[0] } ); // add first lecture to the first room
    }

    for(unsigned int i {1}; i < lectures.size(); ++i){ // i starts from 1 to skip the first lecture (that is already assigned)
        auto recently_added = false;
        for(auto& room : building){ // rooms already assigned
            auto overlap = false;
            for(const auto& assigned_lectures : room){ // lectures already assigned
                // Does the lecture overlap with the assigned lecture?
                if( ! ( lectures[i].first >= assigned_lectures.second ) ){ // overlap
                    overlap = true;
                }
            }
            // add lecture to current room when there's no overlap
            if( overlap == false && recently_added == false ){
                room.push_back( { lectures[i] } );
                recently_added = true;
            }
        }
        // create new room when the lecture did not fit anywhere
        if( recently_added == false ){
            building.emplace_back(); // add new room
            building.back().push_back( { lectures[i] } ); // add lecture to this new room
        }
    }

    // print min number of rooms
    std::cout << std::endl << "Minimal number of rooms required for entered lectures: " << static_cast<int>( building.size() ) << std::endl;

    // print schedule - BONUS :-)
    std::cout << std::endl;
    for(unsigned int i {0}; i < building.size(); ++i){ // rooms
        std::cout << "Room #" << i << ": ";
        for(const auto& lecture : building[i]){ // lectures
            if ( lecture == building[i].back() ){ // last lecture
                std::cout << "(" << lecture.first << " - " << lecture.second << ")" << std::endl;
            } else {
                std::cout << "(" << lecture.first << " - " << lecture.second << "), ";
            }
        }
    }


}
