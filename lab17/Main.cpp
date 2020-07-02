#include "First_Inheritor.h"

CEREAL_REGISTER_TYPE(CProgram)
CEREAL_REGISTER_TYPE(CMalware)
CEREAL_REGISTER_POLYMORPHIC_RELATION(CProgram, CMalware)

int ReadConfigurationFile();
void SaveFile(vector<shared_ptr<CProgram>>&);

void SaveXMLFile(vector<shared_ptr<CProgram>>&);
void ReadXMLFile();

void SaveJSONFile(vector<shared_ptr<CProgram>>&);
void ReadJSONFile();

void main()
{
	{
		vector <shared_ptr<CProgram>> Vector;
		
		for (size_t i = 0; i < 4; i++)
		{
			if (i == 0)
				Vector.emplace_back(new CMalware());
			else if (i == 1)
				Vector.emplace_back(new CProgram("Biology", 1989, 367, 234655, 423));
			else if (i == 2)
				Vector.emplace_back(new CMalware("Physics", 1970, 500, 434322, 4231, "Worm"));
			else if (i == 3)
				Vector.emplace_back(new CProgram("Turkmen", 2010, 422, 353535, 645));
		}
		
		cout << "Objects that will be converted to chosen format" << endl;
		for (const auto& object : Vector)
			cout << *object << endl;
		cout << endl;
		
		int serializationType = ReadConfigurationFile();
		if (serializationType == 1)
		{
			SaveJSONFile(Vector);
			ReadJSONFile();
		}
		else if (serializationType == 2)
		{
			SaveXMLFile(Vector);
			ReadXMLFile();
		}
		else
			cout << "Neither JSON nor XML format were in configuration file" << endl;
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

void ReadJSONFile()
{
	ifstream input("JSONObject.json");
	cereal::JSONInputArchive Iarchive(input);
	vector <shared_ptr<CProgram>> vectorAfterJSONReading;
	Iarchive(vectorAfterJSONReading);
	input.close();
	cout << "Objects that were converted from JSON" << endl;
	for (const auto& object : vectorAfterJSONReading)
		cout << *object << endl;
	SaveFile(vectorAfterJSONReading);
}

void SaveFile(vector <shared_ptr<CProgram>>& vec)
{
	int count = 1;
	ofstream fout("Data.txt");
	fout.setf(std::ios::left);
	fout << setw(16) << "Title" << setw(9) << "Year" << setw(13) << "Pages" << setw(10) << "index" << setw(10) << "Type" << "amountOfLines/Chapters" << endl;
	for (const auto& object : vec)
	{
		fout << count << ") ";
		fout << *object;
		fout << endl;
		count++;
	}
	cout << endl << "Writing in file complete " << endl << endl;
	fout.close();
}

void SaveXMLFile(vector <shared_ptr<CProgram>>& vec)
{
	ofstream output("XMLObject.xml");
	cereal::XMLOutputArchive archive(output);
	archive(cereal::make_nvp("Literature", vec));
}

void ReadXMLFile()
{
	ifstream input("XMLObject.xml");
	cereal::XMLInputArchive Iarchive(input);
	vector <shared_ptr<CProgram>> vectorAfterXMLReading;
	Iarchive(vectorAfterXMLReading);
	input.close();
	cout << "Objects that were converted from XML" << endl;
	for (const auto& object : vectorAfterXMLReading)
		cout << *object << endl;
	SaveFile(vectorAfterXMLReading);
}

int ReadConfigurationFile()
{
	int serializationType;
	string data;
	string fileName;
	cout << "Enter configuration file name" << endl;
	cin >> fileName;
	cout << endl;
	ifstream fin(fileName);
	getline(fin, data);
	regex JSONregularExpression("JSON");
	regex XMLregularExpression("XML");
	if (regex_search(data, JSONregularExpression))
		serializationType = 1;
	else if (regex_search(data, XMLregularExpression))
		serializationType = 2;
	else
		serializationType = 0;
	fin.close();
	return serializationType;
}