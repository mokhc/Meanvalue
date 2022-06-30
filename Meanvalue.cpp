//@mokhc
// Meanvalue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// program to demonstrates the mean value used in financial calculation
//header
#include <iostream>
#include <valarray>

//namespace
using namespace std;

//class to get input and calculate the mean value
class CalMeanVal {
//access modifier
public:
    //variables
    valarray<double> input;
    valarray<double> inputsubsum;
    valarray<double> iss_sq;
    valarray<double> iss_sq_sub_in;
    int sizeofarray;
    double totalinput, meanval;

    //constructor
    CalMeanVal() {

    }

    //constructor with parameter
    CalMeanVal(valarray<double> input) {
        //assignment
        this->input = input;
        this->sizeofarray = input.size();
        //calculate the mean value
        for (int a = 0; a < sizeofarray; a++) {
            totalinput = totalinput + input[a];
        }
        inputsubsum.resize(sizeofarray);
        for (int a = 0; a < sizeofarray; a++) {
            inputsubsum[a] = input[a] - totalinput;
        }
        iss_sq.resize(sizeofarray);
        for (int a = 0; a < sizeofarray; a++) {
            iss_sq[a] = pow(inputsubsum[a],2);
        }
        iss_sq_sub_in.resize(sizeofarray);
        for (int a = 0; a < sizeofarray; a++) {
            iss_sq_sub_in[a] = iss_sq[a] - input[a];
        }
        for (int a = 0; a < sizeofarray; a++) {
            meanval = (meanval + (iss_sq[a] - iss_sq_sub_in[a])/sizeofarray);
        }
    }

    //method to calculate mean value
    void CalMeanValMethod(valarray<double> input) {
        //assignment
        this->input = input;
        this->sizeofarray = input.size();
        //calculate the mean value
        for (int a = 0; a < sizeofarray; a++) {
            totalinput = totalinput + input[a];
        }
        inputsubsum.resize(sizeofarray);
        for (int a = 0; a < sizeofarray; a++) {
            inputsubsum[a] = input[a] - totalinput;
        }
        iss_sq.resize(sizeofarray);
        for (int a = 0; a < sizeofarray; a++) {
            iss_sq[a] = pow(inputsubsum[a], 2);
        }
        iss_sq_sub_in.resize(sizeofarray);
        for (int a = 0; a < sizeofarray; a++) {
            iss_sq_sub_in[a] = iss_sq[a] - input[a];
        }
        for (int a = 0; a < sizeofarray; a++) {
            meanval = (meanval + (iss_sq[a] - iss_sq_sub_in[a]) / sizeofarray);
        }
    }

    //method to get mean value
    void GetMeanVal(){
        cout << "The mean value is :" << meanval << endl;
    }
};

int main()
{
    //declaration and assignment
    valarray<double> input = { 1,2,3,4,5,6,7 };
    //declaration
    CalMeanVal cmv1;
    //assignment
    cmv1 = CalMeanVal(input);
    //calling the method
    cmv1.GetMeanVal();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
