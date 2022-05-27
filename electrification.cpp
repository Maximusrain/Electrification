/**
 * @author Massimiliano Di Ubaldo
 * Group 3, Informatics
 * Academic year 2021/2022
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <limits>

#include "structures.h"
#include "electrification.h"

std::unordered_map<std::string, std::vector<cities>> create_map_cities(const std::string &file_name)
{
    std::ifstream inputFile(file_name);                                                                              ///variable for the input file
    cities c;                                                                                                           ///variable of type city where where gonna store our pairs
    std::unordered_map<std::string, std::vector<cities>> map_cities;                                                    ///unordered_mao of type string for the key and type vector of type cities to create the map with pairs

    if(inputFile.is_open())
    {
        while(inputFile>>c.first_city>>c.second_city>>c.distance)
        {
            map_cities[c.first_city].push_back({c});
        }
    }
    else
        std::cout<<"Error while opening the file!!\n";

    return map_cities;
}

std::unordered_map<std::string, std::vector<cities>> mst_electrification(std::unordered_map<std::string, std::vector<cities>> map_cities)
{
    cities c_current;                                                                                                   ///variable of type where to store the current city pointed
    std::unordered_map<std::string, std::vector<cities>> mst_cities;                                                    ///unorderedmap where we store out MST tree
    double min = std::numeric_limits<double>::max();

    c_current.first_city=map_cities.begin()->first;                                                                     ///We take the first key in the map of cities
    mst_cities[c_current.first_city];                                                                                   ///We insert inside the MST the first city

    while(mst_cities.size()<map_cities.size())                                                                          ///The MST size have to be less then the map of cities total size
    {
        for(auto itMstVertex=mst_cities.begin();itMstVertex!=mst_cities.end();itMstVertex++)                  ///For loop to iterate through the MST tree unorderedmap
        {
            auto found1=map_cities.find(itMstVertex->first);                                               ///We check inside the map of cities if we find the city key inside the MST tre unordered map
            if(found1!=map_cities.end())
            {
                for(auto itVertex=found1;itVertex!=map_cities.end();itVertex++)                               ///if yes we set the start point of the iteration from that point
                {
                    for(auto &connections:itVertex->second)                                                      ///We iterate through the connections avaiable for it
                    {
                        auto found2 = mst_cities.find(connections.second_city);                            ///We check if inside the MST tree we don't have already the connections
                        if (found2 == mst_cities.end() && connections.distance < min)                                   ///if the connections we are pointing is not inside of the MST tree and the distance we are pointing is less then the min
                        {
                            min = connections.distance;                                                                 ///we set the min with the pointing distance
                            c_current = connections;                                                                    ///we save that connection inside the variable of type cities
                        }
                    }
                }
            }
        }
        mst_cities[c_current.first_city].push_back({c_current});                                                        ///When we find the best connection we insert inside the MST unordered map
        mst_cities[c_current.second_city];                                                                              ///We create a new key with the connection
        min=std::numeric_limits<double>::max();
    }

    return mst_cities;
}

void create_output_mst(const std::unordered_map<std::string, std::vector<cities>> &mst_map)
{
    std::ofstream outputFile("../texts/output_mst.txt");
    double sum=0;

    if(outputFile.is_open())
    {
        for (auto &vertex:mst_map)
        {
            outputFile<<"City: "<<vertex.first<<std::endl;
            for(auto &connections:vertex.second)
            {
                outputFile<<" Connected to: "<<connections.first_city<<" "<<connections.second_city<<" "<<connections.distance<<std::endl;
                sum+=connections.distance;
            }
        }
        outputFile<<std::endl;
        outputFile<<"The total length in Km to connect every city is: "<<sum;
        outputFile.close();
    }else
        std::cout<<"Error while opening or creating the file!!\n";
}