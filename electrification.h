/**
 * @author Massimiliano Di Ubaldo
 * Group 3, Informatics
 * Academic year 2021/2022
*/

#ifndef ELECTRIFICATION_H
#define ELECTRIFICATION_H

#include <list>
#include <vector>
#include <string>

/** The function create an "std::unordered_map" from an input file.
 * @param file_name the input file.
 * @return "std::unordered_map" of type "<std::string, std::vector<cities>>".
*/
std::unordered_map<std::string, std::vector<cities>> create_map_cities(const std::string &file_name);

/** The function create an "std::unordered_map" with the MST tree using Prim's Algorithm.
 * @param map_cities the unordered map we create in the function before.
 * @return "std::unordered_map" of type "<std::string, std::vector<cities>>".
*/
std::unordered_map<std::string, std::vector<cities>> mst_electrification(std::unordered_map<std::string, std::vector<cities>> map_cities);

/** The function create a file with the MST tree.
 * @param mst_map the unordermap with the MST tre
*/
void create_output_mst(const std::unordered_map<std::string, std::vector<cities>> &mst_map);

#endif
