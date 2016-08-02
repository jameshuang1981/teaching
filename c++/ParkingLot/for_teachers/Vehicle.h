//
//  Vehicle.h
//  Assignment
//
//  Created by yuxiao huang on 8/1/16.
//  Copyright © 2016 yuxiao huang. All rights reserved.
//

#ifndef Vehicle_h
#define Vehicle_h

#include "ParkingLot.h"

//Vehicle class
class Vehicle {
protected:
    int size; //size of the vehicle
    int start_pos = -1; //the vehicle occupies parking lot, if they are available, in [start_pos, start_pos + size)
    
public:
    //pure virtual function, search for available parking lot and return the start position
    virtual int Search(ParkingLot pl) = 0;
    
    //occupy parking lot in [start_pos, start_pos + size)
    void Occupy(ParkingLot pl, int start_pos);
    
    //free parking lot in [start_pos, start_pos + size)
    void Free (ParkingLot pl);
};

//Car class, derived from Vehicle class
class Car : public Vehicle {
public:
    //constructor
    Car();
    
    //implementation of the pure virtual function in Vehicle class
    int Search(ParkingLot pl);
};

//Bus class, derived from Vehicle class
class Bus : public Vehicle {
public:
    //constructor
    Bus();
    
    //implementation of the pure virtual function in Vehicle class
    int Search(ParkingLot pl);
};

#endif /* Vehicle_h */
