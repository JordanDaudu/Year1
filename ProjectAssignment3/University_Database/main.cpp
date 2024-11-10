#include <iostream>
#include <cstring>
#include "Worker.h"
#include "Teacher.h"
#include "Researcher.h"
#include "Lecturer.h"
#include "Article.h"
#include "Course.h"
#define MAXNAME 20
#define MAXARTICLE 50
using namespace std;
int main()
{
    int numberOfWorkers, numberOfCourses, numberOfArticles, type, seniority, weeklyHours, numberOfStudents;
    char name[MAXNAME], article[MAXARTICLE], course[MAXNAME];
    bool articleAdded = false;
    cout << "~~~~~University workers database~~~~~" << endl;
    cout << "How many workers there is in the university? ";
    // getting number of workers in university
    cin >> numberOfWorkers;
    Worker **p = new Worker *[numberOfWorkers];
    cout << "Lets get information on all " << numberOfWorkers << " workers in the university" << endl;
    // getting all workers information and adding them to the pointer array
    for(int i = 0; i < numberOfWorkers; i++)
    {
        do
        {
            cout << "||Choose worker " << i+1 << " type||\n1. Worker\n2. Teacher\n3. Researcher\n4. Lecturer" << endl;
            cin >> type;
            if(type <= 0 || type > 4)
                cout << "Error! please input a number that is supported, try again." << endl;
        }
        while(type <= 0 || type > 4);
        switch (type)
        {
            case 1:
                // normal worker
                cout << "||" << i+1 << "-Worker: \nInput worker name: ";
                cin >> name;
                cout << "Input " << name << " seniority: ";
                cin >> seniority;
                p[i] = new Worker(name, seniority);
                break;
            case 2:
            {
                // teacher
                cout << "||" << i+1 << "-Teacher: \nInput teacher name: ";
                cin >> name;
                cout << "Input " << name << " seniority: ";
                cin >> seniority;
                cout << "How many courses does teacher " << name << " teaches (in numbers)?: ";
                cin >> numberOfCourses;
                Course *courseArr = new Course[numberOfCourses];
                if(numberOfCourses > 0)
                    cout << "||Lets get information on the courses teacher " << name << " teaches||" << endl;
                for(int j = 0; j < numberOfCourses; j++)
                {
                    cout << "Input course " << j+1 << " name, weeklyHours and number of students (3 parameters): ";
                    cin >> course >> weeklyHours >> numberOfStudents;
                    courseArr[j].setVariables(course, weeklyHours, numberOfStudents);
                }
                p[i] = new Teacher(name, seniority, numberOfCourses, courseArr);
                break;
            }
            case 3:
            {
                //researcher
                cout << "||" << i+1 << "-Researcher: \nInput researcher name: ";
                cin >> name;
                cout << "Input " << name << " seniority: ";
                cin >> seniority;
                cout << "How many articles did researcher " << name << " publish (in numbers)?: ";
                cin >> numberOfArticles;
                Article *articleArr = new Article[numberOfArticles];
                if(numberOfArticles > 0)
                    cout << "||Lets get information on the articles researcher " << name << " published||" << endl;
                for(int j = 0; j < numberOfArticles; j++)
                {
                    cout << "Input article " << j+1 << " name: ";
                    cin >> article;
                    articleArr[j].setName(article);
                }
                p[i] = new Researcher(name, seniority, numberOfArticles, articleArr);
                break;
            }
            case 4:
            {
                // lecturer
                cout << "||" << i+1 << "-Lecturer: \nInput Lecturer name: ";
                cin >> name;
                cout << "Input " << name << " seniority: ";
                cin >> seniority;
                cout << "How many courses does lecturer " << name << " teaches (in numbers)?: ";
                cin >> numberOfCourses;
                Course *courseArr = new Course[numberOfCourses];
                if(numberOfCourses > 0)
                    cout << "||Lets get information on the courses lecturer " << name << " teaches||" << endl;
                for(int j = 0; j < numberOfCourses; j++)
                {
                    cout << "Input course " << j+1 << " name, weeklyHours and number of students (3 parameters): ";
                    cin >> course >> weeklyHours >> numberOfStudents;
                    courseArr[j].setVariables(course, weeklyHours, numberOfStudents);
                }
                cout << "How many articles did lecturer " << name << " publish (in numbers)?: ";
                cin >> numberOfArticles;
                Article *articleArr = new Article[numberOfArticles];
                if(numberOfArticles > 0)
                    cout << "||Lets get information on the articles lecturer " << name << " published||" << endl;
                for(int j = 0; j < numberOfArticles; j++)
                {
                    cout << "Input article " << j+1 << " name: ";
                    cin >> article;
                    articleArr[j].setName(article);
                }
                p[i] = new Lecturer(name, seniority, courseArr, numberOfCourses, articleArr, numberOfArticles);
                break;
            }
            default:
                cout << "Error! input not supported" << endl;
                i--;
        }
    }

    //adding a single article
    cout << "\n||Lets add an article to a researcher/lecturer||" << endl;
    cout << "Type the name of the researcher/lecturer you would like to add a article: " << endl;
    cin >> name;
    cout << "Type the article name: ";
    cin >> article;
    for(int i = 0; i < numberOfWorkers; i++)
    {
        if(strcmp(p[i]->getName(), name) == 0)
        {
            if(dynamic_cast <Researcher *>(p[i]))
            {
                Researcher *reseacher = dynamic_cast <Researcher *>(p[i]);
                reseacher->addArticle(article);
                articleAdded = true;
                break;
            }
        }
    }
    if(articleAdded)
        cout << "||Added article successfully||" << endl;
    else
        cout << "||Error! couldn't find a matching researcher/lecturer, article wasn't added||" << endl;
    //printing salaries
    cout << "\n~~~~~Printing all workers salary~~~~~" << endl;
    for(int i = 0; i < numberOfWorkers; i++)
    {
        cout << p[i]->getName() << ": ";
        cout << "Salary: " << p[i]->salary() << endl;
    }
    // printing names of courses with over 100 students
    cout << "\n~~~~~Printing all courses with over 100 students~~~~~" << endl;
    for(int i = 0; i < numberOfWorkers; i++)
    {
        if(dynamic_cast<Teacher *>(p[i]))
        {
            Teacher *teacher = dynamic_cast<Teacher *>(p[i]);
            teacher->printOver100Students();
        }
    }
    //printing all articles
    cout << "\n~~~~~Printing all articles~~~~~" << endl;
    for(int i = 0; i < numberOfWorkers; i++)
    {
        if(dynamic_cast <Researcher *>(p[i]))
        {
            Researcher *reseacher = dynamic_cast <Researcher *>(p[i]);
            reseacher->printArticles();
        }
    }

    //deleting memory properly that hasn't been deleted already from classes
    for(int i = 0; i < numberOfWorkers; i++)
        delete p[i];
    delete[] p;
    return 0;
}
