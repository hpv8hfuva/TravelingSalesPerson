#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

class MiddleEarth {
private:
  /** These are the private variables that MiddleEarth holds to create the world
   */
  /*
    This is the number of city names and the size of the world in x and y sizes
   */
    int num_city_names, xsize, ysize;

    /*
      the vector of x and y positions for the cities in float form
     */
    vector<float> xpos, ypos;

    /*
      vector of all the string names for the cities
     */
    vector<string> cities;

    /*
this carries the pointer to the distances of specific cities
     */
    float *distances;
    /*
      This is the map of all the cities and there specific positions as indices
     */
    map<string, int> indices;

public:
    /** @brief This is the constructor for middle earth that takes in 4 parameters.
 *
 *
 * @param xsize The first value is the maximum horizontal size of the map
 * @param ysize The second value is the maximum vertical size of the map
 * @param num_cities the number of cities in the map
 * @param seed a random generate seed that will randomize a specific number
 */
    MiddleEarth (int xsize, int ysize, int numcities, int seed);
    /*
      The destructor
     */
    ~MiddleEarth();
    /*
      it prints out the world and is a void type
     */
    void print();
    /*
      it prints out all the distances that are seperated between specific cities
     */
    void printTable();
    /*
      This method will return a float that is the distances between two string of city names
     */
    float getDistance (string city1, string city2);
    /*
      gets a vector of strings that is the size of the length and will randomly grab cities to put into the itinerary
     */
    vector<string> getItinerary(unsigned int length);
};

#endif
