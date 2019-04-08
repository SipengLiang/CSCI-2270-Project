#include <iostream>
#include <fstream>

using namespace std;

int insertIntoSortedArray(int myArray[], int numEntries, int newValue);

int main(int argc, char *argv[]){

  if(argc != 2){
    cout << "Incorrect number of arguments" << endl;
    return 0;
  }
  
  int arr[100];
  int arrsize = 0;
  int newValue;
  string number;
  
  ifstream inStream(argv[1]);
  
  if(inStream.is_open()){
    while (getline(inStream, number)){
      newValue = stoi(number);
      arrsize = insertIntoSortedArray(arr, arrsize, newValue);
      for(int i = 0; i < arrsize; i++){
	if(i == (arrsize - 1)){
	  cout << arr[i] << endl;
	}
	else{
	  cout << arr[i] << ",";
	}
      }
    }
  }
  else{
    cout << "Failed to open the file." << endl;
    inStream.close();
    return 0;
  }
  
  inStream.close();
  
  return 0;
}

int insertIntoSortedArray(int myArray[], int numEntries, int newValue){
  
  if(numEntries == 0) {
    myArray[0] = newValue;
    return numEntries + 1;
  }
  
  for(int j = 0; j < numEntries; j++) {
    if(newValue >= myArray[j] && (j + 1) == numEntries){
      myArray[j + 1] = newValue;
      return numEntries + 1;
    }
    else if (newValue >= myArray[j] && newValue < myArray[j + 1]){
      for(int k = numEntries; k > j + 1; k--){
	myArray[k] = myArray[k - 1];
      }
      myArray[j + 1] = newValue;
      return numEntries + 1;
    }
    else if (newValue <= myArray[j] && j == 0) {
      for(int l = numEntries; l >= j + 1; l--){
	myArray[l] = myArray[l - 1];
      }
      myArray[j] = newValue;
      return numEntries + 1;
    }
  }
  
  return numEntries + 1;
}
