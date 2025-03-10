#include<bits/stdc++.h>
#define MAX_BOOK_TYPES 5
#define MAX_AUTHOR_NUM 3
#define MAX_NUMOFBOOKS 10
#define MAX_NUM_OF_BORROWERS 50
#define MAX_NUM_OF_BORROW_BOOKS 7
#define MAX_NUM_OF_FEEDBACKS 50
#define MAX_NUM_OF_STAFF 20
#define MAX_NUM_OF_THESIS 50
#define NUMBER_OF_BRANCHES 5
#define MAXBOOK 15
using namespace std;

struct Book{
    //david
    string bookname;
    string authorname[MAX_AUTHOR_NUM];
    int numofauthors;
    long long int ISBN;
    string booktype;
    int pubyear;
    string publisher;
    string language;
    int edition;
    int numberofbooks;
};

struct Department{
    Book book[MAXBOOK];
   int size=10;//initialized to 10 Maximum is 15
};
Department department[5];

struct staff{
    //jaisheesh
    string name;
    int age;
    char gender;
    string position;
    int date,month,year;
    string emailid;
    string Address;
    long long phonenum;
};

struct borrowers{
    //vidath and aditya
    string borrowername;
    int borrowerage;
    char borrowergender;
    string borrowermail;
    long long borrowerphonenum;
    int membershipexpdate,membershipexpmonth,membershipexpyear;
   // bool booktaken;
    string bookname[MAX_NUM_OF_BORROW_BOOKS];
    int numberofbookstaken=0;
}; vector<borrowers>total_borrowers;

struct feedback{
    // ravi
    string feedbackgiver;
    int feedbackdate,feedbackmonth,feedbackyear;
    int rating;
    string feedbackcontent;
};

struct thesis {
    string thesisname;
    string nameAuthor;
    int thesisyear;
    string branch;
};

class library{
    //book b[MAX_BOOK_TYPES][MAX_NUMOFBOOKS];
    feedback f[MAX_NUM_OF_FEEDBACKS];
    //borrowers bow[MAX_NUM_OF_BORROWERS];
    staff s[MAX_NUM_OF_STAFF];
    thesis t[NUMBER_OF_BRANCHES][MAX_NUM_OF_THESIS];
    float avgrating;
    int numoffeedbackstaken;//related to feedback
    int number_of_staff;
    int number_of_thesis_per_branch[NUMBER_OF_BRANCHES]; // related to thesis
    int number_of_thesis; // related to thesis

public:
    library() {
         unordered_map<int, pair<string,pair<string, pair<int, pair<string, pair<string, pair<string, pair<string, string>>>>>>>> Staff=StaffDetails();
        //feedback related info in constructor all completed.
        numoffeedbackstaken = 0;
        avgrating = 0;

        //thesis related info in constructor all completed
        number_of_thesis_per_branch[0] = 6;
        number_of_thesis_per_branch[1] = 5;
        number_of_thesis_per_branch[2] = 5;
        number_of_thesis_per_branch[3] = 5;
        number_of_thesis_per_branch[4] = 5;

        // Computer Science

        t[0][0] = {"A Neural Architecture Search for Automated Multimodal Learning", "Singh A, Nair H", 2022, "Computer Science"};
        t[0][1] = {"Securing multimedia videos using space-filling curves", "Sadhya D, Rathore SS, Rajput AS, Anand A", 2022, "Computer Science"};
        t[0][2] = {"A novel Deep ML framework for multi-classification of breast cancer based on transfer learning", "Sharma M, Mandloi A, Bhattacharya M", 2022, "Computer Science"};
        t[0][3] = {"Towards a super-resolution based approach for improved face recognition in low resolution environment", "Singh N, Rathore SS, Kumar S", 2022, "Computer Science"};
        t[0][4] = {"Coverage hole detection using social spider optimized Gaussian Mixture Model", "Gupta A, Kumar S, Pattanaik M", 2022, "Computer Science"};
        t[0][5] = {"Fake and Live Fingerprint Detection Using Local Diagonal Extrema Pattern and Local Phase Quantization", "Agarwal R, Jalal AS, Agrawal SC & Arya KV", 2021, "Computer Science"};

       // Mathematics and Computing
        t[1][0] = {"Nonlinear Spline Adaptive Filters based on a Low Rank Approximation", "Bhattacharjee SS, Patel V, George NV", 2022, "Mathematics and Computing"};
        t[1][1] = {"An eco-epidemic model with seasonal variability: a non-autonomous model", "Gupta J, Dhar J, Sinha P", 2022, "Mathematics and Computing"};
        t[1][2] = {"Trapezoidal Intuitionistic Fuzzy Power Heronian Aggregation Operator and Its Applications to Multiple-Attribute Group Decision-Making", "Selvaraj J, Gatiyala P, Hashemkhani Zolfani S", 2022, "Mathematics and Computing"};
        t[1][3] = {"A note on multi-criteria decision-making using a complete ranking of generalized trapezoidal fuzzy numbers", "Jeevraj S", 2022, "Mathematics and Computing"};
        t[1][4] = {"Modeling effects of impulsive control strategies on the spread of mosquito borne disease: role of latent period", "Sisodiya OS, Misra OP, Dhar J", 2022, "Mathematics and Computing"};

        // Electrical and Electronics
        t[2][0] = {"AERPSO — An adaptive exploration robotic PSO based cooperative algorithm for multiple target searching", "Garg V, Shukla A, Tiwari R", 2022, "Electrical and Electronics"};
        t[2][1] = {"Microstrip line fed dielectric resonator antenna optimization using machine learning algorithms", "Singh O, Bharamagoudra MR, Gupta H, Dwivedi AK, Ranjan P, Sharma A", 2022, "Electrical and Electronics"};
        t[2][2] = {"A compact, high isolation building block for 8 × 8 multi-input multi-output antenna array suitable for 5G smartphone applications", "Gupta SK, Bage A, Ranjan", 2022, "Electrical and Electronics"};
        t[2][3] = {"Design and Implementation of Low Power, High-Speed Configurable Approximation 8-Bit Booth Multiplier", "Kumar S, Poonia M, Kumar R, Sharma G, Kumar S", 2022, "Electrical and Electronics"};
        t[2][4] = {"Hybrid feedback active noise control headset based on binaural signal utilization", "Patel V, Bhattacharjee SS, Cheer J, George NV", 2022, "Electrical and Electronics"};

        // Information Technology
        t[3][0] = {"Predictive modeling for suspicious content identification on Twitter", "Gangwar SS, Rathore SS, Chouhan SS, Soni S", 2022, "Information and Technology"};
        t[3][1] = {"A Green Hybrid Congestion Management Scheme for IoT-Enabled WSNs", "Kaur G, Chanak P, Bhattacharya M", 2022, "Information and Technology"};
        t[3][2] = {"Understanding general concepts of requirements engineering through design thinking: An experimental study with students", "Tiwari S, Rathore SS", 2022, "Information and Technology"};
        t[3][3] = {"Modelling the barriers of weather index insurance service adoption integrating expert mining and ISM Fuzzy-MICMAC", "Singh P, Agrawal G", 2022, "Information and Technology"};
        t[3][4] = {"Applications of blockchain in government education sector: a comprehensive review and future research potentials", "Dash MK, Panda G, Kumar A, Luthra S", 2022, "Information and Technology"};

        // Business Management
        t[4][0] = {"Mapping the customer centric weather index insurance service design using quality function deployment", "Singh P, Agrawal G", 2022, "Business Management"};
        t[4][1] = {"Exploring enablers of modularity in healthcare service delivery", "Prakash G", 2022, "Business Management"};
        t[4][2] = {"What Do We Know About Customer Churn Behaviour in the Telecommunication Industry? A Bibliometric Analysis of Research Trends, 1985–2019", "Bhattacharyya J, Dash MK", 2022, "Business Management"};
        t[4][3] = {"Causal modelling of the enablers of CPFR for building resilience in manufacturing supply chains", "Hemant J, Rajesh R, Daultani Y", 2022, "Business Management"};
        t[4][4] = {"Investigating the barriers to growth in the Indian food processing sector", "Singh G, Daultani Y, Sahu R", 2022, "Business Management"};

        //constructor related to book by david and hima

        department[0].book[0].bookname = "Computer Networking: A Top-Down Approach";
        department[0].book[0].authorname[0] = "James F. Kurose"; department[0].book[0].authorname[1] = "Keith W. Ross";
        department[0].book[0].numofauthors = 2;
        department[0].book[0].ISBN= 133594149;
        department[0].book[0].booktype = "Computer Engineering";
        department[0].book[0].pubyear = 2021;
        department[0].book[0].publisher = "Pearson";
        department[0].book[0].language = "English";
        department[0].book[0].edition = 1;
        department[0].book[0].numberofbooks = 10;
        //now we are gonna fill details of second book in cse category
        department[0].book[1].bookname = "Computer Organization and Design";
        department[0].book[1].authorname[0] = "David A. Patterson"; department[0].book[0].authorname[1] = "John L. Hennessy";
        department[0].book[1].numofauthors = 2;
        department[0].book[1].ISBN = 128119055;
        department[0].book[1].booktype = "Computer Engineering";
        department[0].book[1].pubyear = 2017;
        department[0].book[1].publisher = "Morgan Kaufmann";
        department[0].book[1].language = "English";
        department[0].book[1].edition = 6;
        department[0].book[1].numberofbooks = 10;
        //now we are gonna fill details of third book in cse category
        department[0].book[2].bookname = "Introduction to Algorithms";
        department[0].book[2].authorname[0] = "Thomas H. Cormen";

        department[0].book[2].numofauthors = 1;
        department[0].book[2].ISBN = 262033844;
        department[0].book[2].booktype = "Computer Engineering";
        department[0].book[2].pubyear = 2009;
        department[0].book[2].publisher = "The MIT Press";
        department[0].book[2].language = "English";
        department[0].book[2].edition = 2;
        department[0].book[2].numberofbooks = 10;
        //now we are gonna fill details of the fourth book in cse category
        department[0].book[3].bookname = "Operating System Concepts";
        department[0].book[3].authorname[0] = "Abraham Silberschatz";
        department[0].book[3].numofauthors = 1;
        department[0].book[3].ISBN = 1118063333;
        department[0].book[3].booktype = "Computer Engineering";
        department[0].book[3].pubyear = 2012;
        department[0].book[3].publisher = "Wiley";
        department[0].book[3].language = "English";
        department[0].book[3].edition = 7;
        department[0].book[3].numberofbooks = 10;
        //now we are gonna fill details of the 5th book in cse category
        department[0].book[4].bookname = "Computer Networks";
        department[0].book[4].authorname[0] = "Andrew S. Tanenbaum";
        department[0].book[4].numofauthors = 1;
        department[0].book[4].ISBN = 133594149;
        department[0].book[4].booktype = "Computer Engineering";
        department[0].book[4].pubyear = 2020;
        department[0].book[4].publisher = "Pearson";
        department[0].book[4].language = "English";
        department[0].book[4].edition = 5;
        department[0].book[4].numberofbooks= 10;
        //now we are gonna fill details of the 6th book in cse category
        department[0].book[5].bookname = "Software Engineering: A Practitioner's Approach";
        department[0].book[5].authorname[0] = "Roger S. Pressman";
        department[0].book[5].numofauthors = 1;
        department[0].book[5].ISBN = 78022126;
        department[0].book[5].booktype = "Computer Engineering";
        department[0].book[5].pubyear = 2015;
        department[0].book[5].publisher = "McGraw-Hill Education";
        department[0].book[5].language = "English";
        department[0].book[5].edition = 3;
        department[0].book[5].numberofbooks = 10;

        department[0].book[6].bookname = "The Art of Computer Programming";
        department[0].book[6].authorname[0] = "Donald E. Knuth";
        department[0].book[6].numofauthors = 1;
        department[0].book[6].ISBN= 321751043;
        department[0].book[6].booktype = "Computer Engineering";
        department[0].book[6].pubyear = 2011;
        department[0].book[6].publisher = "Addison-Wesley Professional";
        department[0].book[6].language = "English";
        department[0].book[6].edition = 1;
        department[0].book[6].numberofbooks = 10;

        department[0].book[7].bookname = "Database Management Systems";
        department[0].book[7].authorname[0]= "Raghu Ramakrishnan";
        department[0].book[7].numofauthors = 1;
        department[0].book[7].ISBN = 72465638;
        department[0].book[7].booktype = "Computer Engineering";
        department[0].book[7].pubyear = 2002;
        department[0].book[7].publisher = "McGraw-Hill Education";
        department[0].book[7].language = "English";
        department[0].book[7].edition = 1;
        department[0].book[7].numberofbooks = 10;

        department[0].book[8].bookname = "Computer Graphics: Principles and Practice";
        department[0].book[8].authorname[0] = "John F. Hughes";
        department[0].book[8].numofauthors = 1;
        department[0].book[8].ISBN = 321399528;
        department[0].book[8].booktype = "Computer Engineering";
        department[0].book[8].pubyear = 2013;
        department[0].book[8].publisher = "Addison-Wesley Professional";
        department[0].book[8].language = "English";
        department[0].book[8].edition = 1;
        department[0].book[8].numberofbooks = 10;

        // Adding details for the 10th book
        department[0].book[9].bookname = "Computer Architecture: A Quantitative Approach";
        department[0].book[9].authorname[0] = "John L. Hennessy";
        department[0].book[9].numofauthors = 1;
        department[0].book[9].ISBN = 12383872;
        department[0].book[9].booktype = "Computer Engineering";
        department[0].book[9].pubyear = 2011;
        department[0].book[9].publisher = "Morgan Kaufmann";
        department[0].book[9].language = "English";
        department[0].book[9].edition = 1;
        department[0].book[9].numberofbooks = 10;

        //department[1]. refer to the books which come under the engineering mathematics category category and we have given 10 books for each category
        department[1].book[0].bookname = "Advanced Engineering Mathematics";
        department[1].book[0].authorname[0] = "Erwin Kreyszig";
        department[1].book[0].numofauthors = 1;
        department[1].book[0].ISBN = 9780470458365;
        department[1].book[0].booktype = "Engineering Mathematics";
        department[1].book[0].pubyear = 2011;
        department[1].book[0].publisher = "Wiley";
        department[1].book[0].language = "English";
        department[1].book[0].edition = 6;
        department[1].book[0].numberofbooks = 10;

        department[1].book[2].bookname = "Higher Engineering Mathematics";
        department[1].book[2].authorname[0] = "B. S. Grewal";
        department[1].book[2].numofauthors = 1;
        department[1].book[2].ISBN = 9789352606459;
        department[1].book[2].booktype = "Engineering Mathematics";
        department[1].book[2].pubyear = 2019;
        department[1].book[2].publisher = "Khanna Publishers";
        department[1].book[2].language = "English";
        department[1].book[2].edition = 1;
        department[1].book[2].numberofbooks = 10;

        // Add details for the remaining books
        department[1].book[3].bookname = "Mathematics for Engineers";
        department[1].book[3].authorname[0] = "Anthony Croft";

        department[1].book[3].numofauthors = 1;
        department[1].book[3].ISBN= 9780273742873;
        department[1].book[3].booktype = "Engineering Mathematics";
        department[1].book[3].pubyear = 2011;
        department[1].book[3].publisher = "Pearson";
        department[1].book[3].language = "English";
        department[1].book[3].edition = 1;
        department[1].book[3].numberofbooks = 10;

        department[1].book[4].bookname = "Engineering Mathematics: A Foundation for Electronic, Electrical, Communications, and Systems Engineers";
        department[1].book[4].authorname[0] = "Anthony Croft";

        department[1].book[4].numofauthors = 1;
        department[1].book[4].ISBN = 9781292102209;
        department[1].book[4].booktype= "Engineering Mathematics";
        department[1].book[4].pubyear = 2017;
        department[1].book[4].publisher = "Pearson";
        department[1].book[4].language = "English";
        department[1].book[4].edition = 1;
        department[1].book[4].numberofbooks = 10;

        department[1].book[5].bookname = "Engineering Mathematics Pocket Book";
        department[1].book[5].authorname[0] = "John Bird";
        department[1].book[5].numofauthors = 1;
        department[1].book[5].ISBN = 9781138849962;
        department[1].book[5].booktype = "Engineering Mathematics";
        department[1].book[5].pubyear = 2017;
        department[1].book[5].publisher = "Routledge";
        department[1].book[5].language = "English";
        department[1].book[5].edition = 1;
        department[1].book[5].numberofbooks = 10;

        department[1].book[6].bookname = "Schaum's Outline of Advanced Mathematics for Engineers and Scientists";
        department[1].book[6].authorname[0] = "Murray R. Spiegel";
        department[1].book[6].authorname[1] = "Robert E. Wrede";
        department[1].book[6].numofauthors = 2;
        department[1].book[6].ISBN = 9780071702423;
        department[1].book[6].booktype= "Engineering Mathematics";
        department[1].book[6].pubyear = 2009;
        department[1].book[6].publisher = "McGraw-Hill Education";
        department[1].book[6].language = "English";
        department[1].book[6].edition = 1;
        department[1].book[6].numberofbooks = 10;

        department[1].book[7].bookname = "Practical Engineering Mathematics";
        department[1].book[7].authorname[0] = "Bill Bolton";
        department[1].book[7].numofauthors = 1;
        department[1].book[7].ISBN = 9780750640122;
        department[1].book[7].booktype = "Engineering Mathematics";
        department[1].book[7].pubyear = 1999;
        department[1].book[7].publisher = "Newnes";
        department[1].book[7].language = "English";
        department[1].book[7].edition= 1;
        department[1].book[7].numberofbooks = 10;

        department[1].book[8].bookname = "Fundamentals of Engineering Mathematics";
        department[1].book[8].authorname[0] = "S. Shankar";
        department[1].book[8].authorname[1] = "M. Venkataraman";
        department[1].book[8].numofauthors = 2;
        department[1].book[8].ISBN = 9788120330963;
        department[1].book[8].booktype = "Engineering Mathematics";
        department[1].book[8].pubyear = 2009;
        department[1].book[8].publisher = "Prentice Hall";
        department[1].book[8].language = "English";
        department[1].book[8].edition = 1;
        department[1].book[8].numberofbooks = 10;

        department[1].book[9].bookname = "Essential Engineering Mathematics";
        department[1].book[9].authorname[0] = "Michael Batty";
        department[1].book[9].numofauthors = 1;
        department[1].book[9].ISBN = 9780080453360;
        department[1].book[9].booktype = "Engineering Mathematics";
        department[1].book[9].pubyear = 2003;
        department[1].book[9].publisher = "Butterworth-Heinemann";
        department[1].book[9].language = "English";
        department[1].book[9].edition = 1;
        department[1].book[9].numberofbooks = 10;

        //department[2]. refer to the books which come under the eee category and we have given 10 books for each category
                //now in eee category we have our first book

        department[2].book[0].bookname = "Principles of Electric Circuits: Conventional Current Version";
        department[2].book[0].authorname[0] = "Thomas L. Floyd"; department[2].book[0].authorname[1] = "David Buchla";
        department[2].book[0].numofauthors = 2;
        department[2].book[0].ISBN = 9780135073087;
        department[2].book[0].booktype = "Electrical and Electronics Engineering";
        department[2].book[0].pubyear = 2010;
        department[2].book[0].publisher = "Pearson";
        department[2].book[0].language = "English";
        department[2].book[0].edition = 1;
        department[2].book[0].numberofbooks= 10;

        department[2].book[1].bookname = "Microelectronic Circuits";
        department[2].book[1].authorname[0] = "Adel S. Sedra";
        department[2].book[1].authorname[1] = "Kenneth C. Smith";
        department[2].book[1].numofauthors = 2;
        department[2].book[1].ISBN = 9780199339136;
        department[2].book[1].booktype = "Electrical and Electronics Engineering";
        department[2].book[1].pubyear = 2014;
        department[2].book[1].publisher = "Oxford University Press";
        department[2].book[1].language = "English";
        department[2].book[1].edition = 1;
        department[2].book[1].numberofbooks = 10;

        department[2].book[2].bookname = "Electric Machines and Drives: Principles, Control, Modeling, and Simulation";
        department[2].book[2].authorname[0] = "Shaahin Filizadeh";
        department[2].book[2].authorname[1] = "Mehdi Narimani";
        department[2].book[2].numofauthors = 2;
        department[2].book[2].ISBN = 9781119108159;
        department[2].book[2].booktype = "Electrical and Electronics Engineering";
        department[2].book[2].pubyear = 2016;
        department[2].book[2].publisher = "Wiley";
        department[2].book[2].language = "English";
        department[2].book[2].edition = 1;
        department[2].book[2].numberofbooks = 10;


        department[2].book[3].bookname = "Power Electronics: Converters, Applications, and Design";
        department[2].book[3].authorname[0] = "Ned Mohan";

        department[2].book[3].numofauthors = 1;
        department[2].book[3].ISBN = 9781118065605;
        department[2].book[3].booktype = "Electrical and Electronics Engineering";
        department[2].book[3].pubyear = 2014;
        department[2].book[3].publisher = "Wiley";
        department[2].book[3].language= "English";
        department[2].book[3].edition = 1;
        department[2].book[3].numberofbooks = 10;

        department[2].book[4].bookname = "Modern Control Engineering";
        department[2].book[4].authorname[0] = "Katsuhiko Ogata";
        department[2].book[4].numofauthors = 1;
        department[2].book[4].ISBN = 9780136156734;
        department[2].book[4].booktype = "Electrical and Electronics Engineering";
        department[2].book[4].pubyear = 2009;
        department[2].book[4].publisher = "Pearson";
        department[2].book[4].language = "English";
        department[2].book[4].edition = 1;
        department[2].book[4].numberofbooks = 10;

        department[2].book[5].bookname = "Digital Integrated Circuits: A Design Perspective";
        department[2].book[5].authorname[0] = "Jan M. Rabaey";

        department[2].book[5].numofauthors= 1;
        department[2].book[5].ISBN = 9780130909961;
        department[2].book[5].booktype = "Electrical and Electronics Engineering";
        department[2].book[5].pubyear = 2003;
        department[2].book[5].publisher = "Pearson";
        department[2].book[5].language = "English";
        department[2].book[5].edition = 1;
        department[2].book[5].numberofbooks = 10;

        department[2].book[6].bookname = "Communication Systems";
        department[2].book[6].authorname[0] = "Simon Haykin";
        department[2].book[6].authorname[1]= "Michael Moher";
        department[2].book[6].numofauthors = 2;
        department[2].book[6].ISBN = 9780471697909;
        department[2].book[6].booktype = "Electrical and Electronics Engineering";
        department[2].book[6].pubyear = 2007;
        department[2].book[6].publisher = "Wiley";
        department[2].book[6].language = "English";
        department[2].book[6].edition = 1;
        department[2].book[6].numberofbooks = 10;

        department[2].book[7].bookname = "Engineering Electromagnetics";
        department[2].book[7].authorname[0] = "William H. Hayt Jr.";
        department[2].book[7].authorname[1] = "John A. Buck";
        department[2].book[7].numofauthors = 2;
        department[2].book[7].ISBN = 9780071222281;
        department[2].book[7].booktype = "Electrical and Electronics Engineering";
        department[2].book[7].pubyear = 2006;
        department[2].book[7].publisher= "McGraw-Hill Education";
        department[2].book[7].language = "English";
        department[2].book[7].edition = 1;
        department[2].book[7].numberofbooks = 10;

        department[2].book[8].bookname = "Power System Analysis";
        department[2].book[8].authorname[0] = "Charles A. Gross";
        department[2].book[8].authorname[1] = "William H. Marion";
        department[2].book[8].numofauthors = 2;
        department[2].book[8].ISBN = 9780136919902;
        department[2].book[8].booktype = "Electrical and Electronics Engineering";
        department[2].book[8].pubyear = 1998;
        department[2].book[8].publisher = "Prentice Hall";
        department[2].book[8].language = "English";
        department[2].book[8].edition = 1;
        department[2].book[8].numberofbooks = 10;

        department[2].book[9].bookname = "Electronic Devices and Circuit Theory";
        department[2].book[9].authorname[0] = "Robert L. Boylestad";
        department[2].book[9].authorname[1] = "Louis Nashelsky";
        department[2].book[9].numofauthors = 2;
        department[2].book[9].ISBN = 9780135026496;
        department[2].book[9].booktype = "Electrical and Electronics Engineering";
        department[2].book[9].pubyear = 2012;
        department[2].book[9].publisher = "Pearson";
        department[2].book[9].language = "English";
        department[2].book[9].edition = 1;
        department[2].book[9].numberofbooks = 10;

        //department[3]. refer to the books which come under the mba category and we have given 10 books for each category
            //now in mba category we have our first book
        department[3].book[0].bookname = "The Personal MBA: Master the Art of Business";
        department[3].book[0].authorname[0] = "Josh Kaufman";
        department[3].book[0].numofauthors = 1;
        department[3].book[0].ISBN = 1591845572;
        department[3].book[0].booktype = "Business & Economics";
        department[3].book[0].pubyear = 2010;
        department[3].book[0].publisher = "Portfolio";
        department[3].book[0].language = "English";
        department[3].book[0].edition = 1;
        department[3].book[0].numberofbooks = 10;

        department[3].book[1].bookname= "Case in Point: Complete Case Interview Preparation";
        department[3].book[1].authorname[0] = "Marc P. Cosentino";
        department[3].book[1].numofauthors = 1;
        department[3].book[1].ISBN = 986370711;
        department[3].book[1].booktype = "Business & Money";
        department[3].book[1].pubyear = 2016;
        department[3].book[1].publisher= "Burgee Press";
        department[3].book[1].language = "English";
        department[3].book[1].edition = 1;
        department[3].book[1].numberofbooks = 10;

        // Add details for the remaining books
        department[3].book[2].bookname = "The Lean Startup: How Today's Entrepreneurs Use Continuous Innovation to Create Radically Successful Businesses";
        department[3].book[2].authorname[0] = "Eric Ries";
        department[3].book[2].numofauthors = 1;
        department[3].book[2].ISBN = 307887898;
        department[3].book[2].booktype = "Startups & Entrepreneurship";
        department[3].book[2].pubyear = 2011;
        department[3].book[2].publisher = "Currency";
        department[3].book[2].language = "English";
        department[3].book[2].edition = 1;
        department[3].book[2].numberofbooks = 10;

        // Add details for the remaining books
        department[3].book[3].bookname = "Good to Great: Why Some Companies Make the Leap... and Others Don't";
        department[3].book[3].authorname[0] = "Jim Collins";
        department[3].book[3].numofauthors= 1;
        department[3].book[3].ISBN = 66620996;
        department[3].book[3].booktype = "Business Management";
        department[3].book[3].pubyear = 2001;
        department[3].book[3].publisher = "HarperBusiness";
        department[3].book[3].language = "English";
        department[3].book[3].edition= 1;
        department[3].book[3].numberofbooks = 10;

        // Add details for the remaining books
        department[3].book[4].bookname = "Thinking, Fast and Slow";
        department[3].book[4].authorname[0] = "Daniel Kahneman";
        department[3].book[4].numofauthors= 1;
        department[3].book[4].ISBN = 374275637;
        department[3].book[4].booktype = "Decision-Making & Problem Solving";
        department[3].book[4].pubyear = 2011;
        department[3].book[4].publisher = "Farrar, Straus and Giroux";
        department[3].book[4].language = "English";
        department[3].book[4].edition = 1;
        department[3].book[4].numberofbooks = 10;

        // Add details for the remaining books
        department[3].book[5].bookname = "Blue Ocean Strategy: How to Create Uncontested Market Space and Make the Competition Irrelevant";
        department[3].book[5].authorname[0] = "W. Chan Kim";
        department[3].book[5].authorname[1] = "Renée Mauborgne";
        department[3].book[5].numofauthors = 2;
        department[3].book[5].ISBN = 1591396190;
        department[3].book[5].booktype = "Business & Money";
        department[3].book[5].pubyear = 2005;
        department[3].book[5].publisher = "Harvard Business Review Press";
        department[3].book[5].language = "English";
        department[3].book[5].edition = 1;
        department[3].book[5].numberofbooks = 10;

        // Add details for the remaining books
        department[3].book[6].bookname = "How to Win Friends and Influence People";
        department[3].book[6].authorname[0] = "Dale Carnegie";
        department[3].book[6].numofauthors = 1;
        department[3].book[6].ISBN = 671027034;
        department[3].book[6].booktype = "Interpersonal Relations & Leadership";
        department[3].book[6].pubyear = 1998;
        department[3].book[6].publisher = "Pocket Books";
        department[3].book[6].language = "English";
        department[3].book[6].edition = 1;
        department[3].book[6].numberofbooks = 10;

        // Add details for the remaining books
        department[3].book[7].bookname = "The Innovator's Dilemma: When New Technologies Cause Great Firms to Fail";
        department[3].book[7].authorname[0] = "Clayton M. Christensen";
        department[3].book[7].numofauthors = 1;
        department[3].book[7].ISBN= 1633697262;
        department[3].book[7].booktype = "Strategic Management";
        department[3].book[7].pubyear = 2016;
        department[3].book[7].publisher = "Harvard Business Review Press";
        department[3].book[7].language = "English";
        department[3].book[7].edition = 1;
        department[3].book[7].numberofbooks = 10;

        // Add details for the remaining books
        department[3].book[8].bookname = "Start with Why: How Great Leaders Inspire Everyone to Take Action";
        department[3].book[8].authorname[0] = "Simon Sinek";
        department[3].book[8].numofauthors = 1;
        department[3].book[8].ISBN = 1591846447;
        department[3].book[8].booktype = "Motivational Management & Leadership";
        department[3].book[8].pubyear = 2009;
        department[3].book[8].publisher = "Portfolio";
        department[3].book[8].language = "English";
        department[3].book[8].edition = 1;
        department[3].book[8].numberofbooks = 10;

        // Add details for the remaining books
        department[3].book[9].bookname = "The 7 Habits of Highly Effective People: Powerful Lessons in Personal Change";
        department[3].book[9].authorname[0] = "Stephen R. Covey";
        department[3].book[9].numofauthors = 1;
        department[3].book[9].ISBN = 1982137274;
        department[3].book[9].booktype = "Personal Success in Business";
        department[3].book[9].pubyear = 2020;
        department[3].book[9].publisher = "Simon & Schuster";
        department[3].book[9].language = "English";
        department[3].book[9].edition = 1;
        department[3].book[9].numberofbooks = 10;

        //department[4]. refer to the books which come under the novels category and we have given 10 books for each category
            //now in novels category we have our first book
        department[4].book[0].bookname = "The Martian";
        department[4].book[0].authorname[0] = "Andy Weir";
        department[4].book[0].numofauthors = 1;
        department[4].book[0].ISBN = 9780553418026;
        department[4].book[0].booktype = "Science Fiction";
        department[4].book[0].pubyear = 2014;
        department[4].book[0].publisher = "Crown";
        department[4].book[0].language = "English";
department[4].book[0].edition = 1;
department[4].book[0].numberofbooks = 10;

department[4].book[1].bookname = "Seveneves";
department[4].book[1].authorname[0] = "Neal Stephenson";
department[4].book[1].numofauthors = 1;
department[4].book[1].ISBN = 9780062334510;
department[4].book[1].booktype = "Science Fiction";
department[4].book[1].pubyear = 2015;
department[4].book[1].publisher = "William Morrow";
department[4].book[1].language = "English";
department[4].book[1].edition = 1;
department[4].book[1].numberofbooks = 10;

// Historical Fiction Category
department[4].book[2].bookname = "The Pillars of the Earth";
department[4].book[2].authorname[0] = "Ken Follett";
department[4].book[2].numofauthors = 1;
department[4].book[2].ISBN = 9780451166890;
department[4].book[2].booktype = "Historical Fiction";
department[4].book[2].pubyear = 1989;
department[4].book[2].publisher = "New American Library";
department[4].book[2].language = "English";
department[4].book[2].edition = 1;
department[4].book[2].numberofbooks = 10;

// Fill in details for the remaining books
department[4].book[3].bookname = "The Abyss Beyond Dreams";
department[4].book[3].authorname[0] = "Peter F. Hamilton";
department[4].book[3].numofauthors = 1;
department[4].book[3].ISBN = 9780345547216;
department[4].book[3].booktype = "Science Fiction";
department[4].book[3].pubyear = 2014;
department[4].book[3].publisher = "Del Rey";
department[4].book[3].language = "English";
department[4].book[3].edition = 1;
department[4].book[3].numberofbooks = 10;

// Fill in details for the remaining books
department[4].book[4].bookname = "Iron, Gold, and Aluminium";
department[4].book[4].authorname[0] = "Ernest L. Ransome";
department[4].book[4].numofauthors = 1;
department[4].book[4].ISBN = 9781446534877;
department[4].book[4].booktype = "Historical Fiction";
department[4].book[4].pubyear = 2011;
department[4].book[4].publisher = "Borodino Books";
department[4].book[4].language = "English";
department[4].book[4].edition = 1;
department[4].book[4].numberofbooks = 10;

// Fill in details for the remaining books
department[4].book[5].bookname = "One Second After";
department[4].book[5].authorname[0] = "William R. Forstchen";
department[4].book[5].numofauthors = 1;
department[4].book[5].ISBN = 9780765317582;
department[4].book[5].booktype = "Science Fiction";
department[4].book[5].pubyear = 2009;
department[4].book[5].publisher = "Forge";
department[4].book[5].language = "English";
department[4].book[5].edition = 1;
department[4].book[5].numberofbooks = 10;

// Fill in details for the remaining books
department[4].book[6].bookname = "The Engineer Trilogy";
department[4].book[6].authorname[0] = "K.J. Parker";
department[4].book[6].numofauthors = 1;
department[4].book[6].ISBN = 9780316003415;
department[4].book[6].booktype = "Fantasy Fiction";
department[4].book[6].pubyear = 2008;
department[4].book[6].publisher = "Orbit";
department[4].book[6].language = "English";
department[4].book[6].edition = 1;
department[4].book[6].numberofbooks = 10;

// Fill in details for the remaining books
department[4].book[7].bookname = "Cryptonomicon";
department[4].book[7].authorname[0] = "Neal Stephenson";
department[4].book[7].numofauthors = 1;
department[4].book[7].ISBN = 9780380788620;
department[4].book[7].booktype = "Techno-Thriller, Historical Fiction";
department[4].book[7].pubyear = 1999;
department[4].book[7].publisher= "Avon Books";
department[4].book[7].language = "English";
department[4].book[7].edition = 1;
department[4].book[7].numberofbooks = 10;

// Fill in details for the remaining books
department[4].book[8].bookname = "The Code Book: The Science of Secrecy from Ancient Egypt to Quantum Cryptography";
department[4].book[8].authorname[0] = "Simon Singh";
department[4].book[8].numofauthors = 1;
department[4].book[8].ISBN = 9780385495325;
department[4].book[8].booktype = "Non-fiction";
department[4].book[8].pubyear = 1999;
department[4].book[8].publisher = "Random House";
department[4].book[8].language = "English";
department[4].book[8].edition = 1;
department[4]. book[8].numberofbooks = 10;

// Fill in details for the remaining books
department[4].book[9].bookname = "The Wright Brothers";
department[4].book[9].authorname[0] = "David McCullough";
department[4].book[9].numofauthors = 1;
department[4].book[9].ISBN = 9781476728742;
department[4].book[9].booktype = "Biography";
department[4].book[9].pubyear = 2015;
department[4].book[9].publisher = "Simon & Schuster";
department[4].book[9].language = "English";
department[4].book[9].edition = 1;
department[4].book[9].numberofbooks = 10;

}

    // bool leap year, month, day by ravi functions which are related to the feedback part

    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    bool isValidMonth(int month) {
        return month >= 1 && month <= 12;
    }

    bool isValidDay(int day, int month, int year) {
        if (day < 1)
            return false;

        switch (month) {
            case 2:
                if (isLeapYear(year))
                    return day <= 29;
                else
                    return day <= 28;
            case 4:
            case 6:
            case 9:
            case 11:
                return day <= 30;
            default:
                return day <= 31;
        }
    }

bool leapyr(int a){
    if(a%400==0) return true;
    else if(a%100 == 0) return false;
    else if(a%4 == 0) return true;
    else return false;
}
bool checkvalid(string s) {
    if (s.size() != 10) // Check if the string is of correct length
        return false;

    int dd = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(3, 2));
    int yyyy = stoi(s.substr(6, 4));

    if (mm < 1 || mm > 12) // Check if month is valid
        return false;

    if (dd < 1) // Check if day is valid
        return false;

    if (mm == 2) { // Check for February
        if (leapyr(yyyy)) { // Check if it's a leap year
            if (dd > 29)
                return false;
        } else {
            if (dd > 28)
                return false;
        }
    } else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) { // Check for months with 30 days
        if (dd > 30)
            return false;
    } else { // Check for months with 31 days
        if (dd > 31)
            return false;
    }

    return true;
}

unordered_map<int, pair<string,pair<string, pair<int, pair<string, pair<string, pair<string, pair<string, string>>>>>>>> StaffDetails() {
    unordered_map<int, pair<string,pair<string, pair<int, pair<string, pair<string, pair<string, pair<string, string>>>>>>>> Staff;

 //Deputy Registar - 0
    //Assistant Registar - 1
    //Technician -2
    //Trainee - 3
    //Non-Skilled Staff1 - 4
    //Non-Skilled Staff2 - 5


    Staff[0] ={"Deputy Registrar" ,{"Gopal Singh Jadav", {51, {"Male", {"24/04/2019", {"deputyregistrarLB@iiitm.ac.in", {"85Q2+G5W, Tilak Nagar, Gwalior, Madhya Pradesh 474002", "+91 98765 43210"}}}}}}};
    Staff[1] = {"Assistant Registar",{"Sanjay Soni", {39, {"Male", {"27/10/2018", {"assistantregistrarLB@iiitm.ac.in", {"79V8+FWP, Shinde Ki Chhawani, Gwalior, Madhya Pradesh 474003", "+91 87654 32109"}}}}}}};
    Staff[2] = {"Technician",{"Harish Negi", {48, {"Male", {"31/02/2022", {"technicianLB@iiitm.ac.in", {"62R6+XPR, Lashkar, Gwalior, Madhya Pradesh 474004", "+91 78901 23456"}}}}}}};
    Staff[3] = {"Trainee",{"Manju Atal", {29, {"Female", {"28/02/2021", {"traineeLB@iiitm.ac.in", {"73M4+G6Q, City Centre, Gwalior, Madhya Pradesh 474005", "+91 89012 34567"}}}}}}};
    Staff[4] = {"Non-Skilled Staff1",{"Mukhtos Ali Khan", {57, {"Male", {"15/05/2017", {"Nonskilled1LB@iiitm.ac.in", {"88P7+R89, Morar, Gwalior, Madhya Pradesh 474006", "+91 90123 45678"}}}}}}};
    Staff[5] = {"Non-Skilled Staff2",{"Pradeep Sri Das", {41, {"Male", {"31/01/2015", {"Nonskilled2LB@iiitm.ac.in", {"79J9+42P, Gandhi Road, Gwalior, Madhya Pradesh 474007", "+91 76543 21098"}}}}}}};

    return Staff;
}

void printStaff(unordered_map<int, pair<string,pair<string, pair<int, pair<string, pair<string, pair<string, pair<string, string>>>>>>>> &staff) {
    cout << "These are the following current Staff members\n\n";
    for(auto it = staff.begin(); it != staff.end(); ++it) {
        cout << "Position of Responsibility: " << it->second.first << endl;
        cout << "Name: " << it->second.second.first << endl;
        cout << "Age: " << it->second.second.second.first << endl;
        cout << "Gender: " << it->second.second.second.second.first << endl;
        cout << "Date of Joining: " << it->second.second.second.second.second.first << endl;
        cout << "Email ID: " << it->second.second.second.second.second.second.first << endl;
        cout << "Address: " << it->second.second.second.second.second.second.second.first << endl;
        cout << "Contact Number: " << it->second.second.second.second.second.second.second.second << endl << endl;
    }
}


void updateStaffMember(pair<string,pair<string, pair<int, pair<string, pair<string, pair<string, pair<string, string>>>>>>> &staffMember) {
    cin.ignore(); // Clear input buffer
    cout << "Name: ";
    getline(cin, staffMember.second.first);
 a:
    cout << "Age: ";
    int age;
    cin >> age;
    if(age < 0) {
        cout << "Invalid Input\nRe-Enter again\n";
        goto a;
    }
    if (age < 18) {
        cout << "Persons with age below 18 cannot be employed. Please enter the correct age.\n";
        goto a;
    }
    staffMember.second.second.first = age;
b:
    cout << "Gender:\n1. Male\n2. Female\n";
    int genderChoice;
    cin >> genderChoice;
    switch (genderChoice) {
        case 1:
            staffMember.second.second.second.first = "Male";
            break;
        case 2:
            staffMember.second.second.second.first = "Female";
            break;
        default:
            cout << "Invalid input. Please try again.\n";
            goto b;
    }
    cin.ignore(); // Clear input buffer
jd:
    cout << "Date of joining (DD/MM/YYYY): ";
    string joiningDate;
    getline(cin, joiningDate);
    bool cv=checkvalid(joiningDate);
    if(cv==true){
    staffMember.second.second.second.second.first = joiningDate;

    }
    else{
        cout<<"Invalid date input,Re-Enter again\n";
        goto jd;

    }



    cout << "Address: ";
    getline(cin, staffMember.second.second.second.second.second.second.first);
 ave:
    cout << "Contact Number: ";
    long long int contactNumber;
    cin >> contactNumber;
    string aah = to_string(contactNumber);
    if(aah.length() != 10) {
        cout << "Invalid Input.Re-Enter again\n";
        goto ave;
    }
    staffMember.second.second.second.second.second.second.second = "+91 " + to_string(contactNumber);

    cout << "Staff member details updated successfully.\n";
}

void updateStaff(unordered_map<int, pair<string,pair<string, pair<int, pair<string, pair<string, pair<string, pair<string, string>>>>>>>> &staff) {
    int choice;
    while(true) {
        cout << "Enter the staff member whom you want to replace\n";
        for(int i = 0; i < staff.size(); i++) {
            cout << i + 1 << ". " << staff[i].first << endl;
        }
        cout << staff.size() + 1 << ". Exit" << endl;
        cin >> choice;
        if(choice == staff.size() + 1) {
            cout << "Exited Successfully...\n";
            break;
        }
        if(choice < 1 || choice > staff.size()) {
            cout << "Invalid input\nRe-Enter Again\n";
            continue;
        }
        cout << "Enter the following details for Replacement\n";
        updateStaffMember(staff[choice - 1]);
    }
}



void addstaff(unordered_map<int, pair<string,pair<string, pair<int, pair<string, pair<string, pair<string, pair<string, string>>>>>>>> &staff) {
    int staffCount = staff.size() + 1; // Incrementing staffCount
    cout << "Enter the following details for new staff member\n";
    staff[staffCount-1]; // create new entry
staff[staffCount-1].first = " ";
    cout << "Position of Responsibility: ";
    // cin.ignore(); // Clear input buffer
    getline(cin>>ws, staff[staffCount-1].first);

    cout << "Name: ";
    getline(cin, staff[staffCount-1].second.first);
ak:
    cout << "Age: ";
    int age;
    cin >> age;
    if(age < 0) {
        cout << "Invalid Input\nRe-Enter again\n";
        goto ak;
    }
    if (age < 18) {
        cout << "Persons with age below 18 cannot be employed. Please enter the correct age.\n";
        goto ak;
    }
    staff[staffCount-1].second.second.first = age;
akk:
    cout << "Gender:\n1. Male\n2. Female\n";
    int genderChoice;
    cout<<"Enter:";
    cin >> genderChoice;
    switch (genderChoice) {
        case 1:
            staff[staffCount-1].second.second.second.first = "Male";
            break;
        case 2:
            staff[staffCount-1].second.second.second.first = "Female";
            break;
        default:
            cout << "Invalid input. Please try again.\n";
            goto akk;
    }

    cin.ignore(); // Clear newline character from previous input
    cout << "Email ID: ";
    getline(cin, staff[staffCount-1].second.second.second.second.first);
jd:
    cout << "Date of joining (DD/MM/YYYY): ";
    string joiningDate;
    getline(cin, joiningDate);
    if(checkvalid(joiningDate)){
    staff[staffCount-1].second.second.second.second.second.first = joiningDate;
    }
    else{
        cout<<"Invalid date input...Re-Enter \n";
        goto jd;
    }


    cout << "Address: ";
    getline(cin, staff[staffCount-1].second.second.second.second.second.second.first);
abc:
    cout << "Contact Number: ";
    long long int contactNumber;
    cin >> contactNumber;
    string aah = to_string(contactNumber);
    if(aah.length() != 10) {
        cout << "Invalid Input.Re-Enter again\n";
        goto abc;
    }
    staff[staffCount-1].second.second.second.second.second.second.second = "+91 " + to_string(contactNumber);

    cout << "Staff member details added successfully.\n\n";
}





    //code to receive the feedback by ravi

    void receivefeedback () {
        cout<<"Enter Feedback giver name:";
        getline(cin>>ws,f[numoffeedbackstaken].feedbackgiver);

        year:
        cout<<"Enter Year :";
        cin>>f[numoffeedbackstaken].feedbackyear;
        if (f[numoffeedbackstaken].feedbackyear <= 1997 || f[numoffeedbackstaken].feedbackyear >2024) {
            cout<<"*** INVALID YEAR INPUT ***"<<endl;
            goto year;
        }
        month:
        cout<<"Enter Month :";
        cin>>f[numoffeedbackstaken].feedbackmonth;
        if(!isValidMonth(f[numoffeedbackstaken].feedbackmonth))
        {
            cout<<"Invalid Month"<<endl;
            goto month;
        }
        date:
        cout<<"Enter date :";
        cin>>f[numoffeedbackstaken].feedbackdate;
        if(!isValidDay(f[numoffeedbackstaken].feedbackdate,f[numoffeedbackstaken].feedbackmonth,f[numoffeedbackstaken].feedbackyear))
        {
            cout<<"Invalid Date"<<endl;
            goto date;
        }

        rating:
        cout<<"Enter rating for book (1-5):";
        cin>>f[numoffeedbackstaken].rating;
        if(f[numoffeedbackstaken].rating < 1 || f[numoffeedbackstaken].rating > 5){
            cout<<"Invalid Rating"<<endl;
            goto rating;
        }
        cout<<"Enter feedback content: ";
        getline(cin>>ws, f[numoffeedbackstaken].feedbackcontent);
        numoffeedbackstaken++;
        cout<<"Feedback taken succesfully"<<endl<<endl;
        for (int i=0;i<numoffeedbackstaken;i++) {
            avgrating += f[i].rating;
        }

        if(numoffeedbackstaken>0)  avgrating = avgrating/numoffeedbackstaken;
        else avgrating = 0; //0 if no feedback is given
    }

    //code to print the feedbacks taken by ravi

    void printfeedback () {
        cout<<"\nNumber of feedbacks received:"<<numoffeedbackstaken<<endl;
        cout<<fixed<<setprecision(5)<<"Avg rating:"<<avgrating<<endl;
        if (numoffeedbackstaken == 0) {
            cout<<"There is no feedback to print"<<endl<<endl;
            return;
        }
        while(1) {
            cout<<"\n1. Print all the feedbacks received."<<endl;
            cout<<"2. Print all positive feedbacks (>=3)."<<endl;
            cout<<"3. Print all Negative feedbacks (< 3)."<<endl;
            cout<<"4. Exit."<<endl;
            int tempcount = 0;
            int tempcount1 = 0;
            int operation;

            cout<<"Enter the operation (1-4) : ";
            cin>>operation;

            switch (operation) {
               case 1:
                    cout<<"ALL FEEDBACK RATINGS"<<endl;
                    for(int i=0; i<numoffeedbackstaken; i++)
                    {
                        cout<<"Feedback given by : "<<f[i].feedbackgiver<<endl;
                        cout<<"Feedback taken on date: "<<f[i].feedbackdate<<"/"<<f[i].feedbackmonth<<"/"<< f[i].feedbackyear << endl;
                        cout<<"Rating: "<<f[i].rating<<endl;
                        cout<<"Feedback content: "<<f[i].feedbackcontent << endl;
                    }
                    break;
                case 2:
                    cout<<"FEEDBACKS WHICH HAVE RATING GREATER THAN OR EQUAL TO 3(ALL POSITIVE FEEDBACKS)"<<endl;
                    for(int i=0; i<numoffeedbackstaken; i++)
                    {
                        if(f[i].rating >= 3)
                        {
                            tempcount++;
                            cout<<"Feedback giver: "<<f[i].feedbackgiver<<endl;
                            cout<<"Feedback date: "<<f[i].feedbackdate<<"/"<<f[i].feedbackmonth<<"/"<< f[i].feedbackyear << endl;
                            cout<<"Rating: "<<f[i].rating<<endl;
                            cout<<"Feedback content: "<<f[i].feedbackcontent << endl;
                        }

                    }
                    if (tempcount == 0) {
                        cout<<"\nThere are no positive feedbacks"<<endl;
                    }
                    break;
                case 3:
                    cout<<"FEEDBACKS WHICH HAVE RATING LESSER THAN 3(ALL NEGATIVE FEEDBACKS)"<<endl;
                    for(int i=0; i<numoffeedbackstaken; i++)
                    {
                        if(f[i].rating < 3)
                        {
                            tempcount1++;
                            cout<<"Feedback giver: "<<f[i].feedbackgiver<<endl;
                            cout<<"Feedback date: "<<f[i].feedbackdate<<"/"<<f[i].feedbackmonth<<"/"<< f[i].feedbackyear << endl;
                            cout<<"Rating: "<<f[i].rating<<endl;
                            cout<<"Feedback content: "<<f[i].feedbackcontent << endl;
                        }
                    }
                    if(tempcount1 == 0) {
                        cout<<"\nThere are no negative feedbacks\n";
                    }
                    break;
                case 4:
                    cout<<"Exiting...\n"<<endl;
                    return;
                    break;
                default:
                    cout<<"***   Invalid Input   ***"<<endl;
                    break;
            }
        }
    }

    //code related to feedback has no errors by ravi end till here

    //ALL CODE FUNCTIONS RELATED TO THE BOOK AND BORROWERS START FROM HERE BY D H A V

    pair<int,int> check(Book b)
    {
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<department[i].size;j++)
            {
                if(department[i].book[j].bookname==b.bookname&& department[i].book[j].numofauthors==b.numofauthors&& department[i].book[j].language==b.language&&department[i].book[j].edition==b.edition)
                {
                    return {i,j};
                }
                return {-1,-1};
            }
        }
    }

    void addbook() {
    int copies;
     Book adbook;
        cout<<"Enter name(Official) of book:";
        getline(cin>>ws,adbook.bookname);

        numofauhere:
        cout<<"Enter number of Authors:";
        cin>>adbook.numofauthors;
/*
        if (adbook.numberofbooks<=0 || adbook.numberofbooks > MAX_AUTHOR_NUM) {
            cout<<"***   INVALIDINPUT   ***"<<endl;
            goto numofauhere;
        }*/

        for(int i=0;i<adbook.numofauthors;i++){
            cout<<"Enter name of Author "<<i+1<<" :";
            getline(cin>>ws,adbook.authorname[i]);
        }

        isbihere:
        cout<<"Enter ISBN:";
        cin>>adbook.ISBN;
        if (adbook.ISBN <= 0) {
            cout<<"***   INVALIDINPUT   ***"<<endl;
            goto isbihere;
        }

        cout<<"Enter publisher:";
        getline(cin>>ws,adbook.publisher);

        cout<<"Enter Language:";
        getline(cin,adbook.language);

        hereedition:
        cout<<"Enter Edition:";
        cin>>adbook.edition;
        if (adbook.edition <= 0) {
            cout<<"*** INVALID EDITION INPUT ***"<<endl;
            goto hereedition;
        }

        herecop:
        cout<<"Enter Number of copies you want to add:";
        cin>>copies;

        if (copies<=0) {
            cout<<"***   INVALID INPUT   ***"<<endl;
            goto herecop;
        }

        int departindx=(check(adbook)).first;
        int bookindx=(check(adbook)).second;

        if(departindx !=-1 && bookindx !=-1) {
            cout<<"THE BOOK ALREADY EXISTS SO NUJMBER OF COPIES IS UPDATED"<<endl;
            department[departindx].book[bookindx].numberofbooks+=copies;
            return;
        }

        cout<<"Now enter the book type is related to which of the following departments"<<endl;

        heredepindex:
        cout<<"1.CSE.\n2.MSC.\n3.EEE.\n4.MBA.\n5.Novels\n";
        cout<<"ENTER:";
        cin>>departindx;//range condition

        if (departindx<=0 || departindx>5) {
            cout<<"***   INVALID INPUT   ***"<<endl;
            goto heredepindex;
        }

    departindx--;

          if(department[departindx].size>=15)
          {
              cout<<"\nMaximum number of types of books in a particular deparment is 15"<<endl<<"So there no place for the new book in this department";
              return;
          }
           bookindx=department[departindx].size;

         department[departindx].book[bookindx].bookname=adbook.bookname;

         for(int i=0;i<adbook.numofauthors ;i++){
          department[departindx].book[bookindx].authorname[i]=adbook.authorname[i];
         }
            department[departindx].book[bookindx].booktype=adbook.booktype;
            department[departindx].book[bookindx].edition=adbook.edition;
            department[departindx].book[bookindx].ISBN=adbook.ISBN;
            department[departindx].book[bookindx].language=adbook.language;
            department[departindx].book[bookindx].numberofbooks+=copies;
            department[departindx].book[bookindx].numofauthors=adbook.numofauthors;
            department[departindx].book[bookindx].publisher=adbook.publisher;
            department[departindx].book[bookindx].pubyear=adbook.pubyear;
            department[departindx].size++;
    }




    //initially there will be no borrowers
    void individualdetails(){
        long long phonenum;
        int j=-1;int choice;
        cout<<"Enter your phone number(ID):";//considering phone number as id
        cin>>phonenum;
        for(int i=0;i<total_borrowers.size();i++)
        {
            if(total_borrowers[i].borrowerphonenum==phonenum)
            {
                j=i;
            }
        }
        if(j==-1)
        {
            cout<<"\nYou are not registered Yet!!";
            cout<<"\nIf you want to register Enter ONLY ZERO:";
            cin>>choice;
            if(choice==0)
            {
                addborrower();
            }else
            {
                cout<<"\nThank you for coming";//feedback
            }


        }else
        {
            cout<<"You are already registered \nYour Details are:\n";
            cout<<"\nName:"<<total_borrowers[j].borrowername<<"\nAge:"<<total_borrowers[j].borrowerage<<"\nGender:"<<total_borrowers[j].borrowergender;
            cout<<"\nE-mail:"<<total_borrowers[j].borrowermail<<"\nPhone number(ID):"<<total_borrowers[j].borrowerphonenum<<"\nDate of Registration:"<<total_borrowers[j].membershipexpdate<<'/'<<total_borrowers[j].membershipexpmonth<<'/'<<total_borrowers[j].membershipexpyear;
            cout<<"\nNumber of books taken:"<<total_borrowers[j].numberofbookstaken<<endl;
            /*for(int i=0;i<total_borrowers[j].numberofbookstaken;i++)
            {
                cout<<total_borrowers[j].bookname[i]<<endl;
            }*/
        }




    }

    int addborrower() {
         //aditya and vidath
        long long phonenum;
        int j=-1;
        cout<<"Enter your phone number(ID):";
        cin>>phonenum;
        for(int i=0;i<total_borrowers.size();i++)
        {
            if(total_borrowers[i].borrowerphonenum==phonenum)
            {
                j=i;
            }
        }
        if(j!=-1){
            cout<<"\nYou are already registered!!";
        return j ;
        }

        borrowers b;
        cout<<"Enter Your name:";
        getline(cin>>ws,b.borrowername);
        cout<<"Enter your age:";
        cin>>b.borrowerage;
        cout<<"Enter your gender:";
        cin>>b.borrowergender;
        cout<<"Enter your E-mail:";
        cin>>b.borrowermail;
        cout<<"Enter your phone number:";
        cin>>b.borrowerphonenum;
        herephonenum:
        if (b.borrowerphonenum < 1000000000 || b.borrowerphonenum > 9999999999) {
            cout<<"***   INVALID PHONE NUMBER   ***"<<endl;
            goto herephonenum;
        }
        cout<<"Enter Date of Registration(Year):";
        cin>>b.membershipexpyear;





        backmonth:
        cout<<"Enter Date of Registration(Month):";
        cin>>b.membershipexpmonth;


        if(!(isValidMonth(b.membershipexpmonth)))
        {
            cout<<"***   INVALID  MONTH   ***";
            goto backmonth;
        }


        backday:
        cout<<"Enter Date of Registration(Day):";
        cin>>b.membershipexpdate;

        if(!(isValidDay(b.membershipexpdate,b.membershipexpmonth,b.membershipexpyear)))
        {
            cout<<"***   INVALID  DAY   ***";
            goto backday;
        }



        total_borrowers.push_back(b);

        return total_borrowers.size();
    }

    void printborrowers() {
        //aditya and vidath

        for(int j=0;j<total_borrowers.size();j++)
        {
                cout<<"\nDetails of Borrower-"<<j+1<<endl;
            cout<<"\nName:"<<total_borrowers[j].borrowername<<"\nAge:"<<total_borrowers[j].borrowerage<<"\nGender:"<<total_borrowers[j].borrowergender;
            cout<<"\nE-mail:"<<total_borrowers[j].borrowermail<<"\nPhone number(ID):"<<total_borrowers[j].borrowerphonenum<<"\nDate of Registration:"<<total_borrowers[j].membershipexpdate<<'/'<<total_borrowers[j].membershipexpmonth<<'/'<<total_borrowers[j].membershipexpyear;
            cout<<"\nNumber of books taken:"<<total_borrowers[j].numberofbookstaken;
            for(int i=0;i<total_borrowers[j].numberofbookstaken;i++)
            {
                cout<<total_borrowers[j].bookname[i]<<endl;
            }
        }
    }

    void takebook() {
        //aditya vidath and david
        int j=addborrower();
        if(total_borrowers[j].numberofbookstaken>=MAX_NUM_OF_BORROW_BOOKS)
        {
            cout<<"Maximum number of books can be taken are five\nYour limit exceeded!!\n";
            return;
        }

        int choicedepartment,choicebook;

        cout<<"\nChoose Type of Books you want:";
        cout<<"\n0.To get CSE related books\n1.To get MSC related books\n2.To get EEE related books\n3.To get MBA related books\n4.To get NOVELS: ";
        cin>>choicedepartment;//range condition

       cout<<endl;
       for(int i=0;i<department[choicedepartment].size;i++)
       {
           cout<<i<<"."<<department[choicedepartment].book[i].bookname<<endl;
       }
       cout<<"Choose any book:";//range condition
       cin>>choicebook;
       cout<<department[choicedepartment].book[choicebook].bookname<<"is taken by customer";
       department[choicedepartment].book[choicebook].numberofbooks--;
       total_borrowers[j].numberofbookstaken++;
       //total_borrowers[j].bookname[total_borrowers[j].numberofbookstaken]=department[choicedepartment].book[choicebook].bookname;


    }

    void givebackbook() {
        //aditya vidath and david
         int j=addborrower();
         cout<<"\nChoose the department of the book, that to be returned:";
        cout<<"\n0.Belongs to CSE\n1.Belongs to MSC\n2.Belongs to EEE\n3.Belongs to MBA\n4.Belongs to NOVELS:  ";
         int choicedepartment,choicebook;
         cin>>choicedepartment;
         cout<<endl;
         for(int i=0;i<department[choicedepartment].size;i++)
       {
           cout<<i<<"."<<department[choicedepartment].book[i].bookname<<endl;
       }
       cout<<"Choose that book:";
       cin>>choicebook;

       int indx=-1;
       for(int i=0;i< total_borrowers[j].numberofbookstaken;i++)
       {
           if(department[choicedepartment].book[choicebook].bookname==total_borrowers[j].bookname[i])
           {
               indx=i;
               break;
           }

       }
       if(indx==-1)
       {
           cout<<"\nYou have not taken this book"<<endl;
           return;
       }
       if(indx!=total_borrowers[j].numberofbookstaken-1)
       {
           for(int i=indx;i<total_borrowers[j].numberofbookstaken-1;i++)
           {
               total_borrowers[j].bookname[i]= total_borrowers[j].bookname[i+1];
           }
       }


       cout<<department[choicedepartment].book[choicebook].bookname<<"is returned by customer";
       department[choicedepartment].book[choicebook].numberofbooks++;
       total_borrowers[j].numberofbookstaken--;
    }

    void printingbook() {
        int choicedepartment;

        cout<<"\nChoose Type of Books you want:";
        cout<<"\n0.To get CSE related books\n1.To get MSC related books\n2.To get EEE related books\n3.To get MBA related books\n4.To get other books: ";
        cin>>choicedepartment;//range condition

       cout<<endl;
       for(int i=0;i<department[choicedepartment].size;i++)
       {
           cout<<i<<"."<<department[choicedepartment].book[i].bookname<<endl;
       }
    }

    //till here end of book and borrowers module by David, Hima, Adithya, Vidhat

    //extra function added by sasidhar for  print thesis function
    string getBranchName(int bIndex) {
        switch (bIndex) {
            case 1: return "Computer Science";
            case 2: return "Mathematics and Computing";
            case 3: return "Electrical and Electronics";
            case 4: return "Information Technology";
            case 5: return "Business Management";
            default: return "Unknown";
        }
    }

    //code to add a new thesis papers to the library by sasidhar
    void addthesis() {
        branch:
        cout<< "NOW YOU ARE A NEW THESIS"<<endl;
        cout << "Choose the branch inn which you want to add the new thesis \n" << endl;
        cout << "1. Computer Science\n";
        cout << "2. Mathematics and Computing" << endl;
        cout << "3. Electrical and Electronics" << endl;
        cout << "4. Information Technology" << endl;
        cout << "5. Business Management" << endl;
        cout << "Enter the branch index: ";
        int branchIndex;
        cin >> branchIndex;
        if (branchIndex <= 0 || branchIndex > NUMBER_OF_BRANCHES) {
            cout << "Invalid branch index." << endl;
            goto branch;
        }

        branchIndex--;

        if (number_of_thesis_per_branch[branchIndex] >= MAX_NUM_OF_THESIS) {
            cout << "Maximum number of theses reached for this branch." << endl;
            return;
        }

        cout << "Enter the details of the new thesis:" << endl;
        cout << "Title: ";
        getline(cin >> ws, t[branchIndex][number_of_thesis_per_branch[branchIndex]].thesisname);
        cout << "Authors: ";
        getline(cin >> ws, t[branchIndex][number_of_thesis_per_branch[branchIndex]].nameAuthor);
        year:
        cout << "Year: ";
        cin >> t[branchIndex][number_of_thesis_per_branch[branchIndex]].thesisyear;
        if(t[branchIndex][number_of_thesis_per_branch[branchIndex]].thesisyear <= 1997) {
            cout << "This year is not valid. So, please enter another one"<<endl;
            goto year;
        }
        else if(t[branchIndex][number_of_thesis_per_branch[branchIndex]].thesisyear >= 2024) {
            cout << "This year has not yet happened"<<endl;
            goto year;
        }
        number_of_thesis_per_branch[branchIndex]++;
        number_of_thesis++;
    }

    //code related to print the thesis by sasidhar
    void printthesis() {
        int m;
        do {
            cout << "1. Print details of all the Research Thesis." << endl;
            cout << "2. Print details of all the thesis for a particular branch" << endl;
            cout << "3. Print details of a particular Research Thesis." << endl;
            cout << "4. Exit the program"<<endl;
            cout << "Enter your choice: ";
            cin >> m;

            if (m == 1) {
                for (int i = 0; i < NUMBER_OF_BRANCHES; ++i) {
                    cout << "Thesis for " << getBranchName(i + 1) << " branch:" << endl;
                    for (int j = 0; j < number_of_thesis_per_branch[i]; ++j) {
                        cout << "Thesis " << j + 1 << ":" << endl;
                        cout << "Title: " << t[i][j].thesisname << endl;
                        cout << "Authors: " << t[i][j].nameAuthor << endl;
                        cout << "Year: " << t[i][j].thesisyear << endl;
                        cout << "Branch: " << t[i][j].branch << endl;
                        cout << endl;
                    }
                }
            }
            else if (m == 2) {
                cout << endl<<"The Branches are: \n" << endl;
                cout << "1. Computer Science" << endl;
                cout << "2. Mathematics and Computing" << endl;
                cout << "3. Electrical and Electronics" << endl;
                cout << "4. Information Technology" << endl;
                cout << "5. Business Management" << endl;
                cout << "Enter the branch index: ";
                int bIndex; cin >> bIndex;
                if (bIndex >= 1 && bIndex <= NUMBER_OF_BRANCHES) {
                    cout << "Thesis for " << getBranchName(bIndex) << " branch:" << endl;
                    for (int j = 0; j < number_of_thesis_per_branch[bIndex - 1]; ++j) {
                        cout << "Thesis " << j + 1 << ":" << endl;
                        cout << "Title: " << t[bIndex - 1][j].thesisname << endl;
                        cout << "Authors: " << t[bIndex - 1][j].nameAuthor << endl;
                        cout << "Year: " << t[bIndex - 1][j].thesisyear << endl;
                        cout << "Branch: " << t[bIndex - 1][j].branch << endl;
                        cout << endl;
                    }
                } else {
                    cout << "Invalid branch index." << endl;
                }
            }
            else if (m == 3) {
                cout << endl<<"The Branches are: \n" << endl;
                cout << "1. Computer Science" << endl;
                cout << "2. Mathematics and Computing" << endl;
                cout << "3. Electrical and Electronics" << endl;
                cout << "4. Information Technology" << endl;
                cout << "5. Business Management" << endl;
                br:
                cout << "Enter the branch index: ";
                int branchIndex;
                cin >> branchIndex;
                if (branchIndex >= 1 && branchIndex <= NUMBER_OF_BRANCHES) {
                    for (int i = 0; i < number_of_thesis_per_branch[branchIndex - 1]; ++i) {
                        cout << i+1 << ". " << t[branchIndex - 1][i].thesisname << endl;
                    }
                    cout << "Enter Index: ";
                    int m; scanf("%d", &m);
                    if(m <= number_of_thesis_per_branch[branchIndex - 1]) {
                        cout << "Thesis " << m << ":" << endl;
                        cout << "Title: " << t[branchIndex - 1][m-1].thesisname << endl;
                        cout << "Authors: " << t[branchIndex - 1][m-1].nameAuthor << endl;
                        cout << "Year: " << t[branchIndex - 1][m-1].thesisyear << endl;
                        cout << "Branch: " << t[branchIndex - 1][m-1].branch << endl;
                        cout << endl;
                    }
                }
                else {
                    cout << "Invalid branch index. Enter again" << endl;
                    goto br;
                }
            }
            else if(m == 4) {
                    cout << "The print function has been stopped" << endl;
            }
            else {
                cout << "Invalid choice. Please try again." << endl;
            }
        } while (m != 4);
    }
};


int main() {
    library l;
     unordered_map<int, pair<string,pair<string, pair<int, pair<string, pair<string, pair<string, pair<string, string>>>>>>>> staff=l.StaffDetails();
    cout<<"hee"<<endl;

    while(1) {
        cout<<"1.Print book details."<<endl; // need to be done

        cout<<"2.Add a new book."<<endl; //all correct need to modify the outputs (and final check that the inputs are taking or not)

        cout<<"3.Add new borrower."<<endl;
        cout<<"4.Print borrower details."<<endl;
        cout<<"5.Take a book."<<endl;
        cout<<"6.Give a book back."<<endl;

        cout<<"7.print Thesis details."<<endl; // all correct
        cout<<"8.Add a new thesis."<<endl; //all correct
        cout<<"9.Take a feedback."<<endl; //all correct
        cout<<"10.Print feedbacks taken."<<endl; //all correct
        cout<<"11.Print staff details."<<endl; // all correct
        cout<<"12.Update a staff member details."<<endl; // all correct
        cout<<"13.Add a new staff member."<<endl;// all correct
        cout<<"14.EXIT"<<endl;//all correct
        int op;
        cout<<"ENTER:";
        cin>>op;

        switch (op) {
        case 1:
            l.printingbook();
            break;
        case 2:
            l.addbook();
            break;
        case 3:
            l.addborrower();
            break;
        case 4:
            l.printborrowers();
            break;
        case 5:
            l.takebook();
            break;
        case 6:
            l.givebackbook();
            break;
        case 7:
            l.printthesis();
            break;
        case 8:
            l.addthesis();
            break;
        case 9:
            l.receivefeedback();
            break;
        case 10:
            l.printfeedback();
            break;
        case 11:
            l.printStaff(staff);
            break;
        case 12:
            l.updateStaff(staff);
            break;
        case 13:
            l.addstaff(staff);
            break;
        case 14:
            exit(0);
            break;
        default:
            cout<<"*** INVALID OPERATION INPUT ***"<<endl;
        }
    }

    return 0;
}
