/**
 * @author Massimiliano Di Ubaldo
 * Group 3, Informatics
 * Academic year 2021/2022
*/

#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>

#include "structures.h"
#include "electrification.h"

int main(int argc, char *argv[])
{
    if(argc==1)
    {
        std::cout<<"    ________          __       _ _____            __  _           \n"
                   "   / ____/ ___  _____/ /______(_/ __(__________ _/ /_(_____  ____ \n"
                   "  / __/ / / _ \\/ ___/ __/ ___/ / /_/ / ___/ __ `/ __/ / __ \\/ __ \\\n"
                   " / /___/ /  __/ /__/ /_/ /  / / __/ / /__/ /_/ / /_/ / /_/ / / / /\n"
                   "/_____/_/\\___/\\___/\\__/_/  /_/_/ /_/\\___/\\__,_/\\__/_/\\____/_/ /_/ \n"
                   "                                                                  \n"
                   "Usage: Electrification [options]\n\n"
                   "-i [input file]: load the input file with the pairs of cities\n"
                   "-o: create the output file with the selected links of cities\n\n"
                   "                               Developed by Massimiliano Di Ubaldo\n";

        return 0;
    }else if(argc==4 && strcmp(argv[1],"-i")==0 && strcmp(argv[3],"-o")==0)
    {
        const std::string FILE_NAME(argv[2]);
        std::unordered_map<std::string, std::vector<cities>>un_map_cities;
        un_map_cities=create_map_cities(FILE_NAME);

        if(!un_map_cities.empty())
            std::cout<<"Input file loaded correctly!!\n";
        else
        {
            std::cout<<"There is a problem with the path of the input file or the file it's empty!!\n";
            return 0;
        }

        std::unordered_map<std::string, std::vector<cities>>unmap_mst=mst_electrification(un_map_cities);

        create_output_mst(unmap_mst);

        std::cout<<"Output file created correctly!!\n";
    }

    return 0;
}