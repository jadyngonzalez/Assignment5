#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include "DBTree.h"
#include "Faculty.h"
#include "Student.h"

class DatabaseManager
{
  public:
    DatabaseManager();
    ~DataBaseManager();

    bool printStudents(unsigned int id); //1
    bool printFaculty(unsigned int id); //2
    Student *findStudent(); //3
    Faculty *findFaculty(); //4
    bool printAdvisor(unsigned int id); //5
    bool printAdvisees(unsigned int id); //6
    bool addStudent(string name, string major, double gpa); //7
    bool deleteStudent(unsigned int id); //8
    bool addFaculty(string name, string department); //9
    bool deleteFaculty(unsigned int id); //10
    bool changeAdvisor(unsigned int sid, unsigned int fid); //11
    bool removeAdvisee(unsigned int sid, unsigned int fid); //12
    bool rollback(); //13
    void saveExit(); //14

    void save(string fileName);
    void load(string fileName);
  private:
    DBTree<Student> studentTree;
    DBTree<Faculty> facultyTree;
    TreeNode<Faculty> *assignAdvisor();
    int version;

    unsigned int assignID(string person);
    void displayOptions();
    bool start(int input);
};
#endif
