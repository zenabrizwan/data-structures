#include<iostream>
#include<fstream>
#include<string>



using namespace std;
class SearchEngine;

class BSTNode
{
	string keyword; //key of the tree node
	//list<string> URLs;
	BSTNode* left;
	BSTNode* right;
	friend class SearchEngine;
};

class SearchEngine
{
	BSTNode* root;



	void insert(BSTNode*& t, string val)
	{
		if (t == 0)
		{
			t = new BSTNode;
			t->keyword = val;
			t->left = nullptr;
			t->right = nullptr;
		}
		else if (val < t->keyword)
		{
			insert(t->left, val);
		}
		else if (val > t->keyword)
		{
			insert(t->right, val);
		}
	}
	void inOrder(BSTNode* t)
	{
		if (t != 0)
		{
			inOrder(t->left);
			cout << t->keyword << " ";
			inOrder(t->right);
		}
	}
public:

	bool search(string val)
	{
		BSTNode* t = root;
		while (t != 0)
		{
			if (t->keyword == val)
			{
				cout << val << " exists...!\n";
				return true;
			}
			else if (val < t->keyword)
				t = t->left;
			else
				t = t->right;
		}
		cout << val << " does not exist...!\n";
		return false;
	}


	bool Delete(string key)
	{
		BSTNode* curr = root, * parent = 0;
		while (curr != 0 && curr->keyword != key)
		{
			parent = curr;
			if (key < curr->keyword)
				curr = curr->left;
			else
				curr = curr->right;
		}
		if (curr == 0)
			return false;
		else
		{
			if (curr->left != 0 && curr->right != 0)
			{
				BSTNode* l = curr->left, * pl = curr;
				while (l->right != 0)
				{
					pl = l;
					l = l->right;
				}
				curr->keyword = l->keyword;
				curr = l;
				parent = pl;
			}
			BSTNode* child;
			if (curr->left != 0)
			{
				child = curr->left;
			}
			else
			{
				child = curr->right;
			}
			if (curr == root)
			{
				root = child;
			}
			else
			{
				if (curr == parent->left)
					parent->left = child;
				else
					parent->right = child;
			}
			delete curr;
			curr = 0;
			return true;
		}
	}

	void inOrder()
	{
		inOrder(root);
	}

	SearchEngine()
	{
		root = nullptr;
	}
	~SearchEngine()
	{}

	void insert(string val)
	{
		insert(root, val);
	}



};


string Token(string& s, SearchEngine& obj) {
	char str[200] = &s;
	char* token;
	char* rest = str;

	while ((token = strtok(rest, " ")))
		cout << token;
}
int main()
{
	SearchEngine SS;


	string filename;
	string str[200];
	int i = 0;
	int size = 0;
	double timetaken;
	string word;
	int j = 0;
	string* point;
	string url[200];
	string sentences[200];
	string str[200];
	string words[200];
	string line;
	cout << " file name" << endl;
	cin >> filename;


	ifstream infile;
	infile.open("data.txt", ios::out);

	if (infile.is_open());

	double t;

	if (!infile) {
		cout << "The file is not loaded" << endl;

	}
	else {
		while (!infile.eof()) {
			getline(infile, line);
			str[i] = line;
			i++;
			size++;
		}
	}
	cout << "file successfully loaded " << endl << endl;

	cout << "please enter the word to search " << endl;
	cin >> word;



	string* array;
	array = new string[10000];
	for (int j = 1; j <= size; j++) {

		sentences[i] = str[i];
		Token(sentences[i], SS);
		i++;

	}




	SS.search(word);
	int result;
	if (result == 1) {
		SS.Delete("life");
	}




	system("pause");
	return 0;
}