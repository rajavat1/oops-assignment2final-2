#include "myhead.h"

void removeSpaces(string &str)
{
    str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
}
int randome()
{
    srand(time(0));
    int ren = 1000 + rand() % 10000;
    return ren;
}
string rendomedr()
{
    string drs[] = {"Dr. Kalpana", "Dr. Rahul Sharma", "Dr. Nitin roy", "Dr. Sapna Prajapat", "Dr. Amit Nagar"};
    int size = sizeof(drs) / sizeof(drs[0]);
    srand(time(0));
    int idex = (rand() % size);
    string rendrs = drs[idex];
    return rendrs;
}
string todaydate()
{
    time_t now = time(0);

    // Convert the current time to the broken-down time format
    struct tm *timeinfo = localtime(&now);

    char buffer[80];
    strftime(buffer, 80, "%d/%m/%Y", timeinfo);

    return buffer;
}
int randome_price()
{
    srand(time(0));
    int ren_price = 15 + rand() % 99;
    return ren_price;
}
int randome1()
{
    srand(time(0));
    int ren = 1000 + rand() % 90000;
    return ren;
}
// inventory class
class inventory
{
public:
    void create()
    {
        // file pointer
        fstream fout;

        // opens an existing csv file or creates a new file.
        fout.open("Madicine.csv", ios::out | ios::app);

        cout << "Enter the details " << endl;

        int Madicine_id, Qty;
        string Madicine_name, Madicine_detail, Madicine_company, Madicine_expiry;

        // Read the inputs
        Madicine_id = randome();
        cin.ignore();
        cout << "Enter Madicine Name : ";
        getline(cin, Madicine_name);
        cout << "Enter Madicine Company Name : ";
        getline(cin, Madicine_company);
        cout << "Enter Madicine Detail : ";
        getline(cin, Madicine_detail);
        cout << "Enter Madicine Expiry Date(mm/yyyy) : ";
        getline(cin, Madicine_expiry);
        cout << "Enter Madicine Quantity : ";
        cin >> Qty;
        cout << "\n\nDATA INSERTED SUCCESFULLY!!\n\n";
        // Insert the data to file
        fout
            << Madicine_id << ", "
            << Madicine_name << ", "
            << Madicine_company << ", "
            << Madicine_detail << ", "
            << Madicine_expiry << ", "
            << Qty << "\n";
        fout.close();
    }

    void read_record()
    {
        // File pointer
        fstream fin;

        // Open an existing file
        fin.open("Madicine.csv", ios::in);

        vector<string> row;
        string line, word, temp;

        // Read each line from the file
        while (getline(fin, line))
        {

            row.clear();

            // used for breaking words
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            // Print the found data
            cout << row[0] << " | " << row[1] << " | " << row[2] << " | " << row[3] << row[4] << row[5] << endl;
        }
        // Close the file
        fin.close();
    }

    void search_record()
    {
        // File pointer
        fstream fin;

        // Open an existing file
        fin.open("Madicine.csv", ios::in);

        int count = 0;
        string Madicine_id, Madicine_id2, Madicine_name, Madicine_company;
        cout << "Enter the Madicine number or Madicine name or Company Name to display details: ";
        cin.ignore();
        getline(cin, Madicine_id);
        removeSpaces(Madicine_id);
        for (char &c : Madicine_id)
        {
            c = tolower(c);
        }
        vector<string> row;
        string line, word, temp;

        // Read each line from the file
        while (getline(fin, line))
        {

            row.clear();

            // used for breaking words
            stringstream s(line);

            while (getline(s, word, ','))
            {

                row.push_back(word);
            }

            removeSpaces(row[0]);
            removeSpaces(row[1]);
            removeSpaces(row[4]);
            for (char &c : row[1])
            {
                c = tolower(c);
            }
            for (char &c : row[2])
            {
                c = tolower(c);
            }
            Madicine_id2 = row[0];
            Madicine_name = row[1];
            Madicine_company = row[2];
            removeSpaces(Madicine_company);
            // Compare the roll number
            if (Madicine_id2 == Madicine_id || Madicine_name == Madicine_id || Madicine_company == Madicine_id || row[4] == Madicine_id)
            {
                for (char &c : row[1])
                {
                    c = toupper(c);
                }
                for (char &c : row[2])
                {
                    c = toupper(c);
                }
                // Print the found data
                cout << endl
                     << endl
                     << "Details of Madicine ID #" << row[0] << " :" << endl;
                cout << " | "
                     << "Name : " << row[1] << endl
                     << " | "
                     << "Company Name : " << row[2] << endl
                     << " | "
                     << "Madicine Discription: " << row[3] << endl
                     << " | "
                     << "Expiry Date : " << row[4] << endl
                     << " | "
                     << "QTY : " << row[5] << endl
                     << endl;
                count = 1;
            }
        }
        // Close the file
        fin.close();

        if (count == 0)
            cout << "Record not found\n";
    }

    void update_record()
    {
        // File pointers
        fstream fin, fout;

        // Open an existing record
        fin.open("Madicine.csv", ios::in);

        // Create a new file to store updated data
        fout.open("Madicine_new.csv", ios::out);

        int Madicine_id, property, Madicine_id1, count = 0, i;
        string newdetails;
        int index;
        string line, word;
        vector<string> row;

        // Get the roll number from the user
        cout << "Enter the Madicine ID of the record to be updated: ";
        cin >> Madicine_id;

        // Get the subject to be updated
        cout << "[1] Madicine NAME" << endl
             << "[2] Company Name" << endl
             << "[3] Madicine DETAILS" << endl
             << "[4] Madicine QUANTITY" << endl
             << "[5] Expiry Date" << endl
             << "Enter the Madicine Property : ";
        cin >> property;

        // Determine the index of the subject
        if (property == 1)
        {
            index = 1;
            // Get the new marks
            cout << "Enter new Madicine NAME : ";
            cin >> newdetails;
        }
        else if (property == 2)
        {
            index = 2;
            cout << "Enter new Company NAME : ";
            cin >> newdetails;
        }
        else if (property == 3)
        {
            index = 3;
            cout << "Enter new Madicine DETAILS : ";
            cin >> newdetails;
        }
        else if (property == 4)
        {
            cout << "Enter new QUANTITY : ";
            cin >> newdetails;
            index = 5;
        }
        else if (property == 5)
        {
            cout << "Enter new Madicine EXPIRY DATE(mm/yyyy) : ";
            cin >> newdetails;
            index = 4;
        }
        else
        {
            cout << "Wrong choice. Enter again\n";
            update_record();
            return;
        }

        // Traverse the file
        while (getline(fin, line))
        {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            stringstream convert(row[0]);
            convert >> Madicine_id1;

            if (Madicine_id1 == Madicine_id)
            {
                count = 1;
                row[index] = newdetails;

                for (i = 0; i < row.size() - 1; i++)
                {
                    fout << row[i] << ", "; // Write updated row to new file
                }
                fout << row.back() << "\n";
            }
            else
            {
                for (i = 0; i < row.size() - 1; i++)
                {
                    fout << row[i] << ", "; // Write existing row to new file
                }
                fout << row.back() << "\n";
            }
        }
        fin.close();
        fout.close();

        // Remove the existing file
        if (remove("Madicine.csv") != 0)
        {
            perror("Error deleting file");
        }

        // Rename the updated file
        if (rename("Madicine_new.csv", "Madicine.csv") != 0)
        {
            perror("Error renaming file");
        }

        if (count == 0)
            cout << "Record not found\n";
    }
    void delete_record()
    {
        // File pointers
        fstream fin, fout;

        // Open the existing file
        fin.open("Madicine.csv", ios::in);

        // Create a new file to store non-deleted data
        fout.open("Madicine_new.csv", ios::out);

        int count = 0, i;
        string Madicine_id, Madicine_id1, Madicine_name, Madicine_company, line, word;
        vector<string> row;

        // Get the roll number
        cout << "Enter Company name or spacific Madicine name of the record to be deleted: ";
        cin >> Madicine_id;
        for (char &c : Madicine_id)
        {
            c = tolower(c);
        }
        // Check if this record exists
        // If exists, leave it and
        // add all other data to the new file
        while (getline(fin, line))
        {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            removeSpaces(row[0]);
            removeSpaces(row[1]);
            removeSpaces(row[2]);
            for (char &c : row[1])
            {
                c = tolower(c);
            }
            for (char &c : row[2])
            {
                c = tolower(c);
            }
            Madicine_id1 = row[0];
            Madicine_name = row[1];
            Madicine_company = row[2];

            if (Madicine_id1 != Madicine_id && Madicine_name != Madicine_id && Madicine_company != Madicine_id)
            {
                for (i = 0; i < row.size() - 1; i++)
                {
                    fout << row[i] << ", ";
                }
                fout << row.back() << "\n";
            }
            else
            {
                count = 1;
            }
        }

        if (count == 1)
        {
            cout << "Record deleted\n";
        }
        else
        {
            cout << "Record not found\n";
        }

        // Close the file pointers
        fin.close();
        fout.close();

        // Remove the existing file
        if (remove("Madicine.csv") != 0)
        {
            perror("Error deleting file");
        }

        // Rename the new file
        if (rename("Madicine_new.csv", "Madicine.csv") != 0)
        {
            perror("Error renaming file");
        }
    }
};

// patient management class
class patient
{
public:
    void create()
    {
        // file pointer
        fstream fout;

        // opens an existing csv file or creates a new file.
        fout.open("patient_Record.csv", ios::out | ios::app);

        cout << "Enter the details " << endl;

        int patient_id, Qty;
        string date, patient_name, patient_age, patient_gender, patient_contect_no, altarnative_contect_no, patient_address, Patient_identity_No, Health_Issue, Dignosis, ward;

        // Read the inputs
        patient_id = randome();
        date = todaydate();
        cin.ignore();
        cout << "Enter Patient  Name : ";
        getline(cin, patient_name);
        cout << "Enter Patient  Age : ";
        getline(cin, patient_age);
        cout << "Enter Patient  Gender : ";
        getline(cin, patient_gender);
        cout << "Enter Patient Contect Number : ";
        getline(cin, patient_contect_no);
        cout << "Enter Alternative Contect Number : ";
        getline(cin, altarnative_contect_no);
        cout << "Enter Patient Address : ";
        getline(cin, patient_address);
        cout << "Enter Patient identity Number : ";
        getline(cin, Patient_identity_No);
        cout << "What Is HEalth Issue of Patient : ";
        getline(cin, Health_Issue);
        cout << "Enter Patient Dignosis : ";
        getline(cin, Dignosis);
        if (patient_gender == "male")
        {
            ward = "m1";
        }
        else
        {
            ward = "f1";
        }
        cout << "\n\nPatient record successfully Added \nDoctore is " << rendomedr() << endl
             << "UID is: " << patient_id << endl
             << "Ward is : " << ward << " " << patient_gender << " Ward" << endl
             << endl;
        // Insert the data to file
        fout
            << patient_id << ", "
            << date << ", "
            << patient_name << ", "
            << patient_age << ", "
            << patient_gender << ", "
            << patient_contect_no << ", "
            << altarnative_contect_no << ", "
            << patient_address << ", "
            << Patient_identity_No << ", "
            << Health_Issue << ", "
            << Dignosis << ","
            << ward << ","
            << rendomedr() << "\n";
        fout.close();
    }

    void read_record()
    {
        // File pointer
        fstream fin;

        // Open an existing file
        fin.open("patient_Record.csv", ios::in);

        vector<string> row;
        string line, word, temp;

        // Read each line from the file
        while (getline(fin, line))
        {

            row.clear();

            // used for breaking words
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            // Print the found data
            cout << row[0] << " | " << row[1] << " | " << row[2] << " | " << row[3] << " | " << row[4] << " | " << row[5] << " | " << row[6] << " | " << row[7] << " | " << row[8] << " | " << row[9] << " | " << row[10] << " | " << row[11] << " | " << row[12] << endl;
        }
        // Close the file
        fin.close();
    }

    void search_record()
    {
        // File pointer
        fstream fin;

        // Open an existing file
        fin.open("patient_Record.csv", ios::in);

        int count = 0;
        string patient_Record_id, patient_Record_id2, patient_name, patient_contect;
        cout << "Enter the patient_Record number or patient_Record name or Company Name to display details: ";
        cin.ignore();
        getline(cin, patient_Record_id);
        removeSpaces(patient_Record_id);
        for (char &c : patient_Record_id)
        {
            c = tolower(c);
        }
        vector<string> row;
        string line, word, temp;

        // Read each line from the file
        while (getline(fin, line))
        {

            row.clear();

            // used for breaking words
            stringstream s(line);

            while (getline(s, word, ','))
            {

                row.push_back(word);
            }

            removeSpaces(row[0]);
            removeSpaces(row[2]);
            removeSpaces(row[8]);
            for (char &c : row[1])
            {
                c = tolower(c);
            }
            for (char &c : row[5])
            {
                c = tolower(c);
            }
            patient_Record_id2 = row[0];
            patient_name = row[2];
            patient_contect = row[5];
            removeSpaces(patient_contect);
            // Compare the roll number
            if (patient_Record_id2 == patient_Record_id || patient_name == patient_Record_id || patient_contect == patient_Record_id || row[8] == patient_Record_id)
            {
                for (char &c : row[2])
                {
                    c = toupper(c);
                }
                for (char &c : row[7])
                {
                    c = toupper(c);
                }
                // Print the found data
                cout << endl
                     << endl
                     << "Details of patient ID #" << row[0] << " :" << endl;
                cout << " | "
                     << "Patient Admission Date : " << row[1] << endl
                     << " | "
                     << "Patient Name : " << row[2] << endl
                     << " | "
                     << "Patient Age : " << row[3] << endl
                     << " | "
                     << "Patient Gender : " << row[4] << endl
                     << " | "
                     << "Patient Mobile : " << row[5] << endl
                     << " | "
                     << "Alternative Mobile No. : " << row[6] << endl
                     << " | "
                     << "Address : " << row[7] << endl
                     << " | "
                     << "Identity Number : " << row[8] << endl
                     << " | "
                     << "Health Issue : " << row[9] << endl
                     << " | "
                     << "Dignosis : " << row[10] << endl
                     << " | "
                     << "Ward : " << row[11] << endl
                     << " | "
                     << "Doctore Name : " << row[12] << endl
                     << endl;
                count = 1;
            }
        }
        // Close the file
        fin.close();

        if (count == 0)
            cout << "Record not found\n";
    }
};

// bill genrate
class bill_generate
{
public:
    void create()
    {
        // file pointer
        fstream fout;

        // opens an existing csv file or creates a new file.
        fout.open("Patient_Bill.csv", ios::out | ios::app);

        cout << "Enter the details " << endl;

        int bill_id, Qty1 = 0, Qty2 = 0, Qty3 = 0, price1 = 0, price2 = 0, price3 = 0, total;

        string User_name, prod1 = "NA", prod2 = "NA", prod3 = "NA", c;

        //  Read the inputs
        bill_id = randome();
        cin.ignore();
        cout << "Enter Name Customer : ";
        getline(cin, User_name);
        cout << "Enter Product 1 : ";
        getline(cin, prod1);
        cout << "Enter Product 1 Quantity(number only) : ";
        cin >> Qty1;
        price1 = randome_price();
        cout << "Do You Want to add More Items?(y/n) : ";
        cin.ignore();
        getline(cin, c);
        if (c == "y" || c == "Y")
        {
            cin.ignore();
            cout << "Enter Product 2: ";
            getline(cin, prod2);
            cout << "Enter Product 2 Quantity(number only) : ";
            cin >> Qty2;
            price2 = randome_price();
            cout << "Do You Want to add More Items?(y/n) : ";
            cin.ignore();
            getline(cin, c);
            if (c == "y" || c == "Y")
            {
                cout << "Enter Product 3 : ";
                getline(cin, prod3);
                cout << "Enter Product 3 Quantity(number only) : ";
                cin >> Qty3;
                price3 = randome_price();
            }
        }
        total = (price1 * Qty1) + (price2 * Qty2) + (price3 * Qty3);
        cout << "Bill Genreted Total Amount is :" << total << endl
             << endl;
        // Insert the data to file
        fout
            << bill_id << ", "
            << User_name << ", "
            << prod1 << ", "
            << Qty1 << ", "
            << prod2 << ", "
            << Qty2 << ", "
            << prod3 << ", "
            << Qty3 << ", "
            << "₹" << total << "\n";
        fout.close();
    }

    void read_record()
    {
        // File pointer
        fstream fin;

        // Open an existing file
        fin.open("Patient_Bill.csv", ios::in);

        vector<string> row;
        string line, word, temp;

        // Read each line from the file
        while (getline(fin, line))
        {

            row.clear();

            // used for breaking words
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            // Print the found data
            cout << row[0] << " | " << row[1] << " | " << row[2] << " | " << row[3] << " | " << row[4] << " | " << row[5] << " | " << row[6] << " | " << row[7] << " | " << row[8] << endl;
        }
        // Close the file
        fin.close();
    }

    void search_record()
    {
        // File pointer
        fstream fin;

        // Open an existing file
        fin.open("Patient_Bill.csv", ios::in);

        int count = 0;
        string Patient_Bill_id, Patient_Bill_id2, patient_name, patient_contect;
        cout << "Enter the Bill number or Customer name display Bill: ";
        cin.ignore();
        getline(cin, Patient_Bill_id);
        removeSpaces(Patient_Bill_id);
        for (char &c : Patient_Bill_id)
        {
            c = tolower(c);
        }
        vector<string> row;
        string line, word, temp;

        // Read each line from the file
        while (getline(fin, line))
        {

            row.clear();

            // used for breaking words
            stringstream s(line);

            while (getline(s, word, ','))
            {

                row.push_back(word);
            }

            removeSpaces(row[0]);
            for (char &c : row[1])
            {
                c = tolower(c);
            }
            Patient_Bill_id2 = row[0];
            patient_name = row[1];
            removeSpaces(patient_name);
            // Compare the roll number
            if (Patient_Bill_id2 == Patient_Bill_id || patient_name == Patient_Bill_id)
            {
                for (char &c : row[1])
                {
                    c = toupper(c);
                }
                // Print the found data
                cout << endl
                     << endl
                     << "Details of Bill ID #" << row[0] << " :" << endl;
                cout << " | "
                     << "Customer Name      : " << row[1] << endl
                     << " | "
                     << "Product 1          : " << row[2] << endl
                     << " | "
                     << "Product 1 Quantity : " << row[3] << endl
                     << " | "
                     << "Product 2          : " << row[4] << endl
                     << " | "
                     << "Product 2 Quantity : " << row[5] << endl
                     << " | "
                     << "Product 3          : " << row[6] << endl
                     << " | "
                     << "Product 3 Quantity : " << row[7] << endl
                     << " | "
                     << "Total Amount       : " << row[8] << endl
                     << endl;
                count = 1;
            }
        }
        // Close the file
        fin.close();

        if (count == 0)
            cout << "Record not found\n";
    }
};
// covid report

int report(string name, string result, string age, string gender, string address, vector<string> symptoms, vector<bool> responses, string pera)
{
    cout << endl
         << "               Department Of Health" << endl
         << "               Government Of India" << endl
         << "               COVID - 19 Test Result" << endl
         << "_____________________________________________________" << endl
         << "| Date OF Test | " << todaydate() << endl
         << "_____________________________________________________" << endl
         << "| Test Center  | RDGMC UJJAIN MP" << endl
         << "_____________________________________________________" << endl
         << "| Case ID      | SYS-COC-DYT-YTL-TRY-" << randome() << endl
         << "_____________________________________________________" << endl
         << "| Sample ID    | SAMP-KIP-2985-" << randome1() << endl
         << "_____________________________________________________" << endl
         << "| Type of Test | RTPCR" << endl
         << "_____________________________________________________" << endl
         << "| Patient Name | " << name << endl
         << "_____________________________________________________" << endl
         << "| Age          | " << age << "Y/" << gender << endl
         << "_____________________________________________________" << endl
         << "| Address      | " << address << endl
         << "_____________________________________________________" << endl
         << "Symptom(s):" << endl;

    for (int i = 0; i < symptoms.size(); i++)
    {
        cout << "\t" << (responses[i] ? "[X]" : "[ ]") << " " << symptoms[i] << endl;
    }

    cout << "_____________________________________________________" << endl
         << "| Result       |\t" << result << endl
         << "_____________________________________________________" << endl
         << pera << endl
         << "Wear a mask and maintain social distance. Call 104 for any assistance." << endl
         << "This is a computer-generated report. No signature is required." << endl
         << endl
         << endl;

    return 0;
}
class covid
{
public:
    int covid19()
    {
        vector<string> symptoms = {
            "Fever",
            "Cough",
            "Shortness of breath",
            "Fatigue",
            "Headache",
            "Tiredness",
            "Pink Eye",
            "Diarrhea",
            "Chest Pain"};

        vector<bool> responses(symptoms.size());
        int count = 0;
        string name, result, age, gender, address, pera;
        cout << "Enter patient's name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter patient's age: ";
        cin >> age;
        cout << "Enter patient's gender (M/F): ";
        cin >> gender;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, address);
        // Collecting user responses for symptoms
        for (int i = 0; i < symptoms.size(); i++)
        {
            char response;
            cout << "Do you have " << symptoms[i] << "? (y/n): ";
            cin >> response;
            responses[i] = (response == 'y' || response == 'Y');
            if (response == 'Y' || response == 'y')
            {
                count++;
            }
        }

        if (count >= symptoms.size() / 2)
        {
            result = "Positive";
            pera = "\n\nYou Are Covid Positive :\n 1.Self-isolate immediately to prevent spread.\n"
                   " 2.Follow guidelines from healthcare providers.Monitor symptoms and\n"
                   " 3. seek medical help if necessary.\n\n";
        }
        else
        {
            result = "Negative";
            pera = "\n\nCongratulation's!! You are Covid Negative but : \n 1. Continue following preventive measures.\n"
                   " 2. Stay updated on public health guidelines.Maintain good hygiene and\n"
                   " 3. avoid close contact with symptomatic individuals.\n\n";
        }

        // Generating the report
        report(name, result, age, gender, address, symptoms, responses, pera);
        create(name, age, gender, address, result);
        return 0;
    }
    int create(string name, string age, string gender, string address, string result)
    {
        fstream fout;

        // opens an existing csv file or creates a new file.
        fout.open("covid_report.csv", ios::out | ios::app);

        // Insert the data to file
        fout
            << "SYS-COC-DYT-YTL-TRY-" << randome() << ","
            << "SAMP-KIP-2985-" << randome1() << ","
            << todaydate() << ", "
            << name << ", "
            << age << ", "
            << gender << ", "
            << address << ", "
            << result << "\n";
        fout.close();
        return 0;
    }
};

// insurance
class insurance
{
public:
    void create()
    {
        string name, age, gender, contectno, mail, identity_proof, document_number, policy_type, premium_type, c, duration, insurance_amount;
        int dura, firstime_amount, pd = 0;
        cin.ignore();
        cout << "Enter Name : ";
        getline(cin, name);
        cout << "Enter Age : ";
        getline(cin, age);
        cout << "Enter Gender : ";
        getline(cin, gender);
        cout << "Enter Contact Number : ";
        getline(cin, contectno);
        cout << "Enter Email Id : ";
        getline(cin, mail);

        do
        {
            cout << "Enter Identity Proof : \n";
            cout << "\t1. Aadhaar Card\n";
            cout << "\t2. EPIC Card\n";
            cout << "\t3. Pan Card\n";
            cout << "\t4. Passport Card\n";
            getline(cin, c);

            if (c == "1")
            {
                identity_proof = "Aadhaar Card";
                break;
            }
            else if (c == "2")
            {
                identity_proof = "EPIC Card";
                break;
            }
            else if (c == "3")
            {
                identity_proof = "Pan Card";
                break;
            }
            else if (c == "4")
            {
                identity_proof = "Passport Card";
                break;
            }
            else
            {
                cout << "\nEnter Right Choise\n";
                continue;
            }
        } while (true);

        cout << "Enter Document Number : ";
        getline(cin, document_number);

        do
        {
            cout << "Enter Policy Type : \n";
            cout << "\t1. Term life insurance\n";
            cout << "\t2. Permanent life insurance\n";
            getline(cin, c);
            if (c == "1")
            {
                policy_type = "Term life insurance";
                do
                {
                    cout << "How Many years time insurance ? :\n";
                    cout << "\t1. 10 Year\n";
                    cout << "\t2. 20 Year\n";
                    cout << "\t3. Any other time duration\n";
                    getline(cin, c);
                    if (c == "1")
                    {
                        duration = "10 year";
                        break;
                    }
                    else if (c == "2")
                    {
                        duration = "20 year";
                        break;
                    }
                    else if (c == "3")
                    {
                        cout << "Enter Customised Time Duration :";
                        getline(cin, duration);
                        break;
                    }
                    else
                    {
                        cout << "\nEnter Right Choise\n";
                        continue;
                    }
                } while (true);
                break;
            }
            else if (c == "2")
            {
                policy_type = "Permanent life insurance";
                duration = "100 year";
                pd = 1;
                break;
            }
            else
            {
                cout << "\nEnter Right Choise\n";
                continue;
            }
        } while (true);
        dura = stoi(duration);
        do
        {
            cout << "Enter Premium Type : \n";
            cout << "\t1. Platinum\n";
            cout << "\t2. Gold\n";
            cout << "\t3. Silver\n";
            getline(cin, c);
            if (c == "1")
            {
                premium_type = "Platinum";
                firstime_amount = ((350 * 12 * 100) / 12) / dura;
                insurance_amount = "₹1000000";
                break;
            }
            else if (c == "2")
            {
                premium_type = "Gold";
                firstime_amount = ((250 * 12 * 100) / 12) / dura;
                insurance_amount = "₹500000";
                break;
            }
            else if (c == "3")
            {
                premium_type = "Silver";
                firstime_amount = ((100 * 12 * 100) / 12) / dura;
                insurance_amount = "₹300000";
                break;
            }
            else
            {
                cout << "\nEnter Right Choise\n";
                continue;
            }
        } while (true);
        if (pd == 1)
        {
            duration = "Life time";
        }

        fstream fout;

        // opens an existing csv file or creates a new file.
        fout.open("insurance_dit.csv", ios::out | ios::app);
        for (char &c : name)
        {
            c = toupper(c);
        }
        for (char &c : gender)
        {
            c = toupper(c);
        }
        for (char &c : document_number)
        {
            c = toupper(c);
        }
        // Insert the data to file
        fout
            << randome() << ","
            << todaydate() << ", "
            << name << ", "
            << age << ", "
            << gender << ", "
            << contectno << ", "
            << mail << ", "
            << identity_proof << ", "
            << document_number << ", "
            << policy_type << ", "
            << premium_type << ", "
            << duration << ", "
            << "NOT CLAIM"
            << ", "
            << firstime_amount << ", "
            << insurance_amount << "\n";
        fout.close();

        cout << endl
             << "Your Insurance is successfully done on date : " << todaydate() << " and Insurance number is : " << randome() << endl;
    }

    void read_record()
    {
        // File pointer
        fstream fin;

        // Open an existing file
        fin.open("insurance_dit.csv", ios::in);

        vector<string> row;
        string line, word, temp;

        // Read each line from the file
        while (getline(fin, line))
        {

            row.clear();

            // used for breaking words
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            // Print the found data
            cout << row[0] << " | " << row[1] << " | " << row[2] << " | " << row[3] << " | " << row[4] << " | " << row[5] << " | " << row[6] << " | " << row[7] << " | " << row[8] << " | " << row[9] << " | " << row[10] << " | " << row[11] << " | " << row[12] << " | " << row[13] << " | " << row[14] << endl;
        }
        // Close the file
        fin.close();
    }

    void search_record()
    {
        // File pointer
        fstream fin;

        // Open an existing file
        fin.open("insurance_dit.csv", ios::in);

        int count = 0;
        string uid, uid2, contectno, mail, document_number;
        cout << "Enter the Insurance Number, Contect Number, Mail or Document Number to display details: ";
        cin.ignore();
        getline(cin, uid);
        removeSpaces(uid);
        for (char &c : uid)
        {
            c = tolower(c);
        }
        vector<string> row;
        string line, word, temp;

        // Read each line from the file
        while (getline(fin, line))
        {

            row.clear();

            // used for breaking words
            stringstream s(line);

            while (getline(s, word, ','))
            {

                row.push_back(word);
            }

            removeSpaces(row[0]);
            removeSpaces(row[5]);
            removeSpaces(row[6]);
            removeSpaces(row[8]);
            for (char &c : row[8])
            {
                c = tolower(c);
            }
            uid2 = row[0];
            contectno = row[5];
            mail = row[6];
            document_number = row[8];
            // Compare the roll number
            if (uid2 == uid || contectno == uid || mail == uid || document_number == uid)
            {
                for (char &c : row[8])
                {
                    c = toupper(c);
                }
                // Print the found data
                cout << endl
                     << endl
                     << "Details of INSURANCE NUMBER #" << row[0] << " :" << endl;
                cout << " | "
                     << "Insurance Date : " << row[1] << endl
                     << " | "
                     << "Name : " << row[2] << endl
                     << " | "
                     << "Age : " << row[3] << endl
                     << " | "
                     << "Gender: " << row[4] << endl
                     << " | "
                     << "Contect Number : " << row[5] << endl
                     << " | "
                     << "Mail ID : " << row[6] << endl
                     << " | "
                     << "Identity Proof : " << row[7] << endl
                     << " | "
                     << "Document Number : " << row[8] << endl
                     << " | "
                     << "Policy Type : " << row[9] << endl
                     << " | "
                     << "Premium Type : " << row[10] << endl
                     << " | "
                     << "Duration : " << row[11] << endl
                     << " | "
                     << "Status : " << row[12] << endl
                     << " | "
                     << "Total Given Amount : ₹" << row[13] << endl
                     << " | "
                     << "Insurance Amount : " << row[14] << endl
                     << endl;
                count = 1;
            }
        }
        // Close the file
        fin.close();

        if (count == 0)
            cout << "Record not found\n";
    }

    void update_record()
    {
        // File pointers
        fstream fin, fout;

        // Open an existing record
        fin.open("insurance_dit.csv", ios::in);

        // Create a new file to store updated data
        fout.open("insurance_dit_new.csv", ios::out);

        int uid, property, uid1, count = 0, i;
        string newdetails, documentnumber;
        int index;
        string line, word;
        vector<string> row;

        // Get the roll number from the user
        cout << "Enter the Insurance number of the record to be updated: ";
        cin >> uid;

        // Get the subject to be updated
        cout << "[1] NAME" << endl
             << "[2] AGE" << endl
             << "[3] CONTECT NUMBER" << endl
             << "[4] MAIL ID" << endl
             << "[5] DOCUMENT" << endl
             << "Enter the Any Property : ";
        cin >> property;

        // Determine the index of the subject
        if (property == 1)
        {
            index = 2;
            // Get the new marks
            cout << "Enter New NAME : ";
            cin >> newdetails;
        }
        else if (property == 2)
        {
            index = 3;
            cout << "Enter new Age NAME : ";
            cin >> newdetails;
        }
        else if (property == 3)
        {
            index = 5;
            cout << "Enter new CONTECT number : ";
            cin >> newdetails;
        }
        else if (property == 4)
        {
            cout << "Enter new MAIL ID  : ";
            cin >> newdetails;
            index = 6;
        }
        else if (property == 5)
        {
            string c;
            do
            {
                cout << "Enter Identity Proof : \n";
                cout << "\t1. Aadhaar Card\n";
                cout << "\t2. EPIC Card\n";
                cout << "\t3. Pan Card\n";
                cout << "\t4. Passport Card\n";
                cin.ignore();
                getline(cin, c);

                if (c == "1")
                {
                    newdetails = "Aadhaar Card";
                    break;
                }
                else if (c == "2")
                {
                    newdetails = "EPIC Card";
                    break;
                }
                else if (c == "3")
                {
                    newdetails = "Pan Card";
                    break;
                }
                else if (c == "4")
                {
                    newdetails = "Passport Card";
                    break;
                }
                else
                {
                    cout << "\nEnter Right Choise\n";
                    continue;
                }
            } while (true);
            index = 7;
            cout << "Enter Document Number : ";
            getline(cin, documentnumber);
        }
        else
        {
            cout << "Wrong choice. Enter again\n";
            update_record();
            return;
        }

        // Traverse the file
        while (getline(fin, line))
        {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            stringstream convert(row[0]);
            convert >> uid1;

            if (uid1 == uid)
            {
                count = 1;
                row[index] = newdetails;
                if (property == 5)
                {
                    row[8] = documentnumber;
                }
                for (i = 0; i < row.size() - 1; i++)
                {
                    fout << row[i] << ", "; // Write updated row to new file
                }
                fout << row.back() << "\n";
            }
            else
            {
                for (i = 0; i < row.size() - 1; i++)
                {
                    fout << row[i] << ", "; // Write existing row to new file
                }
                fout << row.back() << "\n";
            }
        }
        fin.close();
        fout.close();

        // Remove the existing file
        if (remove("insurance_dit.csv") != 0)
        {
            perror("Error deleting file");
        }

        // Rename the updated file
        if (rename("insurance_dit_new.csv", "insurance_dit.csv") != 0)
        {
            perror("Error renaming file");
        }

        if (count == 0)
            cout << "Record not found\n";
    }

    void claimInsurance()
    {
        // File pointers
        fstream fin, fout;

        // Open an existing record
        fin.open("insurance_dit.csv", ios::in);

        // Create a new file to store updated data
        fout.open("insurance_dit_new.csv", ios::out);

        int policynumber, policynumber1, input, count = 0, i;
        string newdetails, documentnumber;
        int index;
        string line, word;
        vector<string> row;

        // Get the roll number from the user
        cout << "Enter the Insurance number of the record to be updated: ";
        cin >> policynumber;

        // Determine the index of the subject

        // Traverse the file
        while (getline(fin, line))
        {
            row.clear();
            stringstream s(line);

            while (getline(s, word, ','))
            {
                row.push_back(word);
            }

            stringstream convert(row[0]);
            convert >> policynumber1;

            if (policynumber1 == policynumber)
            {
                cout << "Enter Your Document Number : ";
                cin >> input;

                if (stoi(row[8]) == input)
                {
                    row[index] = newdetails;

                    for (i = 0; i < row.size() - 1; i++)
                    {
                        fout << row[i] << ", "; // Write updated row to new file
                    }
                    fout << row.back() << "\n";
                }
                else
                {
                    cout << "Please Enter Right Documentation Number";
                    continue;
                }
            }
            else
            {
                // cout << "Please Enter right policy number";
                for (i = 0; i < row.size() - 1; i++)
                {
                    fout << row[i] << ", "; // Write existing row to new file
                }
                fout << row.back() << "\n";
            }
        }
        fin.close();
        fout.close();

        // Remove the existing file
        if (remove("insurance_dit.csv") != 0)
        {
            perror("Error deleting file");
        }

        // Rename the updated file
        if (rename("insurance_dit_new.csv", "insurance_dit.csv") != 0)
        {
            perror("Error renaming file");
        }

        if (count == 0)
            cout << "Record not found\n";
    }
};

// Inventory FUNCTION
int inventoryfun()
{
    inventory prdcts;
    int choice;
    cout << endl
         << "━━━━━━━━|| Madicine PAGE ||━━━━━━━━" << endl;
    do
    {
        cout << "[1] Create New Madicine" << endl
             << "[2] Search Madicine" << endl
             << "[3] DISPLAY Madicine" << endl
             << "[4] UPDATE Madicine DATA" << endl
             << "[5] DELETE Madicine" << endl
             << "[0] Exit" << endl
             << "Enter Your Choise : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            prdcts.create();
            break;
        case 2:
            prdcts.search_record();
            break;
        case 3:
            prdcts.read_record();
            break;
        case 4:
            prdcts.update_record();
            break;
        case 5:
            prdcts.delete_record();
            break;
        case 0:
            cout << endl
                 << "Exiting Madicine dashboard." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter again." << endl;
            break;
        }
    } while (true);

    return 0;
}
// patient record Function
int patientfun()
{

    patient prdcts;
    int choice;
    cout << endl
         << "━━━━━━━━|| patient_Record PAGE ||━━━━━━━━" << endl;
    do
    {
        cout << "[1] Create New patient Record" << endl
             << "[2] Search patient Record" << endl
             << "[3] DISPLAY patient Record" << endl
             << "[0] Exit" << endl
             << "Enter Your Choise : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            prdcts.create();
            break;
        case 2:
            prdcts.search_record();
            break;
        case 3:
            prdcts.read_record();
            break;
        case 0:
            cout << endl
                 << "Exiting Patient Record dashboard." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter again." << endl;
            break;
        }
    } while (true);

    return 0;
}

// Patient_Bill FUNCTION
int bill()
{

    bill_generate prdcts;
    int choice;
    cout << endl
         << "━━━━━━━━|| Patient_Bill PAGE ||━━━━━━━━" << endl;
    do
    {
        cout << "[1] Create New  Bill" << endl
             << "[2] Search Bill" << endl
             << "[3] DISPLAY Bills" << endl
             << "[0] Exit" << endl
             << "Enter Your Choise : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            prdcts.create();
            break;
        case 2:
            prdcts.search_record();
            break;
        case 3:
            prdcts.read_record();
            break;
        case 0:
            cout << endl
                 << "Exiting Bill Management Dashboard." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter again." << endl;
            break;
        }
    } while (true);

    return 0;
}
// covid function
void covidfun()
{
    covid covid_obj;
    covid_obj.covid19();
}
// insurance function
int insurancefun()
{

    insurance insu;
    int choice;
    cout << endl
         << "━━━━━━━━|| INSURANCE PAGE ||━━━━━━━━" << endl;
    do
    {
        cout << endl
             << endl
             << "[1] Buy new Insurance" << endl
             << "[2] Search Insurance" << endl
             << "[3] Update Insurance" << endl
             << "[4] Display All insurance" << endl
             << "[5] Claim Insurance" << endl
             << "[0] Exit" << endl
             << "Enter Your Choise : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insu.create();
            break;
        case 2:
            insu.search_record();
            break;
        case 3:
            insu.update_record();
            break;
        case 4:
            insu.read_record();
            break;
        case 5:
            insu.claimInsurance();
            break;
        case 0:
            cout << endl
                 << "Exiting Insurance dashboard." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter again." << endl;
            break;
        }
    } while (true);

    return 0;
}

// MAIN FUNCTION
int main()
{
    string username, userpass;
    cout << endl
         << "Enter User Name : ";
    cin >> username;
    cout << endl
         << "Enter User Password : ";
    cin >> userpass;
    if (username == "admin" && userpass == "Admin@123")
    {
        int n;
        cout << endl
             << " ****************************************" << endl
             << "*  WELCOME TO CRYSIS MANAGEMENT SYSTEM  *" << endl
             << "*               (COVID-19)              *" << endl
             << " ****************************************" << endl;
        do
        {
            cout << endl
                 << "1. Inventory" << endl
                 << "2. Patient Record Management" << endl
                 << "3. Billing Department" << endl
                 << "4. Covid-19 identification" << endl
                 << "5. Insurance Management" << endl
                 << "0. Exit" << endl
                 << "Enter Your Choice : ";
            cin >> n;
            cout << endl;
            switch (n)
            {
            case 1:
                inventoryfun();
                break;
            case 2:
                patientfun();
                break;
            case 3:
                bill();
                break;
            case 4:
                covidfun();
                break;
            case 5:
                insurancefun();
                break;
            case 0:
                cout << endl
                     << "Byy! I See You Again....";
                cout << endl
                     << "****************************************" << endl
                     << "*              DEVELOPED BY            *" << endl
                     << "*           ___________________        *" << endl
                     << "*          | Aaditya Raj Singh |       *" << endl
                     << "*           ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾        *" << endl
                     << "*                THANKYOU              *" << endl
                     << "****************************************" << endl;
                return 0;
            default:
                cout << "Please Enter Right Choice";
                continue;
            }

        } while (true);
    }
    else
    {
        cout << "Please Enter Right USER NAME & PASSWORD";
        main();
    }

    return 0;
}