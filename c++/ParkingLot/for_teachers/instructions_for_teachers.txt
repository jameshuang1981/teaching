
This is the assignment for presentation “Introduction to Inheritance in C++”, given by Yuxiao Huang at Northeastern University (during a job interview).

In this assignment students will be asked to design a toy parking lot in C++.

Specifically, students should implement “Vehicle.h” and “Vehicle.cpp”, given “ParkingLot.h”, “ParkingLot.cpp” and “main.cpp”. This should take them less than 3 hours to finish.

The goal is to reinforce their understanding of Inheritance and (pure) virtual function discussed in the presentation. This is the reason why “Vehicle.h” and “Vehicle.cpp” are hidden.

Please note that the students are supposed to use Inheritance (by making Vehicle a base class and Car / Bus derived class) to handle the similarities between Car and Bus. They should also use (pure) virtual function (by making the search function (pure) virtual) to address the differences between the two.

Here are some hints given to the students in “readme_for_students.txt”.
1. The parking lot has only one line (as shown in “ParkingLot.h”).

2. The parking lot allows two kinds of Vehicle, Car and Bus (as shown in “main.cpp”).

3. A Vehicle has 3 activities, search for available space, occupy the space, and free the space (as shown in “main.cpp”). Use functions in “ParkingLot.h” to implement these activities. 

4. A Car searches for available space from left to right in the parking lot, while a Bus does this from right to left.

5. A Car takes 1 space while a Bus takes 2.

6. Before implementing “Vehicle.h” and “Vehicle.cpp”,
6.1 read “main.cpp” to see the test cases and their expected output;
6.2 think about why “Vehicle.h” is hidden;
6.3 think about the similarities and differences between Car and Bus; what method we learnt from the presentation can be used to implement them.

Please feel free to contact me if there are any questions.
Email: jameshuang1981@gmail.com

Thanks!

Yuxiao Huang

Last updated
08/02/2016

