#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance (MiddleEarth &me, string start, vector<string> dests);
void printRoute (string start, vector<string> dests);

/** @brief In this main there will be the creation of the map through input values and will find the shortest path given these input values. It will display the specific path and the total length of that path.
 *
 * @param argc is the number used to represent the size of the character array of argv. This argc should be 5 because of the 5 inputs that are required to be read in to produce the MiddleEarth
 * @param argv is the character array that is going to have the size of argc. This will store the specific characters to be able to read these inputs in.
 */
int main (int argc, char **argv) {
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf (argv[1], "%d", &width);
    sscanf (argv[2], "%d", &height);
    sscanf (argv[3], "%d", &num_cities);
    sscanf (argv[4], "%d", &rand_seed);
    sscanf (argv[5], "%d", &cities_to_visit);
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    // YOUR CODE HERE
    float test = 0;
    string starto = dests[0];
    dests.erase(dests.begin());
    vector<string> ans = dests;
    sort(dests.begin(),dests.end());
    float shortest = computeDistance(me,starto,dests);
    while(next_permutation(dests.begin(),dests.end())){
      test = computeDistance(me,starto,dests);
      if(test < shortest){
	shortest = test;
	ans = dests;
      }
    }
    printRoute(starto,ans);
    cout << "and will have length " << shortest << endl;
    return 0;
}

/** @brief This method will compute the distances between the cities. It computes the distances between the starting city, and the cities that are next to one another in the dest vector. Finally it computes the distances between the starting city and the last city in the vector. Then it returns the sum of the distances
 *
 * @param me is the MiddleEarth map that will have all the cities and their coordinates to be able to calcuate the distances of each city
 * @param start is the starting city that will begin finding the distances for until it loops back to the starting city.
 * @param dests is a vector of strings that will show the cities in the itinerary
 * @return float this will return the sum of all the distances between the path of cities.
 */
// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
  float sum = 0;
  sum = sum + me.getDistance(start, dests[0]);
  for(int i = 0; i < dests.size()-1 ; i++){
    sum = sum + me.getDistance(dests[i],dests[i+1]);
  }
  sum = sum + me.getDistance(dests[dests.size()-1],start);
  return sum;
}


/** @brief THis method will print out the route for the destinations within the itinerary. It does this by first printing out the start city and iterates through the remaining cities inside the vector of strings to print out the remaining cities. Lastly, it prints out the first city again to represent the cycle.
 *
 * @param start is the starting city that will be at the beginning and end of the route
 * @param dests is a vector of strings that will show the cities in the itinerary
 */

// This method will print the entire route, starting and ending at the
// 'start' parameter.  The output should be of the form:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute (string start, vector<string> dests) {
    // YOUR CODE HERE
  string ans;
  ans = ans + "Your journey will take you along the path ";
  ans = ans + start + " -> ";
  for(int i = 0; i<dests.size(); i++){
    ans = ans + dests[i] + " -> ";
  }
  ans = ans + start + " ";
  cout << ans;
}
