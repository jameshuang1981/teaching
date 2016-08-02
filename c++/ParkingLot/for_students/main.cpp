//
//  main.cpp
//  Assignment
//
//  Created by yuxiao huang on 7/30/16.
//  Copyright © 2016 yuxiao huang. All rights reserved.
//

#include <iostream>
#include <thread>         // this_thread::sleep_for
#include <chrono>         // chrono::seconds
#include "ParkingLot.h"
#include "Vehicle.h"
using namespace std;

int main(int argc, const char * argv[]) {
    ParkingLot pl(2); //parking lot of size 2
    
    Car car; //Car object
    Bus bus; //Bus object

    //test case 1:
    //car search, output "Search success: find parking lot available from 0 to 0"
    //car occupy, output "Occupy success: parking lot from 0 to 0 occupied"
    cout << "test case 1" << endl;
    int car_start_pos = car.Search(pl); //search for available parking lot from left to right
    car.Occupy(pl, car_start_pos); //occupy the space
    cout << endl;

    //test case 2:
    //bus search, output "Search fail: no parking lot available"
    //bus occupy, output "Occupy fail: array bounds overflow!"
    cout << "test case 2" << endl;
    int bus_start_pos = bus.Search(pl); //search for available parking lot from right to left
    bus.Occupy(pl, bus_start_pos); //occupy the space
    cout << endl;
    
    //test case 3:
    //car free, output "Free success: parking lot from 0 to 0 freed"
    //car free again, output "Free fail: array bounds overflow!"
    cout << "test case 3" << endl;
    car.Free(pl); //free the space
    car.Free(pl); //free the space
    cout << endl;

    //test case 4:
    //bus search, output "Search success: find parking lot available from 0 to 1"
    //bus free, output "Free fail: array bounds overflow!"
    //bus occupy, output "Occupy success: parking lot from 0 to 1 occupied"
    cout << "test case 4" << endl;
    bus_start_pos = bus.Search(pl); //search for available parking lot from right to left
    bus.Free(pl); //free the space
    bus.Occupy(pl, bus_start_pos); //occupy the space
    cout << endl;
    
    //test case 5:
    //car search, output "Search fail: no parking lot available"
    //car occupy, output "Occupy fail: array bounds overflow!"
    cout << "test case 5" << endl;
    car_start_pos = car.Search(pl); //search for available parking lot from left to right
    car.Occupy(pl, car_start_pos); //occupy the space
    cout << endl;

    //test case 6:
    //bus free, output "Free success: parking lot from 0 to 1 freed"
    cout << "test case 6" << endl;
    bus.Free(pl); //free the space
    cout << endl;
    
    //test case 7:
    //car search, output "Search success: find parking lot available from 0 to 0"
    //car occupy, output "Occupy success: parking lot from 0 to 0 occupied"
    //car free, output "Free success: parking lot from 0 to 0 freed"
    cout << "test case 7" << endl;
    car_start_pos = car.Search(pl); //search for available parking lot from left to right
    car.Occupy(pl, car_start_pos); //occupy the space
    car.Free(pl); //free the space
    cout << endl;
    
    //empty the parking lot
    pl.empty();
    
    return 0;
}
