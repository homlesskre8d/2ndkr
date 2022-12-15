#include "Input.h"
#include "document.h"
using namespace std;
void AdddocumentConsoleInput(vector<shared_ptr<document>>& documentCase)
{
	int Year = 0;
	int Month = 0;
	int Day = 0;
	string decComeFrom = 0;
	string decComeTo = 0;

	cout << "1 - Circle\n2 - Rectangle\n3 - Trapezoid" << endl;
	documentTypes type = static_cast<documentTypes>(CheckMenuItem(1));
	while (true)
	{
		switch (type)
		{
		case documentTypes::decreee:
			cout << "Enter Year." << endl;
			Year = CheckIntValue();

			cout << "Enter Month." << endl;
			Month = CheckIntValue();

			cout << "Enter Day." << endl;
			Day = CheckIntValue();

			cout << "Enter person that make decree." << endl;
			getline(cin, decComeFrom);
			cout << "Enter person that should tske decree ." << endl;
			getline(cin, decComeTo);




			documentCase.emplace_back(make_shared<decree>(decComeFrom, decComeTo,Year, Month, Day));
		
		}
	}
}

void AdddocumentFileInput(vector<shared_ptr<document>>& documentCase)
{
	string fileName = "";
	ifstream file;

	file.exceptions(ifstream::badbit | ifstream::failbit);
	while (true)
	{
		cout << "Enter file name. " << endl << "ENTER : ";
		cin >> fileName;
		try
		{
			file.open(fileName);
			cout << "Sucefull file open " << endl;
		}
		catch (const exception&)
		{
			cout << "Incorrect file name or way.Try again ." << endl;
			continue;

		}

		string decreeMark = "decree";

		int count;
		string typeMark;

		try
		{
			count = CheckLineInt(file);
			for (int i = 0; i < count; i++)
			{
				typeMark = CheckLineString(file);
				if (typeMark == decreeMark)
				{
					documentCase.emplace_back(make_shared<decree>(CheckLineString(file), CheckLineString(file),CheckLineInt(file), CheckLineInt(file), CheckLineInt(file)));
				}
	
			}
		}
		catch (invalid_argument iaex)
		{
			cout << "Incorect data " << endl;
			file.close();
			continue;
		}

		file.close();
		break;
	}

}