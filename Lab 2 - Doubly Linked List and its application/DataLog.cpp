class DataLog
{
private:
    list<int> logList;
    list<int>::iterator currentState;

public:
    DataLog();
    DataLog(const int &data);
    void addCurrentState(int number);
    void subtractCurrentState(int number);
    void save();
    void undo();
    void redo();

    int getCurrentStateData()
    {
        return *currentState;
    }
    
    void printLog()
    {      
        for (auto i = logList.begin(); i != logList.end(); i++) {
            if(i == currentState) cout << "Current state: ";
            cout << "[ " << *i << " ] => ";
        }
        cout << "END_LOG";
    }
};

DataLog::DataLog()
{
	logList.push_back(0);
	currentState = logList.begin();
}

DataLog::DataLog(const int &data)
{
	logList.push_back(data);
	currentState = logList.begin();
}

void DataLog::addCurrentState(int number)
{
	*this->currentState = *this->currentState + number;
}

void DataLog::subtractCurrentState(int number)
{
	*this->currentState = *this->currentState - number;
}

void DataLog::save()
{
	list<int>::iterator a = currentState;
	++a;
	while (a != logList.end()) {
		a = logList.erase(a);
	}
	logList.push_back(*currentState);
	++currentState;
}

void DataLog::undo()
{
	if (currentState != logList.begin()) currentState = prev(currentState, 1);
}

void DataLog::redo()
{
	list<int>::iterator a = currentState;
	list<int>::iterator b = ++a;
	if (b != logList.end()) ++currentState;
}