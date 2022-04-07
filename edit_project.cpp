#include<bits/stdc++.h>
using namespace std;
class farmer
{
    string id,pass;//for taking id and password from user
    double TC,TI,TR;//for calculating Total Cost(TC), Total Income(TI), Total Revenue(TR).
public:
    farmer()//Initializing variables.
    {
        id.clear();
        pass.clear();
        TC = 0;
        TI = 0;
        TR = 0;
    }
    // Id registration function.
    void registration()
    {
        printf("Enter an user Id: ");
        cin>>id;//Taking user id for registration.
        ifstream in("info.txt");//Opening input file to compare id id exist or not.
        while(1)
        {
            string i,p;//for taking input from info.txt file.
            in>>i>>p;//reading info from file.
            if(in.eof())
            {
                //Id is unique so going next step to take password.
                printf("Enter Your Password: ");
                cin>>pass;
                ofstream out("info.txt",ios::app);//opening output file to write information.
                out<<id<<" "<<pass<<endl;//writing id and password in file.
                out.close();//closing file.
                break;
            }
            if(id==i)//Checking id already exist or not.
            {
                printf("\nSorry the name is not available!!\nEnter another id name!\n\n");
                break;
            }
        }
        in.close();//closing input file.

    }
    //This function takes info for login purpose.
    void login()
    {
        ifstream in("info.txt");
        printf("Enter your id name: ");
        cin>>id;
        printf("Enter your password: ");
        cin>>pass;
        while(1)
        {
            string i,p;
            in>>i>>p;
            if(in.eof())
            {
                printf("\nIncorrect Id or Pass!\n\n");
                break;
            }
            if(id==i&&pass==p)
            {
                printf("\nLogin Successful\n\n");
                menu();//calling menu function from farmer class.
                break;
            }
        }
        in.close();
    }
    //function for operating inside the profile of the user.
    void menu()
    {
        cout<<"\nEnter your choice:\n";
        printf("0.Logout\n1.Crops List\n2.Total Income\n3.Total Cost\n4.Revenue\n5.View Information\n\n");
        int ch;
        scanf("%d",&ch);
        switch(ch)
        {
        case 0://logging out.
            cout<<"\nLog out successful\n\n";
            break;

        case 1:
            CropsList();//calling CropsList() function from farmer class.
            break;
        case 2:
            Income();//calling Income function() from farmer class.
            break;
        case 3:
            TotalCost();//calling TotalCost() function from farmer class.
            break;
        case 4:
            Revenue();//calling Revenue() function from farmer class.
            break;
        case 5:
            view();//calling View() function from farmer class.
            break;
        default:
            break;
        }
        if(ch!=0)
            menu();
    }
//Function to operate crops list.
    void CropsList()
    {
        printf("Enter your choice:\n");
        printf("0.Home\n1.Rice\n2.Bean\n3.Fish\n4.Others\n\n");
        int ch;
        scanf("%d",&ch);
        switch(ch)
        {
        case 0://going back to home.
            break;

        case 1:
            Add(1);//calling add(int idc) function to operate Rice.
            break;
        case 2:
            Add(2);//calling add(int idc) function to operate Bean.
            break;
        case 3:
            Add(3);//calling add(int idc) function to operate Fish.
            break;
        case 4:
            Add(4);////calling add(int idc) function to operate other crops.
            break;
        default:
            break;
        }
        menu();
    }
    //Function for adding cost or revenue for particular crops.
    void Add(int idc)//accepting int idc to ensure for which crop the information have to add.
    {
        printf("\nEnter your choice:\n");
        printf("0.Home\n1.Add Cost\n2.Add Revenue\n\n");
        int ch;
        cin>>ch;//taking choice;
        switch(ch)
        {
        case 0://go back to home.
            break;

        case 1://for adding cost
        {
            printf("Enter cost:");
            double c;
            scanf("%lf",&c);//taking cost info input.
            string fname;//string to set name for opening file.
            fname=id+".txt";

            ifstream in(fname);//opening input file to read info from the file.
            double r=0,tempc=0;
            if(in)//if file exist then goes forward and adds cost.
            {
                double arr[4][2];
                for(int i=0; i<4; i++)
                {
                    in>>arr[i][0]>>arr[i][1];//reading info from users file.
                }
                arr[idc-1][0]+=c;//adding cost to previous cost.
                in.close();
                ofstream out(fname);//opening output file to write updated cost.
                for(int i=0; i<4; i++)
                {
                    out<<arr[i][0]<<" "<<arr[i][1]<<endl;//writing updated cost in users file.
                }
                out.close();//closing output file.
            }
            else//If user has no file created yet then goes forward.
            {
                in.close();//closing input file.
                ofstream out(fname);//opening output file.
                //writing information to users file.
                for(int i=1; i<idc; i++)
                    out<<tempc<<" "<<r<<endl;
                out<<c<<" "<<r<<endl;
                for(int i=idc; i<4; i++)
                    out<<tempc<<" "<<r<<endl;
            }
        }
        break;
        case 2://for adding revenue for regarding crops.
        {
            printf("Enter Revenue: ");
            double r;
            scanf("%lf",&r);
            string fname;
            fname=id+".txt";

            ifstream in(fname);
            double c=0,tempr=0;
            if(in)//if file exist then goes forward and adds cost.
            {
                double arr[4][2];
                for(int i=0; i<4; i++)
                {
                    in>>arr[i][0]>>arr[i][1];
                }
                arr[idc-1][1]+=r;
                in.close();
                ofstream out(fname);
                for(int i=0; i<4; i++)
                {
                    out<<arr[i][0]<<" "<<arr[i][1]<<endl;
                }
                out.close();
            }
            else//If user has no file created yet then goes forward.
            {
                in.close();
                ofstream out(fname);

                for(int i=1; i<idc; i++)
                    out<<c<<" "<<tempr<<endl;
                out<<c<<" "<<r<<endl;
                for(int i=idc; i<4; i++)
                    out<<c<<" "<<tempr<<endl;
            }
        }
        break;

        default:
            break;
        }
    }
    //This function calculates total cost.
    void TotalCost()
    {
        TC=0;
        string fname;
        fname=id+".txt";
        ifstream in(fname);
        if(in)
        {
            double c,r;
            for(int i=0; i<4; i++)
            {
                in>>c>>r;
                TC+=c;
            }
            printf("Total Cost = %.2f\n",TC);
        }
        else
        {
            printf("No Information Yet\n");
        }

    }
    //This function calculates total revenue.
    void Revenue()
    {
        TI=0;
        string fname;
        fname=id+".txt";
        ifstream in(fname);
        if(in)
        {
            double c,r;
            for(int i=0; i<4; i++)
            {
                in>>c>>r;
                TI+=r;
            }
            printf("Total Revenue = %.2f\n",TI);
        }
        else
        {
            printf("No Information Yet\n");
        }

    }
    //This function shows all the information of the user.
    void view()
    {
        printf("");
        string fname;
        fname=id+".txt";
        ifstream in(fname);
        if(in)
        {
            double c,r;
            cout<<" cost         Revenue "<<endl;
            for(int i=0; i<4; i++)
            {
                in>>c>>r;
                printf("%.2f        %.2f\n",c,r);
            }
        }
    }
    //This function calculates total income.
    void Income()
    {
        TC=0;
        TR=0;
        TI=0;
        string fname;
        fname=id+".txt";
        ifstream in(fname);
        if(in)
        {
            double c,r;
            for(int i=0; i<4; i++)
            {
                in>>c>>r;
                TC+=c;
                TI+=r;
            }
            printf("Total Cost = %.2f\nTotal Income = %.2f\n",TC,TI);
            TR = TI - TC;
            printf("Total Revenue = %.2f\n",TR);
        }
        else
        {
            printf("No Information Yet\n");
        }

    }

};
class menu:public farmer
{
    int ch;//for taking choice.
public:
    menu()
    {

    }
    //This Function Shows menu.
    void show()
    {
        while(1)

        {
            printf("Enter your choice:\n");
            printf("0.Exit\n1.Login\n2.Register\n\n");
            scanf("%d",&ch);
            switch(ch)
            {
            case 0:
                return;

            case 1:
                login();//calls login  function from farmer class.
                break;
            case 2:
                registration();//calls registration function from farmer class.
                break;
            default:
                break;

            }
        }
    }
};

int main()
{
    menu ob;
    ob.show();
    return 0;
}
