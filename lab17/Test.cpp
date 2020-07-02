#include "CMalware.h"
void SaveJSONFile(vector <shared_ptr<CProgram>>& vec);
void testJSON(vector <shared_ptr<CProgram>>& vec);
void SaveXMLFile(vector <shared_ptr<CProgram>>& vec);
void testXML(vector <shared_ptr<CProgram>>& vec);

CEREAL_REGISTER_TYPE(CProgram)

CEREAL_REGISTER_TYPE(CMalware)

CEREAL_REGISTER_POLYMORPHIC_RELATION(CProgram, CMalware)

void main()
{
	{
		vector <shared_ptr<CProgram>> Vector;
		for (size_t i = 0; i < 4; i++)
		{
			if (i == 0)
				Vector.emplace_back(new CMalware());
			else if (i == 1)
				Vector.emplace_back(new CProgram("Biology", 1989, 367, 234655, 'e'));
			else if (i == 2)
				Vector.emplace_back(new CMalware("Physics", 1970, 500, 434322, 'p', "https://royallib.com/book/897120"));
			else if (i == 3)
				Vector.emplace_back(new CProgram("Turkmen", 2010, 422, 353535, 'p'));
		}
		/*cout << "Objects that will be converted to JSON" << endl;
		for (const auto& object : Vector)
			cout << *object << endl;
		cout << endl;*/
		SaveJSONFile(Vector);
		testJSON(Vector);
		SaveXMLFile(Vector);
		testXML(Vector);
	}
	if (_CrtDumpMemoryLeaks())
		cout << "WARNING! Memory leak!" << endl;
	else
		cout << "There is no memory leak" << endl;
}

void SaveJSONFile(vector <shared_ptr<CProgram>>& vec)
{
	ofstream output("JSONObject.json");
	cereal::JSONOutputArchive archive(output);
	archive(cereal::make_nvp("Literature", vec));
}

void testJSON(vector <shared_ptr<CProgram>>& vec)
{
	ifstream input("JSONObject.json");
	cereal::JSONInputArchive Iarchive(input);
	vector <shared_ptr<CProgram>> vectorAfterJSONReading;
	Iarchive(vectorAfterJSONReading);
	input.close();
	/*cout << "Objects that were converted from JSON" << endl;
	for (const auto& object : vectorAfterJSONReading)
		cout << *object << endl;*/
	stringstream ss1;
	stringstream ss2;
	bool test = true;
	for (size_t i = 0; i < vec.size(); i++)
	{
		ss1 = vec[i]->getStr();
		ss2 = vectorAfterJSONReading[i]->getStr();
		if (ss1.str() != ss2.str())
			test = false;
	}
	if (test)
		cout << "JSON write and read test successful" << endl << endl;
	else
		cout << endl << "JSON write and read test failed" << endl << endl;
}

void SaveXMLFile(vector <shared_ptr<CProgram>>& vec)
{
	ofstream output("XMLObject.xml");
	cereal::XMLOutputArchive archive(output);
	archive(cereal::make_nvp("Literature", vec));
}

void testXML(vector <shared_ptr<CProgram>>& vec)
{
	ifstream input("XMLObject.xml");
	cereal::XMLInputArchive Iarchive(input);
	vector <shared_ptr<CProgram>> vectorAfterXMLReading;
	Iarchive(vectorAfterXMLReading);
	input.close();
	stringstream ss1;
	stringstream ss2;
	bool test = true;
	for (size_t i = 0; i < vec.size(); i++)
	{
		ss1 = vec[i]->getStr();
		ss2 = vectorAfterXMLReading[i]->getStr();
		if (ss1.str() != ss2.str())
			test = false;
	}
	if (test)
		cout << "XML write and read test successful" << endl << endl;
	else
		cout << endl << "XML write and read test failed" << endl << endl;
}