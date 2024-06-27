#include <bits/stdc++.h>
using namespace std;
class Question{
    public:
    int id;
    string question;
    vector<string>options;
    string difficulty;
    int answer;
    Question(int id,string question,vector<string>options,string difficulty,int answer){
        this->id=id;
        this->question=question;
        this->difficulty=difficulty;
        this->options=options;
        this->answer=answer;
    }
};
class Test{
    int id;
	int Qcount;
	int eq;
	int mq;
	int hq;
	int exclude;
    vector<Question>test;
    Test(int id,int Qcount,int eq,int mq,int hq,int exclude,vector<Question>test)
    {
        this->id=id;
        this->eq=eq;
        this->Qcount=Qcount;
        this->mq=mq;
        this->hq=hq;
        this->exclude=exclude;
        this->test=test;
    }
};
class Result{
    string studentName;
	int TestId;
	int mark;
	Result(string name,int testId,int mark)
	{
		this->studentName = name;
		this->TestId = testId;
		this->mark = mark;
	}

};
class Repo
{
    public:
    vector<Question>questionBank;
    // questionBank.push_back(Question(1, "What is the capital of France?", {"Paris", "London", "Berlin", "Rome"}, "Easy", 0));
    vector<Test>testList;
    vector<Result>resultList;
    void add(Question qu)
    {
        this->questionBank.push_back(qu);
        cout<<"Question Successfully Added\n";
    }
    bool removeQuestion(int id)
    {
        bool flag=false;
        
        for(int i=0;i<questionBank.size();i++)
        {
            int cur=questionBank[i].id;
            if(cur==id)
            {
                questionBank.erase(questionBank.begin()+i);
                flag=true;
                return flag;
            }

        }
            return false;

    }
    
    void DisplayAllQuestion()
    {
        if(questionBank.size()==0)
        cout<<"No Questions Found Add Questions\n"<<questionBank.size()<<endl;
        else
        {
            cout<<"size"<<questionBank.size()<<endl;
            for(int i=0;i<questionBank.size();i++)
            {
                cout<<"Question Id\n";
                cout<<questionBank[i].id<<endl;
                cout<<"Question\n";
                cout<<questionBank[i].question<<endl;
                cout<<"Difficulty\n";
                cout<<questionBank[i].id<<endl;
                
                
            }
        }
    }
};
class User{
    public:
    string username;
    string password;
};

class Teacher:public User{
    public:
    string username,password;
    Teacher(string username,string password)
    {
        this->username=username;
        this->password=password;
    }
    bool verify() 
    {
        ifstream file("admin.txt");
        if (!file) {
            cerr << "Unable to open file" << endl;
            return false;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string fileUsername, filePassword;
            getline(ss, fileUsername, ',');
            getline(ss, filePassword, ',');
            //cout<<"\nUseran= "<<fileUsername<<" "<<filePassword<<endl;
            if (username == fileUsername && password == filePassword) {
                return true;
            }
        }

        return false;
    }
    void addTest(Repo repo)
    {

    }
    void viewResult(Repo repo)
    {

    }
};
class Admin: public User{
    public:
        string username,password;
    public:
    Admin(string username,string password)
    {
        this->username=username;
        this->password=password;
    }
    bool verify() {
        ifstream file("admin.txt");
        if (!file) {
            cerr << "Unable to open file" << endl;
            return false;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string fileUsername, filePassword;
            getline(ss, fileUsername, ',');
            getline(ss, filePassword, ',');
            //cout<<"\nUseran= "<<fileUsername<<" "<<filePassword<<endl;
            if (username == fileUsername && password == filePassword) {
                return true;
            }
        }

        return false;
    }
    void addQuestion(Repo repo)
    {
        cout<<"Enter Question ID\n";
        int id;
        cin>>id;
         cin.ignore(); 

        vector<string>options(4,"");
        cout<<"\nEnter Question\n";
        string question;
        getline(cin,question);
        //  cin.ignore(); 

        cout<<"Enter Option A\n";
        getline(cin,options[0]);

        cout<<"Enter Option B\n";
        getline(cin,options[1]);

        cout<<"Enter Option C\n";
        getline(cin,options[2]);

        cout<<"Enter Option D\n";
        getline(cin,options[3]);

        string difficulty;
        cout<<"Enter Difficulty";
        cin>>difficulty;

        int answer;
        cout<<"Enter the answer\n";
        cin>>answer;
        Question que(99, "What is the capital of France?", {"Paris", "London", "Berlin", "Rome"}, "Easy", 0);
        repo.add(que);

    }
    void deleteQuestion(Repo repo){
        int id;
        cout<<"Enter Question \n";
        cin>>id;
        bool res=repo.removeQuestion(id);
        if(res)
            cout<<"Question Removed Successfully\n";
        else
            cout<<"QuestionID not Found";

    }
    void ViewAllQuestions(Repo repo){
        repo.DisplayAllQuestion();
    }
};
class Student:public User{
     public:
        string username,password;
    public:
    Student(string username,string password)
    {
        this->username=username;
        this->password=password;
    }
    bool verify() {
        ifstream file("admin.txt");
        if (!file) {
            cerr << "Unable to open file" << endl;
            return false;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string fileUsername, filePassword;
            getline(ss, fileUsername, ',');
            getline(ss, filePassword, ',');
            //cout<<"\nUseran= "<<fileUsername<<" "<<filePassword<<endl;
            if (username == fileUsername && password == filePassword) {
                return true;
            }
        }

        return false;
    }
    void takeTest(Repo repo)
    {

    }
    void viewResult(Repo repo)
    {
        
    }

};

class MainClass{
    public:
    void admin(Repo repo)
    {
        cout<<"Enter Username\n";
        string username;
        cin>>username;
        cout<<"Enter Password\n";
        string password;
        cin>>password;
        Admin admin(username,password);
        bool isAdmin=admin.verify();
        if(isAdmin)
        {
            cout<<"Congrats Logged In as Admin\n";
            cout << "What Operations would You like to do\n1. Add Questions\n2. Delete Questions\n3. View all questions\n" << endl;
            int choice;
            cin>>choice;
            switch(choice)
            {
                case 1:
                admin.addQuestion(repo);
                break;
                case 2:
                admin.deleteQuestion(repo);
                break;
                case 3:
                admin.ViewAllQuestions(repo);
                break;
                default:
                cout<<"Enter a valid choice\n";
                break;

            }
        }
        
        else
        cout<<"Wrong Credentials\n";
    }
    void teacher(Repo repo)
    {
        cout<<"Enter Username\n";
        string username;
        cin>>username;
        cout<<"Enter Password\n";
        string password;
        cin>>password;
        Teacher teac(username,password);
        bool isTeacher=teac.verify();
        if(isTeacher)
        {
            cout<<"Congrats Techer Logged In successfully\n";
            bool val=true;
            while(val)
            {
                int choice;
                cout<<"1) Add A test\n2)View Result\n3) Exit\n";
                cin>>choice;
                switch(choice)
                {
                    case 1:
                    teac.addTest(repo);
                    break;
                    case 2:
                    teac.viewResult(repo);
                    break;
                    case 3:
                    cout<<"Thank You\n";
                    val=false;
                    break;
                    default:
                    cout<<"Enter a valid Choice\n";
                    break;
                }
            }
        }
        else
        {
            cout<<"Invalid Credentials\n";
        }
    }
    
    void studentLogin(Repo& repo) {
    cout << "Enter Username\n";
    string username;
    cin >> username;
    cout << "Enter Password\n";
    string password;
    cin >> password;

    Student st(username, password);
    bool isStudent = st.verify();

    if (isStudent) {
        cout << "Congrats, Student Logged In successfully\n";
        bool val = true;
        while(val)
        {
            int choice;
            cout<<"1) Take test\n2)View Result\n3) Exit\n";
            cin>>choice;
            switch(choice)
            {
                case 1:
                st.takeTest(repo);
                break;
                case 2:
                st.viewResult(repo);
                break;
                case 3:
                cout<<"Thank You\n";
                val=false;
                break;
                default:
                cout<<"Enter a valid Choice\n";
                break;
            }
        }
    } else {
        cout << "Invalid Credentials\n";
    }
}

};

int main()
{
    bool val=true;
    Repo repo;
    // Question qu(99, "What is the capital of France?", {"Paris", "London", "Berlin", "Rome"}, "Easy", 0);
    // repo.add(qu);
     while (val) {
        cout<<"Enter Your Role\n";
        cout<<"1)Admin\n";
        cout<<"2)Student\n";
        cout<<"3)Teacher\n";
        cout<<"4)Exit\n";
        int choice;
        cin>>choice;
        // choice = check(UserName, Password);

        switch (choice) {
            case 1: {
                MainClass a;
                a.admin(repo);
                break;
            }
            case 2: {
                MainClass b;
                b.teacher(repo);
                break;
            }
            case 3: {
                MainClass c;
                c.studentLogin(repo);
                break;
            }
            case 4:
                cout << "Thank you" << endl;
                val = false;
                break;
            default:
                cout << "Choose any one value" << endl;
                break;
        }
    }

    return 0;
}