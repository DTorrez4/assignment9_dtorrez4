//generatic array vector template class.
#include <iostream>
using namespace std;
//naming my template
template<typename Tem >

//initilzing my  Generic array class
class Gen_array {

    private:
        Tem* data;
        int current_size;

    public:
        Gen_array() : data(nullptr), current_size(0) {}

        //deconstructor
        ~Gen_array() {
            delete[] data;
        }

        //add the add Elemetn so you can add it to the array
        void Add_Element(Tem param) {
            Tem* new_data = new Tem[current_size + 1];

            for (int i = 0; i < current_size; i++) {
                new_data[i] = data[i];
            }
            new_data[current_size] = param;

            delete[] data;


            data = new_data;
            current_size++;

        }

        //this returns the value in the array at the location param.
        Tem at(int param) const {

            if (param < 0 || param >= current_size) {
                cerr << "Parameter out of range." << endl;
            }
            return data[param];
        }

        //this returns the current size of the array.
        Tem size() const {
            return current_size;
        }

        //returns the sum of the array using a for loop.
        Tem sum() const {
            Tem total = 0;
            for (int i = 0; i < current_size; i++) {
                total += data[i];
            }
            return total;
        }

        //this funtion finds the max of the array.
        Tem max() const {
            //just incase there is no size or elemets of the array.
            if (current_size == 0) {
                cerr << "Nothing to calculate." << endl;
            }

            Tem max = data[0];
            for (int i = 1; i < current_size; i++) {
                if (data[i] > max) {
                    max = data[i];
                }
            }
            return max;
        }
        //this funtion finds the minimuim of the array.
        Tem min() const {
            if (current_size == 0) {
                cerr << "Nothing to calculate." << endl;
            }
            Tem min = data[0];
            for (int i = 1; i < current_size; i++) {
                if (data[i] < min) {
                    min = data[i];
                }
            }
            return min;
        }
        //this
        Tem* slice(int begin , int end){

            if (begin < 0 || end >= current_size || begin > end) {
                cerr << "Parameter out of range." << endl;
            }

            int slice_size = end - begin + 1;
            Tem* sliced_array = new Tem[slice_size];

            for (int i = 0; i < slice_size; ++i) {
                sliced_array[i] = data[begin + i];
            }
            return sliced_array;
        }
};

int main() {

    //calling on the class generic  array
    Gen_array<int> int_array;
    //using add element to put values in the array
    int_array.Add_Element(10);
    int_array.Add_Element(20);
    int_array.Add_Element(30);
    int_array.Add_Element(40);
    int_array.Add_Element(50);

    //this prints out the array that i filled with numbers
    cout << "the array: ";
    for (int i = 0; i < int_array.size(); ++i) {
        cout << int_array.at(i);
        if (i < int_array.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    //prints out what the user need to see like the max min and the sum of the array , size of the array
    cout<<"Size of the array: " << int_array.size()<< endl;
    cout<<"Sum of the array: " << int_array.sum() << endl;
    cout<<"Max of the array: " << int_array.max() << endl;
    cout<<"Min of the array: " << int_array.min() << endl;

    //this is for the slice array.
    int begin_idex = 1;
    int end_index = 3;
    int* sliced_array = int_array.slice(begin_idex, end_index);

    if (sliced_array != nullptr) {
        int sliced_size = end_index - begin_idex + 1;
        cout << "Sliced Array " << begin_idex << " to " << end_index << ": ";
        //this is where i print out the slice array.
        for (int i = 0; i < sliced_size; ++i) {
            cout << sliced_array[i];
            if (i < sliced_size - 1) {
                cout << ", "; // Add comma and space between elements
            }
        }
        cout << "" << endl;

        //deleting the memory i dynamically located.
        delete[] sliced_array;
    }


    return 0;
}