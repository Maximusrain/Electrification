/**
 * @author Massimiliano Di Ubaldo
 * Group 3, Informatics
 * Academic year 2021/2022
*/

#ifndef STRUCTURES_H
#define STRUCTURES_H

///Structure to store pairs of cities
struct cities
{
    std::string first_city, second_city;    ///first_city is the beginning city and second_city is the destination
    double distance;                        ///distance is the distance between two cities
};

#endif
