//
//  ParkingLot.h
//  Assignment
//
//  Created by yuxiao huang on 8/1/16.
//  Copyright © 2016 yuxiao huang. All rights reserved.
//

#ifndef ParkingLot_h
#define ParkingLot_h

class ParkingLot {
    int* array; //the parking lot
    int array_size; //the size of the parking lot
    
public:
    //constructor
    ParkingLot(int array_size);
        
    //search for available parking lot (of vehicle_size) from left to right
    //if find, return the start position
    //otherwise, return -1
    int SearchFromLeft(int vehicle_size);
    
    //search for available parking lot (of vehicle_size) from right to left
    //if find, return the start position
    //otherwise, return -1
    int SearchFromRight(int vehicle_size);
    
    //occupy parking lot in [start_pos, start_pos + vehicle_size) by assigning the corresponding value in array to 1
    //if can occupy, return true
    //otherwise, return false
    bool Occupy(int start_pos, int vehicle_size);
    
    //free parking lot in [start_pos, start_pos + vehicle_size) by assigning the corresponding value in array to 0
    //if can occupy, return true
    //otherwise, return false
    bool Free(int start_pos, int vehicle_size);
    
    //empty the parking lot
    void empty();
};

#endif /* ParkingLot_h */
