// HW_Cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <list>
#include <ostream> 
#include <ctime> 
#include <time.h>

class Task
{
public:
	Task();
	Task(std::string const& n, std::string const& ds, std::string const& dt);
	~Task();
	void SetName(std::string _name);	
	void SetDescription(std::string _description);	
	void SetDate(std::string _date);
	std::string Task::GetName(void);
	std::string Task::GetDescription(void);
	std::string Task::GetDate(void);
	
	void Display() {
		std::cout << GetDate() << ", " << GetName() << ", " << GetDescription() << "\n";		
	}

private:
	std::string Name;
	std::string Description;
	std::string Date;
};

Task::Task()
{
	//std::cout << "Task object is being created" << std::endl;
}
Task::Task(std::string const& n, std::string const& ds, std::string const& dt)
{
	//std::cout << "Task object is being created" << std::endl;
	Name = n;
	Description = ds;
	Date = dt;
}
void Task::SetName(std::string _name) {
	Name = _name;
}
std::string Task::GetName(void) {
	return Name;
}
void Task::SetDescription(std::string _description) {
	Description = _description;
}
std::string Task::GetDescription(void) {
	return Description;
}
void Task::SetDate(std::string _date) {
	Date = _date;
}
std::string Task::GetDate(void) {
	return Date; 
}
Task::~Task()
{
	//std::cout << "Task object is being deleted" << std::endl;
}

class TaskPlanner
{
public:
	TaskPlanner();
	~TaskPlanner();
	void DisplayToday()
	{
		std::cout << "Tasks for today:" << std::endl;
		for (auto v : listOfTasks)
			if (v.GetDate() == Today)
				v.Display();
		std::cout << "_______________________\n";
	};
	void DisplayTomorrow()
	{
		std::cout << "Tasks for tomorrow:" << std::endl;
		for (auto v : listOfTasks)
			if (v.GetDate() == Tomorrow)
				v.Display();
		std::cout << "_______________________\n";
	}; 
	void DisplayDate(std::string _date)
	{
		std::cout << "Tasks for " << _date << ":" << std::endl;
		for (auto v : listOfTasks)
			if (v.GetDate() == _date)
				v.Display();
		std::cout << "_______________________\n";
	};
	void AddTask(Task _t) {
		listOfTasks.push_back(_t);
	};	
	std::string GetToday() {
		time_t rawtime;
		struct tm * timeinfo;
		char buffer[80];
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
		return buffer;
	};
	std::string GetTomorrow() {
		time_t rawtime;
		char buffer[80];
		time(&rawtime);
		struct tm* timeinfo = localtime(&rawtime);
		timeinfo->tm_mday += 1;
		strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
		return buffer;		
	};
private:	
	std::list<Task> listOfTasks;
	std::string Today = GetToday();
	std::string Tomorrow = GetTomorrow();
};

TaskPlanner::TaskPlanner()
{
	std::cout << "TaskPlanner object is being created" << std::endl;
	//listOfTasks = new std::list<Task>;
}


TaskPlanner::~TaskPlanner()
{
	std::cout << "TaskPlanner object is being deleted" << std::endl;
	//delete listOfTasks;
}
int main()
{	
	
	TaskPlanner AllTasks;
	AllTasks.AddTask(Task("Name1", "Description2", "2017-06-18"));
	AllTasks.AddTask(Task("Name2", "Description2", "2017-06-21"));
	AllTasks.AddTask(Task("Name3", "Description2", "2017-06-18"));
	AllTasks.AddTask(Task("Name4", "Description2", "2017-06-19"));
	AllTasks.AddTask(Task("Name5", "Description2", "2017-06-20"));
	AllTasks.AddTask(Task("Name6", "Description2", "2017-06-18"));
	AllTasks.AddTask(Task("Name7", "Description2", "2017-06-19"));	

	std::string date = "2017-06-20";

	AllTasks.DisplayToday();
	AllTasks.DisplayTomorrow();
	AllTasks.DisplayDate(date);
	
	std::cin.get();
	return 0;
}