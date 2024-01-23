#include "main.h"

void tokenize(string const& str, const char delim, vector<string>& out)
{
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}

void writeTextFileRec(TNode<Clock>* node, ofstream& inFile)
{
	if (node != nullptr)
	{
		Clock buffer = node->data;
		string body(buffer.getBody());
		string brand(buffer.getBrand());
		inFile << body << "\t" << brand << "\t" << endl;
		writeTextFileRec(node->left, inFile);
		writeTextFileRec(node->right, inFile);
	}
}

void writeToTextFile(TTree<Clock>* tree, const std::string& filename) {
	ofstream inFile;
	inFile.open(filename);

	if (!inFile.is_open()) {
		cout << "Error writing to text file!" << endl;
		return;
	}

	writeTextFileRec(tree->getHead(), inFile);

	inFile.close();
}



void readFromTextFile(TTree<Clock>* tree, const std::string& filename) {

	std::string line;

	ifstream in;
	in.open(filename);
	if (in.is_open())
	{
		while (std::getline(in, line))
		{
			vector<string> lineOut;
			tokenize(line, '\t', lineOut);
			string body = lineOut[0];
			string brand = lineOut[1];
			Clock newClock(0, 0, body.c_str(), brand.c_str(), Time());
			tree->push(newClock);
		}
	}
	in.close();
}

void writeBinRec(TNode<Clock>* node, ofstream& inFile)
{
	if (node != nullptr) 
	{
		Clock& clock = node->data;
		inFile.write(reinterpret_cast<const char*>(&clock), sizeof(Clock));
		writeBinRec(node->left, inFile);
		writeBinRec(node->right, inFile);
	}
}

void writeToBin(TTree<Clock>* tree, const string& filename) {
	ofstream inFile(filename, ios::out | ios::trunc | ios::binary);

	if (!inFile.is_open()) {
		cout << "Error writing to text file!" << endl;
		return;
	}

	writeBinRec(tree->getHead(), inFile);
	inFile.close();
}



void readFromBinFile(TTree<Clock>* tree, const std::string& filename) {
	std::ifstream fromFile(filename);
	if (!fromFile.is_open()) {
		cout << "Error writing to text file!" << endl;
		return;
	}

	Clock clock;

	if (fromFile.is_open()) {
		while (fromFile.read(reinterpret_cast<char*>(&clock), sizeof(clock))) {
			tree->push(clock);
		}
	}
	fromFile.close();
}
