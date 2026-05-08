#include "speedywagon.h"

namespace speedywagon {


    // Please don't change the interface of the uv_light_heuristic function
    int uv_light_heuristic(std::vector<int>* data_array) {
        double avg{};
        for (auto element : *data_array) {
            avg += element;
        }
        avg /= data_array->size();
        int uv_index{};
        for (auto element : *data_array) {
            if (element > avg) ++uv_index;
        }
        return uv_index;
    }

    bool connection_check(pillar_men_sensor* sensor) {
        if (sensor != nullptr) {
            return true;
        }
        else {
            return false;
        }
    }

    int activity_counter(pillar_men_sensor* sensor, int capacity) {

        bool is_connected = connection_check(sensor);

        if (!is_connected) {
            return 0;
        }

        int total{ 0 };

        for (int i{ 0 }; i < capacity; ++i) {
            total += (sensor + i)->activity;
        }

        return total;


    }

    bool alarm_control(pillar_men_sensor* sensor) {

        bool is_connected = connection_check(sensor);

        if (!is_connected) {
            return false;
        }

        if (sensor->activity <= 0) {
            return false;
        }
        else {
            return true;
        }


    }

    bool uv_alarm(pillar_men_sensor* sensor) {

        bool is_connected = connection_check(sensor);

        if (!is_connected) {
            return false;
        }

        // To assign the address of a variable to a pointer, you use the address-of operator (&).
        int uv_index = uv_light_heuristic(&sensor->data);

        if (uv_index > sensor->activity) {
            return true;
        }
        else {
            return false;
        }

    }

}  // namespace speedywagon
