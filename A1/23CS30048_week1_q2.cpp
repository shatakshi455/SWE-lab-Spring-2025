//SHATAKSHI SINGH
//23CS30048
//WEEK 1 QUESTION 2

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include<bits/stdc++.h>
using namespace std;

vector<int>worked(12, 0);

map<string, int> monthOrder = {
        {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4},
        {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8},
        {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
};


int max_sal=0, min_sal=INT_MAX;

pair<string, double> processSalaries(const string &salaryDetails) {
    
    stringstream ss(salaryDetails);
    string salary;
    vector<pair<int, string>> salaryData;
    double totalSalary = 0;
    int count = 0;

    while (getline(ss, salary, ',')) {
        size_t pos = salary.find('-');
        if (pos != string::npos) {
            string month = salary.substr(0, pos);
            worked[monthOrder[month]-1]++; //updating that user worked that month
            string amountStr;
            if(salary.substr(4, 1)=="'") amountStr = salary.substr(pos + 2, salary.length()-6); //when salary is in single quotes
            else amountStr = salary.substr(pos + 1);
            
                int amount = round(stof(amountStr)); //salary in nearest integer
                min_sal=min(min_sal, amount); //minimum salary ever
                max_sal=max(max_sal, amount); //maximum salary ever

                if (monthOrder.find(month) != monthOrder.end()) {
                    salaryData.push_back({monthOrder.at(month), month + "-" + to_string(amount)});
                    totalSalary += amount; //for calculating mean salary later
                    count++;
                }
            
        } 
    }

    // Sort salaries by calendar month order
    sort(salaryData.begin(), salaryData.end());

    // Rebuild sorted salary string
    string sortedSalaryDetails;
    for (const auto &entry : salaryData) {
        sortedSalaryDetails += entry.second + ",";
    }
    if (!sortedSalaryDetails.empty()) {
        sortedSalaryDetails.pop_back(); // Remove trailing comma
    }

    double meanSalary = count > 0 ? totalSalary / count : 0; //finding mean salary for that user
    return {sortedSalaryDetails, meanSalary};
}

int main()
{
    string line;
    ifstream infile("users.txt");
    ofstream outfile;
    outfile.open("new_users.txt");

    map<string, long long int>sal_sum, freq; //map to store total of avg salaries for all companies and the frequency of companies
    int malen=0, milen=INT_MAX;

    string long_user, short_user; //strings with longest and shortest username
    long long int passlen=0; //total length of all passwords
    int users=0;//total users
    while (getline(infile, line)) {
        if(line.length()==0) break;
        stringstream ss(line);
        string username, company, password, salaryDetails;
        
        getline(ss, username, ',');
        username = username.substr(5); //removing prefix "user_"

        if(username.length()<milen){ //updating shortest username
            milen=username.length();
            short_user=username;
        }

        if(username.length()>malen){ //updating longest username
            malen=username.length();
            long_user=username;
        }

        
        getline(ss, company, ',');
        freq[company]++; //increments frequency for that company

        getline(ss, password, ',');
        getline(ss, salaryDetails);

        passlen+=password.length();  //total of all password lengths
        users++; //total users

        
        if (password.size() < 9) { //if password is too short, append weak password
            password += "__WEAK_PASSWORD";
        }
        
        auto [sortedSalaries, meanSalary] = processSalaries(salaryDetails);
        
        outfile << username << "," << company << "," << password << "," 
                << sortedSalaries << ",Mean_Salary-" << meanSalary << endl;
        sal_sum[company]+=meanSalary;

    }
    cout<<"Average password length: "<<(double)passlen/users<<endl;
    cout<<"Longest Username: "<<long_user<<endl;
    cout<<"Shortest Username: "<<short_user<<endl;

    map<int, string, greater<int> > mymap, avg_sal;
 
    for(auto x:freq){
        mymap.insert(make_pair(x.second, x.first));
    }
    int nu=0;

    for(auto x:freq){
        avg_sal.insert(make_pair(sal_sum[x.first]/x.second, x.first));
    }

    cout<<"Top 5 frequent companies are:"<<endl;
    for (auto it = mymap.begin(); it != mymap.end() && nu<5; it++){
        cout <<nu+1<<") "<<(*it).second << ", " << (*it).first << endl;
        nu++;
    }
    cout<<"Minimum Salary:"<<min_sal<<endl;
    cout<<"Maximum Salary:"<<max_sal<<endl;
    auto it = avg_sal.begin();
    cout<<"Highest Paying Company: "<<(*it).second <<endl;
    it=avg_sal.end();
    it--;
    cout<<"Lowest Paying Company: "<<(*it).second <<endl;

    //function to find month with most workers
    int maxWorked = 0;
    int maxMonthIndex = 0;
    for (int i = 0; i < 12; i++) {
        if (worked[i] > maxWorked) {
            maxWorked = worked[i];
            maxMonthIndex = i;
        }
    }

    const vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    cout << "The month with the most users who received a salary/worked is: " 
     << months[maxMonthIndex] << " with " << maxWorked << " users." << endl;

    infile.close();
    outfile.close();
    return 0;
}
