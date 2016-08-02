//
//  Vehicle.cpp
//  Assignment
//
//  Created by yuxiao huang on 7/31/16.
//  Copyright © 2016 yuxiao huang. All rights reserved.
//

#include "Vehicle.h"
#include "ParkingLot.h"

//occupy parking lot in [start_pos, start_pos + size)
void Vehicle::Occupy(ParkingLot pl, int start_pos) {
    if (pl.Occupy(start_pos, size)) {
        this->start_pos = start_pos;
    }
}
    
//free parking lot in [start_pos, start_pos + size)
void Vehicle::Free (ParkingLot pl) {
    if (pl.Free(start_pos, size)) {
        this->start_pos = -1;
    }
}

Car::Car () {
    size = 1;
}
    
//implementation of the pure virtual function in Vehicle class
int Car::Search(ParkingLot pl) {
    //a car searches for available parking lot from left to right
    return pl.SearchFromLeft(size);
}

Bus::Bus () {
    size = 2;
}
    
//implementation of the pure virtual function in Vehicle class
int Bus::Search(ParkingLot pl) {
    //a bus searches for available parking lot from right to left
    return pl.SearchFromRight(size);
}
