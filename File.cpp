#include "File.h"

File::File(){}

void File::writeData(vector<string> data){

	fileWrite.open("DataPlayer.txt");
	if (!fileWrite.fail()) {
		for (int i = 0; i < data.size(); i++)
			fileWrite << data.at(i) << "\n";

		fileWrite.flush();
		fileWrite.close();
	}
}

//vector<string> File::readData(){


//}






//~File::File(){}
