//
//  ParkingLot.cpp
//  Assignment
//
//  Created by yuxiao huang on 7/30/16.
//  Copyright © 2016 yuxiao huang. All rights reserved.
//
#include <iostream>
#include "ParkingLot.h"
using namespace std;

ParkingLot::ParkingLot(int array_size) {
    this->array_size = array_size;
    array = new int[array_size];
    for (int i = 0; i < array_size; i++) { //initialize the array with 0
        array[i] = 0;
    }
}

//search for available parking lot (of vehicle_size) from left to right
//if find, return the start position
//otherwise, return -1
int ParkingLot::SearchFromLeft(int vehicle_size) {
    for (int i = 0; i <= array_size - vehicle_size; i++) {
        int j = i;
        for (; j < i + vehicle_size; j++) {
            if (array[j] != 0) {
                break;
            }
        }
        if (j >= i + vehicle_size) {
            cout << "Search success: find parking lot available from " << i << " to " << i + vehicle_size - 1 << endl;
            return i; //return the start position
        }
    }
    cout << "Search fail: no parking lot available" << endl;
    return -1;
}

//search for available parking lot (of vehicle_size) from right to left
//if find, return the start position
//otherwise, return -1
int ParkingLot::SearchFromRight(int vehicle_size) {
    for (int i = array_size - 1; i >= vehicle_size - 1; i--) {
        int j = i;
        for (; j > i - vehicle_size; j--) {
            if (array[j] != 0) {
                break;
            }
        }
        if (j <= i - vehicle_size) {
            cout << "Search success: find parking lot available from " << i - vehicle_size + 1 << " to " << i << endl;
            return i - vehicle_size + 1; //return the start position
        }
    }
    cout << "Search fail: no parking lot available" << endl;
    return -1;
}

//occupy parking lot in [start_pos, start_pos + vehicle_size) by assigning the corresponding value in array to 1
//if can occupy, return true
//otherwise, return false
bool ParkingLot::Occupy(int start_pos, int vehicle_size) {
    //get the end position
    int end_pos = start_pos + vehicle_size - 1;
    
    //check array bounds overflow
    if (start_pos < 0 || start_pos >= array_size || end_pos < 0 || end_pos >= array_size) {
        cout << "Occupy fail: array bounds overflow!" << endl;
        return false;
    }
    
    //occupy parking lot
    for (int i = start_pos; i < start_pos + vehicle_size; i++) {
        array[i] = 1;
    }
    
    cout << "Occupy success: parking lot from " << start_pos << " to " << start_pos + vehicle_size - 1 << " occupied" << endl;
    return true;
}

//free parking lot in [start_pos, start_pos + vehicle_size) by assigning the corresponding value in array to 0
//if can occupy, return true
//otherwise, return false
bool ParkingLot::Free(int start_pos, int vehicle_size) {
    //get the end position
    int end_pos = start_pos + vehicle_size - 1;
    
    //check array bounds overflow
    if (start_pos < 0 || start_pos >= array_size || end_pos < 0 || end_pos >= array_size) {
        cout << "Free fail: array bounds overflow!" << endl;
        return false;
    }
    
    //free parking lot
    for (int i = start_pos; i < start_pos + vehicle_size; i++) {
        array[i] = 0;
    }
    
    cout << "Free success: parking lot from " << start_pos << " to " << start_pos + vehicle_size - 1 << " freed" << endl;
    return true;
}

//empty the parking lot
void ParkingLot::empty() {
    delete [] array;
}
