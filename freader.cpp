#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

//check if patameters are valid 
void check_paramaters(string param,string file,string word,int x){
	if(!(param == "-f" || param == "-p")){
		cout << "Error: Wrong parameter" << endl;
		exit(1);}
}
//this function search if given word is in file
void search_word(string file,string word,string text){
	int value;
	string line;
	ifstream wordfile;
	wordfile.open(file);
	if(!wordfile){
		cout << "Could not open " << file << endl;
		wordfile.close();
		exit(1);
	}
	//read all text file to find if given word is in
	while(!wordfile.eof()){
		getline(wordfile,line);
		if((value = line.find(word, 0)) != string::npos){
			cout << "Word '"<< text <<"' already exist" << endl;
			wordfile.close();
			exit(1);
		}
	}
}
//text to ascii code transformation
string string_to_ascii(string word){
	stringstream text;
	for (int i = 0; i < word.size(); i++){
		if((int)tolower(word[i]) < 100){
        		text << "0" << (int)tolower(word[i]);}
		else{
			text << (int)tolower(word[i]);}
	}
	string text_2 = text.str();
	return text_2;
}
//Write to file the given word if its not exist
void write_file(string param,string file,string word){
    	ofstream wordfile;
	string text;
	//call transformation function and pass it as variable
	text = string_to_ascii(word);
	wordfile.open(file,ofstream::app);
	//call search function and 
	//search for given word before write it in file
	search_word(file,text,word);
	for(int i=0;i < word.size(); i++){
		if((int)tolower(word[i]) < 100){
			wordfile << "0" << (int)tolower(word[i]);}
		else{
			wordfile <<(int)tolower(word[i]);}
		}
	wordfile << endl;
	wordfile.close();
}
//This function read file and sort it alphabetical
void sort_file(string file,string word){
	string content;
	fstream wordfile;
	wordfile.open(file,ios::in);
	vector<string> text;
	while(getline(wordfile,content)){
		text.push_back(content);}
	sort(text.begin(), text.end());
	wordfile.close();
	wordfile.clear();
	wordfile.open(file,ios::out);
	for(string &s : text){
		wordfile << s << endl; 
	}
	
}
//print the file <encoded/decoded> 
//and check if option is valid
string print_file(string file,string word){
	string flag;
	string content;
	ifstream wordfile;
	wordfile.open(file);
	//encoded mean that file content is already in ascii
	//so print already encoded text
	if(!wordfile){
		cout << "Could not open " << file << endl;
		wordfile.close();
		exit(1);
	}
	if(word == "encoded"){
		while(!wordfile.eof()){
			getline(wordfile,content);
			cout << content << endl;}
		return flag;
	}
	//decoded mean that, we print the decoded message
	//print it as plain text
	if(word == "decoded"){
		while(!wordfile.eof()){
			getline(wordfile,content);
			int len = content.length();
			int num = 0;
			for(int i=0; i < len; i++){
				num = num * 10 + (content[i] - '0');
				if(num >= 32 && num <= 126){
					char ch = (char)num;
					cout << ch;
					num = 0;}
			}
			cout << endl;
		}
		
		return flag;
	}
	else{
		cout << "Invalid option '" << word <<"' "<< endl;
		wordfile.close();
		exit(1);}
	flag = "done";
	wordfile.close();
	return flag;
}
int main(int argc, char* argv[]){
	int x;
	string param, file, word;
	x = argc;
	//check if arguments are more than 4
	//that means that we dont need less because 
	if(argc < 4) {
		cout << "Not Enough arguments" << endl;
		exit(1);}
	if(((argc-1) % 3) != 0 ){
	cout << "Bad usage!" << endl; 
	exit(1);
	}
	//we check arguments per 3 
	for(int i=1;i < argc-1;++i){
		param = argv[i];
		file = argv[i+1];
		word = argv[i+2];
		i=i+2;
	//call parameter function if parameter is ok.
	check_paramaters(param,file,word,x);
	if(param == "-f"){	
		write_file(param,file,word);
		sort_file(file,word);
		}
	if(param == "-p"){
		print_file(file,word);
	}
	}
	return 0;
}

