#include <iostream>
#include <stdexcept>

template <typename T>
class GenericArray {
	private:
		T* data;
		int length;


	public:
		GenericArray() : data(nullptr), length(0) {}
		~GenericArray() {
			delete[] data;
		}


	void addElement(T value) {
		T* new_data = new T[length +1];
			for(int i=0; i<length; ++i) {
				new_data[i] = data[i];
			}
			new_data[length] = value;
			delete[] data;
			data = new_data;
			++length;
	}


	T at(int index) const {
		if(index<0 || index>= length) {
			throw std::out_of_range("Index is out of bounds!");
		}
		return data[index];
	}


	T sum() const {
		if(length == 0) throw std::runtime_error("Array is empty!");
		T total = 0;
			for(int i=0; i<length; ++i) {
				total += data[i];
			}
		return total;
	}


	T max() const {
		if(length == 0) throw std::runtime_error("Array is empty!");
		T max_value = data[0];
			for(int i=1; i<length; i++) {
				if(data[i] > max_value) {
					max_value = data[i];
				}
			}
		return max_value;
	}




	T min() const {
		if(length == 0) throw std::runtime_error("Array is empty!");
		T min_value = data[0];
			for(int i=1; i<length; ++i) {
				if(data[i] < min_value) {
					min_value = data[i];
				}
			}
		return min_value;
	}


	T*slice(int begin, int end) const {
		if(begin<0 || end>=length || begin>end) {
			throw std::out_of_range(" Invalide Range of Slice!");
		}
		int new_size = end - begin + 1;
		T* sliced_array = new T[new_size];
			for(int i=0; i< new_size; ++i) {
				sliced_array[i] = data[begin +i];
			}
		return sliced_array;
	}



	int size() const {
    	return length;
	}

};




int main() {
	GenericArray<int> int_array;

	int_array.addElement(0);
	int_array.addElement(2);
	int_array.addElement(4);
	int_array.addElement(6);
	int_array.addElement(8);
	int_array.addElement(10);
	int_array.addElement(12);

	
	std::cout<<"The size of array: \n " <<int_array.size() <<std::endl;
	std::cout<<"The sum of the  array: \n" <<int_array.sum() <<std::endl;
	std::cout<<"The maximum and mumimum of the array: \n" <<int_array.max()<<", " <<int_array.min() <<std::endl;


	try {
		int* sliced_array = int_array.slice(2,4);
		std::cout<<"Sliced array: ";
			for(int i=0; i<= 4-2; ++i) {
				std::cout<<sliced_array[i] <<" ";
			}

		std::cout<< std::endl;
		delete[] sliced_array;
	}
	catch(std::exception& e) {
		std::cout<<"Error: " <<e.what() <<std::endl;
	}

	return 0;
}







