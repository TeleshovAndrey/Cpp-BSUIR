#include "main.h"



int main()
{
	string txtName ("in.txt");
	string binName ("in.bin");

	Clock clock1(0, 0 , "iron", "sumsung", Time(20,10,5));
	Clock clock2(0, 0, "plastic" , "versachy", Time(22,10,0));
	Clock clock3(0,0, "gold", "google", Time(13,0,0));

	TTree<Clock>* tree = new TTree<Clock>();

	tree->push(clock1);
	tree->push(clock2);
	tree->push(clock3);

	writeToTextFile(tree, txtName);
	writeToBin(tree, binName);

	TTree<Clock>* treeNew =new TTree<Clock>();
	//readFromTextFile(treeNew, txtName);

	readFromBinFile(treeNew, binName);

	delete tree;
	delete treeNew;

	


}