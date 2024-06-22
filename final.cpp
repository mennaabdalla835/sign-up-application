#include <iostream>
#include <string>
#include <vector>
enum class option {
    Add_record = 1,
    fetch_record = 2,
    Quit =3
 };
 class record {
    public:
    int userId;
    std::string Name;
     int age;
record(int id, const std::string& name, int age) : userId(id), Name(name), age(age) {}
 };

 const int MAX_NUMBERS= 100;
 std::vector<record> records;
 option DEFAULT = option ::Add_record;
 void show ();
 void add_record();
 void fetch(int age);
 const option select (); 
 int main ()
 {
    bool isRunning = true;
    option option = DEFAULT;
    while (isRunning == true)
    {
        show();
        option = select();
        switch (option)
        {
            case option ::Add_record :
            {
                add_record();
            }
            break;
            case option ::fetch_record:
            {
                int id;
                std :: cout<< "please enter user ID \n";
                std :: cin>> id;
                fetch(id);
            }
            break;
            case option ::Quit :
            {
                isRunning = false;
            }
            break;
            default:
            {
                std:: cout<<"invalid option \n";
            }
        
        }
    }
   
 }
 std::istream& operator>> (std::istream & input_stream,option & result )
{
    int int_option;
    input_stream >> int_option;
    result = static_cast<option>(int_option);
    return input_stream;
}
 void show ()
 {
    std :: cout<<" \n Please select an option";
    std :: cout<<" \n 1- Add record \n 2- Fetch record \n 3- Quit \n"; 
 }
const option select ()
{
    option option =DEFAULT;
    std :: cin>> option;
    return option;
}
  void add_record()
  {
   
    if ( records.size() >= MAX_NUMBERS)
    {
        std:: cout << "invalid to add you reached the MAX numbers" ;
        return;
    }
    else {
    int user_Id = 1;
    std:: string name;
    int age;
    std:: cout <<" \n please enter User name and age: \n";
    std:: cin >>name;
    std:: cin >>age;
    record enter_record (user_Id,name,age);
    records.push_back(enter_record);
    std:: cout <<"Name: " <<enter_record.Name <<"\n Age: " <<enter_record.age;
    ++user_Id;
    }
  }
  void fetch(int Id)
  {
    bool found = false;
    for (const auto &rec : records)
    {
        if (rec.userId == Id )
        {
            std :: cout <<"user Id"<< rec.userId <<" \n Name: "<<rec.Name <<"\n age: "<<rec.age;
            found = true;
            break; 
        }
        else if (found == false)
        {
            std ::cout<<"not found \n";
        }
    }

    
  }