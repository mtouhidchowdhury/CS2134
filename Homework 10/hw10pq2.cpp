#define CATCH_CONFIG_MAIN

#include <unordered_map>
#include <list>
#include <vector>
#include "catch.hpp"
using namespace std;


SCENARIO("Checking for adjacency") {
	GIVEN("Some subways with adjacency are tested") {
		unordered_map < string, list<string>> adjList;
		WHEN("The container has been populated") {

			/*
			//INSERT FUNCTIONS THAT POPULATE THE UNORDERED MAP HERE
			*/

			//checking if stop 125 is there
			unordered_map < string, list<string>> ::iterator adjListItr = adjList.find("125");
			THEN("125 is a stop in the container ") {
				//make sure find returns a true
				REQUIRE(adjListItr != adjList.end());
			}
			THEN("The adjacency list of stop 125 is correctly stored") {
				//go through and check all of adjacency list of station 125 
				vector<string> adjVec;
				//putting all the adjacent stops in a vector so that the order in which they were inserted into the map doesn't matter
				for (list<string>::iterator litr = adjListItr->second.begin(); litr != adjListItr->second.end(); litr++) {
					adjVec.push_back(*litr);
				}

				//Checking to see if stops 124, A24, and 126 are there 
				bool stop124 = false;
				bool stopA24 = false;
				bool stop126 = false;
				for (int i = 0; i < adjVec.size(); i++) {
					if (adjVec[i] == "124") stop124 = true;
					else if (adjVec[i] == "A24") stopA24 = true;
					else if (adjVec[i] == "126") stop126 = true;
				}
				REQUIRE(stop124);
				REQUIRE(stopA24);
				REQUIRE(stop126);

			}

			//checking if stop B16 is there
			unordered_map < string, list<string>> ::iterator adjListItr2 = adjList.find("B16");
			THEN("B16 is a stop in the container ") {
				//make sure find returns a true
				REQUIRE(adjListItr2 != adjList.end());
			}
			THEN("The adjacency list of stop B16 is correctly stored") {
				//go through and check all of adjacency list of station 125 
				vector<string> adjVec;
				//putting all the adjacent stops in a vector so that the order in which they were inserted into the map doesn't matter
				for (list<string>::iterator litr = adjListItr2->second.begin(); litr != adjListItr2->second.end(); litr++) {
					adjVec.push_back(*litr);
				}

				//Checking to see if stops B15, N04 and B17 are there 
				bool stopB15 = false;
				bool stopN04 = false;
				bool stopB17 = false;
				for (int i = 0; i < adjVec.size(); i++) {
					if (adjVec[i] == "B15") stopB15 = true;
					else if (adjVec[i] == "N04") stopN04 = true;
					else if (adjVec[i] == "B17")stopB17 = true;
				}
				REQUIRE(stopB15);
				REQUIRE(stopN04);
				REQUIRE(stopB17);

			}
		}
	}
}
