#include "malware.h"
#include "Functor.h"

void VectorTest();
void ListTest();
void MapTest();
void SetTest();

vector <shared_ptr<CProgram>> CombineVectors(vector<shared_ptr<CProgram>>&, vector <shared_ptr<CProgram>>&);
map <int, shared_ptr<CProgram>> CombineMaps(map<int, shared_ptr<CProgram>>&, map<int, shared_ptr<CProgram>>&);

int main()
{
    setlocale(LC_ALL, "Rus");

    VectorTest();
    ListTest();
    MapTest();
    SetTest();
    
    if (_CrtDumpMemoryLeaks())
        cout << "\nЕсть утечка памяти.\n";
    else 
        cout << "\nУтечка памяти отсутствует.\n";

    return 0;
}
void VectorTest()
{
    cout << "Vector" << endl;
    vector <shared_ptr<CProgram>> vector;
    std::vector <shared_ptr<CProgram>> vectorMerge;
    std::vector<shared_ptr<CProgram>>::const_iterator it;
    Functor funct(1);
    stringstream line;
    string data;
    int vectorSize;
    int value, result = 0, sum = 0;
    int i = 0;

    for (size_t i = 0; i < 4; i++)
    {
        if (i == 0)
            vector.emplace_back(new CProgram());
        else if (i == 1)
            vector.emplace_back(new CMalware(1, 8800, 555, 35, 35634, "BestMalware", "Exploit"));
        else if (i == 2)
            vector.emplace_back(new CProgram(0, 423, 523, 654, 53453, "Calculator"));
        else if (i == 3)
            vector.emplace_back(new CMalware(0, 345, 789, 423, 67456, "MoneyStealer", "Rootkit"));
    }
    
    vectorSize = vector.size();
    vector.emplace_back(new CMalware());
    if(vectorSize != vector.size())
        cout << "Тест добавления элемента\tвыполнен успешно.\n";
    else
        cout << "Тест добавления элемента\tне выполнен успешно.\n";

    it = vector.begin();
    advance(it, 2);
    vector.erase(it);
    if (vectorSize == vector.size())
        cout << "Тест удаления элемента\t\tвыполнен успешно.\n";
    else
        cout << "Тест удаления элемента\t\tне выполнен успешно.\n";

    line = vector[0]->getStr();
    data = line.str();
    if (data == "Basic 65 0 0 0 0")
        cout << "Тест получения элемента\t\tвыполнен успешно.\n";
    else
        cout << "Тест получения элемента\t\tне выполнен успешно.\n";

    it = vector.begin();
    data = "false";
    while (i < vector.size())
    {
        result = (*it)->countElement(6, data);
        i++;
        it++;
        sum += result;
    }
    if (sum == 3)
        cout << "Тест подсчёта элементов\t\tвыполнен успешно.\n";
    else
        cout << "Тест подсчёта элементов\t\tне выполнен успешно.\n";

    sort(vector.begin(), vector.end(), funct);
    line = vector[0]->getStr();
    data = line.str();
    if(data == "Basic 65 0 0 0 0")
        cout << "Тест сортировки вектора\t\tвыполнен успешно.\n";
    else
        cout << "Тест сортировки вектора\t\tне выполнен успешно.\n";

    vectorSize = vector.size();
    vectorMerge = vector;
    vector = CombineVectors(vector, vectorMerge);
    if (vector.size() != vectorSize && vector.size() == (vectorSize + vectorMerge.size()))
        cout << "Тест слияния векторов\t\tвыполнен успешно.\n";
    else
        cout << "Тест слияния векторов\t\tне выполнен успешно.\n";

}
void ListTest()
{
    cout << endl << "List" << endl;
    list <shared_ptr<CProgram>> list;
    std::list<shared_ptr<CProgram>>::const_iterator it;
    Functor funct(1);
    int listSize;
    int value, sum = 0, result = 0;
    int i = 0;
    stringstream line;
    string data;

    for (size_t i = 0; i < 4; i++)
    {
        if (i == 0)
            list.emplace_back(new CProgram());
        else if (i == 1)
            list.emplace_back(new CMalware(1, 8800, 555, 35, 35634, "BestMalware", "Exploit"));
        else if (i == 2)
            list.emplace_back(new CProgram(0, 423, 523, 654, 53453, "Calculator"));
        else if (i == 3)
            list.emplace_back(new CMalware(0, 345, 789, 423, 67456, "MoneyStealer", "Rootkit"));
    }
    
    listSize = list.size();
    list.emplace_back(new CMalware());
    if (listSize < list.size())
        cout << "Тест добавления элемента\tвыполнен успешно.\n";
    else
        cout << "Тест добавления элемента\tне выполнен успешно.\n";

    it = list.begin();
    list.erase(it);
    if (list.size() == listSize)
        cout << "Тест удаления элемента\t\tвыполнен успешно.\n";
    else
        cout << "Тест удаления элемента\t\tне выполнен успешно.\n";

    it = list.begin();
    line = (*it)->getStr();
    data = line.str();
    if(data == "BestMalware 35634 8800 555 35 1 Exploit")
        cout << "Тест получения элемента\t\tвыполнен успешно.\n";
    else
        cout << "Тест получения элемента\t\tне выполнен успешно.\n";

    it = list.begin();
    data = "false";
    while (i < list.size())
    {
        result = (*it)->countElement(6, data);
        i++;
        it++;
        sum += result;
    }
    if (sum == 3)
        cout << "Тест подсчёта элементов\t\tвыполнен успешно.\n";
    else
        cout << "Тест подсчёта элементов\t\tне выполнен успешно.\n";

    list.sort(funct);
    it = list.begin();
    line = (*it)->getStr();
    data = line.str();
    if (data == "Basic 65 0 0 0 0 Exploit")
        cout << "Тест сортировки вектора\t\tвыполнен успешно.\n";
    else
        cout << "Тест сортировки вектора\t\tне выполнен успешно.\n";

}
void SetTest()
{
    cout << endl << "Set" << endl;
    set <shared_ptr<CProgram>> set;
    std::set<shared_ptr<CProgram>>::const_iterator it;
    Functor funct(1);
    stringstream line;
    string data;
    int setSize, sum = 0, i = 0;
    int value;
    
    for (size_t i = 0; i < 4; i++)
    {
        if (i == 0)
            set.emplace(new CProgram());
        else if (i == 1)
            set.emplace(new CMalware(1, 8800, 555, 35, 35634, "BestMalware", "Exploit"));
        else if (i == 2)
            set.emplace(new CProgram(0, 423, 523, 654, 53453, "Calculator"));
        else if (i == 3)
            set.emplace(new CMalware(0, 345, 789, 423, 67456, "MoneyStealer", "Rootkit"));
    }

    setSize = set.size();
    set.emplace(new CMalware());
    if (setSize < set.size())
        cout << "Тест добавления элемента\tвыполнен успешно.\n";
    else
        cout << "Тест добавления элемента\tне выполнен успешно.\n";

    it = set.begin();
    set.erase(it);
    if (set.size() == setSize)
        cout << "Тест удаления элемента\t\tвыполнен успешно.\n";
    else
        cout << "Тест удаления элемента\t\tне выполнен успешно.\n";

    it = set.begin();
    line = (*it)->getStr();
    data = line.str();
    if (data == "MoneyStealer 67456 345 789 423 0 Rootkit" || data == "BestMalware 35634 8800 555 35 1 Exploit" || data == "Basic 65 0 0 0 0 Exploit")
        cout << "Тест получения элемента\t\tвыполнен успешно.\n";
    else
        cout << "Тест получения элемента\t\tне выполнен успешно.\n";

    it = set.begin();
    data = "53453";
    while (i < set.size())
    {
        value = (*it)->countElement(5, data);
        i++;
        it++;
        sum += value;
    }
    if (sum == 1)
        cout << "Тест подсчёта элементов\t\tвыполнен успешно.\n";
    else
        cout << "Тест подсчёта элементов\t\tне выполнен успешно.\n";

    vector <shared_ptr<CProgram>> temp(set.begin(), set.end());
    set.erase(set.begin(), set.end());
    sort(temp.begin(), temp.end(), funct);
    set.insert(temp.begin(), temp.end());
    it = set.begin();
    line = (*it)->getStr();
    data = line.str();
    if (data == "BestMalware 35634 8800 555 35 1 Exploit" || data == "MoneyStealer 67456 345 789 423 0 Rootkit" || data == "Basic 65 0 0 0 0 Exploit")
        cout << "Тест сортировки сета\t\tвыполнен успешно.\n";
    else
        cout << "Тест сортировки сета\t\tне выполнен успешно.\n";
}
void MapTest()
{
    cout << endl << "Map" << endl;
    std::map<int, shared_ptr<CProgram>>::const_iterator it;
    std::map <int, shared_ptr<CProgram>> mergeMap;
    map <int, shared_ptr<CProgram>> map;
    vector <shared_ptr<CProgram>> temp;
    Functor funct(1);
    stringstream line;
    string data;
    int number = 0, result, sum = 0;
    int mapSize;
    int i = 0;

    for (; i < 4; i++)
    {
        if (i == 0)
            map.emplace(i + 1, new CProgram());
        else if (i == 1)
            map.emplace(i + 1, new CMalware(1, 8800, 555, 35, 35634, "BestMalware", "Exploit"));
        else if (i == 2)
            map.emplace(i + 1, new CProgram(0, 423, 523, 654, 53453, "Calculator"));
        else if (i == 3)
            map.emplace(i + 1, new CMalware(0, 345, 789, 423, 67456, "MoneyStealer", "Rootkit"));
    }
    
    mapSize = map.size();
    map.emplace(++i, new CMalware);
    if (mapSize < map.size())
        cout << "Тест добавления элемента\tвыполнен успешно.\n";
    else
        cout << "Тест добавления элемента\tне выполнен успешно.\n";

    it = map.begin();
    map.erase(it);
    if (mapSize == map.size())
        cout << "Тест удаления элемента\t\tвыполнен успешно.\n";
    else
        cout << "Тест удаления элемента\t\tне выполнен успешно.\n";

    it = map.begin();
    line = it->second->getStr();
    data = line.str();
    if (data == "BestMalware 35634 8800 555 35 1 Exploit")
        cout << "Тест получения элемента\t\tвыполнен успешно.\n";
    else
        cout << "Тест получения элемента\t\tне выполнен успешно.\n";

    
    data = "53453";
    while (number < map.size())
    {
        result = it->second->countElement(5, data);
        number++;
        it++;
        sum += result;
    }
    if (sum == 1)
        cout << "Тест подсчёта элементов\t\tвыполнен успешно.\n";
    else
        cout << "Тест подсчёта элементов\t\tне выполнен успешно.\n";

    sort(temp.begin(), temp.end(), funct);
    transform(temp.begin(), temp.end(), inserter(map, map.end()), [&number](const shared_ptr<CProgram>& program)
        {
            return std::make_pair(number++, program);
        });
    it = map.begin();
    line = it->second->getStr();
    data = line.str();
    if (data == "BestMalware 35634 8800 555 35 1 Exploit")
        cout << "Тест сортировки map\t\tвыполнен успешно.\n";
    else
        cout << "Тест сортировки map\t\tне выполнен успешно.\n";

    for (size_t j = 0; j < 4; j++)
    {
        if (j == 0)
            mergeMap.emplace(j + 1, new CProgram(1, 534, 164, 4123, 56789, "Browser"));
        else if (j == 1)
            mergeMap.emplace(j + 1, new CProgram(1, 423, 6452, 3122, 53425, "TextEditor"));
        else if (j == 2)
            mergeMap.emplace(j + 1, new CMalware(0, 231, 534, 634, 23567, "JustMap", "Worm"));
        else if (j == 3)
            mergeMap.emplace(j + 1, new CMalware(1, 123, 345, 964, 90346, "Imtired", "Adware"));
    }
    map = CombineMaps(map, mergeMap);
    if (map.size() != mapSize)
        cout << "Тест слияния map\t\tвыполнен успешно.\n";
    else
        cout << "Тест слияния map\t\tне выполнен успешно.\n";

}

vector <shared_ptr<CProgram>> CombineVectors(vector<shared_ptr<CProgram>>& first, vector <shared_ptr<CProgram>>& second)
{
    vector <shared_ptr<CProgram>> resultVector;

    resultVector.insert(resultVector.end(), make_move_iterator(first.begin()), make_move_iterator(first.end()));
    resultVector.insert(resultVector.end(), make_move_iterator(second.begin()), make_move_iterator(second.end()));

    cout << endl << "Векторы объединены." << endl;
    return resultVector;
}
map <int, shared_ptr<CProgram>> CombineMaps(map<int, shared_ptr<CProgram>>& firstMap, map<int, shared_ptr<CProgram>>& secondMap)
{
    map <int, shared_ptr<CProgram>> resultMap;
    vector <shared_ptr<CProgram>> data1;
    vector <shared_ptr<CProgram>> data2;
    vector <int> map1Keys;
    vector <int> map2Keys;
    vector <int> temp;
    vector <int> res;

    for (auto const& it : firstMap)
        map1Keys.push_back(it.first);
    for (auto const& it : secondMap)
        map2Keys.push_back(it.first);

    for (auto const& it : firstMap)
        data1.push_back(it.second);
    for (auto const& it : secondMap)
        data2.push_back(it.second);

    sort(map1Keys.begin(), map1Keys.end());
    sort(map2Keys.begin(), map2Keys.end());

    set_intersection(map1Keys.begin(), map1Keys.end(), map2Keys.begin(), map2Keys.end(), back_inserter(res));

    temp.insert(temp.end(), map1Keys.begin(), map1Keys.end());
    temp.insert(temp.end(), map2Keys.begin(), map2Keys.end());
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    auto it1 = map1Keys.begin();
    auto it2 = map2Keys.begin();
    stringstream ss1, ss2;
    int count1, count2;

    int time1, time2;
    string internetTF1, internetTF2;
    bool internet;
    int size1, size2;
    int lines1, lines2;
    int index1, index2, index3;
    string name1, name2;
    string type1, type2;

    string value1, value2;

    for (size_t i = 0; i < temp.size(); i++)
    {
        if (find(res.begin(), res.end(), i + 1) != res.end())
        {
            auto itIndex1 = find(map1Keys.begin(), map1Keys.end(), i + 1);
            auto itIndex2 = find(map2Keys.begin(), map2Keys.end(), i + 1);

            index1 = distance(map1Keys.begin(), itIndex1);
            index2 = distance(map2Keys.begin(), itIndex2);

            ss1 = data1[index1]->getStr();
            ss2 = data2[index2]->getStr();

            value1 = ss1.str();
            value2 = ss2.str();

            count1 = count(value1.begin(), value1.end(), ' ');
            count2 = count(value2.begin(), value2.end(), ' ');

            ss1 >> name1;
            ss1 >> index1;
            ss1 >> time1;
            ss1 >> size1;
            ss1 >> lines1;
            ss1 >> internetTF1;
            if (count1 == 6)
                ss1 >> type1;

            ss2 >> name2;
            ss2 >> index2;
            ss2 >> time2;
            ss2 >> size2;
            ss2 >> lines2;
            ss2 >> internetTF2;
            if (count2 == 6)
                ss2 >> type2;

            name1 += name2;
            index1 += index2;
            time1 += time2;
            size1 += size2;
            lines1 += lines2;
            if (internetTF1 == "1" || internetTF2 == "1")
                internet = true;
            if (count1 == 6 || count2 == 6)
            {
                type1 += type2;
                resultMap.emplace(i + 1, new CMalware(internet, time1, size1, lines1, index1, name1, type1));
            }
            else
                resultMap.emplace(i + 1, new CProgram(internet, time1, size1, lines1, index1, name1));

        }
        else
        {
            it1 = find(map1Keys.begin(), map1Keys.end(), i + 1);
            if (it1 != map1Keys.end())
            {
                index3 = distance(map1Keys.begin(), it1);
                resultMap.emplace(i + 1, data1[index3]);
            }
            else
            {
                it2 = find(map2Keys.begin(), map2Keys.end(), i + 1);
                index3 = distance(map2Keys.begin(), it2);
                resultMap.emplace(i + 1, data2[index3]);
            }
        }
    }

    map1Keys.erase(map1Keys.begin(), map1Keys.end());
    map2Keys.erase(map2Keys.begin(), map2Keys.end());
    temp.erase(temp.begin(), temp.end());
    res.erase(res.begin(), res.end());
    data1.erase(data1.begin(), data1.end());
    data2.erase(data2.begin(), data2.end());

    return resultMap;
}