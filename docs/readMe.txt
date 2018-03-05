Sawaiba Sial
0990358

Traffic Simulator

This program uses a doubly linked list to simulate vehicles going through a traffic signal. It parses data from an input file that contains information about the car’s direction prior to its arrival (N,E,S,W), the direction that the car will proceed through the intersection (forward, left, right) and the time in seconds that the vehicle reaches the intersection. The program determines which cars proceed or wait following basic traffic laws and implements a simulation clock to compute the time it takes for each car to complete its turn. After execution, an ouput table containing information about the vehicle, intersection arrival time and completed time will be displayed on the scree.


To run the carMain.c enter the following commands: (contains the actual trafic simulation)
    make main
    cd bin
    ./runMe data.txt

To run the testMain.c enter the following commands: (contains custom test cases for the linked list API)
    make test
    cd bin
    ./runMe
