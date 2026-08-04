#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<string>

using namespace std;

class ElectronicComponent
{
protected:

    string type;
    string name;
    int quantity;
    float unitPrice;
    string rating;
    string description;

public:
    ElectronicComponent()
    {
        type="";
        name="";
        quantity=0;
        unitPrice=0;
        rating="";
        description="";
    }
    
    ElectronicComponent(string t,string n,int q,float p,string r,string d)
    {
        type=t;
        name=n;
        quantity=q;
        unitPrice=p;
        rating=r;
        description=d;
    }

    virtual ~ElectronicComponent(){}
    virtual void input()
    {
        cin.ignore();
        cout<<"Component Name : ";
        getline(cin,name);
        cout<<"Quantity : ";
        cin>>quantity;
        cout<<"Unit Price : ";
        cin>>unitPrice;
        cin.ignore();

        cout<<"Power Rating / Voltage : ";
        getline(cin,rating);
        cout<<"Description : ";
        getline(cin,description);
    }

    virtual void display()
    {
        cout<<left
            <<setw(18)<<type
            <<setw(20)<<name
            <<setw(10)<<quantity
            <<setw(12)<<unitPrice
            <<setw(18)<<rating
            <<description<<endl;
    }
    string getType()
    {
        return type;
    }
    string getName()
    {
        return name;
    }
    int getQuantity()
    {
        return quantity;
    }
    float getPrice()
    {
        return unitPrice;
    }
    string getRating()
    {
        return rating;
    }

    string getDescription()
    {
        return description;
    }
    void setType(string t)
    {
        type=t;
    }

    void setName(string n)
    {
        name=n;
    }
    void setQuantity(int q)
    {
        quantity=q;
    }
    void setPrice(float p)
    {
        unitPrice=p;
    }

    void setRating(string r)
    {
        rating=r;
    }

    void setDescription(string d)
    {
        description=d;
    }
};

class InventoryItem:public ElectronicComponent
{
public:
    InventoryItem(){}
    InventoryItem(string t,string n,int q,float p,string r,string d): ElectronicComponent(t,n,q,p,r,d)
    {
    }
    void display() override
    {
        ElectronicComponent::display();
    }
};
class Inventory
{
private:
    vector<InventoryItem> components;

public:
    void menu();

    void addComponent();
    void viewComponent();
    void updateComponent();
    void deleteComponent();
    void purchaseComponent();
    void saveData();
    void loadData();
};
void Inventory::menu()
{
    cout<<"\tELECTRONICS COMPONENTS STORE MANAGEMENT\n\n";

    cout<<"1. Add Component"<<endl;
    cout<<"2. View Component"<<endl;
    cout<<"3. Update Component"<<endl;
    cout<<"4. Delete Component"<<endl;
    cout<<"5. Purchase Component"<<endl;
    cout<<"6. Save Data"<<endl;
    cout<<"7. Exit"<<endl;
}

void Inventory::addComponent()
{
    InventoryItem item;

    string componentType[] =
    {
        "Resistor",
        "Capacitor",
        "Inductor",
        "Diode",
        "LED",
        "Transistor",
        "IC",
        "Microcontroller",
        "Display Module"
    };

    int choice;

    cout<<"Select Component Type"<<endl;

    for(int i=0;i<9;i++)
    {
        cout<<i+1<<". "<<componentType[i]<<endl;
    }

	    cout<<"\nEnter Choice :";
    cin>>choice;
    
    if(choice<1 || choice>9)
    {
        cout<<"\nInvalid Choice!\n"<<endl;
        return;
    }

    item.setType(componentType[choice-1]);

    item.input();

    components.push_back(item);

    cout<<"\nComponent Added Successfully!\n"<<endl;
}

void Inventory::viewComponent()
{
    if(components.empty())
    {
        cout<<"\nNo Components Found!\n"<<endl;
        return;
    }


    cout<<left
        <<setw(18)<<"Type"
        <<setw(20)<<"Name"
        <<setw(10)<<"Qty"
        <<setw(12)<<"Price"
        <<setw(18)<<"Rating"
        <<"Description"<<endl;


    for(int i=0;i<components.size();i++)
    {
        components[i].display();
    }

}
void Inventory::updateComponent()
{
    if(components.empty())
    {
        cout<<"\nNo Components Found!\n"<<endl;
        return;
    }

    string search;

    cin.ignore();

    cout<<"\nEnter Component Name to Update : ";
    getline(cin,search);

    bool found=false;

    for(int i=0;i<components.size();i++)
    {
        if(components[i].getName()==search)
        {
            found=true;
            cout<<"\nCurrent Details\n";

            cout<<"Type        : "<<components[i].getType()<<endl;
            cout<<"Name        : "<<components[i].getName()<<endl;
            cout<<"Quantity    : "<<components[i].getQuantity()<<endl;
            cout<<"Unit Price  : "<<components[i].getPrice()<<endl;
            cout<<"Rating      : "<<components[i].getRating()<<endl;
            cout<<"Description : "<<components[i].getDescription()<<endl;

            string newName,newRating,newDescription;
            int newQuantity;
            float newPrice;

            cout<<"\nEnter New Details\n";
            cout<<"Component Name : ";
            getline(cin,newName);
            cout<<"Quantity : ";
            cin>>newQuantity;
            cout<<"Unit Price : ";
            cin>>newPrice;
            cin.ignore();

            cout<<"Power Rating / Voltage : ";
            getline(cin,newRating);
            cout<<"Description : ";
            getline(cin,newDescription);

            components[i].setName(newName);
            components[i].setQuantity(newQuantity);
            components[i].setPrice(newPrice);
            components[i].setRating(newRating);
            components[i].setDescription(newDescription);

            cout<<"\nComponent Updated Successfully!\n"<<endl;
            break;
        }
    }

    if(!found)
    {
        cout<<"\nComponent Not Found!\n"<<endl;
    }
}

void Inventory::deleteComponent()
{
    if(components.empty())
    {
        cout<<"\nNo Components Found!\n"<<endl;
        return;
    }

    string search;

    cin.ignore();

    cout<<"\nEnter Component Name to Delete : ";
    getline(cin,search);

    bool found=false;

    for(int i=0;i<components.size();i++)
    {
        if(components[i].getName()==search)
        {
            components.erase(components.begin()+i);
            found=true;

            cout<<"\nComponent Deleted Successfully!\n"<<endl;
            break;
        }
    }
    if(!found)
    {
        cout<<"\nComponent Not Found!\n"<<endl;
    }
}
void Inventory::purchaseComponent()
{
    if(components.empty())
    {
        cout<<"\nNo Components Found!\n"<<endl;
        return;
    }

    string search;
    int buyQuantity;

    cin.ignore();

    cout<<"\nEnter Component Name to Purchase : ";
    getline(cin,search);

    bool found=false;

    for(int i=0;i<components.size();i++)
    {
        if(components[i].getName()==search)
        {
            found=true;

            cout<<"\nAvailable Stock : "<<components[i].getQuantity();
            cout<<"\nEnter Quantity to Purchase : ";
            cin>>buyQuantity;
            if(buyQuantity<=0)
            {
                cout<<"\nInvalid Quantity!\n"<<endl;
                return;
            }
            if(buyQuantity>components[i].getQuantity())
            {
                cout<<"\nNot Enough Stock Available!"<<endl;
                return;
            }

            int remainingStock =
                components[i].getQuantity()-buyQuantity;

            components[i].setQuantity(remainingStock);

            float totalBill =
                buyQuantity*components[i].getPrice();

            cout<<"\tPURCHASE BILL";
            cout<<"Component Name : "
                <<components[i].getName()<<endl;
            cout<<"Component Type : "
                <<components[i].getType()<<endl;
            cout<<"Purchased Qty  : "
                <<buyQuantity<<endl;
            cout<<"Unit Price     : Rs. "
                <<components[i].getPrice()<<endl;
            cout<<"Total Bill     : Rs. "
                <<totalBill<<endl;
            cout<<"Remaining Qty  : "
                <<components[i].getQuantity()<<endl;

            cout<<"\nPurchase Successful!\n"<<endl;
            break;
        }
    }

    if(!found)
    {
        cout<<"\nComponent Not Found!\n"<<endl;
    }
}

void Inventory::saveData()
{
    ofstream fout("components.txt");

    if(!fout)
    {
        cout<<"\nUnable to Open File!\n"<<endl;
        return;
    }

    for(int i=0;i<components.size();i++)
    {
        fout<<components[i].getType()<<endl;
        fout<<components[i].getName()<<endl;
        fout<<components[i].getQuantity()<<endl;
        fout<<components[i].getPrice()<<endl;
        fout<<components[i].getRating()<<endl;
        fout<<components[i].getDescription()<<endl;
    }

    fout.close();
    cout<<"\nData Saved Successfully!"<<endl;
}

void Inventory::loadData()
{
    ifstream fin("components.txt");

    if(!fin)
        return;

    components.clear();

    while(true)
    {
        InventoryItem item;

        string type,name,rating,description;
        int quantity;
        float price;

        if(!getline(fin,type))
            break;

        getline(fin,name);
        fin>>quantity;
        fin>>price;
        fin.ignore();
        getline(fin,rating);
        getline(fin,description);
        item.setType(type);
        item.setName(name);
        item.setQuantity(quantity);
        item.setPrice(price);
        item.setRating(rating);
        item.setDescription(description);

        components.push_back(item);
    }

    fin.close();
}

int main()
{
    Inventory store;
    store.loadData();
    int choice;

    do
    {
        store.menu();
        cout<<"\nEnter Choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                store.addComponent();
                break;
            case 2:
                store.viewComponent();
                break;
            case 3:
                store.updateComponent();
                break;
            case 4:
                store.deleteComponent();
                break;
            case 5:
                store.purchaseComponent();
                break;
            case 6:
                store.saveData();
                break;
            case 7:
                store.saveData();
                cout<<"\nThank You!"<<endl;
                break;

            default:
                cout<<"\nInvalid Choice!\n"<<endl;
        }

    }while(choice!=7);
    
    return 0;
}